#include <iostream>
using namespace std;

int maximumSum(int arr[], int n, int k)
{
	if (n < k) {
		cout << "Invalid";
		return -1;
	}

	int maxm_sum = 0;
	for (int i = 0; i < k; i++)
		maxm_sum += arr[i];
	int window_sum = maxm_sum;
	for (int i = k; i < n; i++) {
		window_sum += arr[i] - arr[i - k];
		maxm_sum = max(maxm_sum, window_sum);
	}

	return maxm_sum;
}

int main()
{
	int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
	int k = 4;
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << maximumSum(arr, n, k);
	return 0;
}
