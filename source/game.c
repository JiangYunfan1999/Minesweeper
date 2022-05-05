#include "game.h"

//函数的定义
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for(i=0; i<rows; i++)
		for(j=0; j<cols; j++)
			board[i][j] = set;
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//打印列编号
	for(i=0; i<=col; i++)
		printf("%d ", i);
	for(i=1; i<=row; i++)
	{
		//打印行编号
		printf("%d ", i);
		//打印棋盘内容
		for(j=1; j<=col; j++)
			printf("%c ",board[i][j]);
	}
}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT; //雷的个数
	while(count) // 当剩余雷的个数不为0时
	{
		int x = rand()%row + 1; //随机生成1-9
		int y = rand()%col + 1; //随机生成1-9
		if(mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x-1][y-1]+mine[x-1][y]+mine[x-1][y+1]
		+mine[x][y-1]+mine[x][y+1]
		+mine[x+1][y-1]+mine[x+1][y]+mine[x+1][y+1]
		- 8*'0' //转换成整型0/整型1...
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0; //已排雷的个数
	while(win<row*col-EASY_COUNT) //当雷没有被排完时
	{
		printf("请输入排雷的坐标：");
		scanf("%d%d",&x, &y);
		//若输入坐标合法
		if(x>=1 && x<=row && y>=1 && y<=col)
		{
			//若踩雷，游戏结束，显示雷的位置
			if(mine[x][y] == '1')
			{
				printf("此处是雷，游戏结束");
				DisplayBoard(mine, row, col);
				break;
			}
			//若不是雷，计算该点周围有几个雷，显示排查出的雷的信息
			else
			{
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0'; //转换为字符0/字符1...
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else //若输入坐标不合法
		{
			printf("输入坐标不合法，请重新输入");
		}
	}
	if(win==row*col-EASY_COUNT)
	{
		printf("恭喜你，游戏获胜");
	}
}
