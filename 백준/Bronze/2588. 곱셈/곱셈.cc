#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using std::cout;
using std::cin;
using std::string;
using std::vector;

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B;
	cin >> A >> B;

	vector<int> result;
	int final_result = 0;
	string B_str = std::to_string(B);

	vector<char> number_location;
	for (int i = B_str.size()-1; i >= 0; i--)
	{
		number_location.push_back(B_str[i]);
	}

	for (int i = 0; i < number_location.size(); i++)
	{
		result.push_back(A * (number_location[i] - '0'));
		final_result += A * ((number_location[i] - '0') * std::pow(10, i));
		cout << result[i] << '\n';
	}

	cout << final_result;

	return 0;
}