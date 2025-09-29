#include <iostream>
#include <ctime>

using namespace std;

//use quick select algorithm
int QuickSelectAlgorithm(int* _arr, int _start_pos , int _end_pos, int _want_find) // 피봇, 현재 피봇 위치(반복해야 하는 횟수), 찾아야하는 번호
{
	int random = _start_pos + rand() % (_end_pos - _start_pos + 1);
	swap(_arr[random], _arr[_end_pos]);
	int pivot = _arr[_end_pos];
	int present_pivotPos = _start_pos;

	for (int i = _start_pos; i < _end_pos; i++)
	{
		if (_arr[i] < pivot)
		{
			if (_arr[i] != _arr[present_pivotPos])
			{
				swap(_arr[i], _arr[present_pivotPos]);
			}
			present_pivotPos++;
		}
	}
	if (_arr[_end_pos] != _arr[present_pivotPos])
	{
		swap(_arr[_end_pos], _arr[present_pivotPos]);
	}

	if (present_pivotPos == _want_find)
	{
		return _arr[present_pivotPos];
	}
	else if (present_pivotPos > _want_find)
	{
		return QuickSelectAlgorithm(_arr, _start_pos, present_pivotPos - 1, _want_find);
	}
	else
	{
		return QuickSelectAlgorithm(_arr, present_pivotPos + 1, _end_pos, _want_find);
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int N, k;
	cin >> N >> k;

	int* arr = new int[N];

	//배열 채우기
	for (int n = 0; n < N; n++)
	{
		int grade;
		cin >> grade;
		arr[n] = grade;
	}

	cout << QuickSelectAlgorithm(arr, 0,  N - 1, N - k);

	return 0;
}