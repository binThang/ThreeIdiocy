#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX(a, b) ((a) < (b)) ? (b) : (a)

using namespace std;

typedef struct City
{
	int cases = -1;
	vector<int> neighbor;
	vector<int> child;
	int parent;
	int level;

	bool isLeaf() { return neighbor.size() == 1; }

}City;

City cities[100000];
vector<int> cityByLevel[100000];

int calculate(City& city, int index, int start)
{
	if (city.cases == -1)
	{
		// default, case is 2
		city.cases = 2;

		// calculate
		if (city.isLeaf())
			return city.cases;

		// find non leaf nodes
		vector<int> nonLeafNeighbor;
		for (int i = 0; i < city.neighbor.size(); i++)
		{
			if (cities[city.neighbor[i]].isLeaf() == false && city.neighbor[i] != start)
				nonLeafNeighbor.push_back(city.neighbor[i]);
		}

		// find child nodes
		vector<int> nonLeafChildNode = nonLeafNeighbor;

		// calculate
		if (nonLeafNeighbor.size() == 0)
			return city.cases;

		for (int i = 0; i < nonLeafChildNode.size(); i++)
		{
			city.cases *= calculate(cities[nonLeafChildNode[i]], nonLeafChildNode[i], index);
		}
	}

	return city.cases;
}


int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		cities[a].neighbor.push_back(b);
		cities[b].neighbor.push_back(a);
	}

	queue<int> leafNodes;
	for (int i = 1; i <= n; i++)
	{
		if (cities[i].isLeaf()) {
			leafNodes.push(i);
			cities[i].level = 1;
		}
	}

	int rootIndex;
	while (leafNodes.size()>1)
	{
		int leaf = leafNodes.front();
		leafNodes.pop();
		
		cities[leaf].parent = cities[leaf].neighbor[0];
		cities[leaf].neighbor.clear();

		int parent = cities[leaf].parent;

		cities[parent].neighbor.erase(find(cities[parent].neighbor.begin(), cities[parent].neighbor.end(), leaf));
		cities[parent].child.push_back(leaf);
		cities[parent].level = MAX( cities[parent].level, cities[leaf].level + 1);

		if (cities[parent].isLeaf())
			leafNodes.push(parent);
	}

	//
	for (int i = 1; i <= n; i++)
	{
		cityByLevel[ cities[i].level ].push_back(i);
	}

	int cases = 0;
	for (int t = 1; t <= n; t++)
	{
		for (int i = 0; i < cityByLevel[t].size(); i++)
		{
			cases = MAX(cases, calculate(cities[cityByLevel[t][i]], cityByLevel[t][i], 0));
		}
	}

	cout << cases;

	return 0;
}