#include "sort.h"

void ShellSort(int *a)
{
    int group = MAX_LEN/2;
    int i, j;
    int temp = 0;

    while(group > 0)
    {
        for(i = group; i < MAX_LEN; i++)
        {
            j = i;
            temp = a[j];

            if(a[j] < a[j-group])
            {
                while(j-group >= 0 && a[j-group] > temp)
                {
                    a[j] = a[j-group];
                    j -= group;
                }
                a[j] = temp;
            }
        }
        group /= 2;
    }
}

int partion(int *a , int low, int high)
{
    int star = 0;
    star = a[low];

    while(low < high)
    {
        while(a[high] > star && low < high)
        {
            high--;
        }
        a[low] = a[high];
        while(a[low] < star && low < high)
        {
            low++;
        }
        a[high] = a[low];
    }
    a[low] = star;

    return low;

}

void Quick(int *a , int low, int high)
{
    int mid = 0;

    if(low >= high)
    {
        return;
    }
    mid = partion(a, low, high);

    if(low < mid)
    {
        Quick(a, low, mid-1);
    }
    if(high > mid)
    {
        Quick(a, mid+1, high);
    }
}

void QuickSort(int *a)
{
    int low = 0;
    int high = MAX_LEN-1;

    Quick(a, low, high);
}


void InsertSort(int *a)
{
    int i, j, m;

    for(i = 0; i < MAX_LEN-1; i++)
    {
        j = i+1;
        if(a[j] < a[i])
        {
            m = a[j];

            while( j > 0 && m <= a[j-1] )
            {
                a[j] = a[j-1];
                j--;
            }
            a[j] = m;
        }
    }
}

void BubbleSort(int *a)
{
    int i, j;

    for(i = 0; i < MAX_LEN-1; i++)
    {
        for(j = 0; j < MAX_LEN-i-1; j++)
        {
            if(a[j] < a[j+1])
            {
                a[j] = a[j]+a[j+1];
                a[j+1] = a[j]-a[j+1];
                a[j] = a[j]-a[j+1];
            }
        }
    }
}

void SelectSort(int *a)
{
    int i, j;

    for(i = 0; i < MAX_LEN - 1; i++)
    {
        for(j = i+1; j < MAX_LEN; j++)
        {
            if(a[i] > a[j])
            {
                a[i] += a[j];
                a[j] = a[i] - a[j];
                a[i] = a[i] - a[j];
            }
        }
    }
}

void mysort(int *a)
{
    ShellSort(a);
}



