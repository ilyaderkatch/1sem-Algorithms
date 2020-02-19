#include <iostream>
#include <vector>

using namespace std;

struct element
{
    int n = 0;
    int a = 0;
    int b = 0;
    int c = 0;
};

void SortOfThree(int &a, int &b, int &c)
{
    int a1, b1, c1;
    a1 = min(a, min(b, c));
    c1 = max(a, max(b, c));
    b1 = a + b + c - a1 - c1;
    a = a1;
    b = b1;
    c = c1;
}

void InputVector (vector <element> &A)
{
    int l;
    cin >> l;
    element e;
    for (int i = 0; i < l; ++i)
    {
        cin >> e.a >> e.b >> e.c;
        SortOfThree(e.a, e.b, e.c);
        e.n = i;
        A.push_back(e);
    }
}

bool operator<(const element &first, const element &second)
{
    if (first.a < second.a)
    {
        return true;
    }
    if (first.a > second.a)
    {
        return false;
    }
    if (first.b < second.b)
    {
        return true;
    }
    if (first.b > second.b)
    {
        return false;
    }
    if (first.c < second.c)
    {
        return true;
    }
    if (first.c > second.c)
    {
        return false;
    }
    return first.n < second.n;
}

void InsertionSort (vector <element> &A)
{
    for (int i = 0; i < A.size(); ++i)
    {
        element temp = A[i];
        int j = i - 1;
        while(j >= 0 && temp < A[j])
        {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = temp;
    }
}

int main()
{
    vector <element> A;
    InputVector(A);
    InsertionSort(A);
    for (int i = 0; i < A.size(); ++i)
    {
        cout << A[i].n << endl;
    }
    return 0;
}
