#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumUnfairness(int k, vector<int> arr)
{
	int min = INT_MAX;

	sort(arr.begin(), arr.end());

	for (int i=0; i<arr.size() - k; i++)
	{
		int unfairness = arr[i+k-1] - arr[i];
		if (unfairness < min)
			min = unfairness;
	}

	return min;
}

int main()
{
	int n;
	cin >> n;
	int k;
	cin >> k;
	vector<int> arr(n);
	for (int arr_i = 0; arr_i < n; arr_i++)
	{
		cin >> arr[arr_i];
	}
	int result = minimumUnfairness(k, arr);
	cout << result << endl;
	return 0;
}