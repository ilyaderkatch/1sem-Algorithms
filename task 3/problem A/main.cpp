//Âûâåäèòå ıëåìåíòû â ïîğÿäêå post-order (ñíèçó ââåğõ).
#include <iostream>
#include <vector>
#include <fstream>
#include <stack>

using namespace std;

struct CNode
{
  long long int data = 0;
  CNode* left = NULL;
  CNode* right = NULL;
  CNode* parent = NULL;
  CNode (int d) : data(d) {}
};

class BinaryTree
{
 private:
  CNode* first;
 public:
  BinaryTree();
  ~BinaryTree();
  void Insert(long long int value);
  void Delete(CNode* node);
  void OutputTree();
};

void BinaryTree::Delete(CNode* node)
{
  if(node->left != NULL)
  {
    Delete(node->left);
  }
  if(node->right != NULL)
  {
    Delete(node->right);
  }
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

void BinaryTree::OutputTree()
{
  stack <pair <CNode*, bool> > Queue;
  Queue.push({first, 1});
  while(Queue.size() != 0)
  {
    pair <CNode*, bool> node = Queue.top();
    Queue.pop();
    if (node.first->right == NULL && node.first->left == NULL)
    {
      node.second = 0;
    }

    if (node.second == 0)
    {
      cout << node.first->data << " ";
    }
    else
    {
      node.second = 0;
      Queue.push(node);
      if (node.first->right != NULL)
      {
        Queue.push({node.first->right, 1});
      }
      if (node.first->left != NULL)
      {
        Queue.push({node.first->left, 1});
      }
    }
  }
}

int main()
{
  BinaryTree A;
  int n;
  cin >> n;
  long long int a = 0;
  while(n != 0)
  {
    --n;
    cin >> a;
    A.Insert(a);
  }
  A.OutputTree();
  return 0;
}
