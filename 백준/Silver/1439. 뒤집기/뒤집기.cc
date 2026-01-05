#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string str;
	cin >> str;

	int INF = 1000001;

	char present_num;
	int min_num = INF;
	//전부 방문해서 세트가 몇개인지 알아낸다. pair<int,int> 0,1 세트수
	pair<int, int> zero_one = { 0,0 };
	if (!str.empty())
	{
		present_num = str[0];

		if (str[0] == '0')
		{
			zero_one.first++;
		}
		else if(str[0] == '1')
		{
			zero_one.second++;
		}
		else{}
	}

	for (int index = 1; index < str.size(); index++)
	{
		if (present_num != str[index])
		{
			present_num = str[index];

			if (present_num == '0')
			{
				zero_one.first++;
			}
			else if (present_num == '1')
			{
				zero_one.second++;
			}
		}
	}

	cout << min(zero_one.first, zero_one.second);

	return 0;
}