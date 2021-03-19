#include <cstdio>
#include <cassert>
#include <cstdint>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

using namespace std;

#define fread fread_unlocked
#define fgets fgets_unlocked
#define putchar putchar_unlocked

constexpr int MAX = 1e8;

static char buf[MAX];
static char out[MAX];
int_fast32_t space = 0;
int index = 0;

int main()
{
	fgets(buf, MAX + 1, stdin);

	for (int i = 0; buf[i]; ++i)
	{
		if (buf[i] != ' ')
		{
			if (space & 1)
				out[index++] = ' ';
			out[index++] = buf[i];
			space = 0;
		}
		else
			++space;
	}

	fputs(out, stdout);

	return 0;
}
