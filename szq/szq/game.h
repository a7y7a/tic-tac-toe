#pragma once

//头文件的包含
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//符号的定义
#define ROW 3
#define COL 3

//函数的声明
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
char IsFull(char board[ROW][COL], int row, int col);//sa
char IsWin(char board[ROW][COL], int row, int col);