//Doolittle三角分解法
#define N 2
#include <stdio.h>
#include <stdlib.h>
#include "myhpp.hpp"
int bigger(int a, int b);
int smaller(int a, int b);	
double** create(double t);
double** lu(double** a, int r, int s);
double* solve(double** a, double* b, int r, int s);
/*

*/
int main()
{
	puts("Doolittle三角分解法");
	puts("equation1");
	int i;
	double t;
	double** a;
	double* b;
	double* x;
	b = (double*)malloc(sizeof(double) * N);
	
	t = 0.1;
	a = create(t);
	
    b[0]=1,b[1]=2;
	lu(a,3,3);
	x = solve(a, b, 3, 3);

	for (i = 0; i < N; i++)
	printf("x[%d] = %-10.8f\n",i, x[i]);

	free(b);
	free(x);
	for (i = 0; i < N; i++)
		free(a[i]);
	free(a);
	puts("");
}


int bigger(int a, int b)
{
	if (a >= b)
		return a;
	else return b;
}

int smaller(int a, int b)
{
	if (a >= b)
		return b;
	else return a;
}

double** create(double t)
{
	int i, j;
	double** a;
	a = (double**)malloc(sizeof(double*) * N);              
	for (i = 0; i < N; i++)                                 
		a[i] = (double*)malloc(sizeof(double) * N);
	a[0][0]=0.0001,a[0][1]=1,a[1][0]=1,a[1][1]=1;
	return a;
}



double** lu(double** a, int r, int s)
{
	int k, i, j, t;
	int row, col;
	double temp = 0;
	for (k = 0; k < N; k++)
	{
		col = smaller(k + s, N - 1);
		row = smaller(k + r, N - 1);
		for (j = k; j <= col; j++)
		{
			temp = 0;
			if (bigger(j - s, k - r) > 0)
			{
				for (t = bigger(j - s, k - r); t < k; t++)
				{
					temp = temp + a[k][t] * a[t][j];
				}
			}
			else
			{
				for (t = 0; t < k; t++)
				{
					temp = temp + a[k][t] * a[t][j];
				}
			}
			a[k][j] = a[k][j] - temp;
		}
		for (i = k + 1; i <= row; i++)
		{
			temp = 0;
			if (bigger(k - s, i - r) > 0)
			{
				for (t = bigger(k - s, i - r); t < k; t++)
				{
					temp = temp + a[i][t] * a[t][k];
				}
			}
			else
			{
				for (t = 0; t < k; t++)
				{
					temp = temp + a[i][t] * a[t][k];
				}
			}
			a[i][k] = (a[i][k] - temp) / a[k][k];
		}
	}
	/*for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%f\t", a[i][j]);
		}
		printf("\n");
	}*/
	return a;
}

double* solve(double** a, double* b, int r, int s)
{
	double* x, * y;
	double temp;
	int k, t;
	x = (double*)malloc(sizeof(double) * N);         //attention
	y = (double*)malloc(sizeof(double) * N);
	for (k = 0; k < N; k++)
	{
		temp = 0;
		for (t = bigger(0, k - r); t < k; t++)
		{
			temp = temp + a[k][t] * y[t];
		}
		y[k] = b[k] - temp;
	}
	//for (k = 0; k < N; k++)
	//	printf("%f\n", y[k]);
	for (k = N - 1; k >= 0; k--)
	{
		temp = 0;
		for (t = k + 1; t <= smaller(k + s, N - 1); t++)
		{
			temp = temp + a[k][t] * x[t];
		}
		x[k] = (y[k] - temp) / a[k][k];
	}
	free(y);
	return x;
}