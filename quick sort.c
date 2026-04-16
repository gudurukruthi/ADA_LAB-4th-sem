#include<stdio.h>

int partition(int a[], int low, int high)
{
    int i = low;
    int j = high+1;
    int pivot = a[low];
    int temp;
    while(i<j)
    {
        do
        {
            i++;
        }while(i<=high && a[i]<=pivot);
        do
        {
            j--;
        }while(a[j]>pivot);

        if(i<j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}
void quickSort(int a[], int low, int high)
{
    if(low<high)
    {
        int j =
    }
}
