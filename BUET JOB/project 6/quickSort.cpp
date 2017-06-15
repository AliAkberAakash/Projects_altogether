#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int partition(int arr[], int l, int r);
//int partition(int arr[], int l, int r, int x);

void swap(int* x, int* y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

//int partition(int* a,int start, int enD);


int randomPartition(int arr[], int l, int r)
{
    int n = r-l+1;
    int pivot = rand() % n;
    swap(&arr[l + pivot], &arr[r]);
    return partition(arr, l, r);
}

int kthSmallest(int arr[], int l, int r, int k)
{
    // If k is smaller than number of elements in array
    if (k > 0 && k <= r - l + 1)
    {
        // Partition the array around a random element and
        // get position of pivot element in sorted array
        int pos = randomPartition(arr, l, r);

        // If position is same as k
        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)  // If position is more, recur for left subarray
            return kthSmallest(arr, l, pos-1, k);

        // Else recur for right subarray
        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }

    // If k is more than number of elements in array
    return INT_MAX;
}


void qSort(int* a, int start, int enD)
{
    if(start<enD)
    {
        int pIndex=partition(a, start, enD);
        qSort(a, start, pIndex-1);
        qSort(a,  pIndex+1, enD);
    }
}



int partition (int arr[], int low, int high)
{
	int pivot = kthSmallest(arr, low, high, high/2);
	int i = (low - 1);

	for (int j = low; j <= high- 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

int main()
{
    int i,n,a[100];

    scanf("%d", &n);

    for(i=0; i<n; i++)
        scanf("%d", &a[i]);

    printf("\n%d\n\n", kthSmallest(a,0,n-1,n/2));

    qSort(a,0,n-1);

    for(i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
