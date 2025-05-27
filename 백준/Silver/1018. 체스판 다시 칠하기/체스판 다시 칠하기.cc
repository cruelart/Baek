#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int black_chess[8][8] = {};
	for (int i = 0; i < 8; i++)
	{
		if (i % 2 == 1)
		{
			black_chess[i][0] = 1;
		}
		else if (i % 2 == 0)
		{
			black_chess[i][0] = -1;
		}
		else {}
		for (int j = 0; j < 8; j++)
		{
			if (j > 0)
			{
				black_chess[i][j] = -black_chess[i][j-1];
			}
		}
	}
	int white_chess[8][8] = {};
	for (int i = 0; i < 8; i++)
	{
		if (i % 2 == 1)
		{
			white_chess[i][0] = -1;
		}
		else if (i % 2 == 0)
		{
			white_chess[i][0] = 1;
		}
		else {}
		for (int j = 0; j < 8; j++)
		{
			if (j > 0)
			{
				white_chess[i][j] = -white_chess[i][j - 1];
			}
		}
	}

	int M, N;
	int min_try; // 최소 실행 횟수

	int m = 0;
	int n = 0;

	cin >> M >> N;

	min_try = M * N;

	//initialize chess_block
	int** chess_block = new int*[M];

	for (int i = 0; i < M; i++)
	{
		chess_block[i] = new int[N];
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char chess_color;
			cin >> chess_color;
			if (chess_color == 'W')
			{
				chess_block[i][j] = 1;
			}
			else if (chess_color == 'B')
			{
				chess_block[i][j] = -1;
			}
		}
	}

	int change_blackchessNum = 0;
	int change_whitechessNum = 0;

	while ((8 + m) != (M+1) && (8 + n) != (N+1))
	{
		for (int i = m; i < (8 + m); i++)
		{
			for (int j = n; j < (8 + n); j++)
			{
				//전체적인 그림
				//처음이 W냐 B냐에 따라 두가지 경우로 나누어서 비교

				//예외사항
				//1, 맨 아래일 경우에는 접근 불가능하게 설정 >> 비할당 메모리 참조 방지

				if (chess_block[i][j] != black_chess[i - m][j-n])
				{
					change_blackchessNum++;
				}

				if (chess_block[i][j] != white_chess[i - m][j - n])
				{
					change_whitechessNum++;
				}
			}
		}

		if (change_whitechessNum < change_blackchessNum)
		{
			if (change_whitechessNum < min_try)
			{
				min_try = change_whitechessNum;
			}
		}
		else if (change_blackchessNum <= change_whitechessNum)
		{
			if (change_blackchessNum < min_try)
			{
				min_try = change_blackchessNum;
			}
		}

		if ((8 + m) != M)
		{
			m++;
			change_blackchessNum = 0;
			change_whitechessNum = 0;
		}
		else
		{
			n++;
			m = 0;
			change_blackchessNum = 0;
			change_whitechessNum = 0;
		}
	}

	cout << min_try;
	return 0;
}