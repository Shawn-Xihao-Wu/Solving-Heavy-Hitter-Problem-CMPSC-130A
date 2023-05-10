#include "HeavyHitter.h"
HeavyHitter::HeavyHitter()
{


}
void HeavyHitter::insert(string word)
{
  if(hashTable.exists(word)==false)
  {
    if(minheap.isFull()==false)
    {
      minheap.insert(word);
      minheap.heapify(1);
      hashTable.insert(word,minheap.getIndexOfWord(word));

    }
    else
    {
      replaceMin(word);
    }

  }
  else
  {
    minheap.updateFrequency(word);
    hashTable.updateFrequency(word,minheap.getIndexOfWord(word));
  }

}

void HeavyHitter::replaceMin(string x)
{
  minheap.heapify(1);
  string wordDelete = minheap.getRoot();
  hashTable.deleteKey(wordDelete);
  minheap.replaceKey(x);
  hashTable.insert(x,1);


}

void HeavyHitter::printHeap()
{
  minheap.printHeap();
}

void HeavyHitter::printHashTable()
{
  for(int i=0;i<hashTable.getBucket();i++)
  {
    cout<<i;
    for(pair<string,int> x:hashTable.table[i])
    {
      cout<<"-->"<<x.first<<", "<<minheap.getIndexOfWord(x.first);
    }
    cout<<endl;
  }


}
