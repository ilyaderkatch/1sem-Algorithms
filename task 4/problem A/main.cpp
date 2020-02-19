//õåøòàáëèöû ÷åğåç êâàäğàòè÷íîå ïğîáèğîâàíèå
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

class HashTable
{
 private:
  vector <pair <string, bool> > Table;
  int num = 0;
  int Hash(const string &S);
  void Resize();

 public:
  HashTable();
  ~HashTable();
  bool DeleteString(string &key);
  bool AddString(string &key);
  bool Has(string &key);
};

void HashTable::Resize()
{
  vector <pair <string, bool> > New;
  New = Table;
  Table.clear();
  Table.resize(New.size() * 2);
  for (int i = 0; i < New.size(); ++i)
  {
    if(New[i].first != "" && New[i].second != true)
    {
      AddString(New[i].first);
    }
  }
}

bool HashTable::DeleteString(string &key)
{
  int h = Hash(key);
  int i = 1;
  while(i != Table.size() && Table[h].first != key && ((Table[h].first != "") || (Table[h].second == true)))
  {
    h += i;
    h %= Table.size();
    i += 1;
  }
  if (Table[h].first == key)
  {
    Table[h].first = "";
    Table[h].second = true;
    --num;
    return true;
  }
  return false;
}

bool HashTable::AddString(string &key)
{
  if ((num + 1) * 4 >= 3 * Table.size())
  {
    Resize();
  }
  int h = Hash(key);
  int i = 1;
  while(Table[h].first != "" && Table[h].second == false)
  {
    if (Table[h].first == key)
    {
      return false;
    }
    h += i;
    h %= Table.size();
    i += 1;
  }
  Table[h].first = key;
  Table[h].second = false;
  ++num;
  return true;
}

bool HashTable::Has(string &key)
{
  int h = Hash(key);
  int i = 1;
  while(i != Table.size() && Table[h].first != key && ((Table[h].first != "") || (Table[h].second == true)))
  {
    h += i;
    h %= Table.size();
    i += 1;
  }
  if (Table[h].first == key)
  {
    return true;
  }
  return false;
}

int HashTable::Hash(const string &S)
{
  int result = 0;
  for (int i = 0; i < S.size(); ++i)
  {
    result += S[i] - 'a';
    result *= 179;
    result %= Table.size();
  }
  return result;
}

HashTable::HashTable()
{
  Table.resize(8, {"", false});
}

HashTable::~HashTable()
{
  Table.clear();
}

int main()
{
  HashTable Table;
  string input;
  char data;
  while (in >> data)
  {
    in >> input;
    if (data == '+')
    {
      if (Table.AddString(input))
      {
        out << "OK" << endl;
      }
      else
      {
        out << "FAIL" << endl;
      }
    }
    else if (data == '-')
    {
      if (Table.DeleteString(input))
      {
        out << "OK" << endl;
      }
      else
      {
        out << "FAIL" << endl;
      }
    }
    else
    {
      if (Table.Has(input))
      {
        out << "OK" << endl;
      }
      else
      {
        out << "FAIL" << endl;
      }
    }
  }
  return 0;
}