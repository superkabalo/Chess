#pragma once
#include "Point.h"
#include "Figure.h"
#include <string>
#include <iostream>

#define SIZE 8

class Board
{
public:
	/// <summary>
	/// C'TOR - initiate board
	/// </summary>
	Board();
	/// <summary>
	/// C'TOR - initiate board with given initial game board string
	/// </summary>
	/// <param name="board">char board[64] with initial game board string</param>
	Board(const char board[SIZE * SIZE]);
	/// <summary>
	/// D'TOR - clear board
	/// </summary>
	~Board();

	/// <summary>
	/// method ideally moves figure from point a to point b
	/// </summary>
	/// <param name="a">Point of src point</param>
	/// <param name="b">Point of dst point</param>
	/// <param name="color">color of the current player turn</param>
	/// <returns>std::string with an according code saying what happened</returns>
	std::string moveFigure(const Point& a, const Point& b, int color);
	/// <summary>
	/// method prints board
	/// </summary>
	void printBoard() const;
private:
	/// <summary>
	/// method checks if given coordinates (two points) are valid
	/// </summary>
	/// <param name="a">Point of first point</param>
	/// <param name="b">Point of second point</param>
	/// <returns>int of a code saying generally if the coordinates are valid or not (there are a few different codes)</returns>
	int checkCoordinates(const Point& a, const Point& b) const;
	/// <summary>
	/// method checks if there is check on a player
	/// </summary>
	/// <param name="color">int of the player to check if there is check on</param>
	/// <returns>bool saying if there is check on the given player or not</returns>
	bool isCheck(const int color);
	/// <summary>
	/// method check if there is checkmate on a player
	/// </summary>
	/// <param name="color">int of player color to check if there is checkmate on</param>
	/// <returns>bool saying if there is checmate on the given player</returns>
	bool isCheckmate(const int color);
	/// <summary>
	/// method updates the kings' positions (as needed)
	/// </summary>
	/// <param name="possibleKing">Figure* which could be a king, if it is the position of the according king will be updated</param>
	void updateKingPosition(const Figure* possibleKing);

	Figure* _board[SIZE][SIZE];
	Point _whiteKing;
	Point _blackKing;
};	