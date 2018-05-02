#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min(int n1, int n2, int n3)
{
	return min(min(n1, n2), n3);
}

void calculateCounts(vector<int> &counts)
{
	counts[0] = 0;
	counts[1] = 1;
	counts[2] = 1;
	counts[3] = 2;
	counts[4] = 2;
	counts[5] = 1;

	for (int i=6; i<counts.size(); i++)
		counts[i] = min(counts[i-1], counts[i-2], counts[i-5]) + 1;
}

int equal(vector<int> arr)
{
	int countSum = 0;

	vector<int> counts = vector<int>(1000, 0);

	sort(arr.begin(), arr.end());

	calculateCounts(counts);

	for (int i=1; i<arr.size(); i++)
	{
		int disparity = arr[i] - arr[0];
		countSum += counts[disparity];
	}

	return countSum;
}

int main()
{
	int t;
	cin >> t;
	for (int a0 = 0; a0 < t; a0++)
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int arr_i = 0; arr_i < n; arr_i++)
		{
			cin >> arr[arr_i];
		}
		int result = equal(arr);
		cout << result << endl;
	}
	return 0;
}