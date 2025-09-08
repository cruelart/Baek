#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int project_num; // 과목 갯수
	cin >> project_num;

	float* array_num = new float[project_num];

	for (int p = 0; p < project_num; p++)
	{
		float project_score; // 과목 점수
		cin >> project_score;
		array_num[p] = project_score;
	}

	float average = [project_num](float* _array_num)
		{
			float all_score = 0; // 모든 점수 합
			float max = _array_num[0];
			for (int i = 0; i < project_num; i++)
			{
				all_score += _array_num[i];
				if (max < _array_num[i])
				{
					max = _array_num[i];
				}
			}
			return (all_score * 100)/(max * project_num);
		}(array_num);

	cout << average;

	return 0;
}