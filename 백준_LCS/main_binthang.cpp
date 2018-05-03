#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int LengthOfLCS(string str1, string str2)
{
	vector<string> LCSs(str1.length());

	vector<vector<int>> maxLCS(str1.length()+1, vector<int>(str2.length()+1, 0));

	for (int i=0; i<str1.length(); i++)
	{
		for (int j=0; j<str2.length(); j++)
		{
			if (str1[i] == str2[j])
			{
				maxLCS[i+1][j+1] = maxLCS[i][j] + 1;
			}
			else
			{
				maxLCS[i+1][j+1] = maxLCS[i][j+1] > maxLCS[i+1][j] ? maxLCS[i][j+1] : maxLCS[i+1][j];
			}
		}
	}

	return maxLCS[str1.length()][str2.length()];
}

int main(int argc, char* argv[])
{
	string str1, str2;
	cin >> str1 >> str2;

	cout << LengthOfLCS(str1, str2) << endl;

	return 0;
}