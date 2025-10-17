#include <iostream>
#include <stdio.h>

void my_qsort(int *a, int l, int r);

int main(void)
{
    int n = 10;
    int a[] = {5, 4, 3, 2, 1, 5, 4, 3, 2, 1};


    my_qsort(a, 0, 9);

    for (size_t i = 0; i < n; i++)
    {
        std::cout << a[i] << ' ';
    }
    

    return 0;
}


void my_qsort(int *a, int l, int r)
{
    if (l >= r)
        return;
        int i_p = l + rand() % (r - l + 1);
        int pivot = a[i_p];

        int i = l, j = r;
        while (i <= j)
        {
            while (a[i] < pivot)
                i++;
            while (a[j] > pivot)
                j--;
            if (i <= j)
            {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
                i++;
                j--;
            }
            my_qsort(a, l, j);
            my_qsort(a, i, r);
        }
}