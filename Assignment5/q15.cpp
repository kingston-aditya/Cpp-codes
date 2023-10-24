#include <iostream>
#include <queue>
#include <utility>
#include <map>

//question 1
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n,vector<int>(m,0));
    queue<pair<pair<int, int>, int>> q;

    //applying multi source bfs
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m;j++)
        {
            cin >> v[i][j];
            if(v[i][j] == 2)
            {
                q.push({{i, j}, 0});
            }
        }
    }

    int Sum = 0;
    while (!q.empty())
    {
        pair<int, int> p = q.front().first;
        int p1 = p.first;
        int p2 = p.second;
        int value = q.front().second;

        q.pop();

        if (p2 + 1 < m and v[p1][p2+1] == 1)
        {
            v[p1][p2+1] = 2;
            q.push({{p1, p2+1}, value + 1});
            Sum = value + 1;
        }

        if(p1>=1 and v[p1-1][p2] == 1)
        {
            v[p1 - 1][p2] = 2;
            q.push({{p1 - 1, p2}, value + 1});
            Sum = value;
        }

        if (p1 + 1 < n and v[p1 + 1][p2] == 1)
        {
            v[p1 + 1][p2] = 2;
            q.push({{p1 + 1, p2}, value + 1});
            Sum = value;
        }

        if (p2 - 1 >= 0 and v[p1][p2-1] == 1)
        {
            v[p1][p2-1] = 2;
            q.push({{p1, p2-1}, value + 1});
            Sum = value + 1;
        }


    }

    for (int i = 0;i<n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            if(v[i][j] == 1)
            {
                cout<<-1<<endl;
            }
        }
    }
    cout<<Sum<<endl;

    return 0;
}
