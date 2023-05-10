#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <list>
#include <string>
#include <utility>
#include "MinHeap.h"
using namespace std;

class Hash
{
public:
  Hash(int b);
  bool exists(string word); 
  int locationOfKey(string word); 
  void insert(string word,int index); 
  void deleteKey(string word);
  int hashFunction(int x){return x % bucket;} 
  void updateFrequency(string word,int newIndex); 
  void printTable();
  void updateTable();
  list< pair<string,int> > *table;
  int getBucket(){return bucket;}
  int getIndexOfWord1(string word){return minheap.getIndexOfWord(word);}

private:
  int bucket;
  MinHeap minheap=MinHeap();

};


#endif
