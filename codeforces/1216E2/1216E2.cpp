#include <iostream>
#include <cmath>

using namespace std;

using int16 = short;
using uint16 = unsigned short;
using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;

uint64 getBit(uint64 _i)
{
	uint64 curlen = 1, number = 1, pos = 0, dange = 1;
	while (_i > curlen)
	{
		pos = curlen;
		dange += log10(double(++number)) + 1;
		curlen += dange;
	}
	pos = _i - curlen + dange;
	curlen = 1;
	number = 1;
	dange = 0;
	while (pos > curlen)
	{
		dange = curlen;
		curlen += log10(double(++number)) + 1;
	}
	pos -= dange;
	return number / int(pow(10, int(log10(number)) + 1 - pos)) % 10;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		uint64 i;
		cin >> i;
		cout << getBit(i) << endl;
	}
	return 0;
}