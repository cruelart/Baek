#include <iostream>

using namespace std;

int main()
{
	int T; // 테스트 횟수
	cin >> T;
	string* result = new string[T];
	
	for (int t = 0; t < T; t++)
	{
		int R;
		string str;
		string new_str;

		cin >> R >> str;
		for (int i = 0; i < str.size(); i++)
		{
			for (int j = 0; j < R; j++)
			{
				new_str += str[i];
			}
		}

		result[t] += new_str;
	}

	for (int k = 0; k < T; k++)
	{
		cout << result[k] << '\n';
	}
}