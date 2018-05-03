#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	vector<int> M(21, 0);
	vector<int> p(15, 0);
	vector<int> t(15, 0);

	int n;

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> t[i] >> p[i];

	for (int i=1; i<=n; i++)
	{
		for (int j=i+t[i]; j<=n+1; j++)
		{
			M[j] = max(M[j], M[i] + p[i]);
		}
	}

	cout << M[n+1];

	return 0;
}