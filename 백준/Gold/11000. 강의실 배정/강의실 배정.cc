#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<long long, long long>> lec(N);
    // lec[i].first  = 시작시간
    // lec[i].second = 끝시간

    for (int i = 0; i < N; i++)
    {
        cin >> lec[i].first >> lec[i].second;
    }

    // 시작시간 기준 정렬
    sort(lec.begin(), lec.end());

    // 끝나는 시간만 저장하는 최소 힙
    priority_queue<long long, vector<long long>, greater<>> pq;

    // 첫 수업의 끝시간 push
    pq.push(lec[0].second);

    for (int i = 1; i < N; i++)
    {
        long long earliestEnd = pq.top();

        // 가장 빨리 끝나는 강의실에 이어서 쓸 수 있으면
        if (lec[i].first >= earliestEnd)
        {
            pq.pop();
            pq.push(lec[i].second);
        }
        else
        {
            // 새 강의실 필요
            pq.push(lec[i].second);
        }
    }

    cout << pq.size();
    return 0;
}