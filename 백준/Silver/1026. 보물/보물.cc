#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> A(N);
	vector<int> B(N);

	for (int n = 0; n < N; n++)
	{
		cin >> A[n];
	}
	for (int n = 0; n < N; n++)
	{
		cin >> B[n];
	}
	
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), [](int a, int b) {return a > b;}); // sort(B.being(), B.end(), greater<int>())

	int result = 0;

	for (int n = 0; n < N; n++)
	{
		result += A[n] * B[n];
	}

	cout << result;

	return 0;
}