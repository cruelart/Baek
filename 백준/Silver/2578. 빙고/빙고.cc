#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int arr[5][5];

int Bingo() // 반드시 지나야하는 점을 기준으로
{
	// 가운데부분을 지나야 하므로
	int bingoCount = 0;

	//1. 세로먼저
	for (int y = 0; y < 5; y++)
	{
		if (arr[2][y] == arr[2][2])
		{
			if (y == 4)
			{
				bingoCount++;
			}
			continue;
		}
		break;
	}
	for (int y = 0; y < 5; y++)
	{
		if (arr[1][y] == arr[1][2])
		{
			if (y == 4)
			{
				bingoCount++;
			}
			continue;
		}
		break;
	}
	for (int y = 0; y < 5; y++)
	{
		if (arr[0][y] == arr[0][2])
		{
			if (y == 4)
			{
				bingoCount++;
			}
			continue;
		}
		break;
	}
	for (int y = 0; y < 5; y++)
	{
		if (arr[3][y] == arr[3][2])
		{
			if (y == 4)
			{
				bingoCount++;
			}
			continue;
		}
		break;
	}
	for (int y = 0; y < 5; y++)
	{
		if (arr[4][y] == arr[4][2])
		{
			if (y == 4)
			{
				bingoCount++;
			}
			continue;
		}
		break;
	}
	//x 빙고
	for (int x = 0; x < 5; x++)
	{
		if (arr[x][2] == arr[2][2])
		{
			if (x == 4)
			{
				bingoCount++;
			}
			continue;
		}
		break;
	}

	for (int x = 0; x < 5; x++)
	{
		if (arr[x][1] == arr[2][1])
		{
			if (x == 4)
			{
				bingoCount++;
			}
			continue;
		}
		break;
	}

	for (int x = 0; x < 5; x++)
	{
		if (arr[x][0] == arr[2][0])
		{
			if (x == 4)
			{
				bingoCount++;
			}
			continue;
		}
		break;
	}

	for (int x = 0; x < 5; x++)
	{
		if (arr[x][3] == arr[2][3])
		{
			if (x == 4)
			{
				bingoCount++;
			}
			continue;
		}
		break;
	}

	for (int x = 0; x < 5; x++)
	{
		if (arr[x][4] == arr[2][4])
		{
			if (x == 4)
			{
				bingoCount++;
			}
			continue;
		}
		break;
	}

	//대각선
	for (int x = 0; x < 5; x++)
	{
		if (arr[x][x] == arr[2][2])
		{
			if (x == 4)
			{
				bingoCount++;
			}
			continue;
		}
		break;
	}

	for (int x = 0; x < 5; x++)
	{
		if (arr[4-x][x] == arr[2][2])
		{
			if (x == 4)
			{
				bingoCount++;
			}
			continue;
		}
		break;
	}

	return bingoCount;
}

int main()
{
	unordered_map<int,pair<int,int>> save_numOrder;
	//빙고판 작성
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			cin >> arr[x][y];
			save_numOrder[arr[x][y]] = { x,y };
		}
	}

	//사회자의 호출
	vector<int> save_order(25); // 순서 기억용
	for (int i = 0; i < 25; i++)
	{
		cin >> save_order[i];
	}

	for (int order_num = 0; order_num < save_order.size(); order_num++)
	{
		pair<int, int> index = save_numOrder[save_order[order_num]];
		arr[index.first][index.second] = -1; // -1로 해서 체크처리함
		if (order_num >= 9)
		{
			if (Bingo() >= 3)
			{
				cout << order_num + 1;
				return 0;
			}
		}
	}

	cout << "또 버그야ㅅㅍ";
	return 0;
}