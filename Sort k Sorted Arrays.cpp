#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    int row;
    int col;
    Node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>> &arr, int k)
{
    priority_queue<Node *, vector<Node *>, compare> mini;
    for (int i = 0; i < k; i++)
    {
        Node *temp = new Node(arr[i][0], i, 0);
        mini.push(temp);
    }

    vector<int> ans;
    while (!mini.empty())
    {
        Node *temp = mini.top();
        mini.pop();
        ans.push_back(temp->data);
        int i = temp->row;
        int j = temp->col;
        if (j + 1 < arr[i].size())
        {
            Node *next = new Node(arr[i][j + 1], i, j + 1);
            mini.push(next);
        }
    }
    return ans;
    // Write your code here.
}

int main()
{
    /* Here the parameter for mergeKSortedArrays function will be generated and
    the answer will be printed..
    IMP is the above function and classes that are written to merge K sorted array.
     */
}