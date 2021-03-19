#pragma warning( disable : 4996 )
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map <string, long long> umap;
long long n, m, l = 0, r = 0, cata = 0, ans = 0;
string s[200001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n && cin >> s[i]; ++i);

	for (int i = 0; i < m; ++i)
	{
		if (!umap[s[i]])
			++cata;
		++umap[s[i]];
	}

	l = 0, r = m;
	for (; r <= n;)
	{
		ans += (m == cata);

		if (--umap[s[l]] == 0)
			--cata;

		if (umap[s[r]]++ == 0)
			++cata;

		++l, ++r;
	}
	cout << ans;
	return 0;
}