//В большой IT-фирме есть только одна переговорная комната. Желающие посовещаться заполняют заявки с желаемым временем начала и конца. Ваша задача определить максимальное количество заявок, которое может быть удовлетворено. Число заявок ≤ 100000
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

void InputArray(vector <pair <int, int> > &A)
{
  pair <int, int> Time;
  while (in >> Time.second)
  {
    in >> Time.first;
    A.push_back(Time);
  }
}

int main()
{
  vector <pair<int, int> > A;
  InputArray(A);
  sort(A.begin(), A.end());
  int result = 0;
  int last = A[0].second;
  for (int i = 0; i < A.size(); ++i)
  {
    if (A[i].second >= last)
    {
      ++result;
      last = A[i].first;
    }
  }
  out << result << endl;
  return 0;
}
