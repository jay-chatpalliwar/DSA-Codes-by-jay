#include <bits/stdc++.h>
using namespace std;

/*In the array(where heap is implemented),indices from (size/2+1) to size
have values of root nodes. */

/*We have followed 1 based indexing--> left node = 2*i ,right node = 2*i + 1
For 0 based indexing --> left node = 2*i + 1 , right node = 2*i + 2 */

/*STL also has a data structure "Priority Queue" which is by default a Max-Heap
.If Min-Heap is needed we can use the following definition of Priority Queue:
priority_queue<T,vector<T>,<greater>> pq;
*/

class Heap
{
public:
    int arr[100];
    int size = 0;

    Heap() { arr[0] = -1; }

    void insert(int val)
    {
        size = size + 1;
        arr[size] = val;

        int index = size;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[index] > arr[parent])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
                return;
        }
    }

    void print()
    {
        for (int i = 1; i < size + 1; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void remove()
    {
        /* Always the root node is deleted and then adjustments are
         made to make the CBT a Max-heap. */

        arr[1] = arr[size];
        size = size - 1;

        int i = 1;
        while (i < size)
        {
            int left = 2 * i, right = 2 * i + 1;

            if (left < size && arr[i] < arr[left])
            {
                swap(arr[i], arr[left]);
                i = left;
            }

            else if (right < size && arr[i] < arr[right])
            {
                swap(arr[i], arr[right]);
                i = right;
            }

            else
                return;
        }
    }
};

void heapify(int arr[], int n, int i)
{
    int curr = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && arr[i] < arr[left])
    {
        curr = left;
    }

    else if (right <= n && arr[i] < arr[right])
    {
        curr = right;
    }

    if (curr != i)
    {
        swap(arr[curr], arr[i]);
        heapify(arr, n, curr);
    }
}

void HeapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
}

int main()
{
    // Heap h;
    // h.insert(55);
    // h.insert(60);
    // h.insert(65);
    // h.insert(70);
    // h.insert(45);
    // h.insert(50);
    // h.print();
    // h.remove();
    // h.print();

    int arr[6] = {-1, 52, 55, 52, 53, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, 5, i);
    }
    cout << "Printing the array :" << endl;
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;

    HeapSort(arr, n);
    cout << "Printing the sorted array:";
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}