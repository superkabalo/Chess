#include "Game.h"
#include "Board.h"
#include "Figure.h"
#include "King.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "Pawn.h"
#include "None.h"

Board::Board() : Board(INITIAL_GAME_STR)
{
}

Board::Board(const char board[SIZE * SIZE])
{
    int stringIndex = ZERO;

    for (int i = ZERO; i < SIZE; i++)  // go over board
    {
        for (int j = ZERO; j < SIZE; j++)
        {
            char pieceSymbol = board[stringIndex++];  // get current figure type

            switch (pieceSymbol)  // create board figures accordingly
            {
            case BLACK_KING:
				_board[i][j] = new King(BLACK, Point(j + ONE, SIZE - i), BLACK_KING);
				_blackKing = Point(j + ONE, SIZE - i);  // set king position
                break;

            case BLACK_ROOK:
                _board[i][j] = new Rook(BLACK, Point(j + ONE, SIZE - i), BLACK_ROOK);
                break;

            case BLACK_BISHOP:
                _board[i][j] = new Bishop(BLACK, Point(j + ONE, SIZE - i), BLACK_BISHOP);
                break;

            case BLACK_KNIGHT:
                _board[i][j] = new Knight(BLACK, Point(j + ONE, SIZE - i), BLACK_KNIGHT);
                break;

            case BLACK_QUEEN:
                _board[i][j] = new Queen(BLACK, Point(j + ONE, SIZE - i), BLACK_QUEEN);
                break;

            case BLACK_PAWN:
                _board[i][j] = new Pawn(BLACK, Point(j + ONE, SIZE - i), BLACK_PAWN);
                break;

            case WHITE_KING:
                _board[i][j] = new King(WHITE, Point(j + ONE, SIZE - i), WHITE_KING);
                _whiteKing = Point(j + ONE, SIZE - i);
                break;
            case WHITE_ROOK:
                _board[i][j] = new Rook(WHITE, Point(j + ONE, SIZE - i), WHITE_ROOK);
                break;

            case WHITE_BISHOP:
                _board[i][j] = new Bishop(WHITE, Point(j + ONE, SIZE - i), WHITE_BISHOP);
                break;

            case WHITE_KNIGHT:
                _board[i][j] = new Knight(WHITE, Point(j + ONE, SIZE - i), WHITE_KNIGHT);
                break;

            case WHITE_QUEEN:
                _board[i][j] = new Queen(WHITE, Point(j + ONE, SIZE - i), WHITE_QUEEN);
                break;

            case WHITE_PAWN:
                _board[i][j] = new Pawn(WHITE, Point(j + ONE, SIZE - i), WHITE_PAWN);
                break;

            default:  // an empty square
                _board[i][j] = new None(Point(j + ONE, SIZE - i));
            }
        }
    }
}

Board::~Board()
{
    for (int i = ZERO; i < SIZE; i++)  // free memory of _board array
    {
        for (int j = ZERO; j < SIZE; j++)
        {
            delete _board[i][j];  // delete current element
        }
    }
}

std::string Board::moveFigure(const Point& a, const Point& b, int color)
{
    if (checkCoordinates(a, b) == FIVE)  // check coordinates
    {
        return CODE5;
    }

    if (checkCoordinates(a, b) == SEVEN)
    {
        return CODE7;
    }

    Figure* sourceFigure = _board[SIZE - a.getY()][a.getX() - ONE];  // get figures at points a and b
    Figure* destinationFigure = _board[SIZE - b.getY()][b.getX() - ONE];

	if (sourceFigure->getColor() != color)  // check source figure and destination figure colors
	{
        return CODE2;
	}

	if (destinationFigure->getColor() == color)
	{
        return CODE3;
	}

    // Check if the move is legal for the specific figure type
    if (!sourceFigure->canMove(b, _board))
    {
        return CODE6; // Invalid move: illegal movement of a tool.
    }

    // Perform the move
    sourceFigure->moveFigure(b, _board);
    
    // Update the kings' position if necessary
    updateKingPosition(sourceFigure);

    // Check if the move resulted in check on the current player
    if (isCheck(color))
    {
        // Undo the move
        delete _board[SIZE - a.getY()][a.getX() - ONE];  // delete current figure at a since moveFigure will place a new figure there
        sourceFigure->moveFigure(a, _board);

        delete _board[SIZE - b.getY()][b.getX() - ONE];  // delete current figure at b since we will place the original destination figure there
        _board[SIZE - b.getY()][b.getX() - ONE] = destinationFigure;  // return the destination figure to its place

        // revert kings' position change if neccessary
        updateKingPosition(sourceFigure);
        return CODE4; // Improper move, the move will result in check on the current player.
    }

    delete destinationFigure;  // delete memory of the destination figure if the move went correctly
    sourceFigure->successfulMove();


    // BONUS - if a pawn reaches the other end of the board it will turn into a queen
    Figure* newFigure = sourceFigure; // create new figure as sourceFigure
    if (sourceFigure->getType() == WHITE_PAWN && sourceFigure->getCoordinates().getY() == EIGHT)  // if white pawn reached the other end of the board
    {
        newFigure = new Queen(sourceFigure->getColor(), sourceFigure->getCoordinates(), WHITE_QUEEN);  // replace pawn with queen
        delete sourceFigure;  // delete pawn
    }
    else if (sourceFigure->getType() == BLACK_PAWN && sourceFigure->getCoordinates().getY() == ONE)  // if black pawn reached the other end of the board
    {
        newFigure = new Queen(sourceFigure->getColor(), sourceFigure->getCoordinates(), BLACK_QUEEN);
        delete sourceFigure;
    }
    _board[SIZE - b.getY()][b.getX() - ONE] = newFigure;  // set new figure on the board


    // Switch the current player after a successful move
    color = (color == WHITE) ? BLACK : WHITE;

    // Check if the move caused check on the opponent
    if (isCheck(color))
    {
        // BONUS 2 - added checkmate!
        if (isCheckmate(color))  // check if moved caused checkmate on the oppponent
        {
            return CODE8;
        }
        return CODE1; // A proper move, a move was made that caused check on the opponent.
    }

    return CODE0; // Correct move, chess is played!
}


