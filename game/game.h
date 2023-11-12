#pragma once
#define ROW 5
#define COL 5

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//��ʼ������
void initial_board(char board[ROW][COL], int row, int col);
//��ӡ����
void display_board(char board[ROW][COL], int row, int col);
//�������
void PlayerMove(char board[ROW][COL], int row, int col);
//��������
void ComputerMove(char board[ROW][COL], int row, int col);
/*
�ж���Ӯ
���Ӯ ����*
����Ӯ ����#
ƽ�� ����Q
���� ����C
*/
char judge_win(char board[ROW][COL], int row, int col);
//�ж�ƽ��
int judge_full(char board[ROW][COL], int row, int col);
