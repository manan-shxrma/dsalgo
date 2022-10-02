#include <bits/stdc++.h>
using namespace std;

// function build Max Heap where value
// of each child is always smaller
// than value of their parent
void buildMaxHeap(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		// if child is bigger than parent
		if (arr[i] > arr[(i - 1) / 2])
		{
			int j = i;
	
			// swap child and parent until
			// parent is smaller
			while (arr[j] > arr[(j - 1) / 2])
			{
				swap(arr[j], arr[(j - 1) / 2]);
				j = (j - 1) / 2;
			}
		}
	}
}

void heapSort(int arr[], int n)
{
	buildMaxHeap(arr, n);

	for (int i = n - 1; i > 0; i--)
	{
		// swap value of first indexed
		// with last indexed
		swap(arr[0], arr[i]);
	
		// maintaining heap property
		// after each swapping
		int j = 0, index;
		
		do
		{
			index = (2 * j + 1);
			
			// if left child is smaller than
			// right child point index variable
			// to right child
			if (arr[index] < arr[index + 1] &&
								index < (i - 1))
				index++;
		
			// if parent is smaller than child
			// then swapping parent with child
			// having higher value
			if (arr[j] < arr[index] && index < i)
				swap(arr[j], arr[index]);
		
			j = index;
		
		} while (index < i);
	}
}
int main()
{
	int arr[] = {10, 20, 15, 17, 9, 21};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	printf("Given array: ");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
		
	printf("\n\n");

	heapSort(arr, n);

	printf("Sorted array: ");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	return 0;
}
