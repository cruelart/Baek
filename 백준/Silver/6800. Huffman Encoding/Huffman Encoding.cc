#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	int k;
	cin >> k;

	unordered_map<string, int> my_map;

	for (int i = 0; i < k; i++)
	{
		string str;
		char alpabet;

		cin >> alpabet >> str;

		my_map[str] = alpabet;
	}

	string output_str;
	cin >> output_str;

	int len = 1;
	int present_index = 0;
	string result_str;

	while (present_index <= output_str.length() - 1)
	{
		if (my_map.find(output_str.substr(present_index, len)) != my_map.end())
		{
			result_str += my_map[output_str.substr(present_index, len)];
			present_index += len;
			len = 1;
		}
		else
		{
			len++;
		}
	}


	cout << result_str;

	return 0;
}