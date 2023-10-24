#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;
// question coding: 2
// my roll no. is 03
// finding gcd(a,b) where a,b belongs to integer
int main()
{
  // define a,b and take input from user
  int a,b,k=1;
  cin>>a;
  cin>>b;
  cout<<"a= "<<a<<" and "<<"b= "<<b<<endl;
  // if a=0 or b=0
  if (a==0 || b==0)
  {
    cout<<"the hcf is "<<max(a,b)<<endl;
  }
  else
  {
    // starting a loop
    while(a!=b)
    { //checking if a,b is divisible by 3
      if((a/3)*3==a && (b/3)*3==b)
      {
        a=a/3;
        b=b/3;
        cout<<"a= "<<a<<" and "<<"b= "<<b<<endl;
        k=k*3;
      }
      else
      // applying euclid's gcd algorithm
      {
        if(a>b)
        {
          a=a-b;
          cout<<"a= "<<a<<" and "<<"b= "<<b<<endl;
        }
        else
        {
          b=b-a;
          cout<<"a= "<<a<<" and "<<"b= "<<b<<endl;
        }
      }
    }
    cout<<"the hcf is "<<k*a<<endl;
  }
	return 0;

}
