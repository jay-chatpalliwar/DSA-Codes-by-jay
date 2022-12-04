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

Node* solve(int s,int e,int &ind,vector<int> &pre,vector<int> &in) {
  if(s>=e || ind <0)
  return NULL;

  Node* root = new Node(pre[ind]);
  int newe=find(pre[ind],in);
  ind = ind + 1;
  root->left = solve(s,newe,ind,pre,in);
//   ind = ind + 1;
  root->right = solve(newe+1,e,ind,pre,in);

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
 
 vector<int> pre={5,2,7,1,6,4,3},in={7,2,1,5,4,6,3};
 int n=pre.size(),ind = 0;
 Node* root = solve(0,n,ind,pre,in);
 
 inorder(root);
 cout<<endl;

 lot(root);
 
  return 0;
}