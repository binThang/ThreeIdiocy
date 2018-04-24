#include <iostream>
#include <vector>
#include <stack>

using namespace std;

unsigned long long calc(vector<vector<int>> adjList)
{
	int n = adjList.size();
	vector<bool> visited(n);
	vector<int> numOfAstronauts(n);
	stack<int> stack;

	fill_n(visited.begin(), n, false);
	fill_n(numOfAstronauts.begin(), n, 1);

	for (int i = 0; i < n; i++)
	{
		if (visited[i])
		{
			numOfAstronauts[i] = 0;
			continue;
		}

		int tmp = i;
		int cnt = 1;
		stack.push(tmp);
		visited[tmp] = true;

		while (!stack.empty())
		{
			for (int v : adjList[tmp])
			{
				if (!visited[v])
				{
					stack.push(v);
					cnt++;
					visited[v] = true;
					tmp = v;
				}
			}
			tmp = stack.top();
			stack.pop();
		}

		numOfAstronauts[i] = cnt;
	}

	unsigned long long sum = 0;
	unsigned long long result = 0;
	for (int num : numOfAstronauts)
	{
		if (num == 0)
			continue;
		result += sum*num;
		sum += num;
	}

	return result;
}

unsigned long long journeyToMoon(int n, vector < vector<int> > astronaut)
{
	// setup adjacency list
	vector<vector<int>> adjList(n);
	for (vector<int> pair : astronaut)
	{
		adjList[pair[0]].push_back(pair[1]);
		adjList[pair[1]].push_back(pair[0]);
	}

	return calc(adjList);
}

int main() {
	int n;
	int p;
	cin >> n >> p;
	vector< vector<int> > astronaut(p, vector<int>(2));
	for (int astronaut_i = 0; astronaut_i < p; astronaut_i++) {
		for (int astronaut_j = 0; astronaut_j < 2; astronaut_j++) {
			cin >> astronaut[astronaut_i][astronaut_j];
		}
	}
	unsigned long long result = journeyToMoon(n, astronaut);
	cout << result << endl;
	return 0;
}