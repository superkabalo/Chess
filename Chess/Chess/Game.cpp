#include "Game.h"

Game::Game()
{
	_board = new Board(INITIAL_GAME_STR);  // initiate fields
	_curPlayerTurn = WHITE;
}

Game::~Game()
{
	delete _board;
	_curPlayerTurn = -ONE;
}

std::string Game::move(const std::string& cooridnates)
{
	int x = cooridnates[FIRST_X_INDEX] - CHAR_A + ONE;  // get src point coordinates
	int y = cooridnates[FIRST_Y_INDEX] - CHAR_1 + ONE;
	Point src = Point(x, y);
	x = cooridnates[SECOND_X_INDEX] - CHAR_A + ONE;  // get dst point coordinates
	y = cooridnates[SECOND_Y_INDEX] - CHAR_1 + ONE;
	Point dst = Point(x, y);
	std::string msg = _board->moveFigure(src, dst, _curPlayerTurn);  // try to move figure from src to dst
	if (msg[MSG_CODE_INDEX] == CHAR_0 || msg[MSG_CODE_INDEX] == CHAR_1 || msg[MSG_CODE_INDEX] == CHAR_8)  // if move was successful
	{
		switch (_curPlayerTurn)  // changed current player turn accordingly from BLACK to WHITE or the opposite
		{
		case BLACK:
			_curPlayerTurn = WHITE;
			break;
		case WHITE:
			_curPlayerTurn = BLACK;
			break;
		}
	}
	msg += '\0';
	_board->printBoard();  // print the board after the move was made
	return msg;
}

std::string Game::initGame() const
{
	std::string initStr = INITIAL_GAME_STR;  // initiate game str (white begins)
	initStr += std::to_string(WHITE);  // add first player color
	initStr += '\0';
	return initStr;
}
