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

void merge_sort(int *a, int *res, int l, int r)
{
    if (l >= r)
        return;
    merge_sort(a, res,  l, (l+r) / 2);
    merge_sort(a, res, (l+r) / 2 + 1, r);

    int k = l, i = l, j = (l+r) / 2 + 1;
    
    while ((i <= (l+r)/2) && (j <= r))
    {
        if (a[i] <= a[j]) {
            res[k++] = a[i++];
        }
        if (a[i] > a[j]) {
            res[k++] = a[j++];
        }
    }
    while (i <= (l+r)/2)
    {
        res[k++] = a[i++];
    }
    while (j <= r)
    {
        res[k++] = a[j++];
    }

    for (size_t i = l; i <= r; i++)
    {
        a[i] = res[i];
    }
    
    
    
    
}