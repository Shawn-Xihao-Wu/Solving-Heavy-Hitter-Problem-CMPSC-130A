#ifndef MINHEAP_H
#define MINHEAP_H
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <utility>
using namespace std;

class MinHeap
{
public:
  MinHeap();
  void heapify(int root); 
  
  bool isFull();
  int parent(int i){return (i/2);} 
  int leftChild(int i){return 2*i;}
  int rightChild(int i){return (2*i + 1);}
  string getRoot();
  void updateFrequency(string word); 
  void replaceKey(string word); 
  void insert(string w); 
  int getSize(){return currentSize;}
  int getFrequency(int index){return heapArray[index].first;} 
  string getWord(int index){return heapArray[index].second;} 
  void setHarrIndex(int harrIndex){this->harrIndex=harrIndex;}
  int getharrIndex(){return harrIndex;}
  int getIndexOfWord(string word);
  void printHeap();




private:
  int harrIndex;
  static const int capacity=16;
  int currentSize;
  pair<int,string> heapArray[16];

};




#endif
