#pragma once
#define ROW 5
#define COL 5

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//初始化棋盘
void initial_board(char board[ROW][COL], int row, int col);
//打印棋盘
void display_board(char board[ROW][COL], int row, int col);
//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);
//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);
/*
判断输赢
玩家赢 返回*
电脑赢 返回#
平局 返回Q
继续 返回C
*/
char judge_win(char board[ROW][COL], int row, int col);
//判断平局
int judge_full(char board[ROW][COL], int row, int col);
