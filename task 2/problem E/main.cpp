//Дан массив строк. Количество строк не больше 100000. Отсортировать массив методом поразрядной сортировки MSD по символам. Размер алфавита - 256 символов. Последний символ строки = ‘0’.

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

void InputVector (vector <string> &A)
{
  string s;
  while(in >> s)
  {
    A.push_back(s);
  }
}

void OutputVector(const vector <string> &A)
{
  for (int i = 0; i < A.size(); ++i)
  {
    cout << A[i] << endl;
  }
}

void CoutingSort(vector <string> &A, const int byte, const int first, const int last, vector <int> &C)
{
  for (int i = first; i < last; ++i)
  {
    ++C[A[i][byte]];
  }
  for (int i = 1; i < C.size(); ++i)
  {
    C[i] += C[i - 1];
  }
  vector <int> InArr;
  InArr = C;
  vector <string> B(last - first);
  for (int i = last - 1; i >= first; --i)
  {
    --InArr[A[i][byte]];
    B[InArr[A[i][byte]]] = A[i];
  }
  for (int i = first; i < last; ++i)
  {
    A[i] = B[i - first];
  }
}

void MSD(vector <string> &A, const int byte, const int first, const int last)
{
  if (last - first <= 1)
  {
    return;
  }
  vector <int> C(257, 0);
  CoutingSort(A, byte, first, last, C);
  for (int i = 1; i < C.size(); ++i)
  {
    MSD(A, byte + 1, first + C[i - 1], first + C[i]);
  }
}

int main()
{
  vector <string> S;
  InputVector(S);
  MSD(S, 0, 0, S.size());
  OutputVector(S);
  return 0;
}