#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

#include <stdlib.h>

using std::cin, std::cout, std::ios, std::vector, std::swap;

void bubble_sort(int *a, int n);
void insertion_sort(int *a, int n);
void check_sort(void (*func)(int *, int), int *a, int *b, int n);
void choice_sort(int *a, int n);
void test_merge_sort(int *a, int n);
void merge_sort(int *a, int *res, int l, int r);
void test_qsort(int *a, int n);
void my_qsort(int *a, int l, int r);
void mergesort(int *a, int n);
void heapsort(int *a, int n);

class Heap
{
private:
    vector<int> arr; 
public:
    Heap();

    size_t len()
    {
        return arr.size() - 1;
    }

    void SiftUp(int i)
    {
        int parent = i / 2;
        if (parent == 0)
            return;

        if (arr[i] > arr[parent])
        {
            swap(arr[i], arr[parent]);
            SiftUp(parent);
        }
    }

    void SiftDown(int i)
    {
        int n = arr.size();
        int l = 2 * i;
        int r = 2 * i + 1;
        int big = i;

        if (l < n && arr[l] > arr[big])
            big = l;
        if (r < n && arr[r] > arr[big])
            big = r;

        if (big != i)
        {
            swap(arr[i], arr[big]);
            SiftDown(big);
        }
    }

    void Insert(int key)
    {
        arr.push_back(key);
        SiftUp(arr.size() - 1);
    }

    void ExtractMax()
    {
        if (arr.size() <= 1)
            return;

        arr[1] = arr.back();
        arr.pop_back();

        if (arr.size() > 1)
            SiftDown(1);
    }

    int GetMax()
    {
        return arr[1];
    }
};

Heap::Heap()
{
    arr.push_back(0); 
}



int main(void)
{
    srand(time(NULL));
    int n;
    cin >> n;

    int *a = new int[n];
    int *b = new int[n];

    for (size_t i = 0; i < n; i++)
    {
        b[i] = n+1-i;
    }
    
    std::ofstream f("results.csv", ios::out);
    
    check_sort(bubble_sort, a, b, n);
    check_sort(insertion_sort, a, b, n);
    check_sort(choice_sort, a, b, n);
    check_sort(test_merge_sort, a, b, n);
    check_sort(test_qsort, a, b, n);
    check_sort(heapsort, a, b, n);


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

void test_merge_sort(int *a, int n)
{
    int *res = (int*)malloc(sizeof(int) * n);

    merge_sort(a, res, 0, n-1);

    free(res);
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

void test_qsort(int *a, int n)
{
    my_qsort(a, 0, n-1);
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
            
        }
        my_qsort(a, l, j);
        my_qsort(a, i, r);
}

void heapsort(int *a, int n)
{
    Heap h;
    for (int i = 0; i < n; i++)
    {
        h.Insert(a[i]);
    }

    for (int i = n-1; i >= 0; i--)
    {
        a[i] = h.GetMax();
        h.ExtractMax();
    }
    
    
}