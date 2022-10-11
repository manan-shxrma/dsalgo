// C++ program to print largest contiguous array sum

#include <climits>
#include <iostream>
using namespace std;

void maximumSubArray(int a[], int size)
{
	int max_till_now = INT_MIN, max_end = 0,
		start = 0, end = 0, s = 0;

	for (int i = 0; i < size; i++) {
		max_end += a[i];

		if (max_till_now < max_end) {
			max_till_now = max_end;
			start = s;
			end = i;
		}

		if (max_end < 0) {
			max_end = 0;
			s = i + 1;
		}
	}
	cout << "Maximum contiguous sum is " << max_till_now
		<< endl;
	cout << "Starting index " << start << endl
		<< "Ending index " << end << endl;
}

/*Driver program to test maxSubArraySum*/
int main()
{
	int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
	int n = sizeof(a) / sizeof(a[0]);
	int max_sum = maximumSubArray(a, n);
	return 0;
}
