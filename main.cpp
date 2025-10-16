#include <iostream>
#include <chrono>
#include <fstream>
#include <stdlib.h>

using std::cin, std::cout, std::ios;

void bubble_sort(int *a, int n);
void insertion_sort(int *a, int n);
void check_sort(void (*func)(int *, int), int *a, int *b, int n);
void choice_sort(int *a, int n);

int main(void)
{
    srand(time(NULL));
    int n;
    cin >> n;

    int *a = new int[n];
    int *b = new int[n];

    for (size_t i = 0; i < n; i++)
    {
        b[i] = rand();
    }
    
    std::ofstream f("results.csv", ios::out);
    
    check_sort(bubble_sort, a, b, n);
    check_sort(insertion_sort, a, b, n);
    check_sort(choice_sort, a, b, n);


    return 0;

}

void check_sort(void (*func)(int *, int), int *a, int *b, int n)
{
    std::ofstream f("results.csv", ios::out | ios::app);


    for (size_t k = 1; k <= n; k++)
    {
        for (size_t i = 0; i < k; i++)
        {
            a[i] = b[i];
        }
        
        auto start = std::chrono::high_resolution_clock::now();

        func(a, k);

        auto end = std::chrono::high_resolution_clock::now();

        auto nsec = end - start;
        f << nsec.count() << ' ';
        
    }
    f << '\n';
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



void insertion_sort(int *a, int n)
{
    for (size_t i = 1; i < n; i++)
    {
        int j = i - 1;
        while (j >= 0 && (a[j] > a[j+1]))
        {
            int tmp = a[j];
            a[j] = a[j+1];
            a[j+1] = tmp;
            j--;
        }
    }
    
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