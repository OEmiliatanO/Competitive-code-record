// d135.cpp
#pragma warning( disable : 4996 )
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;

using Vector = pair<double, double>;

constexpr double esp = 1e-8;

double x[3], y[3];
double TriArea;

double Cross(Vector a, Vector b)
{
	return (a.first * b.second) - (a.second * b.first);
}

bool inTri(double checkX, double checkY)
{
	double area[3];
	for (int i = 0; i < 3; ++i)
		area[i] = fabs(Cross({x[i] - checkX, y[i] - checkY}, {x[(i + 1) % 3] - checkX, y[(i + 1) % 3] - checkY})) / 2;

	double Sum = area[0] + area[1] + area[2];
	if (fabs(Sum - TriArea) <= esp)
		return true;

	return false;
}

int main()
{
	while (~scanf("%lf %lf %lf %lf %lf %lf", x, y, x + 1, y +1, x + 2, y + 2))
	{
		double s = 0;
		for (int i = 0; i < 3; ++i)
			s += x[i] + y[i];
		if (fabs(s) <= esp) break;

		TriArea = Cross({ x[1] - x[0], y[1] - y[0] }, { x[2] - x[0], y[2] - y[0] }) / 2;
		TriArea = fabs(TriArea);

		int cnt = 0;
		for (int treex = 1; treex <= 99; ++treex)
			for (int treey = 1; treey <= 99; ++treey)
				cnt += inTri(static_cast<double>(treex), static_cast<double>(treey));

		printf("%4d\n", cnt);
	}

    return 0;
}
