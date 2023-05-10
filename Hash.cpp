#include "Hash.h"

Hash::Hash(int b)
{
  this->bucket=b;
  table = new list< pair<string,int> >[bucket];
}
void Hash::insert(string word, int harrIndex)
{
  pair<string,int> key;
  int index=hashFunction(word.length());
  key.first=word;
  key.second=harrIndex;
  table[index].push_back(key);
}
void Hash::deleteKey(string word)
{
  int index=hashFunction(word.length());
  list< pair<string,int> > :: iterator i;
  for(i=table[index].begin(); i!=table[index].end();i++)
  {
    if(i->first == word)
      break;
  }
  if(i!=table[index].end())
    table[index].erase(i);

}
int Hash::locationOfKey(string word)
{

  int index = 0;
  while(index!=bucket)
  {
    list< pair<string,int> > :: iterator i;
    for(i=table[index].begin(); i!=table[index].end();i++)
    {
      if(i->first==word)
        return i->second;
    }
    index++;
  }
  return -1;



}
bool Hash::exists(string word)
{
  int index=0;
  while(index!=bucket)
  {
    list< pair<string,int> > :: iterator i;
    for(i=table[index].begin(); i!=table[index].end();i++)
    {
      if(i->first == word)
        return true;
    }
    index++;
  }
  return false;

}
void Hash::updateFrequency(string word,int newIndex)
{
  int index=hashFunction(word.length());
  list< pair<string,int> > :: iterator i;
  for(i=table[index].begin(); i!=table[index].end();i++)
  {
    if(i->first == word)
      i->second=newIndex;
  }

}
void Hash::printTable()
{
  int num=0;
  for(int i=0;i<bucket;i++)
  {
    cout<<i;
    for(pair<string,int> x:table[i])
    {
      cout<<"-->"<<x.first<<", "<<x.second;
    }
    cout<<endl;
  }
}
