//Дано невзвешенное дерево. Расстоянием между двумя вершинами будем называть количество ребер в пути, соединяющем эти две вершины. Для каждой вершины определите расстояние до самой удаленной от нее вершины.

#include <iostream>
#include <vector>

using namespace std;

void InputGraph(vector <vector <int> > &ChildList, vector <int> &ParentList)
{
  int a, b;
  for (int i = 0; i < ChildList.size() - 1; ++i)
  {
    cin >> a >> b;
    ChildList[min(a, b)].push_back(max(a, b));
    ParentList[max(a, b)] = min(a, b);
  }
}

void FindMax(int k, vector <pair<int, int> > &MaxOfDown, const vector <vector <int> > &ChildList)
{
  for (int i = 0; i < ChildList[k].size(); ++i)
  {
    FindMax(ChildList[k][i], MaxOfDown, ChildList);
    int found = MaxOfDown[ChildList[k][i]].first + 1;
    if (found > MaxOfDown[k].second)
    {
      if (found > MaxOfDown[k].first)
      {
        MaxOfDown[k].second = MaxOfDown[k].first;
        MaxOfDown[k].first = found;
      }
      else
      {
        MaxOfDown[k].second = found;
      }
    }
  }
}

void FindMaxFromRoot(vector <pair<int, int> > &MaxOfDown, const vector <vector <int> > &ChildList)
{
  FindMax(0, MaxOfDown, ChildList);
}

void OutputResult(vector <pair<int, int> > &MaxOfDown, vector <int> ParentList)
{
  cout << MaxOfDown[0].first << endl;
  for (int i = 1; i < ParentList.size(); ++i)
  {
    if(MaxOfDown[ParentList[i]].first == MaxOfDown[i].first + 1)
    {
      MaxOfDown[i].second = max(MaxOfDown[i].second, min(MaxOfDown[ParentList[i]].second + 1, MaxOfDown[i].first));
      MaxOfDown[i].first = max(MaxOfDown[ParentList[i]].second + 1, MaxOfDown[i].first);
      cout << MaxOfDown[i].first << endl;
    }
    else
    {
      MaxOfDown[i].second = max(MaxOfDown[i].second, min(MaxOfDown[ParentList[i]].first + 1, MaxOfDown[i].first));
      MaxOfDown[i].first = max(MaxOfDown[ParentList[i]].first + 1, MaxOfDown[i].first);
      cout << MaxOfDown[i].first << endl;
    }
  }
}

int main()
{
  int n;
  cin >> n;
  vector <vector <int> > ChildList(n);
  vector <int> ParentList(n, 0);
  InputGraph(ChildList, ParentList);
  vector <pair<int, int> > MaxOfDown(n, {0, 0});
  FindMaxFromRoot(MaxOfDown, ChildList);
  OutputResult(MaxOfDown, ParentList);
}
