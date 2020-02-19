//Каждая строка содержащит команду добавления или удаления натуральных чисел, а также запрос на получение k-ой порядковой статистики
#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
  Node* left = NULL;
  Node* right = NULL;
  int data = 0;
  int counter = 1;
  unsigned char height = 1;
  Node(int value);
};

Node::Node(int value)
{
  data = value;
}

class AvlTree
{
 private:
  Node* root;

  //базовый функционал - приват
  void Delete(Node* node);
  Node* Find(Node* start, int key);
  void UpdateHeight(Node* node);
  unsigned char HeightOut(Node* node);
  int BFactor(Node* node);
  //повороты
  Node* RightRotate(Node* node);
  Node* LeftRotate(Node* node);
  //балансировка дерева
  Node* Balance(Node* node);
  // добавление элемента - приват
  Node* SubInsert(Node* node, int key);
  // удаление элемента - приват
  Node* FindMin(Node* node);
  Node* SwapForDelete(Node* node);
  Node* DeleteNode(Node* node, int key);
  Node* DeleteMin(Node* node);
  // функции для вывода порядковой статистики - приват
  int CounterOut(Node* node);
  Node* SubFindStatistics(Node* node, int num);

 public:
  //базовый функционал
  AvlTree();
  ~AvlTree();
  // добавление элемента
  void Insert(int key);
  // удаление элемента
  void DeleteKey(int key);
  // функции для вывода порядковой статистики
  int FindStatistics(int num);
};

//статистика

int AvlTree::FindStatistics(int num)
{
  return SubFindStatistics(root, num)->data;
}

Node* AvlTree::SubFindStatistics(Node* node, int num)
{
  //cout << node << endl;
  //cout << node->data << " " << node->counter << endl;
  if (num == CounterOut(node->left))
  {
    return node;
  }
  if (num < CounterOut(node->left))
  {
    return SubFindStatistics(node->left, num);
  }
  else
  {
    return SubFindStatistics(node->right, num - CounterOut(node->left) - 1);
  }
}

//удаление элемента
void AvlTree::DeleteKey(int key)
{
  if (Find(root, key) == NULL)
  {
    return;
  }
  root = DeleteNode(root, key);
}

Node* AvlTree::DeleteMin(Node* node)
{
  if (node->left == NULL)
  {
    return node->right;
  }
  node->left = DeleteMin(node->left);
  UpdateHeight(node);
  Balance(node);
}


Node* AvlTree::DeleteNode(Node* node, int key)
{
  if (node == NULL)
  {
    return NULL;
  }
  if (node->data < key)
  {
    node->right = DeleteNode(node->right, key);
  }
  else if (node->data > key)
  {
    node->left = DeleteNode(node->left, key);
  }
  else
  {
    Node* left_child = node->left;
    Node* right_child = node->right;
    delete node;
    if (right_child == NULL)
    {
      return left_child;
    }
    Node* new_node = FindMin(right_child);
    new_node->right = DeleteMin(right_child);
    new_node->left = left_child;
    UpdateHeight(new_node);
    return Balance(new_node);
  }
  UpdateHeight(node);
  return Balance(node);
}

Node* AvlTree::FindMin(Node* node)
{
  if (node->left == NULL)
  {
    return node;
  }
  return FindMin(node->left);
}


//добавление элемента
void AvlTree::Insert(int key)
{
  root = SubInsert(root, key);
}

Node* AvlTree::SubInsert(Node* node, int key)
{
  if (node == NULL)
  {
    return new Node(key);
  }
  if (node->data < key)
  {
    node->right = SubInsert(node->right, key);
  }
  else
  {
    node->left = SubInsert(node->left, key);
  }
  UpdateHeight(node);
  return Balance(node);
}

//балансировка дерева
Node* AvlTree::Balance(Node* node)
{
  //cout << node->data << " " << BFactor(node) << endl;
  if (BFactor(node) == 2)
  {
    if (BFactor(node->left) < 0)
    {
      node->left = LeftRotate(node->left);
    }
    return RightRotate(node);
  }
  else if (BFactor(node) == -2)
  {
    if (BFactor(node->right) > 0)
    {
      node->right = RightRotate(node->right);
    }
    return LeftRotate(node);
  }
  return node;
}

//повороты

Node* AvlTree::RightRotate(Node* node)
{
  Node* left_child = node->left;
  node->left = left_child->right;
  left_child->right = node;
  UpdateHeight(node);
  UpdateHeight(left_child);
  return left_child;
}

Node* AvlTree::LeftRotate(Node* node)
{
  Node* right_child = node->right;
  node->right = right_child->left;
  right_child->left = node;
  UpdateHeight(node);
  UpdateHeight(right_child);
  return right_child;

}

//конструктор, деструктор, вспомогательные функции для работы с классом: поиск, обновление значений приватной части

int AvlTree::BFactor(Node* node)
{
  return HeightOut(node->left) - HeightOut(node->right);
}

unsigned char AvlTree::HeightOut(Node* node)
{
  if (node == NULL)
  {
    return 0;
  }
  return node->height;
}

int AvlTree::CounterOut(Node* node)
{
  if (node == NULL)
  {
    return 0;
  }
  return node->counter;
}

void AvlTree::UpdateHeight(Node* node)
{
  node->height = max(HeightOut(node->left), HeightOut(node->right)) + 1;
  node->counter = CounterOut(node->left) + CounterOut(node->right) + 1;
}

Node* AvlTree::Find(Node* start, int key)
{
  if (start == NULL)
  {
    return NULL;
  }
  if (start->data > key)
  {
    return Find(start->left, key);
  }
  else if (start->data < key)
  {
    return Find(start->right, key);
  }
  return start;
}

AvlTree::AvlTree()
{
  root = NULL;
}

void AvlTree::Delete(Node* node)
{
  if (node == NULL)
  {
    return;
  }
  Delete(node->right);
  Delete(node->left);
  delete node;
}

AvlTree::~AvlTree()
{
  Delete(root);
}

int main()
{
  AvlTree A;
  int n;
  cin >> n;
  int a, b;
  while(n != 0)
  {
    --n;
    cin >> a >> b;
    if (a < 0)
    {
      A.DeleteKey(-a);

    }
    else
    {
      A.Insert(a);
    }
    cout << A.FindStatistics(b) << endl;
  }

}
