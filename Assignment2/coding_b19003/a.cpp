#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
// question coding: 1
// condition function for sorting
bool cmp(pair<int,int>&a,pair<int,int>&b)
{
  return a.second < b.second ;
}
// main function
int main()
{
  // define t and take input from user
  int t;
  cin>>t;
  // define vectors
  vector<int> staq;
  vector<int> end;
  while(t--)
  {
    //define a,b
    int a,b;
    cin>>a>>b;
    staq.push_back(a);
    end.push_back(b);
  }
  // defined vector
  vector< pair <int,int> > vect;
  // making pairs
  for(int i=0;i<staq.size();i++)
  {
    vect.push_back(make_pair(staq[i],end[i]));
  }
  // sorting acc to ques given in question
  sort(vect.begin(),vect.end(),cmp);
  // start vector and finish vector
  vector<int> s;
  vector<int> f;

  for(auto it:vect)
  {
    s.push_back(it.first);
    f.push_back(it.second);
  }
  // counting no. of free slots
  int i=0,j,k=0;
  for(j=1;j<s.size();j++)
  {
    if(s[j]>=f[i])
    {
      k=k+1;
      i=j;

    }
  }
  cout<<k+1<<endl;


  return 0;

}
