#include <iostream>
#include <string>
#include <vector>

//Create deque

using std::string;
using std::ios;
using std::cout;
using std::cin;
using std::vector;

class KJSDeque
{

public:
	KJSDeque()
		:map_size{ 8 },
		max_indexSize( 512 / sizeof(int)),
		m_front{ nullptr },
		m_back{nullptr},
		m_frontNum{-1},
		m_backNum{-1},
		total_size{0},
		m_mapfrontIndex{ 0 },
		m_mapbackIndex{ 0 }
	{
		m_map = new int*[map_size](); // () nullptr초기화
	}

	~KJSDeque()
	{
	}

//Deque Function
public:

	void push_front(int _num)
	{
		// => 예외사항
		// 1. map자체가 꽉차있다면 -> map을 확장시키고 다시 배열에 기존 map을 넣어준 뒤 새로운 블록배열을 만든다.
		// 2. 블록이 꽉차있다면
		// 3. 아예 비어있다면

		//1.map자체가 꽉차있다면 expand
		if (m_mapfrontIndex == 0 && m_frontNum == 0) //앞쪽이 꽉차다면
		{
			//expand m_map
			int save_size = map_size;
			map_size *= 2;
			int** new_map = new int* [map_size]();
			int** past_map = m_map;
			for (int i = 0; i < save_size; i++)
			{
				new_map[map_size/2 - save_size/2 + i] = m_map[i];
			}
			m_mapfrontIndex = map_size / 2 - save_size / 2;
			m_mapbackIndex = map_size / 2 + save_size / 2 - 1;
			m_map = new_map;
			delete[] past_map;
			past_map = nullptr;
		}
		//2.블록이 꽉차있다면
		if (m_front != m_map[0] && m_frontNum == 0)
		{
			int* blockArray = new int[max_indexSize]();

			m_mapfrontIndex--;
			m_map[m_mapfrontIndex] = blockArray;
			m_front = m_map[m_mapfrontIndex];
			m_frontNum = max_indexSize;
		}



		//3.map이 아예 비어있는 상태라면
		if (m_front == nullptr || m_back == nullptr) // m_map에 아무것도 들어가 있지 않다면
		{
			int* blockArray = new int[512 / sizeof(int)]();

			//initialize
			m_map[map_size / 2] = blockArray;
			m_front = m_map[map_size / 2];
			m_mapfrontIndex = map_size / 2;
			m_back = m_map[map_size / 2];
			m_mapbackIndex = map_size / 2;

			m_frontNum = max_indexSize / 2;
			m_backNum = max_indexSize / 2 - 1;
		}

		//exe
		if (m_front != nullptr)
		{
			m_front[m_frontNum - 1] = _num;
			m_frontNum--;
			total_size++;
		}
	}

	void push_back(int _num)
	{
		// => 예외사항
		// 1. map자체가 꽉차있다면 -> map을 확장시키고 다시 배열에 기존 map을 넣어준 뒤 새로운 블록배열을 만든다.
		// 2. 블록이 꽉차있다면
		// 3. 아예 비어있다면

		// 1.map자체가 꽉차있다면
		if (m_back == m_map[map_size - 1] && m_backNum == max_indexSize - 1) // 뒤쪽이 꽉차있는 경우
		{
			//expand m_map
			int save_size = map_size;
			map_size *= 2;
			int** new_map = new int* [map_size]();
			int** past_map = m_map;
			for (int i = 0; i < save_size; i++)
			{
				new_map[map_size / 2 - save_size / 2 + i] = m_map[i];
			}

			m_mapfrontIndex = map_size / 2 - save_size / 2;
			m_mapbackIndex = map_size / 2 + save_size / 2 - 1;
			m_map = new_map;
			delete[] past_map;
			past_map = nullptr;
		}

		//2.블록이 꽉차있다면
		if (m_back != m_map[map_size-1] && m_backNum == max_indexSize-1)
		{
			int* blockArray = new int[max_indexSize]();

			m_mapbackIndex++;
			m_map[m_mapbackIndex] = blockArray;

			m_back = m_map[m_mapbackIndex];
			m_backNum = -1;
		}



		//3.map이 아예 비어있는 상태라면
		if (m_front == nullptr || m_back == nullptr) // m_map에 아무것도 들어가 있지 않다면
		{
			int* blockArray = new int[max_indexSize]();

			//initialize
			m_map[map_size / 2] = blockArray;
			m_front = m_map[map_size / 2];
			m_mapfrontIndex = map_size / 2;
			m_back = m_map[map_size / 2];
			m_mapbackIndex = map_size / 2;

			m_frontNum = max_indexSize / 2;
			m_backNum = max_indexSize / 2 - 1;

		}

		//exe
		if (m_back != nullptr)
		{
			m_back[m_backNum + 1] = _num;
			m_backNum++;
			total_size++;
		}
	}

