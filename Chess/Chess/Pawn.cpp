#include "Pawn.h"
#include "None.h"

Pawn::Pawn()
{
    _color = -ONE; // set values
    _coordinates = Point();
    _type = ' ';
    _isFirstMove = false;
}

Pawn::Pawn(const int color, const Point& coordinates, const char type)
{
    _color = color;  // set values
    _coordinates = coordinates;
    _type = type;
    _isFirstMove = true;
}

Pawn::~Pawn()
{
    _color = ZERO;  // clear values
    _coordinates = Point();
    _type = (' ');
    _isFirstMove = false;
}

void Pawn::successfulMove()
{
    _isFirstMove = false;  // if a successful move was made we are not at the first move
}

bool Pawn::canMove(const Point& dst, Figure* board[][SIZE]) const
{
    int deltaX = abs(dst.getX() - getCoordinates().getX());
    int deltaY = dst.getY() - getCoordinates().getY();

    // Check if the pawn is moving forward
    int direction = (getColor() == WHITE) ? ONE : -ONE;

    // Check if the move is a valid single or double step forward
    if ((deltaX == ZERO) && ((deltaY == direction) || (deltaY == TWO * direction && _isFirstMove && board[SIZE - getCoordinates().getY() - direction][getCoordinates().getX() - ONE]->getType() == NONE)))
    {
        // Check if the destination is empty
        if (board[SIZE - dst.getY()][dst.getX() - ONE]->getType() == NONE)
        {
            return true;
        }
    }
    // Check if the pawn is capturing diagonally
    else if (deltaX == ONE && deltaY == direction)
    {
        // Check if the destination has an opponent's piece
        if (board[SIZE - dst.getY()][dst.getX() - ONE]->getColor() != getColor() && board[SIZE - dst.getY()][dst.getX() - ONE]->getType() != NONE)
        {
            return true;
        }
    }

    return false;
}
