#include <vector>
#include <iostream>

using namespace std;

long getWays(long n, vector <long> c)
{
	long* T = new long[n+1];
	fill_n(T, n + 1, 0);

	T[0] = 1;

	for (int i = 0; i < c.size(); i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if(j-c[i] >= 0)
				T[j] += T[j - c[i]];
		}
	}

	return T[n];
}

int main() 
{
	int n;
	int m;
	cin >> n >> m;
	vector<long> c(m);

	for (int c_i = 0; c_i < m; c_i++)
	{
		cin >> c[c_i];
	}
	// Print the number of ways of making change for 'n' units using coins having the values given by 'c'

	unsigned long ways = getWays(n, c);
	cout << ways << endl;
	return 0;
}