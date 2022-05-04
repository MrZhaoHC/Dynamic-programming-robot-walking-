#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define MAXSIZE 100

//动态规划|||机器人走路


//递归算法
//int fun(int cur, int rest, int aim, int N)
//{//机器人从cur位置出法，经过rest步，目标是aim，一共有N个位置
// 	if (cur<1||cur>N||rest<1||aim<1||aim>N||N<2) //过滤条件
//      	return -1;
//
//	if (rest == 0)  // 走完了不需要走了 
//	{
//		if (cur == aim)
//			return 1;
//		else
//			return 0;
//	}
//	//步数不为0
//	if (cur == 1)
//	{//处于头位置
//		return fun(cur + 1, rest - 1, aim,N);
//	}
//	else if (cur == N)
//	{//处于尾位置
//		return fun(cur -1, rest - 1, aim, N);
//	}
//	//处于中间位置
//	return fun(cur-1, rest-1, aim, N) + fun(cur+1, rest-1, aim, N);
//}
//
//int main()
//{
//	cout << fun(2, 4, 4, 4);
//}


//------------------------------------------------------------------------------ -




//动态规划算法
//res的范围是1--N
//cur的范围是1--N

//int fun(int cur, int  rest, int  aim, int N, int** dp)
//{
// 	if (cur<1||cur>N||rest<1||aim<1||aim>N||N<2) //过滤条件
//      	return -1;
//	if (dp[cur][rest] != -1)      //如果不为-1说明表中已经有了数据
//	{
//		return dp[cur][rest];
//	}
//	int num=0;
//	if (rest == 0)
//	{
//		num = cur == aim ? 1 : 0;
//	}
//	else if (cur == 1)
//	{
//		num= fun(cur+1, rest-1, aim, N, dp);
//	}
//	else if (cur == N)
//	{
//		num= fun(cur-1, rest-1, aim, N, dp);
//	}
//	else
//	{
//		num= fun(cur-1, rest-1, aim, N, dp)+fun(cur+1, rest-1, aim, N, dp);
//	}
//	dp[cur][rest] = num;       //将数据填入表中相应位置
//	return num;
//}
//
//int main()
//{
//	int N = 4;
//	int cur = 2;
//	int rest = 4;
//	int aim = 4;
//	int** dp;
//	dp = (int**)malloc((N)* sizeof(int*));         //建立一个N*rest的数组存放数据
//	for (int i = 0; i <= N ; i++)
//	{
//		dp[i] = (int*)malloc((rest) * sizeof(int));
//	}
//	for (int i = 0; i <= N ; i++)
//	{
//		for (int j = 0; j <= rest ; j++)
//		{
//			dp[i][j] = -1;
//		}
//	}
//	cout<<fun(cur, rest, aim, N,dp);
//
//}

//-------------------------------------------------------------------------------

//动态规划||最终版本||填表
//
int fun(int cur, int rest, int aim, int N, int** dp)
{
//	 	if (cur<1||cur>N||rest<1||aim<1||aim>N||N<2) //过滤条件
//      		return -1;
	for (int i = 1; i <= rest; i++)//列
	{
		dp[1][i] = dp[2][i - 1];
		for (int j = 2; j < N; j++)
		{
			dp[j][i] = dp[j - 1][i - 1] + dp[j + 1][i - 1];
		}
		dp[N][i] = dp[N - 1][i - 1];
	}
	return dp[cur][rest];
}

int main()
{
	int cur = 2;
	int rest = 4;
	int aim = 4;
	int N = 4;
	int** dp = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i <= N; i++)
	{
		dp[i] = (int*)malloc(rest * sizeof(int));
	}
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= rest; j++)
		{
			dp[i][j] = 0;
		}
	}
	dp[aim][0] = 1; //当rest=0，且aim=cur时候返回1
	cout<<fun(cur, rest, aim, N,dp);
}


//  
//  0 1 2 3 4 rest(移动步数)
//1 0 0 0 1 0
//2 0 0 1 0 (3)
//3 0 1 0 2 0
//4 1 0 1 0 2
// 
//N
