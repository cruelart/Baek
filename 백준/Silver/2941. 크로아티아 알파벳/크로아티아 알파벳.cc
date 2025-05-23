#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string croatia_word;
	cin >> croatia_word;

	int croatia_wordNum = 0; // 알파벳 수

	for (int i = 0; i < croatia_word.size(); i++)
	{
		if (croatia_word[i] == 'c')
		{
			if (i + 1 < croatia_word.size())
			{
				if (croatia_word[i + 1] == '=' || croatia_word[i + 1] == '-')
				{
					croatia_wordNum++;
					i++;
					continue;
				}
			}
		}

		else if (croatia_word[i] == 'd')
		{
			if (i + 1 < croatia_word.size())
			{
				if (i + 2 < croatia_word.size())
				{
					if (croatia_word[i + 1] == 'z' && croatia_word[i + 2] == '=')
					{
						croatia_wordNum++;
						i += 2;
						continue;
					}
				}

				if (croatia_word[i + 1] == '-')
				{
					croatia_wordNum++;
					i++;
					continue;
				}
			}
		}

		else if (croatia_word[i] == 'l' || croatia_word[i] == 'n')
		{
			if (i + 1 < croatia_word.size())
			{
				if (croatia_word[i + 1] == 'j')
				{
					croatia_wordNum++;
					i++;
					continue;
				}
			}
		}

		else if (croatia_word[i] == 's' || croatia_word[i] == 'z')
		{
			if (i + 1 < croatia_word.size())
			{
				if (croatia_word[i + 1] == '=')
				{
					croatia_wordNum++;
					i++;
					continue;
				}
			}
		}
		else
		{

		}

		croatia_wordNum++;
	
	}

	cout << croatia_wordNum;
}