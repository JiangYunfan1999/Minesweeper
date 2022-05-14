# Minesweeper
simple minesweeper game

## 扫雷小游戏
扫雷(Minesweeper)是iThinkdiff开发的一款经典的扫雷益智游戏

## C语言实现
- 数组的应用
  - char mine[ROWS][COLS] 布置好的雷
  - char show[ROWS][COLS] 排查出的雷
- 设置随机种子
  - srand((unsigned int)time(NULL))
- 自定义函数
  - InitBoard 初始化棋盘
  - DisplayBoard 展示棋盘
  - SetMine 设置雷
  - FindMine 扫雷

## 文件目录
- 头文件
  - game.h 包含全局常量的定义、函数的声明
- 源文件 
  - game.c 游戏实现函数的定义
  - test.c 测试整体程序
