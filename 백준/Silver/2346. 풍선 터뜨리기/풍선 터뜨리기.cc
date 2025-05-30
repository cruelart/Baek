#include <iostream>
#include <queue> // pop_front하고 push_back이 들어가야하니까? 그럼에도 왜 deque? queue만해도 충분한데?

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	queue<pair<int,int>> circle_queue;
	queue<int> result_queue;

	int N;
	cin >> N;

	//queue에 들어갈 값 입력받기
	for (int i = 1; i < N + 1; i++)
	{
		int input_num;
		cin >> input_num;

		pair<int, int> index_inputNum;
		index_inputNum.first = i;
		index_inputNum.second = input_num;


		circle_queue.push(index_inputNum);
	}

	//주의사항 : 인덱스는 0부터 시작하지만 출력에는 1부터 시작하도록 해야할 것

	while (true)
	{
		//exe
		int circle_queueValue = circle_queue.front().second; // 다음으로 받아올 value 번호
		result_queue.push(circle_queue.front().first);

		circle_queue.pop();

		int real_moveRange;
		if (!circle_queue.empty())
		{
			if (circle_queueValue < 0)
			{
				while (circle_queueValue < 0)
				{
					circle_queueValue = circle_queueValue + (circle_queue.size());
					if (circle_queueValue >= 0)
					{
						circle_queueValue += 1;
					}
				}
				real_moveRange = circle_queueValue;
			}

			else
			{
				real_moveRange = circle_queueValue % circle_queue.size();
				if (real_moveRange == 0)
				{
					real_moveRange = circle_queue.size();
				}
			}

			//뒤로 옮기는 과정
			for (int i = 0; i < real_moveRange - 1; i++)
			{
				pair<int, int> plusNextIndex_num = circle_queue.front();
				circle_queue.pop();
				circle_queue.push(plusNextIndex_num);
			}

			continue;
		}
		break;
	}
	int result_size = result_queue.size();

	for(int i = 0 ; i< result_size; i++)
	{
		cout << result_queue.front() << ' ';
		result_queue.pop();
	}

	return 0;
}