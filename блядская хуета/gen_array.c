#include <time.h>
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    srand(time(NULL));

    int n;
    scanf("%d", &n);

    FILE *file = fopen("array.csv", "w");
    if (!file)
        perror("Failed to open file");

    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%d ", rand());
    }
    
    
    fclose(file);


    return 0;
    
}