#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble_sort(int *a, int n);

int main(void)
{
    FILE *file = fopen("array.csv", "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    size_t cnt = 0;
    int _tmp;
    while (fscanf(file, "%d", &_tmp) > 0)
        cnt++;

    printf("%zu elements\n", cnt);

    int *array = malloc(sizeof(int) * cnt);
    rewind(file);
    for (size_t i = 0; i < cnt; i++)
        fscanf(file, "%d", &array[i]);
    fclose(file);

    int *tmp = malloc(sizeof(int) * cnt);
    struct timespec start, end;
    FILE *time_results = fopen("results.csv", "w");

    for (size_t k = 1; k <= cnt; k++) {
        memcpy(tmp, array, sizeof(int) * k);

        clock_gettime(CLOCK_MONOTONIC, &start);
        bubble_sort(tmp, k);
        clock_gettime(CLOCK_MONOTONIC, &end);

        long long nsec = (end.tv_sec - start.tv_sec) * 1000000000LL +
                         (end.tv_nsec - start.tv_nsec);

        fprintf(time_results, "%lld ", nsec);
    }

    fclose(time_results);
    free(array);
    free(tmp);
    return 0;
}

void bubble_sort(int *a, int n)
{
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}
