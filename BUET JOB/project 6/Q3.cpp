#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<climits>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findMedian(int arr[], int n)
{
    sort(arr, arr+n);
    return arr[n/2];
}

int partitioN(int arr[], int l, int r, int x)
{
    int i;
    for (i=l; i<r; i++)
        if (arr[i] == x)
           break;
    swap(&arr[i], &arr[r]);

    // Standard partition algorithm
    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int kthSmallest(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int n = r-l+1;

        int i, median[(n+4)/5];
        for (i=0; i<n/5; i++)
            median[i] = findMedian(arr+l+i*5, 5);
        if (i*5 < n)
        {
            median[i] = findMedian(arr+l+i*5, n%5);
            i++;
        }

        int medOfMed = (i == 1)? median[i-1]:
                                 kthSmallest(median, 0, i-1, i/2);

        int pos = partitioN(arr, l, r, medOfMed);

        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)
            return kthSmallest(arr, l, pos-1, k);

        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }
    return INT_MAX;
}



int partition(int arr[], int l, int r)
{
    int x = kthSmallest(arr,l,r,(r+1)/2);
    int  i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int randomPartition(int arr[], int l, int r)
{
    int n = r-l+1;
    int pivot = rand() % n;
    swap(&arr[l + pivot], &arr[r]);
    return partition(arr, l, r);
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


int main()
{
    int n, a[1000];

    scanf("%d", &n);

    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);

    int k = kthSmallest(a,0,n-1,n/2);

    printf("\n\n%d\n\n", k);

    qSort(a, 0,  n-1);

    for(int i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}


