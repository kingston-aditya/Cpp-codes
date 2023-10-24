#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<fstream>

using namespace std;
// question coding: 2
// making condition for sorting
bool cmp(pair<int,int>&a,pair<int,int>&b)
{
  if(a.second==b.second)
  {
    return a.first < b.first;
  }
  else
  {
    return a.second < b.second ;
  }

}

int main()
{
  // define t,x and take input from user
  int i;
  int x;
  // file input and output
  ifstream inFile;
  ofstream outFile;
  // vector balls
  vector<int> ball;
  inFile.open("coding-question-b.txt");
  outFile.open("a.txt");
  while(inFile >> x)
  {
    ball.push_back(x);
  }
  inFile.close();
  // while(t--)
  // {
  //   int a;
  //   cin>>a;
  //   ball.push_back(a);
  // }

  // making map for counting common elements
  map<int, int> mapa;
  for(i=0;i<ball.size();i++)
  {
    mapa[ball[i]]++;
  }
  // for(auto it:mapa)
  // {
  //   cout<<it.first<<it.second<<endl;
  // }

  vector< pair <int,int> > vect;
  // make vectors having pairs
  for(auto it:mapa)
  {
    vect.push_back(make_pair(it.first,it.second));
  }

  // sorting vector acc to cond given in ques
  sort(vect.begin(),vect.end(),cmp);
  // sorted results
  for(auto it:vect)
  {
      for(i=0;i<it.second;i++)
      {
        outFile<<it.first<<endl;
      }
  }
  outFile.close();
  return 0;

}
