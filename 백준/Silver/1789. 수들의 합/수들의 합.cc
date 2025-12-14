#include <iostream>

using namespace std;

int main()
{
	long long S;
	cin >> S;

	unsigned int num = 1;
	unsigned int total_num = num;
	int count_num = 0;

	while ((long long)num*(num+1)/2 <= S)
	{
		num++;
		count_num++;
	}

	cout << count_num;

	return 0;
}