int Board::checkCoordinates(const Point& a, const Point& b) const
{
	// Check if coordinates are within the board boundaries
	if (a.getX() < ONE || a.getX() > SIZE || a.getY() < ONE || a.getY() > SIZE ||
		b.getX() < ONE || b.getX() > SIZE || b.getY() < ONE || b.getY() > SIZE)
	{
		return FIVE; // Invalid coordinates
	}

	// Check if source and destination are the same
	if (a.getX() == b.getX() && a.getY() == b.getY())
	{
		return SEVEN; // Same coordinates
	}

	return TWO; // Valid coordinates
}

bool Board::isCheck(const int color)
{

    Point kingPos = (color == WHITE) ? _whiteKing : _blackKing;  // get position of king according to color

	// Check if the king is under attack by any opponent's figure
	for (int i = ZERO; i < SIZE; i++)
	{
		for (int j = ZERO; j < SIZE; j++)
		{
			Figure* figure = _board[i][j];  // current figure

			if (figure->getColor() != color && figure->canMove(kingPos, _board))
			{
				return true; // King is in check
			}
		}
	}

	return false; // King is not in check
}

void Board::printBoard() const
{
    for (int i = ZERO; i < SIZE; i++)  // go over all board elements
    {
        for (int j = ZERO; j < SIZE; j++)
        {
            std::cout << _board[i][j]->getType() << " ";  // print current figure type
        }
        std::cout << std::endl;
    }
}

bool Board::isCheckmate(const int color)
{
    Figure* curFigure = nullptr;  // current piece
    // Iterate over all pieces of the player's color
    for (int i = ZERO; i < SIZE; i++)
    {
        for (int j = ZERO; j < SIZE; j++)
        {
            curFigure = _board[i][j];

            // Check if the piece belongs to the player
            if (curFigure->getColor() == color)
            {
                // Try all possible moves for the current piece
                for (int x = ONE; x <= SIZE; x++)
                {
                    for (int y = ONE; y <= SIZE; y++)
                    {
                        Point destination(x, y);

                        // Check if the move is valid
                        if (_board[SIZE - y][x - ONE]->getColor() != color && curFigure->canMove(destination, _board))
                        {
                            // move curFigure to destination
                            Point srcCoordinates(curFigure->getCoordinates());  // src corrdinates
                            Figure* destinationFigure = _board[SIZE - y][x - ONE];  // figure at destination;
                            curFigure->moveFigure(destination, _board);

                            updateKingPosition(curFigure);  // update king position

                            this->printBoard();
                            std::cout << std::endl << std::endl;
                            // Check if the move removes the check - if it does it is not checkmate
                            if (!isCheck(color))
                            {
                                // Undo the move
                                delete _board[SIZE - srcCoordinates.getY()][srcCoordinates.getX() - ONE];  // delete current figure at srcCoordinates since moveFigure will place a new figure there
                                curFigure->moveFigure(srcCoordinates, _board);

                                delete _board[SIZE - y][x - ONE];  // delete current figure at destination since we will place the original destination figure there
                                _board[SIZE - y][x - ONE] = destinationFigure;  // return the destination figure to its place

                                // revert kings' position change if neccessary
                                updateKingPosition(curFigure);
                                return false;
                            }

                            // Undo the move
                            delete _board[SIZE - srcCoordinates.getY()][srcCoordinates.getX() - ONE];  // delete current figure at srcCoordinates since moveFigure will place a new figure there
                            curFigure->moveFigure(srcCoordinates, _board);

                            delete _board[SIZE - y][x - ONE];  // delete current figure at destination since we will place the original destination figure there
                            _board[SIZE - y][x - ONE] = destinationFigure;  // return the destination figure to its place

                            // revert kings' position change if neccessary
                            updateKingPosition(curFigure);
                        }
                    }
                }
            }
        }
    }

    return true; // The player is in checkmate
}


void Board::updateKingPosition(const Figure* possibleKing)
{
    if (possibleKing->getType() == BLACK_KING)  // if the given figure is a king - set new king position in according color
    {
        _blackKing = possibleKing->getCoordinates();
    }
    else if (possibleKing->getType() == WHITE_KING)
    {
        _whiteKing = possibleKing->getCoordinates();
    }

}