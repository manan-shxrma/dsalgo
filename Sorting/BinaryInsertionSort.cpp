#include <iostream>
using namespace std;

int binarySearch(int a[], int item,
                int low, int high)
{
    if (high <= low)
        return (item > a[low]) ?
                (low + 1) : low;
  
    int mid = (low + high) / 2;
  
    if (item == a[mid])
        return mid + 1;
  
    if (item > a[mid])
        return binarySearch(a, item,
                            mid + 1, high);
    return binarySearch(a, item, low,
                        mid - 1);
}

void insertionSort(int a[], int n)
{
    int i, loc, j, k, selected;
  
    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];
  
        // find location where selected should be inserted
        loc = binarySearch(a, selected, 0, j);
  
        // Move all elements after location to create space
        while (j >= loc)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }
}

//Main driver code
int main()
{
    int a[]
        = { 38, 23, 0, 18, 12, 72, 31, 46, 100, 88, 54 };
    int n = sizeof(a) / sizeof(a[0]), i;
  
    insertionSort(a, n);
  
    cout <<"Sorted array is : \n";
    for (i = 0; i < n; i++)
        cout <<" "<< a[i];
  
    return 0;
}
