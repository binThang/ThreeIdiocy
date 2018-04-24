#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
	//auto cin = ifstream("B3");	// for file input testing

	int desk[100000];
	int n, k;

	// input
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> desk[i];

	// check k
	if (n <= k-1)
	{
		for (int i = n; i > 0; i--)
		{
			cout << i;
			cout << ' ';
		}
	}
	else
	{
		// swap
		int skip = 0;
		for (int i = 0; (i-skip) < k; i++)
		{
			if (desk[i] == n-i )	// if already sorted for index i
			{
				skip++;
				continue;
			}

			// swap first number and biggest number
			int biggestIndex = i + 1;
			for (biggestIndex = i + 1; biggestIndex < n; biggestIndex++)
			{
				if (desk[biggestIndex] == n - i)
					break;
			}

			swap(desk[i], desk[biggestIndex]);
		}

		for (int i = 0; i < n; i++)
		{
			cout << desk[i];
			cout << ' ';
		}
	}


    return 0;
}