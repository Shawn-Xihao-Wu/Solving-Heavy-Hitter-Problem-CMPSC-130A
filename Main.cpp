#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>
#include "HeavyHitter.h"



using namespace std;

int main()
{
  HeavyHitter hitter=HeavyHitter();
  ifstream myfile;
  string article;
  string addedWord;
  int choice;
  bool flag=true;
  myfile.open("article.txt");
  vector<string> words;
  if(!myfile.is_open())
    cout<<"failed to open"<<endl;
  while(myfile>>article)
  {
    transform(article.begin(),article.end(),article.begin(),::tolower);
    words.push_back(article);
  }
  while(flag==true)
  {
    cout<<"Welcome to the Heavy-Hitter Application."<<endl;
      cout<<"1) Run the program with given txt file."<<endl;
      cout<<"2) Enter a word into the program."<<endl;
      cout<<"3) Print the Heap."<<endl;
      cout<<"4) Print the HashTable."<<endl;
      cout<<"5) Exit."<<endl;
      cout<<"Which operation do you want to make? (1,2,3,4,5)"<<endl;
      cin>>choice;

      if(choice==1)
      {
        for(int i=0;i<words.size();i++)
        {
          hitter.insert(words[i]);

        }
      }

      else if(choice==2)
      {
        cout<<"Enter the word: "<<endl;
        cin>>addedWord;
        hitter.insert(addedWord);
        cout<<endl;

      }
      else if(choice==3)
      {
        hitter.printHeap();
      }
      else if(choice==4)
      {
        hitter.printHashTable();
      }
      else if(choice==5)
      {
        cout<<"Exiting"<<endl;
        flag=false;
      }
      else
      {
        cout<<"Please enter a valid input."<<endl;
        cin.clear();
        cin.ignore(1000000,'\n');
      }

  }



  myfile.close();
}
