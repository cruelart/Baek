#include <iostream>

using namespace std;

int main()
{
    int test_score;
    cin >> test_score;

    if (test_score >= 90)
    {
        cout << 'A';
    }
    else if (test_score >= 80)
    {
        cout << 'B';
    }
    else if (test_score >= 70)
    {
        cout << 'C';
    }
    else if (test_score >= 60)
    {
        cout << 'D';
    }
    else
    {
        cout << 'F';
    }

    return 0;
}