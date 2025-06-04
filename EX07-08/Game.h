#include "Point.h"
#include "Board.h"
#define INITIAL_GAME_STR "rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR"

// colors
#define BLACK 1
#define WHITE 0

// Indexes
#define FIRST_X_INDEX 0
#define FIRST_Y_INDEX 1
#define SECOND_X_INDEX 2
#define SECOND_Y_INDEX 3
#define MSG_CODE_INDEX 0

// Chars
#define CHAR_A 'a'
#define CHAR_1 '1'
#define CHAR_0 '0'
#define CHAR_8 '8'

// Numbers
#define ZERO	0
#define ONE		1
#define TWO		2
#define FIVE	5
#define SEVEN	7
#define EIGHT	8

// Figures
#define WHITE_KING		'K'
#define WHITE_ROOK		'R'
#define WHITE_BISHOP	'B'
#define WHITE_KNIGHT	'N'
#define WHITE_QUEEN		'Q'
#define WHITE_PAWN		'P'
#define BLACK_KING		'k'
#define BLACK_ROOK		'r'
#define BLACK_BISHOP	'b'
#define BLACK_KNIGHT	'n'
#define BLACK_QUEEN		'q'
#define BLACK_PAWN		'p'

// Codes
#define CODE0 "0"
#define CODE1 "1"
#define CODE2 "2"
#define CODE3 "3"
#define CODE4 "4"
#define CODE5 "5"
#define CODE6 "6"
#define CODE7 "7"
#define CODE8 "8"

class Game
{
private:
	Board* _board;
	int _curPlayerTurn;
public:
	/// <summary>
	/// C'TOR - initiate fields
	/// </summary>
	Game();
	/// <summary>
	/// D'TOR - clear fields
	/// </summary>
	~Game();

	/// <summary>
	/// method moves figure on the board and returns a message which shows what happened (if the movement was successful or not - what went wrong...)
	/// </summary>
	/// <param name="cooridnates">the coordinates of the src square and dst square</param>
	/// <returns>std::string of a message with a code saying what occured</returns>
	std::string move(const std::string& cooridnates);
	/// <summary>
	/// method initiates game
	/// </summary>
	/// <returns>std::string with the initiate board, beginning player, and null at the end</returns>
	std::string initGame() const;
};