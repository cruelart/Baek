#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int A, B; // 두 수
	cin >> A >> B;

	string str_a = to_string(A);
	string str_b = to_string(B);

	reverse(str_a.begin(), str_a.end());
	reverse(str_b.begin(), str_b.end());

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