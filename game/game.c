#include "game.h"
void initial_board(char board[ROW][COL], int row, int col)
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
void display_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		//��ӡ����
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//��ӡ�ָ���
		if (i < row - 1)
		{
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
	int x = 0;
	int y = 0;
	printf("�������\n");
	while (1)
	{
		printf("����������:>");
		scanf("%d%d", &x, &y);
		//����Ϸ��Ե��ж�
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("���걻ռ�ã�����������λ��\n");
			}
		}
		else
		{
			printf("����Ƿ�,����������\n");
		}
	}

}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("��������\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
//���˷���1��û��������0
int judge_full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}

	return 1;
}

char judge_win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//��
	for (i = 0; i < row; i++)
	{
		int flag1 = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ' || board[i][j] != board[i][0])
			{
				flag1 = 1;
				break;
			}
		}
		if (flag1 == 0)
		{
			return board[i][0];
		}
	}
	//��
	for (j = 0; j < col; j++)
	{
		int flag2 = 0;
		for (i = 0; i < row; i++)
		{
			if (board[i][j] == ' ' || board[i][j] != board[0][j])
			{
				flag2 = 1;
				break;
			}
		}
		if (flag2 == 0)
		{
			return board[0][j];
		}
	}
	//���Խ���
	int flag3 = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][i] == ' ' || board[i][i] != board[0][0])
		{
			flag3 = 1;
			break;
		}
	}
	if (flag3 == 0)
	{
		return board[0][0];
	}
	//�ζԽ���
	int flag4 = 0;
	for(i=0,j=col-1;i<row;i++,j--)
	{
			if (board[i][j] == ' ' || board[i][j] != board[0][col - 1])
			{
				flag4 = 1;
				break;
			}
	}
	if (flag4 == 0)
	{
		return board[0][col - 1];
	}
	//ƽ��
	if (judge_full(board, row, col))
	{
		return 'Q';
	}
	//����
	return 'C';
}



