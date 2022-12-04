#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
  int data;
  Node* left;
  Node* right;

  Node(int d) {
    this->data=d;
    this->left=NULL;
    this->right=NULL;
  }
};

int find(int num,vector<int> &in)
{
  int n=in.size();

  for(int i=0;i<n;i++)
  {
    if(in[i]==num)
    return i;
  }
  return -1;
}

Node* solve(int s,int e,int &ind,vector<int> &post,vector<int> &in) {
  if(s>=e || ind <0)
  return NULL;

  Node* root = new Node(post[ind]);
  int newe=find(post[ind],in);
  ind = ind - 1;
  root->right = solve(newe+1,e,ind,post,in);
  root->left = solve(s,newe,ind,post,in);

  return root;
}

void inorder(Node* root) {
  if(!root)
  return ;

  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

void lot(Node* root)
{
  queue<Node*> q;
  q.push(root);
  q.push(NULL);

  while(!q.empty()) {
    Node* temp = q.front();
    q.pop();

    if(temp==NULL) {
      cout<<endl;
      if(!q.empty())
      q.push(NULL);
    }

    else {
      cout<<temp->data<<" ";

      if(temp->left)
      q.push(temp->left);

      if(temp->right)
      q.push(temp->right);
    }
  }
}

int main() {
 
 vector<int> post={8,6,5,2,1,3,4},in={8,5,6,4,2,3,1};
 int n=post.size(),ind = n-1;
 Node* root = solve(0,n,ind,post,in);
 
 inorder(root);
 cout<<endl;
 
 lot(root);
 
  return 0;
}