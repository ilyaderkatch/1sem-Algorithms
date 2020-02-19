//высокая пирамида
#include <iostream>
#include <vector>

using namespace std;

void InputArray(vector <vector <long long> > &A)
{
  //изначальное заполнение
  for (int i = 0; i < A.size(); ++i)
  {
    A[1][i] = 1;
    A[0][i] = 1;
  }
  for (int j = 1; j < A.size(); ++j)
  {
    A[j][1] = 1;
    A[j][0] = 1;
  }
  //динамически заполняем
  for (int i = 2; i < A.size(); ++i)
  {
    for (int j = 2; j < A[i].size(); ++j)
    {
      if (i >= j)
      {
        A[i][j] = A[i - j][j] + A[i][j - 1];
      }
      else
      {
        A[i][j] = A[i][j - 1];
      }
    }
  }
}

int main()
{
  long long n;
  cin >> n;
  vector <vector <long long> > A(n + 1, vector <long long> (n + 1, 0));
  InputArray(A);
  cout << A[n][n] << endl;
  return 0;
}
