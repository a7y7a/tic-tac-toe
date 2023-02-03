#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"



void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = '*';
			break;
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x = rand() % row, y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

char IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
		for (j = 0; j < col - 1; j++)
		{
			if (board[i][j] != board[i][j + 1] || board[i][j] == ' ')
				break;
			if (j == col - 2)
				return board[i][j];
		}
	for (j = 0; j < col; j++)
		for (i = 0; i < row - 1; i++)
		{
			if (board[i][j] != board[i + 1][j] || board[i][j] == ' ')
				break;
			if (i == row - 2)
				return board[i][j];
		}
	for (i = 0, j = 0; i < row - 1; i++, j++)
	{
		if (board[i][j] != board[i + 1][j + 1] || board[i][j] == ' ')
			break;
		if (i == row - 2)
			return board[i][j];
	}
	for (i = 0, j = col - 1; i < row - 1; i++, j--)
	{
		if (board[i][j] != board[i + 1][j - 1] || board[i][j] == ' ')
			break;
		if (i == row - 2)
			return board[i][j];
	}
	char ret = IsFull(board, row, col);
	if (ret == 1)
		return 'Q';
	return 'C';
}