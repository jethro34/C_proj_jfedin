
#include <stdio.h>
#include <ctype.h>

char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char whosMoving = 'O';

void drawBoard()
{
	printf("\x1b[2J\x1b[H");	// clear screen via ANSI escape codes
	printf("\n\n\t\t\tTic Tac Toe\n\n\n");
	printf("\t\t Player X    -    Player O\n\n\n");
	
	printf("\t\t\t %c | %c | %c \n", board[0], board[1], board[2]);
	printf("\t\t\t---|---|---\n");
	printf("\t\t\t %c | %c | %c \n", board[3], board[4], board[5]);
	printf("\t\t\t---|---|---\n");
	printf("\t\t\t %c | %c | %c \n", board[6], board[7], board[8]);
	
	printf("\n\n");
	return;
}

void switchPlayer()
{
	whosMoving = whosMoving == 'X' ? 'O' : 'X';
	return;
}

int getNextMove()
{
	char cellToMark;
	int cellIndex;
	do {
		printf("\tPlayer %c, enter the cell number of your next move: ", whosMoving);
		scanf(" %c", &cellToMark);		// passing the ch to cellToMark's address
		printf("\n\n");
		
		cellIndex = cellToMark - '0' - 1;
		// check for non-numerical input
		if (!isdigit(cellToMark) || cellIndex < 0 || cellIndex > 8) {
			printf("\tIllegal value, Player %c. Please type in a numerical key between 1 and 9.\n", whosMoving);
			cellIndex = -1;
		// check for invalid numerical input
		} else if (board[cellIndex] == 'X' || board[cellIndex] == 'O') {
			printf("\tIllegal move, Player %c. Please choose a cell which hasn't been marked.\n", whosMoving);
			cellIndex = -1;
		}
	} while (cellIndex == -1);
	
	return cellIndex;
}

void markBoard(int cellIndex)
{
	board[cellIndex] = whosMoving;		// update board
	return;
}

int checkForWin()
{
	if (
	(board[0] == board[1] && board[0] == board[2]) || 
	(board[3] == board[4] && board[3] == board[5]) || 
	(board[6] == board[7] && board[6] == board[8]) ||
	
	(board[0] == board[3] && board[0] == board[6]) || 
	(board[1] == board[4] && board[1] == board[7]) || 
	(board[2] == board[5] && board[2] == board[8]) ||
	
	(board[0] == board[4] && board[0] == board[8]) || 
	(board[2] == board[4] && board[2] == board[6])) {
		return 1;		// win
	} else {
		for (int cell = 0; cell <= 8; cell++) {
			if (board[cell] != 'X' && board[cell] != 'O') {
				return 0;		// keep playing
			}
		}
		return 2;		// draw
	}
}

void render(int result)
{
	if (result == 1) {
		printf("\tPlayer %c is the winner! :)\n\n", whosMoving);
	} else {
		printf("\tThere isn't a winner... :(\n\n");
	}
	return;
}

int main(void)
{
	int result;
	int validMove;
	
	drawBoard();
	
	do {
		switchPlayer();
		validMove = getNextMove();
		markBoard(validMove);
		drawBoard();
		result = checkForWin();
	} while (result == 0);

	render(result);
	
	return 0;
}
