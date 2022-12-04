#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(Node *root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void level(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }

        else
        {
            cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}

Node *buildbst(Node *root, int x)
{
    if (root == NULL)
    {
        root = new Node(x);
        return root;
    }

    if (root->data > x)
        root->left = buildbst(root->left, x);

    else
        root->right = buildbst(root->right, x);

    return root;
}

void takeinput(Node *&root)
{
    int x;
    cin >> x;

    while (x != -1)
    {
        root = buildbst(root, x);
        cin >> x;
    }
}

Node *minvalue(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
        temp = temp->left;

    return temp;
}

Node *maxvalue(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
        temp = temp->right;

    return temp;
}

void BST_To_Sorted_LinkedList(Node *root)
{
    // Store the Inorder traversal of given BST in an array and manually create
    //  a Tree from this array..
}

int main()
{
    Node *root = NULL;

    cout << "Enter the data:" << endl;
    takeinput(root);

    level(root);
    BST_To_Sorted_LinkedList(root);
    Node *temp = root;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
    inorder(root);
    //     cout << endl
    //          << minvalue(root)->data << endl;
    //     cout << endl
    //          << maxvalue(root)->data << endl;
}