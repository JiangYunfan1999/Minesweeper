#include "game.h"

//打印菜单
void menu()
{
	printf("******** 扫雷游戏 *********/n");
	printf("***** 1.play   0.exit *****/n");
	printf("***************************/n");
}

//游戏实现
void game()
{
	//用两个数组存储关于雷的信息
	// 9*9 --> 11*11
	char mine[ROWS][COLS] = {0}; //布置好的雷的位置
	char show[ROWS][COLS] = {0}; //排查出的雷的信息
	//初始化
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//进行扫雷
	FindMine(mine, show, ROW, COL);
}

//测试程序
void test()
{
	int input = 0;
	//设置随机种子
	srand((unsigned int)time(NULL));
	do
	{
		//打印菜单
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				printf("开始扫雷游戏");
				//游戏实现
				game();
				break;
			case 0:
				printf("退出游戏");
				break;
			default:
				printf("输入错误，请重新选择");
				break;
		}
	}while(input); //仅当input为0时才跳出
}

//主程序入口
int main()
{
	// 测试程序
	test();
	return 0;
}
