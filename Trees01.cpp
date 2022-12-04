//Binary Trees--->
#include<iostream>
#include<queue>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* BuildTree(node* root)
{
   cout<<"Enter data:"<<endl;
   int data;
   cin>>data;
   root =new node(data);

   if(data==-1)
   return NULL;

   cout<<"Enter data to left of "<<data<<endl;
   root->left=BuildTree(root->left);

   cout<<"Enter data to right of "<<data<<endl;
   root->right=BuildTree(root->right);

   return root;
}

void LevelOrderTravers(node* root)
{
    queue<node* > q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        if(temp==NULL)
        {
          cout<<endl;

          if(!q.empty())
          q.push(NULL);
        }

        else
        {
            cout<<temp->data<<" ";

            if(temp->left)
            q.push(temp->left);

            if(temp->right)
            q.push(temp->right);
        }
    }
}

void Inorder(node* root)
{
    if(root==NULL)
    return;

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void Preorder(node* root)
{

    if(root==NULL)
    return;

    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(node* root)
{
    if(root==NULL)
    return;

    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}

void BuildTreelevelorder(node* &root)
{
    queue<node*> q;
    int data;
    cout<<"Enter root data:"<<endl;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();

        cout<<"Enter the left of "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata!=-1)
        {temp->left=new node(leftdata);
        q.push(temp->left);}

        cout<<"Enter the right of "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata!=-1)
        {temp->right=new node(rightdata);
        q.push(temp->right);}
    }
}
//1 2 3 6 -1 -1 5 -1 -1 4 -1 -1 -1
int main()
{
    node *root;
    /*root=BuildTree(root);
    cout<<"Displaying using recursive version ::"<<endl;
    // LevelOrderTravers(root);
    cout<<"Inorder::"<<endl;
    Inorder(root);
    cout<<"Preorder::"<<endl;
    Preorder(root);
    cout<<"Postorder::"<<endl;
    Postorder(root);*/
    BuildTreelevelorder(root);
    cout<<"Displaying binary trees using level order traversal::"<<endl;
    LevelOrderTravers(root);
    
    return 0;
}