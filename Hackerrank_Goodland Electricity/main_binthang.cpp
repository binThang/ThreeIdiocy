#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int switchOn(int i, int k, vector<int> &arr)
{
	if (i == -1)
		return switchOn(i + k, k, arr);
	
	if (i >= arr.size())
		return 0;

	if (arr[i] == 2)
		return -1;
	
	if (arr[i] == 1)
	{	
		arr[i] = 2;
		int next = i + 2 * (k - 1) + 1;

		if ((next >= arr.size() - 1) && !(i + k - 1 >= arr.size() - 1))
			next = arr.size() - 1;

		return switchOn(next, k, arr);
	}
	else
	{
		if (i == 0)
			return -1;

		return switchOn(i - 1, k, arr);
	}
}

int pylons(int k, vector <int>arr) 
{
	int cnt = 0;

	int var = switchOn(-1, k, arr);

	if (var == -1)
		return -1;

	for (int test : arr)
	{
		if (test == 2)
			cnt++;
	}
	
	return cnt;
}

int main() {
	int n;
	int k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int arr_i = 0; arr_i < n; arr_i++) {
		cin >> arr[arr_i];
	}
	int result = pylons(k, arr);
	cout << result << endl;
	return 0;
}