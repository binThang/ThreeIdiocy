#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

//int diffMinimumStep[] = { 0, 1, 2, 1, 2, 1, 2, 3, 2, 3 };	// 1, 3, 5
int diffMinimumStep[] = { 0, 1, 1, 2, 2, 1, 2, 2, 3, 3 };	// 1, 2, 5

int main()
{
	int t;	// 100
	cin >> t;

	int people[10000];
	for (int a = 0; a < t; a++)
	{
		int step = 0;

		// 1. input
		int n;		// <10000
		cin >> n;

		for (int b = 0; b < n; b++)
			cin >> people[b];

		// 2. get diff
		int minValue = people[0];
		for (int b = 1; b < n; b++)
			minValue = min(minValue, people[b]);
		for (int b = 0; b < n; b++)
			people[b] -= minValue;

		// TODO solve
		for (int b = 0; b < n; b++)
		{
			step += (people[b] / 10) * 2;
			people[b] = people[b] % 10;
		}

		for (int b = 0; b < n; b++)
		{
			step += diffMinimumStep[ people[b] ];
		}

		cout << step << endl;
	}

	return 0;
}