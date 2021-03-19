#include <cstdio>

using namespace std;

/* main code */

int main()
{
	puts("1999");
	for (int x = 1; x <= 1000; ++x)
		printf("%d 1 %d 2\n", x, x);
	for (int x = 2; x <= 1000; ++x)
		printf("%d 1 %d 2\n", x, x);

	return 0;
}
