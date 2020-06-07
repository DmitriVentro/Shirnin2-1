#include <iostream>
#include <ctime>
#include "stdlib.h"

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");

	int a, b, i, j, length;
	int maxarr, minarr, maxi, maxj, mini, minj, temp = 0;

	cout << "¬ведите размер матрицы" << endl;
	cin >> length;

	int** arr2 = new int* [length];
	for (i = 0; i < length; i++)
		arr2[i] = new int[length];

	cout << "¬ведите a и b через пробел" << endl;
	cin >> a >> b;

	srand(time(NULL));

	for (i = 0; i < length; i++)
	{
		cout << endl;
		for (j = 0; j < length; j++)
		{
			arr2[i][j] = rand() % (b - a + 1) + a;
			cout << arr2[i][j] << " ";
		}
	}

	cout << endl;
	maxarr = a;
	minarr = b;
	maxi = 0;
	maxj = 0;
	mini = 0;
	minj = length - 1;

	temp = 0;

	for (i = 0; i < length; i++)
	{
		for (j = 0; j <= temp; j++)
		{
			if ((arr2[i][j] < 0) && (maxarr < arr2[i][j]))
			{
				maxarr = arr2[i][j];
				maxi = i;
				maxj = j;
			}
		}

		if (i < length / 2)
			temp++;
		else
			temp--;
	}

	temp = 1;

	for (i = 0; i < length; i++)
	{
		for (j = length - temp; j < length; j++)
		{
			if ((arr2[i][j] > 0) && (minarr > arr2[i][j]))
			{
				minarr = arr2[i][j];
				mini = i;
				minj = j;
			}
		}
		cout << "OK" << endl;

		if (i < length / 2)
			temp++;
		else
			temp--;
	}



	temp = arr2[mini][minj];
	arr2[mini][minj] = arr2[maxi][maxj];
	arr2[maxi][maxj] = temp;

	cout << "»зменЄнна€ матрица" << endl;
	cout << "»дексы max i и j : " << maxi << " , " << maxj << endl;
	cout << "»дексы min i и j : " << mini << " , " << minj << endl;

	for (i = 0; i < length; i++)
	{
		cout << endl;
		for (j = 0; j < length; j++)
		{
			cout << arr2[i][j] << " ";
		}
	}

	return 0;
}
