#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;

	cout << (A + B) % C << '\n' << ((A % C) + (B % C)) % C << '\n' << (A * B) % C << '\n' << ((A % C) * (B % C)) % C;
}