#include <iostream>
#include <vector>
#include <string>

using std::vector, std::swap, std::cin, std::cout;

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
    Heap h;
    int n;
    cin >> n;

    int *a = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        h.Insert(a[i]);
    }

    for (int i = n-1; i >= 0; i--)
    {
       a[i] = h.GetMax();
       h.ExtractMax();
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "";
    }
    
    
    

    
    

    return 0;
}
