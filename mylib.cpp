#include "mylib.h"
#include <iostream>
#include <ctime>
using namespace std;

void get_lists(float** A, float** B, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			A[i][j] = rand() % 1000 / (float)100 - 5;
			B[i][j] = rand() % 1000 / (float)100 - 5;
		}
}

void print_lists(float** A, float** B, int n)
{
	float sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%10.2f", A[i][j]);
			sum += abs(A[i][j]);
		}
		printf("		sum = %5.2f", sum);
		sum = 0;
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%10.2f", B[i][j]);
			sum += abs(B[i][j]);
		}
		printf("		sum = %5.2f", sum);
		sum = 0;
		cout << endl;
	}
}

float M_norm(float** arr, int n)
{
	float res = 0, max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			res += abs(arr[i][j]);
		}
		if (res > max) max = res;
		res = 0;
	}
	return max;
}

void solve(int n)
{
	srand((unsigned int)time(0));
	float** A = new float* [n];
	float** B = new float* [n];
	for (int i = 0; i < n; i++)
	{
		A[i] = new float[n];
		B[i] = new float[n];
	}
	get_lists(A, B, n);
	print_lists(A, B, n);

	printf("result: %.3f\n", (M_norm(A, n) + M_norm(B, n)) / 2);

	for (int i = 0; i < n; i++)
	{
		delete[] A[i];
		delete[] B[i];
	}
	delete[] A;
	delete[] B;
}