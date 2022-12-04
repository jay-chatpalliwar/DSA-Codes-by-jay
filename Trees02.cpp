#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;
};

class TypesOfTraversal
{
    public:

    //ZIG-ZAG TRAVERSAL*******
    vector <int>  solve(Node* root)
    {
        vector <int> ans;
        if(root==NULL)
        return ans;
        
        queue<Node*> q;
        q.push(root);
        
        bool ltor=true;
        
        while(!q.empty())
        {
            int n=q.size();
            vector <int> v(n);
            
            for(int i=0;i<n;i++)
            {
                Node* temp=q.front();
            q.pop();
            
                int index=ltor?i:n-i-1;
                v[index]=temp->data;
                
                 if(temp->left)
            q.push(temp->left);
            
            if(temp->right)
            q.push(temp->right);
            }
            ltor=!ltor;
        
            for(auto it:v)
            ans.push_back(it);
        }
        return ans;
        
    }
    
   //BOUNDARY TREE TRAVERSAL*******
   void leftpart(Node* root,vector<int> &ans)
    {
        if(root==NULL)
        return;
        
        if(root->left==NULL && root->right==NULL)
        return;
        
        ans.push_back(root->data);
        
        if(root->left)
        leftpart(root->left,ans);
        
        else
        leftpart(root->right,ans);
        
    }
    
    void leafnode(Node* root ,vector<int> &ans)
    {
        if(root==NULL)
        return;
        
        if(root->left==NULL && root->right==NULL)
        ans.push_back(root->data);
        
        leafnode(root->left,ans);
        leafnode(root->right,ans);
    }
    
    void rightpart(Node* root,vector<int> &ans)
    {
        if(root==NULL)
        return;
        
        if(root->left==NULL && root->right==NULL)
        return;
        
        if(root->right)
        rightpart(root->right,ans);
        
        else
        rightpart(root->left,ans);
        
        ans.push_back(root->data);
    }
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        ans.push_back(root->data);
        leftpart(root->left,ans);
        leafnode(root->left,ans);
        leafnode(root->right,ans);
        rightpart(root->right,ans);
        
        return ans;
    }
};
   int main()
{
    return 0;
}