#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	map<string, int> my_map;
	vector<tuple<int, int,  string>> cout_vec;// 중복 횟수, 단어 길이 , 단어 이름
	int max = 0;

	for (int n = 1; n <= N; n++)
	{
		string str;
		cin >> str;
		if (str.length() >= M)
		{
			my_map[str]++;
		}
	}

	for (auto p : my_map)
	{
		int repeat_num = p.second; // 단어 중복 횟수
		string word = p.first; // 단어 이름
		int word_length = p.first.length(); // 단어 길이

		cout_vec.push_back({ repeat_num, word_length ,word });
	}

	sort(cout_vec.begin(), cout_vec.end(), [](auto& a, auto& b) {
		if (get<0>(a) != get<0>(b)) return get<0>(a) > get<0>(b); // 빈도 내림차순
		if (get<1>(a) != get<1>(b)) return get<1>(a) > get<1>(b); // 길이 내림차순
		return get<2>(a) < get<2>(b); // 사전순 오름차순
		});

	for (int i = 0; i < cout_vec.size(); i++)
	{
		cout << get<2>(cout_vec[i]) << '\n';
	}

	return 0;
}