#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	string N;
	int B; // 진법
	cin >> N >> B;

	vector<string> new_N; // 숫자변환 N
	int result = 0;

	for (int i = 0; i < N.length(); i++)
	{
		int num;
		if (N[i] >= 'A')
		{
			num = N[i] - 'A' + 10;
		}
		else
		{
			num = N[i] - '0';
		}
		new_N.push_back(to_string(num));
	}
	reverse(new_N.begin(), new_N.end());

	//new_N에 들어있는건 B진법수 N 이므로 10진수로 교체
	for (int i = 0; i < new_N.size(); i++)
	{
		result += stoi(new_N[i]) * pow(B, i);
	}

	cout << result;
}