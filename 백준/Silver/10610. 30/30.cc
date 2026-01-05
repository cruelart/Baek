#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string N;
    cin >> N;

    // 0이 없으면 불가능
    if (N.find('0') == string::npos) {
        cout << -1;
        return 0;
    }

    // 전체 숫자 합 계산
    int sum = 0;
    for (char c : N)
        sum += c - '0';

    // 3의 배수 확인
    if (sum % 3 != 0) {
        cout << -1;
        return 0;
    }

    // 내림차순 정렬
    sort(N.begin(), N.end(), greater<char>());

    cout << N;
    return 0;
}