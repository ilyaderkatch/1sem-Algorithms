//На числовой прямой окрасили N отрезков. Известны координаты левого и правого концов каждого отрезка [Li, Ri]. Найти сумму длин частей числовой прямой, окрашенных ровно в один слой.
#include <iostream>
#include <vector>

using namespace std;

struct point
{
  int X = 0;
  bool IsStart = false;
};

void InputVector(vector <point> &A)
{
  int n;
  cin >> n;
  point PointFirst, PointLast;
  for (int i = 0; i < n; ++i)
  {
    cin >> PointFirst.X >> PointLast.X;
    PointFirst.IsStart = true;
    A.push_back(PointFirst);
    A.push_back(PointLast);
  }
}

bool operator<(const point &first, const point &second)
{
  return first.X < second.X;
}

void sift_down(vector <point> &A, int index, int heapSize)
{
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  int largest = index;
  if (left < heapSize && A[index] < A[left]) {
    largest = left;
  }
  if (right < heapSize && A[largest] < A[right]) {
    largest = right;
  }
  if (largest != index) {
    swap(A[index], A[largest]);
    sift_down(A, largest, heapSize);
  }
}

void BuildHeap(vector <point> &A)
{
  for (int i = A.size() / 2 - 1; i >= 0; --i)
  {
    sift_down(A, i, A.size());
  }
}

void HeapSort(vector <point> &A)
{
  BuildHeap(A);
  int HeapRealSize = A.size();
  while(HeapRealSize != 0)
  {
    swap(A[0], A[HeapRealSize - 1]);
    --HeapRealSize;
    sift_down(A, 0, HeapRealSize);
  }
}

int main()
{
  vector <point> A;
  InputVector(A);
  HeapSort(A);
  int result = 0;
  int layer = 0;
  for (int i = 0; i < A.size(); ++i)
  {
    if (layer == 1)
    {
      result += A[i].X - A[i - 1].X;
    }
    if (A[i].IsStart == true)
    {
      layer += 1;
    }
    else
    {
      layer -= 1;
    }
  }
  cout << result << endl;
  return 0;
}