#pragma warning( disable : 4996 )
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map <string, int> umap;
int n, m, index = 1;
string tmp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	while (cin >> n >> m)
	{
		cin.ignore();

		umap.clear();

		for (int i = 0; i < n * m - 1; ++i)
		{
			getline(cin, tmp, '\n');
			++umap[tmp];
		}

		for (auto x : umap)
			if (x.second != m)
			{
				cout << x.first << '\n';
				break;
			}
	}

	return 0;
}
