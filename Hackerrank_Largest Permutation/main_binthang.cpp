#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void swap(int n, int m, vector<int> &arr)
{
	int temp = arr[n];
	arr[n] = arr[m];
	arr[m] = temp;
}

vector <int> largestPermutation(int k, vector<int> arr) 
{
	int n = arr.size();

	vector<int> idxvec = vector<int>(n);

	for (size_t i = 0; i < n; i++)
	{
		idxvec[arr[i] - 1] = i;
	}

	for (size_t i = 0; i < k; i++)
	{
		if (i == n)
			break;

		if (arr[i] == n-i)
		{
			k++;
			continue;
		}

		int swap1 = arr[i];
		swap(idxvec[n - i - 1], i, arr);
		swap(n - i - 1, swap1-1, idxvec);
	}

	return arr;
}

int main() {
	int n;
	int k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int arr_i = 0; arr_i < n; arr_i++) {
		cin >> arr[arr_i];
	}
	vector <int> result = largestPermutation(k, arr);
	for (size_t i = 0; i < result.size(); i++) {
		cout << result[i] << (i != result.size() - 1 ? " " : "");
	}
	cout << endl;

	return 0;
}