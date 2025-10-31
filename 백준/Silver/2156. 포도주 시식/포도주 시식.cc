#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> vec(n + 1);
	vector<vector<int>> dp_table(n + 1, vector<int>(3, 0)); // 특정 인덱스값을 무조건 포함한다고 했을 떄 최댓값

	//와인잔 채우기
	for (int i = 1; i <= n; i++)
	{
		cin >> vec[i];
	}

	dp_table[1][1] = vec[1]; // 첫 값 설정
	dp_table[1][2] = 0;

	if (n >= 2)
	{
		dp_table[2][1] = vec[2];
		dp_table[2][2] = dp_table[1][1] + vec[2];
	}


	//점화식짜기
	for (int i = 3; i <= n; i++)
	{
		dp_table[i][1] = max(dp_table[i - 2][2] + vec[i], dp_table[i][1]); // 떨어져있는 것으로부터 다시 1번세는경우
		dp_table[i][1] = max(dp_table[i - 2][1] + vec[i], dp_table[i][1]); // 1번밖에 세지않았지만 나중을 위해 안 세놓은 경우
		dp_table[i][1] = max(dp_table[i - 3][2] + vec[i], dp_table[i][1]); // 1번밖에 세지않았지만 나중을 위해 안 세놓은 경우

		dp_table[i][2] = max(dp_table[i - 1][1] + vec[i], dp_table[i][2]); // 연속일 경우
	}

	cout << max(max(dp_table[n - 1][1], dp_table[n - 1][2]), max(dp_table[n][1], dp_table[n][2])); // 맨끝 아니면 맨끝 바로 전꺼중 최댓값

	return 0;
}

//12 9 13 50 33 42 123 84