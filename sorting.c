#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

void Bubble(int A[], int n)

{
    int i, j, flag = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

void Insertion(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j > -1 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

void Selection(int a[], int n)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        k = i;
        for (j = i; j < n; j++)
        {
            if (a[j] < a[k])
            {
                k = j;
            }
        }
        swap(&a[i], &a[k]);
    }
}

int partition(int a[], int l, int h)
{
    int pivot = a[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (a[i] <= pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i < j)
        {
            swap(&a[i], &a[j]);
        }
    } while (i < j);
    swap(&a[l], &a[j]);
    return j;
}

void quick(int a[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(a, l, h);
        quick(a, j + 1, h);
        quick(a, l, j);
    }
}

void Merge(int a[], int l, int h, int mid)
{
    int i = l, j = mid + 1, k = l;
    int c[100];
    while (i <= mid && j < h)
    {
        if (a[i] < a[j])
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = a[j++];
        }
    }
    for (; i <= mid; i++)
    {
        c[k++] = a[i];
    }
    for (; j < h; j++)
    {
        c[k++] = a[j];
    }

    for (i = l; i < h; i++)
    {
        a[i] = c[i];
    }
}

void IMergeSort(int A[], int n)
{
    int p, l, h, mid, i;

    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i + p - 1 <= n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            Merge(A, l, mid, h);
        }
    }
    if (p / 2 < n)
        Merge(A, 0, p / 2 - 1, n);
}

void shell(int a[], int n)
{
    int gap, temp, i, j;

    for (gap = n / 2; gap >= 1; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = a[i];
            j = i - gap;
            while (j >= 0 && a[j] > temp)
            {
                a[j + gap] = a[j];
                j = j - gap;
            }
            a[j + gap] = temp;
        }
        
    }
}

int main()
{
    int a[] = {5, 6, 2, 77, 3, 56, 67, 10, 43}, n = 9;

    // quick(a, 0, 10);
    // Bubble(a, n);
    //Insertion(a,n);
    Selection(a, n);
    // IMergeSort(a, 9);
    //shell(a, n);
    int i;
    for (i = 0; i < n ; i++)
    {
      printf("%d\t", a[i]);
    }
    return 0;
}