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
	//��ʼ������
	initial_board(board,ROW,COL);
	//��ӡ����
	display_board(board,ROW,COL);
	//����
	while (1)
	{
		PlayerMove(board, ROW, COL);
		//�ж���Ӯ
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
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
	display_board(board, ROW, COL);
}
int main(void)
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();//��ʼ����
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
}