	int pop_front()
	{
		//예외사항
		//1. 삭제했더니 해당 블록배열이 비게 되는 경우
		// 2. 삭제했더니 m_map이 비게되는 경우

		//exe
		if (m_front != nullptr)
		{
			int output_num = m_front[m_frontNum];
			//m_frontNum++;

			//1. 하필 삭제할랬더니 m_map 자채가 비게되는 경우
			if (total_size == 1)
			{
				delete[] m_front;
				m_front = nullptr;
				m_back = nullptr;
				//delete[] m_map;
				//m_map = nullptr;
				//std::cout << "delete map" << '\n';
				total_size = 0;
				return output_num;
			}
			// 2. 삭제할랬더니 해당 블록배열이 비게 되는 경우
			if (m_mapbackIndex != m_mapfrontIndex && m_frontNum == max_indexSize - 1)
			{
				int* delete_array = m_front;
				delete[] delete_array;
				m_map[m_mapfrontIndex] = nullptr;
				delete_array = nullptr;
				m_mapfrontIndex++;
				m_front = m_map[m_mapfrontIndex];
				m_frontNum = 0;
				return output_num;
			}
			m_frontNum++;
			total_size--;
			return output_num;
		}
		//std::cout << "Error" << '\n';
		return -1;
	}

	int pop_back()
	{
		if (m_back != nullptr)
		{
			int output_num = m_back[m_backNum];
			//m_backNum--;

			//1. 하필 삭제했더니 m_map 자체가 비게되는 경우
			if (total_size == 1)
			{
				delete[] m_back;
				m_front = nullptr;
				m_back = nullptr;
				//delete[] m_map;
				//m_map = nullptr;
				//std::cout << "delete map" << '\n';
				total_size = 0;
				return output_num;
			}

			// 2. 삭제했더니 해당 블록배열이 비게 되는 경우
			if (m_mapbackIndex != m_mapfrontIndex && m_backNum == 0)
			{
				int* delete_array = m_back;
				delete[] delete_array;
				m_map[m_mapbackIndex] = nullptr;
				delete_array = nullptr;
				m_mapbackIndex--;
				m_back = m_map[m_mapbackIndex];
				m_backNum = max_indexSize - 1;
				return output_num;

			}
			//exe
			m_backNum--;
			total_size--;
			return output_num;
		}
		//std::cout << "Error" << '\n';
		return -1;
	}

	int size()
	{
		return total_size;
	}

	int empty()
	{
		if (m_front == nullptr || m_back == nullptr)
		{
			return 1;
		}
		return 0;
	}

	int front()
	{
		if (m_front != nullptr)
		{
			//std::cout << m_front[m_frontNum];
			return m_front[m_frontNum];
		}
		//output Error message
		//std::cout << "this deque is empty" << '\n';
		return -1;
	}

	int back()
	{
		if (m_back != nullptr)
		{
			//std::cout << m_back[m_backNum];
			return m_back[m_backNum];
		}
		//output Error message
		//std::cout << "this deque is empty" << '\n';
		return -1;
	}

private:
	int map_size;
	int** m_map; // 블록배열을 담을 map변수

	int* m_front; // map배열의 첫 요소위치
	int m_frontNum; // 해당 배열의 요소위치
	int m_mapfrontIndex; // 해당 배열의 요소위치
	int* m_back; // map베열의 마지막 요소 위치
	int m_backNum; // 해당 배열의 요소위치
	int m_mapbackIndex; // 해당 배열의 요소위치

	int max_indexSize; // 블록배열이 저장핤 수 있는 갯수

	int total_size; // 전체 요소갯수

};


void is_dequeReference(const string& _str, KJSDeque& _kjsDeque, vector<int>& _vec);

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(NULL);

	KJSDeque kjsDeque;

	int N; //명령의 수

	cin >> N;

	vector<int> vec;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		is_dequeReference(str, kjsDeque, vec);
	}

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << '\n';
	}

	return 0;
}

void is_dequeReference(const string& _str, KJSDeque& _kjsDeque, vector<int>& _vec)
{
	if (_str == "push_back")
	{
		int num;
		cin >> num;
		_kjsDeque.push_back(num);
		return;
	}
	
	else if (_str == "push_front")
	{
		int num;
		cin >> num;
		_kjsDeque.push_front(num);
		return;
	}

	else if (_str == "front")
	{
		_vec.push_back(_kjsDeque.front());
		return;
	}

	else if (_str == "back")
	{
		_vec.push_back(_kjsDeque.back());
		return;
	}

	else if (_str == "size")
	{
		_vec.push_back(_kjsDeque.size());
		return;
	}
	else if (_str == "pop_front")
	{
		_vec.push_back(_kjsDeque.pop_front());
		return;
	}
	else if (_str == "pop_back")
	{
		_vec.push_back(_kjsDeque.pop_back());
		return;
	}
	else if (_str == "empty")
	{
		_vec.push_back(_kjsDeque.empty());
		return;
	}
	else
	{
		//cout << "올바른 문자열을 입력해주십시오." << '\n';
		return;
	}

}