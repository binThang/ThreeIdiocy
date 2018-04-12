#include <iostream>
#include <math.h>

using namespace std;

int ary[1000][1000] = { 0 };
int maximum[1000][1000] = { 0 };

int main()
{

	// read input
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> ary[i][j];
		}
	}

	//
	maximum[0][0] = ary[0][0];

	// traverse ary
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int upperValue = (0 <= (i - 1) && (i - 1) < n) ? maximum[i - 1][j] : 0;
			int leftValue = (0 <= (j - 1) && (j - 1) < m) ? maximum[i][j - 1] : 0;
			int leftupperValue = ((0 <= (i - 1) && (i - 1) < n) && (0 <= (j - 1) && (j - 1) < m)) ? maximum[i - 1][j - 1] : 0;

			maximum[i][j] = fmax(upperValue, fmax(leftValue, leftupperValue)) + ary[i][j];
		}
	}

	// print
	cout << maximum[n-1][m-1];

	return 0;
}