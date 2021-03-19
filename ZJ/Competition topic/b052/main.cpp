#include <iostream>
#include <string>

using namespace std;

string Reverse(string input)
{
	string buffer = "";
	for (int i = input.size() - 1; i >= 0; i--)
		buffer += input[i];
	return buffer;
}

string IntegerBinary(int number)
{
	string buffer = "";
	do
    {
		buffer += (number % 2 + '0'), number >>= 1;
	}while(number);

	return Reverse(buffer);
}

string DecimalBinary(int number, int size)
{
	int powerOf10 = 1;
	string buffer = "";

	while(size--)
		powerOf10 *= 10;

	do
    {
		number <<= 1;
		buffer += (number / powerOf10 + '0');
		number %= powerOf10;
	}while(number);
	return buffer;
}

int integerPart, decimalPart, dotPosition;
bool dot;
string input;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	while(cin >> input)
    {
		dot = false;
		integerPart = decimalPart = 0;
		for (int i = 0; i != input.size(); i++)
			if (input[i] == '.')
				dot = true, dotPosition = i;
			else if (dot)
				decimalPart *= 10, decimalPart += (input[i] - '0');
			else
				integerPart *= 10, integerPart += (input[i] - '0');

		cout << IntegerBinary(integerPart) << '.' << DecimalBinary(decimalPart, input.size() - dotPosition - 1) << endl;
	}
}
