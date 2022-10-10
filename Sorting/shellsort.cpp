#include<iostream>
 
using namespace std;
 

void ShellSort(int a[], int n)
{
	int i, j, k, temp;
	for(i = n/2; i > 0; i = i/2)
	{
		for(j = i; j < n; j++)
		{
			for(k = j-i; k >= 0; k = k-i)
			{
				if(a[k+i] >= a[k])
				break;
			
				else
				{
					temp = a[k];
					a[k] = a[k+i];
					a[k+i] = temp;
				}
			}
		}
	}
}
int main()
{	
	int n, i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
 
	int arr[100];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}
 
	ShellSort(arr, n);
 
	//  sorted data.
	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
		cout<<"->"<<arr[i];
 
	return 0;
}