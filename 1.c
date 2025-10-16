#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *a, int n);

int main(void)
{
    FILE *file = fopen("array.csv", "r");
        if (!file)
            perror("Failed to open file");

    size_t cnt = 0;
    int _tmp;

    while (fscanf(file, "%d", &_tmp) > 0)
        cnt++;

    printf("%zu elements\n", cnt);
    
    int *array = (int*)malloc(sizeof(int) * cnt);
    rewind(file);
    for (size_t i = 0; i < cnt; i++)
    {
        fscanf(file, "%d", &array[i]);
    }

    for (size_t i = 0; i < cnt; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);

    bubble_sort(array, cnt);

    clock_gettime(CLOCK_MONOTONIC, &end);

    long long nsec = (end.tv_sec - start.tv_sec) * 1000000000LL +
                     (end.tv_nsec - start.tv_nsec);

    for (size_t i = 0; i < cnt; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("%lld", nsec);
    return 0;
    
}


void bubble_sort(int *a, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n-i-1; j++)
        {
            if (a[j] > a[j+1])
            {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
        
    }
    
}
