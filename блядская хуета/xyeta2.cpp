
#include <iostream>
#include <string>

#define MAXN (200000 + 5)

using std::cin, std::cout, std::string;



class Heap
{
private:

    int minHeap[MAXN];
    int maxHeap[MAXN];
    int posMin[MAXN];
    int posMax[MAXN];
    int values[MAXN];
    int sz;


public:

    Heap()
    {
        sz = 0;
    }

    void SwapMin(int i, int j)
    {
        int vi = minHeap[i], vj = minHeap[j];
        minHeap[i] = vj;
        minHeap[j] = vi;
        posMin[vi] = j;
        posMin[vj] = i;
    }

    void SwapMax(int i, int j)
    {
        int vi = maxHeap[i], vj = maxHeap[j];
        maxHeap[i] = vj;
        maxHeap[j] = vi;
        posMax[vi] = j;
        posMax[vj] = i;
    }

    void SiftUpMin(int i)
    {
        while (i > 1)
        {
            int p = i / 2;
            if (values[minHeap[p]] <= values[minHeap[i]])
                break;
            SwapMin(i, p);
            i = p;
        }
    }

    void SiftDownMin(int i)
    {
        while (2 * i <= sz)
        {
            int l = 2 * i, r = 2 * i + 1, smallest = l;
            if (r <= sz && values[minHeap[r]] < values[minHeap[l]])
                smallest = r;
            if (values[minHeap[i]] <= values[minHeap[smallest]])
                break;
            SwapMin(i, smallest);
            i = smallest;
        }
    }

    void SiftUpMax(int i)
    {
        while (i > 1)
        {
            int p = i / 2;
            if (values[maxHeap[p]] >= values[maxHeap[i]])
                break;
            SwapMax(i, p);
            i = p;
        }
    }

    void SiftDownMax(int i)
    {
        while (2 * i <= sz)
        {
            int l = 2 * i, r = 2 * i + 1, largest = l;
            if (r <= sz && values[maxHeap[r]] > values[maxHeap[l]])
                largest = r;
            if (values[maxHeap[i]] >= values[maxHeap[largest]])
                break;
            SwapMax(i, largest);
            i = largest;
        }
    }

    void Insert(int val)
    {
        sz++;
        values[sz] = val;
        minHeap[sz] = maxHeap[sz] = sz;
        posMin[sz] = posMax[sz] = sz;
        SiftUpMin(sz);
        SiftUpMax(sz);
        cout << "ok\n";
    }

    void ExtractMin()
    {
        if (sz == 0)
        {
            cout << "error\n";
            return;
        }
        int id = minHeap[1];
        int val = values[id];
        cout << val << "\n";

        SwapMin(1, sz);
        sz--;
        SiftDownMin(1);

        int pos = posMax[id];
        SwapMax(pos, sz + 1);
        if (pos <= sz)
        {
            SiftUpMax(pos);
            SiftDownMax(pos);
        }
    }

    void ExtractMax()
    {
        if (sz == 0)
        {
            cout << "error\n";
            return;
        }
        int id = maxHeap[1];
        int val = values[id];
        cout << val << "\n";

        SwapMax(1, sz);
        sz--;
        SiftDownMax(1);

        int pos = posMin[id];
        SwapMin(pos, sz + 1);
        if (pos <= sz)
        {
            SiftUpMin(pos);
            SiftDownMin(pos);
        }
    }

    void GetMin()
    {
        if (sz == 0)
            cout << "error\n";
        else
            cout << values[minHeap[1]] << "\n";
    }

    void GetMax()
    {
        if (sz == 0)
            cout << "error\n";
        else
            cout << values[maxHeap[1]] << "\n";
    }

    void Size()
    {
        cout << sz << "\n";
    }

    void Clear()
    {
        sz = 0;
        cout << "ok\n";
    }
};

int main()
{

    int n;
    cin >> n;

    Heap h;

    for (int i = 0; i < n; ++i)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "insert")
        {
            int n;
            cin >> n;
            h.Insert(n);
        }
        else if (cmd == "extract_min")
        {
            h.ExtractMin();
        }
        else if (cmd == "extract_max")
        {
            h.ExtractMax();
        }
        else if (cmd == "get_min")
        {
            h.GetMin();
        }
        else if (cmd == "get_max")
        {
            h.GetMax();
        }
        else if (cmd == "size")
        {
            h.Size();
        }
        else if (cmd == "clear")
        {
            h.Clear();
        }
    }

    return 0;
}

