//Вычислить количество узлов в самом широком слое декартового дерева и количество узлов в самом широком слое наивного дерева поиска. Вывести их разницу.
#include <iostream>
#include <vector>
#include <fstream>
#include <stack>
#include <algorithm>

using namespace std;

struct CNode
{
  long long int data = 0;
  CNode* left = NULL;
  CNode* right = NULL;
  CNode (int d) : data(d) {}
};

struct CTreapNode
{
  long long int x = 0;
  long long int y = 0;
  CTreapNode* left = NULL;
  CTreapNode* right = NULL;
  CTreapNode* parent = NULL;
  CTreapNode(long long int X, long long int Y);
};

CTreapNode::CTreapNode(long long int X, long long int Y)
{
  x = X;
  y = Y;
}

class BinaryTree
{
 private:
  CNode* first;
 public:
  BinaryTree();
  ~BinaryTree();
  void Insert(long long int value);
  void Delete(CNode* node);
  int Width();
};

class Treap
{
 private:
  CTreapNode* first;
 public:
  Treap();
  ~Treap();
  void InsertTreapNode(CTreapNode* value, CTreapNode*& first);
  void Insert(long long int X, long long int Y);
  void Delete(CTreapNode* node);
  int Width();
  void Split(long long int key, CTreapNode* first, CTreapNode*& left_tree, CTreapNode*& right_tree);
};

void Treap::Insert(long long int X, long long int Y)
{
  CTreapNode* A = new CTreapNode(X, Y);
  InsertTreapNode(A, first);
}

void Treap::InsertTreapNode(CTreapNode* value, CTreapNode*& first)
{
  if (first == NULL)
  {
    first = value;
    return;
  }
  if (value->y < first->y)
  {
    if(value->x < first->x)
    {
      InsertTreapNode(value, first->left);
    }
    else
    {
      InsertTreapNode(value, first->right);
    }
    return;
  }
  Split(value->x, first, value->left, value->right);
  first = value;
}



void Treap::Split(long long int key, CTreapNode* first, CTreapNode*& left_tree, CTreapNode*& right_tree )
{
  if(first == NULL)
  {
    left_tree = NULL;
    right_tree = NULL;
  }
  else if(key < first->x)
  {
    Split(key, first->left, left_tree, first->left);
    right_tree = first;
  }
  else
  {
    Split(key, first->right, first->right, right_tree );
    left_tree = first;
  }
}

int Treap::Width()
{
  if (first == NULL)
  {
    return 0;
  }
  stack <CTreapNode*> Queue;
  Queue.push(first);
  int result = 0;
  while(Queue.size() != 0)
  {
    if (result < Queue.size())
    {
      result = Queue.size();
    }
    stack <CTreapNode*> NextLevel;
    while(Queue.size() != 0)
    {
      CTreapNode* node = Queue.top();
      Queue.pop();
      if (node->left != NULL)
      {
        NextLevel.push(node->left);
      }
      if (node->right != NULL)
      {
        NextLevel.push(node->right);
      }
    }
    Queue = NextLevel;
  }
  return result;
}

Treap::Treap()
{
  first = NULL;
}

void Treap::Delete(CTreapNode* node)
{
  if (node == NULL)
  {
    return;
  }
  Delete(node->right);
  Delete(node->left);
  delete node;
}

Treap::~Treap()
{
  Delete(first);
}

int BinaryTree::Width()
{
  if (first == NULL)
  {
    return 0;
  }
  stack <CNode*> Queue;
  Queue.push(first);
  int result = 0;
  while(Queue.size() != 0)
  {
    if (result < Queue.size())
    {
      result = Queue.size();
    }
    stack <CNode*> NextLevel;
    while(Queue.size() != 0)
    {
      CNode* node = Queue.top();
      Queue.pop();
      if (node->left != NULL)
      {
        NextLevel.push(node->left);
      }
      if (node->right != NULL)
      {
        NextLevel.push(node->right);
      }
    }
    Queue = NextLevel;
  }
  return result;
}

void BinaryTree::Delete(CNode* node)
{
  if (node == NULL)
  {
    return;
  }
  Delete(node->right);
  Delete(node->left);
  delete node;
}

BinaryTree::BinaryTree()
{
  first = NULL;
}

BinaryTree::~BinaryTree()
{
  Delete(first);
}

void BinaryTree::Insert(long long int value)
{
  CNode* node = first;
  if (node == NULL)
  {
    first = new CNode(value);
    return;
  }

  while ((node->data <= value && node->right != NULL) || (node->data > value && node->left != NULL))
  {
    if (node->data <= value)
    {
      node = node->right;
    }
    else
    {
      node = node->left;
    }
  }
  if (node->data <= value)
  {
    node->right = new CNode(value);
  }
  else
  {
    node->left = new CNode(value);
  }
}

int main()
{
  BinaryTree A;
  Treap B;
  int n;
  cin >> n;
  long long int x = 0;
  long long int y = 0;
  while(n != 0)
  {
    --n;
    cin >> x >> y;
    A.Insert(x);
    B.Insert(x, y);
  }
  cout << B.Width() - A.Width() << endl;
  return 0;
}