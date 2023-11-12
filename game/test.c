#include "game.h"
void menu()
{
	printf("********************************\n");
	printf("******** 1. play 0. exit********\n");
	printf("********************************\n");
}
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	initial_board(board,ROW,COL);
	//打印棋盘
	display_board(board,ROW,COL);
	//下棋
	while (1)
	{
		PlayerMove(board, ROW, COL);
		//判断输赢
		ret = judge_win(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		display_board(board, ROW, COL);
		ComputerMove(board,ROW,COL);
		ret = judge_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		display_board(board, ROW, COL);
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
	display_board(board, ROW, COL);
}
int main(void)
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();//开始界面
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
}