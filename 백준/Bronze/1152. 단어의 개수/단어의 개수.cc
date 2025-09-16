#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	getline(cin, str);
	int count = 0;

	bool isWord = false; // -1이면 단어를 읽지않는 상태 1이면 단어를 읽는상태

	for (int i = 0; i < str.size(); i++)
	{
		if (!isWord)
		{
			if (str[i] != ' ') // 공백에서 문자가 입력이 됐다면
			{
				isWord = true;
				count++;
			}
		}
		else
		{
			if (str[i] == ' ') // 단어 하나 생성완료
			{
				isWord = false; // 새로운 단어을 입력받을 준비 완료
			}
		}
	}
	
	cout << count;
}