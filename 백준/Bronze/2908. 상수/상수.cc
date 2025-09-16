#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int A, B; // 두 수
	cin >> A >> B;

	string str_a = to_string(A);
	string str_b = to_string(B);

	for (int i = 0; i < str_a.length()/2; i++)
	{
		char save = str_a[i];
		str_a[i] = str_a[str_a.length() - 1];
		str_a[str_a.length() - 1] = save;
	}

	for (int i = 0; i < str_b.length() / 2; i++)
	{
		char save = str_b[i];
		str_b[i] = str_b[str_b.length() - 1];
		str_b[str_b.length() - 1] = save;
	}

	int new_A = stoi(str_a);
	int new_B = stoi(str_b);

	if (new_A > new_B)
	{
		cout << new_A;
	}
	else
	{
		cout << new_B;
	}
}