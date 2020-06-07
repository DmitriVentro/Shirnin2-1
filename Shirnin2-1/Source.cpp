#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	int const n = 4, m = 3;
	int A[n][m], B[m], C[m][n], D[m], CT[n][m];

	ifstream fine;
	fine.open("MasA.txt");

	if (!fine)
	{
		cout << "Файл не открыт\n\n";
		return -1;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			fine >> A[i][j];
	fine.close();

	cout << endl << endl << "Massive A:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (int j = 0; j < m; j++)
			cout << A[i][j] << " ";
	}


	fine.open("VekB.txt");

	if (!fine)
	{
		cout << "Файл не открыт\n\n";
		return -1;
	}

	for (int i = 0; i < m; i++)
		fine >> B[i];
	fine.close();


	fine.open("MasC.txt");

	if (!fine)
	{
		cout << "Файл не открыт\n\n";
		return -1;
	}

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fine >> C[i][j];
	fine.close();

	cout << endl << endl << "Massive C:" << endl;
	for (int i = 0; i < m; i++)
	{
		cout << endl;
		for (int j = 0; j < n; j++)
			cout << C[i][j] << " ";
	}


	fine.open("VekD.txt");

	if (!fine)
	{
		cout << "Файл не открыт\n\n";
		return -1;
	}

	for (int i = 0; i < m; i++)
		fine >> D[i];
	fine.close();



	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			CT[i][j] = A[j][i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			CT[i][j] *= 5;

	cout << endl << endl << "Massive C (transposed):" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (int j = 0; j < m; j++)
		{
			cout << CT[i][j] << " ";

		}
	}

	int F[n];

	for (int i = 0; i < n; i++)
		F[i] = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			F[i] += B[j] * A[i][j];

	int G[n];

	for (int i = 0; i < n; i++)
		G[i] = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			G[i] += D[j] * CT[i][j];

	for (int i = 0; i < n; i++)
		F[i] += G[i];

	cout << endl << endl << "Результат : ";
	for (int i = 0; i < n; i++)
		cout << F[i] << " ";

	return 0;
}
