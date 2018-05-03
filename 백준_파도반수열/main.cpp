#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

long long table[] = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9 };
long long answer[100];

long long get(int n)
{
	if (answer[n] == 0)
	{
		answer[n] = get(n - 1) + get(n - 5);
	}

	return answer[n];
}

int main()
{
	int t;	// 100
	cin >> t;

	for (int a = 0; a < t; a++)
	{
		// 1. input
		int n;		// <10000
		cin >> n;

		fill_n(answer, 100, 0);
		for (int i = 0; i < 10; i++)
			answer[i] = table[i];

		// TODO solve
		long long ans;

		if (n <= 10)
			ans = table[n];
		else
		{
			ans = get(n);
		}

		cout << ans << endl;
	}

	return 0;
}