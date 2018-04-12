#include <iostream>

using namespace std;

int main()
{
	int A, B, C, N;
	cin >> A >> B >> C >> N;

	int *T = new int[N+1];
	fill_n(T, N + 1, 0);
	T[0] = 1;

	for (int i = 1; i <= N; i++)
	{
		if (i - A >= 0)
		{
			if (T[i - A] == 1)
			{
				T[i] = 1;
				continue;
			}
		}

		if (i - B >= 0)
		{
			if (T[i - B] == 1)
			{
				T[i] = 1;
				continue;
			}
		}

		if (i - C >= 0)
		{
			if (T[i - C] == 1)
			{
				T[i] = 1;
				continue;
			}
		}
	}

	cout << T[N] << endl;

	return 0;
}