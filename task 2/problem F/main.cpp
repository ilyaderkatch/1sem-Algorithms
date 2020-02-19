//шестая задача
#include <iostream>
#include <vector>
#include <fstream>
#include <stack>

using namespace std;

void InputArray(vector <int> &A)
{
  int a;
  while (cin >> a)
  {
    A.push_back(a);
  }
}

void OutputArray(vector <int> &A)
{
  for (int i = 9; i < A.size(); i += 10)
  {
    cout << A[i] << " ";
  }
  cout << endl;
}

int mean(const int a, const int b, const int c)
{
  return a + b + c - max(a, max(b, c)) - min(a, min(b, c));
}

int Partition(vector <int> &A, const int first, const int last)
{
  if (last - first <= 1)
  {
    return first;
  }
  swap(A[first], A[last - 1]);
  int pivot = A[last - 1];
  int i = first;
  int j = last - 2;
  while(i <= j)
  {
    while(A[i] < pivot)
    {
      ++i;
    }
    while(j >= first && !(A[j] < pivot))
    {
      --j;
    }
    if (i < j)
    {
      swap(A[i], A[j]);
      ++i;
      --j;
    }
  }
  swap(A[i], A[last - 1]);
  return i;
}

void QuickSort(vector <int> &A, stack< pair <int, int> > &Queue)
{
  while(Queue.size() != 0)
  {
    pair <int, int> section;
    section = Queue.top();
    Queue.pop();
    int part = Partition(A, section.first, section.second);
    if (part > section.first)
    {
      Queue.push({section.first, part});
    }
    if (part < section.second - 1)
    {
      Queue.push({part + 1, section.second});
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  vector <int> A;
  stack <pair <int, int> > Queue;
  InputArray(A);
  Queue.push({0, A.size()});
  QuickSort(A, Queue);
  OutputArray(A);
  return 0;
}