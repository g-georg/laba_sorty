#include <iostream>

void choice_sort(int *a, int n);

int main(void)
{
    int a[5] = {5, 4, 3, 2, 1};

    choice_sort(a, 5);

    for (size_t i = 0; i < 5; i++)
    {
        std::cout << a[i] << ' ';
    }
    

    return 0;
}

void choice_sort(int *a, int n)
{
    for (size_t i = 0; i < n-1; i++)
    {
        for (size_t j = i+1; j < n; j++)
        {
            if (a[i] >  a[j])
            {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
        
    }
    
}