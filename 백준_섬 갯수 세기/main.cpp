#include <iostream>
#include <stack>
#include <fstream>

using namespace std;


int main()
{
	//auto cin = ifstream("B3");	// for file input testing
	int nRow = -1, nCol = -1;

	while (1)
	{
		int map[50][50];
		int search[50][50];

		// input
		cin >> nCol >> nRow;

		if ( !(nCol | nRow))	// exit condition
			break;

		for (int y = 0; y < nRow; y++)
		{
			for (int x = 0; x < nCol; x++)
			{
				cin >> map[y][x];
				search[y][x] = 0;
			}
		}

		// search
		int nIsland = 0;
		for (int y = 0; y < nRow; y++)
		{
			for (int x = 0; x < nCol; x++)
			{
				// skip untile first tile of next island
				if (search[y][x] != 0 || map[y][x] == 0)
					continue;

				search[y][x] = ++nIsland;	// makr that tile of next island

				// search all adjacent tiles and marking
				stack<pair<int, int>> remainTiles;
				remainTiles.push(pair<int, int>(x, y));
				while (!remainTiles.empty())
				{
					auto currentTile = remainTiles.top();
					remainTiles.pop();

					// push all neighbors
					for (int ty = currentTile.second - 1; ty <= currentTile.second + 1; ty++)
					{
						for (int tx = currentTile.first - 1; tx <= currentTile.first + 1; tx++)
						{
							if (ty < 0 || ty >= nRow || tx < 0 || tx >= nCol)
								continue;;

							if (map[ty][tx] == 0)
								continue;

							if (search[ty][tx] != 0)
								continue;

							// mark tile
							search[ty][tx] = search[currentTile.second][currentTile.first];

							// push this neighbor
							remainTiles.push(pair<int, int>(tx, ty));
						}
					}
				}
			}
		}

		cout << nIsland << endl;
	}
}