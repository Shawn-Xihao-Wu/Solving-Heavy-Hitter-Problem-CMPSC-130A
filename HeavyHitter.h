#ifndef HEAVYHITTER_H
#define HEAVYHITTER_H
#include "MinHeap.h"
#include "Hash.h"
#include <iostream>
#include <string>
using namespace std;

class HeavyHitter
{
public:
  HeavyHitter();
  void insert(string word); //inserts word into hash table, updates freq in heap
  void replaceMin(string x); //when the string is new but heap is full
  void printHeap(); //prints the most frequent 15 words
  void printHashTable(); //prints the current Hash table

  bool full(){return minheap.isFull();}

private:
  MinHeap minheap=MinHeap();
  Hash hashTable=Hash(21);


};


#endif
