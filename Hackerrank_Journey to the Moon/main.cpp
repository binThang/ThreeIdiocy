#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	//auto cin = ifstream("B3");	// for file input testing

	int n, p;

	// input
	cin >> n >> p;

	int countryIndex[100000];
	memset(countryIndex, -1, sizeof(int) * 100000);

	vector<vector<int>> country;
	for (int i = 0; i < p; i++)
	{
		pair<int, int> edge;
		cin >> edge.first >> edge.second;

		// old country
		if ((countryIndex[edge.second] != -1) && (countryIndex[edge.first] != -1))
		{
			if (countryIndex[edge.second] == countryIndex[edge.first])
				continue;

			// both astronaut is on both country.
			// merge two country
			// move astronauts of countryA to countryB
			int to = countryIndex[edge.first];
			int from = countryIndex[edge.second];

			country[to].insert(
				country[to].end(),
				country[from].begin(),
				country[from].end());

			// clear countryA
			country[from].clear();

			// change countryIndex of all astronauts of countryA
			for (int a = 0; a < n; a++)
			{
				if (countryIndex[a] == from)
				{
					countryIndex[a] = to;
				}
			}
		}
		else if (countryIndex[edge.second] != -1)
		{
			// an astronaut has country, and another doesn't have a country
			countryIndex[edge.first] = countryIndex[edge.second];
			country[countryIndex[edge.second]].push_back(edge.first);
		}
		else if (countryIndex[edge.first] != -1)
		{
			// an astronaut has country, and another doesn't have a country
			countryIndex[edge.second] = countryIndex[edge.first];
			country[countryIndex[edge.first]].push_back(edge.second);
		}
		else
		{
			// new country
			int newCountryNumber = country.size();
			country.push_back(vector<int>());

			country[newCountryNumber].push_back(edge.first);
			country[newCountryNumber].push_back(edge.second);

			countryIndex[edge.first] = newCountryNumber;
			countryIndex[edge.second] = newCountryNumber;
		}
	}


	// calculate edges
	unsigned long totalEdge = (unsigned long)n * (n - 1) / 2;
	for (auto it = country.begin(); it != country.end(); it++)
	{
		unsigned long numOfVertexInSubgraph = it->size();
		if (numOfVertexInSubgraph == 0)
			continue;

		totalEdge -= (numOfVertexInSubgraph) * (numOfVertexInSubgraph - 1) / 2;
	}
	cout << totalEdge;

	return 0;
}