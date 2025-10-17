#include <iostream>
#include <stdio.h>

void choice_sort(int *a, int n);
void merge_sort(int *a, int *res, int l, int r);

int main(void)
{
    int n = 10;
    int a[] = {5, 4, 3, 2, 1, 5, 4, 3, 2, 1};
    int *b = (int*)malloc(sizeof(int) * n);

    merge_sort(a, b, 0, 9);

    for (size_t i = 0; i < n; i++)
    {
        std::cout << a[i] << ' ';
    }
    

    return 0;
}

void sort(int *a, int *res, int l, int r)
{

    if (l >= r)
        return;

    int m = (l + r) / 2;

    sort(a, l, m, res);
    sort(a, m + 1, r, res);

    int i = l, j = m+1, k = 0;

    while (k < (r - l + 1) && (i <= m) && (j <= r))
    {
        if ((a)[i] <= (a)[j])
            res[k++] = (a)[i++];
        if ((a)[j] < (a)[i])
            res[k++] = (a)[j++];
    }

    while (i <= m)
    {
        res[k++] = (a)[i++];
    }
    while (j <= r)
    {
        res[k++] = (a)[j++];
    }

    k = 0;
    for (int i = l; i <= r; i++)
    {
        a[i] = res[k++];
    }
}