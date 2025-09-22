#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true)
	{
		int side_length[3];
		cin >> side_length[0] >> side_length[1] >> side_length[2];
		sort(side_length, side_length + 3);

		int withoutMax_sum = 0;

		withoutMax_sum += side_length[0] + side_length[1];

		if (side_length[2] == 0)
		{
			break;
		}

		if (side_length[2] >= withoutMax_sum)
		{
			cout << "Invalid" << '\n';
		}
		else if (side_length[0] == side_length[1] || side_length[1] == side_length[2])
		{
			if (side_length[0] == side_length[1] && side_length[1] == side_length[2])
			{
				cout << "Equilateral" << '\n';
				continue;
			}
			cout << "Isosceles" << '\n';
		}
		else
		{
			cout << "Scalene" << '\n';
		}

	}
}