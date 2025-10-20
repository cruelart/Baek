#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    unordered_map<long long, int> freq;
    pair<long long, int> max_pair = {0, -1};

    for (int i = 0; i < N; i++)
    {
        long long num;
        cin >> num;

        int cnt = ++freq[num];

        if (cnt > max_pair.second)
            max_pair = {num, cnt};
        else if (cnt == max_pair.second && num < max_pair.first)
            max_pair.first = num;
    }

    cout << max_pair.first;
}