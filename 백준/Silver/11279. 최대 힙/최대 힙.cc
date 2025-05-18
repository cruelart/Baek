#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;

using std::vector;
using std::make_heap;
using std::push_heap;
using std::pop_heap;
using std::ios;
using std::cout;
using std::cin;

void make_maxHeap(vector<unsigned int>& _vec, vector<unsigned int>& _ouput_vec, const int _num);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<unsigned int> vec;
	vector<unsigned int> output_vec;
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		make_maxHeap(vec, output_vec, x);
	}

	int outputExe_num = output_vec.size();

	for (int i : output_vec)
	{
		cout << i << '\n';
	}

	return 0;
}

void make_maxHeap(vector<unsigned int>& _vec, vector<unsigned int>& _ouput_vec, const int _num)
{
	if (_num == 0)
	{
		if (_vec.empty())
		{
			_ouput_vec.push_back(0);
			return;
		}
		_ouput_vec.push_back(_vec.front());
		pop_heap(_vec.begin(), _vec.end());
		_vec.pop_back();
	}

	_vec.push_back(_num);
	push_heap(_vec.begin(), _vec.end()); // push_back할때마다 heap유지
}