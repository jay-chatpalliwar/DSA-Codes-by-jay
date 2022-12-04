#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode()
  {
    this->data = 0;
    this->left = NULL;
    this->right = NULL;
  }

  TreeNode(int x)
  {
    this->data = x;
    this->left = NULL;
    this->right = NULL;
  }
};

TreeNode *BuiltTree(TreeNode *root)
{
  int val;
  cout << "Enter the data :" << endl;
  cin >> val;
  if (val == -1)
    return NULL;

  root = new TreeNode(val);

  cout << "Enter data left of " << val << endl;
  root->left = BuiltTree(root->left);

  cout << "Enter data right of " << val << endl;
  root->right = BuiltTree(root->right);

  return root;
}

void inorder(TreeNode *root)
{
  if (!root)
    return;

  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

void BuildTreeLevelOrder(TreeNode *&root)
{
  queue<TreeNode *> q;
  int val;
  cout << "Enter the data :" << endl;
  cin >> val;
  root = new TreeNode(val);
  q.push(root);

  while (!q.empty())
  {
    TreeNode *temp = q.front();
    q.pop();

    cout << "Enter data left of " << temp->data << endl;
    int lefty;
    cin >> lefty;

    if (lefty != -1)
    {
      temp->left = new TreeNode(lefty);
      q.push(temp->left);
    }

    cout << "Enter data right of " << temp->data << endl;
    int righty;
    cin >> righty;

    if (righty != -1)
    {
      temp->right = new TreeNode(righty);
      q.push(temp->right);
    }
  }
}

void LevelOrder(TreeNode *root)
{
  queue<TreeNode *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty())
  {
    TreeNode *temp = q.front();
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

void zig_zag(TreeNode *root)
{
  queue<TreeNode *> q;
  q.push(root);
  q.push(NULL);
  bool flag = true;

  while (!q.empty())
  {
    TreeNode *temp = q.front();
    q.pop();

    if (temp == NULL)
    {
      cout << endl;
      if (!q.empty())
        q.push(NULL);
    }

    else
    {
      vector<int> v;
      while (!q.empty())
      {
        v.push_back(temp->data);
        if (temp->left)
          q.push(temp->left);

        if (temp->right)
          q.push(temp->right);

        temp = q.front();
        if (temp == NULL)
          break;

        else
          q.pop();
      }
      if (flag)
      {
        for (int i = 0; i < v.size(); i++)
          cout << v[i] << " ";

        flag = !flag;
      }

      else
      {
        for (int i = v.size() - 1; i >= 0; i--)
          cout << v[i] << " ";

        flag = !flag;
      }
    }
  }
}

int height(TreeNode *root)
{
  if (root == NULL)
    return 0;

  if (root->left == NULL && root->right == NULL)
    return 1;

  int left = height(root->left) + 1;
  int right = height(root->right) + 1;

  return max(left, right);
}

void VerticalOrder(TreeNode *root)
{
  map<int, vector<int>> ans;
  int lvl = 0, hd = 0;

  queue<pair<TreeNode *, int>> q;
  q.push({root, 0});

  while (!q.empty())
  {
    pair<TreeNode *, int> frontnode = q.front();
    q.pop();
    TreeNode *temp = frontnode.first;
    int hd = frontnode.second;

    ans[hd].push_back(temp->data);

    if (temp->left)
      q.push({temp->left, hd - 1});

    if (temp->right)
      q.push({temp->right, hd + 1});
  }

  for (auto x : ans)
  {
    for (auto y : x.second)
      cout << y << " ";

    cout << endl;
  }
}

void VerticalOrder2(TreeNode *root)
{
  map<pair<int, int>, vector<int>> mp;

  queue<pair<TreeNode *, pair<int, int>>> q;
  q.push({root, {0, 0}});

  while (!q.empty())
  {
    pair<TreeNode *, pair<int, int>> node = q.front();
    q.pop();

    TreeNode *temp = node.first;
    int hd = node.second.first;
    int lvl = node.second.second;

    mp[{hd, lvl}].push_back(temp->data);

    if (temp->left)
      q.push({temp->left, {hd - 1, lvl + 1}});

    if (temp->right)
      q.push({temp->right, {hd + 1, lvl + 1}});
  }

  auto it = mp.begin();

  for (it; it != mp.end(); it++)
    sort(it->second.begin(), it->second.end());

  vector<vector<int>> ans;
  vector<int> temp;

  auto it1 = mp.begin();
  int x = it1->first.first;

  for (it1; it1 != mp.end(); it1++)
  {
    if (x == it1->first.first)
    {
      for (auto k : it1->second)
        temp.push_back(k);
    }

    else
    {
      ans.push_back(temp);
      temp.clear();
      x = it1->first.first;
      it1--;
    }
  }

  if (temp.size() != 0)
    ans.push_back(temp);

  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << endl;
  }
}

void MorrisTraversal_Inorder(TreeNode *root)
{
  TreeNode *curr = root, *prev;

  while (curr != NULL)
  {
    if (curr->left == NULL)
    {
      cout << curr->data << " ";
      curr = curr->right;
    }

    else
    {
      prev = curr->left;
      while (prev->right != NULL && prev->right != curr)
        prev = prev->right;

      if (prev->right == NULL)
      {
        prev->right = curr;
        curr = curr->left;
      }

      else
      {
        prev->right = NULL;
        cout << curr->data << " ";
        curr = curr->right;
      }
    }
  }
  cout << endl;
}

//---------------------------------------------------Start of Boundary Traversal
void BoundaryTraversal_C1(TreeNode *root, vector<int> &v)
{
  if (root == NULL)
    return;

  if (root->left == NULL && root->right == NULL)
    return;

  v.push_back(root->data);
  if (root->left)
    BoundaryTraversal_C1(root->left, v);

  else if (root->right)
    BoundaryTraversal_C1(root->right, v);
}

void BoundaryTraversal_C2(TreeNode *root, vector<int> &v)
{
  if (!root)
    return;

  if (root->left == NULL && root->right == NULL)
    v.push_back(root->data);

  BoundaryTraversal_C2(root->left, v);

  BoundaryTraversal_C2(root->right, v);
}

void BoundaryTraversal_C3(TreeNode *root, vector<int> &v)
{
  if (!root)
    return;

  if (root->left == NULL && root->right == NULL)
    return;
  if (root->right)
    BoundaryTraversal_C3(root->right, v);

  else if (root->left)
    BoundaryTraversal_C3(root->left, v);

  v.push_back(root->data);
}
//----------------------------------------------------End of Boundary Traversal

void BinaryTree_To_Linkedlist(TreeNode *root)
{
  while (root)
  {
    if (root->left)
    {
      TreeNode *curr = root->left;

      while (curr->right)
        curr = curr->right;

      curr->right = root->right;
      root->right = root->left;
      root->left = NULL;
    }
    root = root->right;
  }
}

int main()
{
  TreeNode *root;

  // inorder(root);

  BuildTreeLevelOrder(root);

  // LevelOrder(root);

  // zig_zag(root);

  // cout<<height(root)<<endl;

  // cout<<diameter(root)<<endl;

  // VerticalOrder(root);

  // VerticalOrder2(root);

  // MorrisTraversal_Inorder(root);

  // vector<int> ans;
  // ans.push_back(root->data);
  // BoundaryTraversal_C1(root->left, ans);
  // BoundaryTraversal_C2(root, ans);
  // BoundaryTraversal_C3(root->right, ans);
  // for (auto i : ans)
  //   cout << i << " ";
  // cout << endl;

  // BinaryTree_To_Linkedlist(root);
  // TreeNode *temp = root;
  // while (temp)
  // {
  //   cout << temp->data << " ";
  //   temp = temp->right;
  // }

  return 0;
}