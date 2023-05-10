#include "MinHeap.h"

MinHeap::MinHeap()
{
  currentSize=0;
}

void MinHeap::heapify(int i)
{

  int left=leftChild(i);
  int right=rightChild(i);
  int smallest=i;
  if(left<=currentSize && (heapArray[left].first<heapArray[smallest].first))
  {
    smallest=left;
  }
  if(right<=currentSize && (heapArray[right].first<heapArray[smallest].first))
  {
    smallest=right;
  }
  if(smallest!=i)
  {
    swap(heapArray[i],heapArray[smallest]);
    heapify(smallest);
  }

}
string MinHeap::getRoot()
{
  return heapArray[1].second;

}
int MinHeap::getIndexOfWord(string word)
{
  for(int i=1;i<=currentSize;i++)
  {
    if(heapArray[i].second==word)
    {
      return i;
    }

  }
  return 0;



}
bool MinHeap::isFull()
{
  if(currentSize>=15)
  {
    return true;
  }
  else
  {
    return false;
  }
}
void MinHeap::updateFrequency(string word)
{
  int index=getIndexOfWord(word);
  heapArray[index].first++;
  heapify(index);




}
void MinHeap::replaceKey(string word)
{
  heapArray[1].second=word;



}
void MinHeap::printHeap()
{
  heapify(1);
  cout<<"The Most 15 Frequent Words: "<<endl;
  for(int i=1;i<=currentSize;i++)
  {
    cout<<"[";
    cout<<i;
    cout<<"] ";
    cout<<heapArray[i].second;
    cout<<" ";
    cout<<heapArray[i].first;
    cout<<endl;

  }

}
void MinHeap::insert(string word)
{
  pair<int,string> key={1,word};
  currentSize++;
  int i=currentSize;
  heapArray[i]=key;
  
  while(i!=1 && heapArray[parent(i)].first>heapArray[i].first)
  {
  swap(heapArray[i],heapArray[parent(i)]);
    i=parent(i);
  }



}
