#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> card(100001);
	vector<pair<int, int>> pairs;

	for (int i = 0; i < M; i++)
	{
		int tempX, tempY;
		cin >> tempX >> tempY;
		pairs.push_back(pair<int, int>(tempX, tempY));
	}

	for (int i = 0; i < 100001; i++)
		card[i] = i;

	for (auto object : pairs)
	{
		card[object.first]++;
		card[object.second]--;
	}

	auto test = vector<int>(card);
	std::sort(test.begin(), test.end(), std::less<int>());
	auto pos = unique(test.begin(), test.end());
	if (distance(pos, test.end()) != 0)
	{
		cout << -1 << endl;
		return 0;
	}

	for (int i=1; i<=N; i++)
	{
		cout << card[i] << " ";
	}

	cout << endl;

	return 0;
}