// 1326D.cpp

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

constexpr int MAXN = 2e6;

int t;

int failure[MAXN + 100];
string find_Palindrome(const string& s)
{
	string a = s;
	int c = 0;

	reverse(a.begin(), a.end());
	a = s + '=' + a;

	failure[0] = 0;
	for (int i = 1; i < a.size(); ++i)
	{
		while (c != 0 && a[c] != a[i])
			c = failure[c - 1];

		if (a[c] == a[i])
			c++;

		failure[i] = c;
	}

	return a.substr(0, c);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	string s, a, palindrome_pre, palindrome_suf;

	cin >> t;
	while (t--)
	{
		cin >> s;
		int l = 0;
		while (s[l] == s[s.size() - l - 1] && l < s.size() - l - 1)
			++l;

		cout << s.substr(0, l);

		a = s.substr(l, s.size() - 2 * l);
		if (a.size())
		{
			palindrome_pre = find_Palindrome(a);
			reverse(a.begin(), a.end());
			palindrome_suf = find_Palindrome(a);

			if (palindrome_pre.size() > palindrome_suf.size())
				cout << palindrome_pre;
			else
				cout << palindrome_suf;
		}
		cout << s.substr(s.size() - l, l) << '\n';
	}

	return 0;
}
