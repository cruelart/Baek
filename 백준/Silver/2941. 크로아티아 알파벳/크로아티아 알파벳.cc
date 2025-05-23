#include <iostream>
#include <string>

//#define Test1

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string croatia_alphabet[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

	string str;
	cin >> str;

	int croatia_alphabetNum = 0;
	//int str_index = 0;

	for (string _str : croatia_alphabet)
	{
		while (true)
		{
			size_t croatia_index = str.find(_str);

			if (croatia_index != string::npos)
			{
				str.replace(croatia_index, _str.size(), "1");
				continue;
			}
			else
			{
				break;
			}
		}
	}

	cout << str.size();
	
}