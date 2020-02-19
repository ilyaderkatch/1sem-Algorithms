//Дана последовательность целых чисел a1...an и натуральное число k, такое что для любых i, j: если j >= i + k, то a[i] <= a[j]. Требуется отсортировать последовательность. Последовательность может быть очень длинной. Время работы O(n * log(k)). Доп. память O(k). Использовать слияние.

#include <iostream>
#include <vector>

using namespace std;

void Merge(vector <int> &first, vector <int> &second, vector <int> &result)
{
  int i = 0;
  int j = 0;
  while(i != first.size() && j != second.size())
  {
    if (first[i] <= second[j])
    {
      result.push_back(first[i]);
      ++i;
    }
    else
    {
      result.push_back(second[j]);
      ++j;
    }
  }
  while(i != first.size())
  {
    result.push_back(first[i]);
    ++i;
  }
  while(j != second.size())
  {
    result.push_back(second[j]);
    ++j;
  }
}

void MergeSort(vector <int> &A)
{
  if (A.size() == 1)
  {
    return;
  }
  vector <int> first;
  vector <int> last;
  for (int i = 0; i < A.size() / 2; ++i)
  {
    first.push_back(A[i]);
  }
  for (int j = A.size() / 2; j < A.size(); ++j)
  {
    last.push_back(A[j]);
  }
  MergeSort(first);
  MergeSort(last);
  A.clear();
  Merge(first, last, A);
}

void InputArray(vector <int> &A, int k)
{
  for (int i = 0; i < k; ++i)
  {
    int a;
    cin >> a;
    A.push_back(a);
  }
}

void OutputArray(vector <int> &A, int k)
{
  for (int i = 0; i < k; ++i)
  {
    cout << A[i] << " ";
  }
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector <int> result;
  InputArray(result, min(n, k));
  MergeSort(result);
  n -= k;
  while(n > 0)
  {
    vector <int> New;
    InputArray(New, min(n, k));
    MergeSort(New);
    vector <int> Sort;
    Merge(New, result, Sort);
    result = Sort;
    OutputArray(result, k);
    result.erase(result.begin(), result.begin() + k);
    n -= k;
  }
  OutputArray(result, result.size());
  return 0;
}