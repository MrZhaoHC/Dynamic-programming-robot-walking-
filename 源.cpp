#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define MAXSIZE 100

//��̬�滮|||��������·


//�ݹ��㷨
//int fun(int cur, int rest, int aim, int N)
//{//�����˴�curλ�ó���������rest����Ŀ����aim��һ����N��λ��
//	if (rest == 0)  // �����˲���Ҫ���� 
//	{
//		if (cur == aim)
//			return 1;
//		else
//			return 0;
//	}
//	//������Ϊ0
//	if (cur == 1)
//	{//����ͷλ��
//		return fun(cur + 1, rest - 1, aim,N);
//	}
//	else if (cur == N)
//	{//����βλ��
//		return fun(cur -1, rest - 1, aim, N);
//	}
//	//�����м�λ��
//	return fun(cur-1, rest-1, aim, N) + fun(cur+1, rest-1, aim, N);
//}
//
//int main()
//{
//	cout << fun(2, 4, 4, 4);
//}


//------------------------------------------------------------------------------ -




//��̬�滮�㷨
//res�ķ�Χ��1--N
//cur�ķ�Χ��1--N

//int fun(int cur, int  rest, int  aim, int N, int** dp)
//{
//	if (dp[cur][rest] != -1)
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
//	dp[cur][rest] = num;
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
//	dp = (int**)malloc((N)* sizeof(int));
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

//��̬�滮||���հ汾||���
//
int fun(int cur, int rest, int aim, int N, int** dp)
{
	for (int i = 1; i <= rest; i++)//��
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
	dp[aim][0] = 1; //��rest=0����aim=curʱ�򷵻�1
	cout<<fun(cur, rest, aim, N,dp);
}


//  
//  0 1 2 3 4 rest(�ƶ�����)
//1 0 0 0 1 0
//2 0 0 1 0 (3)
//3 0 1 0 2 0
//4 1 0 1 0 2
// 
//N