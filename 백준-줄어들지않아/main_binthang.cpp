#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<long long>> nonDecreasingDigits(66, vector<long long>(10, 0));
//long long nonDecreasingDigits[66][10];

void makeNonDecreasingDigits()
{
	for (int i=0; i<=9; i++)
		nonDecreasingDigits[1][i] = 1; // 1자리 수
	for (int i=1; i<=65; i++)
		nonDecreasingDigits[i][9] = 1; // 9로 시작하는 ndd

	for (int i=2; i<=65; i++)
	{
		for (int j=8; j>=0; j--)
		{
			nonDecreasingDigits[i][j] = nonDecreasingDigits[i-1][j] + nonDecreasingDigits[i][j+1];
		}
	}
}


long long NonDecreasing(int n)
{
	return nonDecreasingDigits[n+1][0];
}

int main(int argc, char* argv[])
{
	int t;
	cin >> t;

	makeNonDecreasingDigits();
	for (int i=0; i<t; i++)
	{
		int n;
		cin >> n;
		cout << NonDecreasing(n) << endl;
	}

	return 0;
}