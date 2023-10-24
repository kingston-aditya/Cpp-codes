#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

// This function returns decoded string for 'str'
string decode(string str)
{
    //stacks for storing integer and character resp
    stack<int> intstack;
    stack<char> strstack;
    string temp = "", res = "";

    // Traverses the string
    for (int i = 0; i < str.length(); i++)
    {
        int count = 0;

        // char is a number, convert it to integer
        if (str[i] >= '0' && str[i] <='9')
        {
            while (str[i] >= '0' && str[i] <= '9')
            {
                count = count * 10 + str[i] - '0';
                i++;
            }

            i--;
            intstack.push(count);
        }

        // If closing bracket ')', pop elemment until
        // '(' opening bracket is not found in the
        // character stack.
        else if (str[i] == ')')
        {
            temp = "";
            count = 0;

            if (! intstack.empty())
            {
                count = intstack.top();
                intstack.pop();
            }

            while (! strstack.empty() && strstack.top()!='(' )
            {
                temp = strstack.top() + temp;
                strstack.pop();
            }

            if (! strstack.empty() && strstack.top() == '(')
                strstack.pop();

            // Repeating the popped string 'temo' count
            // number of times.
            for (int j = 0; j < count; j++)
                res = res + temp;

            // Push it in the character stack.
            for (int j = 0; j < res.length(); j++)
                strstack.push(res[j]);

            res = "";
        }

        // If '(' opening bracket, push it into character stack.
        else if (str[i] == '(')
        {
            if (str[i-1] >= '0' && str[i-1] <= '9')
                strstack.push(str[i]);

            else
            {
                strstack.push(str[i]);
                intstack.push(1);
            }
        }

        else
            strstack.push(str[i]);
    }

    // Pop all the elements, make a string and return.
    while (! strstack.empty())
    {
        res = strstack.top() + res;
        strstack.pop();
    }

    return res;
}

int main()
{
    string str,dec;

    int r=0,c=0,m,n;

    cin>>m>>n;
    cin>>str;

    dec=decode(str);

    //traversing the string
    for(char k:dec)
    {
      if(k=='N')
      {
        r=r-1;
      }
      else if(k=='S')
      {
        r=r+1;
      }
      else if(k=='W')
      {
        c=c-1;
      }
      else if(k=='E')
      {
        c=c+1;
      }
    }

    //perform reduction of values
    if(r>m)
    {
      r=r%m;
    }

    if(c>n)
    {
     c=c%n;
    }
    // perform increase of values
    if(r<0)
    {
      while(r<0)
      {
        r=r+m;
      }
    }

    if(c<0)
    {
      while(c<0)
      {
        c=c+n;
      }
    }

    cout<<r<<","<<c<<endl;
    return 0;
}
