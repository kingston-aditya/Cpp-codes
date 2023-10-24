    #include <iostream>
    #include <stack>
    #include <queue>
    #include <utility>

    using namespace std;

    struct Node
    {
        int value,cost;
        Node* next;
    };

    struct Edge
    {
        int start,end,weight;
    };

    class Graph
    {
        private:

        Node* adjlistnode(int value, int weight, Node* head)
        {
            Node* newnode = new Node;
            newnode->value = value;
            newnode->cost = weight;
            newnode->next = head;
            return newnode;
        }

        int N;

        public:
            Node **head;
            Graph(Edge edges[],int m, int N)
            {
                head = new Node*[N+1]();
                this->N = N;
                for (int i=1;i<=N;i++)
                {
                    head[i] = nullptr;
                }
                for (long int i=0;i<m;i++)
                {
                    int start = edges[i].start;
                    int end = edges[i].end;
                    int weight = edges[i].weight;
                    Node* newnode = adjlistnode(end,weight,head[start]);
                    head[start] = newnode;
                    newnode = adjlistnode(start,weight,head[end]);
                    head[end] = newnode;
                }
            }

    };

     void printPathmst(stack<int> s,int c,Graph graph)
    {
        stack<int> temp;
        int arr[s.size()];
        temp=s;

        int a=temp.top();
        temp.pop();

        while(!temp.empty())
        {
            int b=temp.top();
            auto ptr=graph.head[a];
            while (ptr->value!=b)
            {
                ptr=ptr->next;
            }
            if (ptr->cost>c)
            {
                cout<<"NOT POSSIBLE"<<"\n";
                return;
            }

            a=b;temp.pop();


        }
        if(temp.empty())
        {
            cout<<"POSSIBLE"<<"\n";
            int idx=s.size()-1;
            int idx1=idx;
            while(!s.empty())
            {
                arr[idx]= s.top();
                idx--;
                s.pop();
            }
            for(int i=0;i<=idx1;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<"\n";

        }



    }



    void dfs (Graph graph,bool vis[], int a,int b,stack<int> s,int c)
    {

        s.push(a);
        if (a==b)
        {
            printPathmst(s,c,graph);
            return;
        }
        vis[a]=true;
        auto i =graph.head[a];
        if(i!=nullptr)
        {
            while(i!=nullptr)
            {
                if(vis[i->value]==false)
                {
                    dfs(graph,vis,i->value,b,s,c);
                }
                i=i->next;
            }
        }
        s.pop();


    }

    void calldfs(int x, int y, Graph graph,  int n,  stack<int> s,int c)
    {

        bool visited[n + 1];
        for(int i=1;i<=n;i++)
        {
            visited[i]=false;
        }

        dfs(graph, visited, x, y, s,c);
    }

    int main()
    {


            int n,m;
            cin>>n>>m;
            Edge edges[m];
            Edge edgemst[n-1];
            int e=0;

            for(int i=0;i<m;i++)
            {
                int a,b,c;
                cin>>a>>b>>c;
                edges[i]={a,b,c};
            }
            int N =n;

            Graph graph(edges,m,N);

            bool d[n+1];d[0]=1;
            for(int i=1;i<=n;i++)
            {
                d[i]=0;
            }
            priority_queue<pair<int,pair<int,int>>> p;int i=1;
            Node* ptr= graph.head[i];
            while (ptr!=nullptr)
            {
                pair<int,pair<int,int>> temp;
                temp.first=-ptr->cost;
                temp.second=make_pair(i,ptr->value);
                p.push(temp);
                ptr=ptr->next;
            }

            auto top = p.top();
            edgemst[e]={top.second.first,top.second.second,-top.first};e++;
            d[top.second.first]=1;d[top.second.second]=1;p.pop();

            while (e<n-1)
            {

                i = top.second.second;
                ptr= graph.head[i];
                while (ptr!=nullptr)
                {
                    pair<int,pair<int,int>> temp;
                    temp.first=-ptr->cost;
                    temp.second=make_pair(i,ptr->value);

                    if (d[temp.second.second]==0 or d[temp.second.first]==0)
                    {
                        p.push(temp);


                    }

                    ptr=ptr->next;
                }
                top=p.top();
                if (d[top.second.second]==0 or d[top.second.first]==0)
                {
                    edgemst[e]={top.second.first,top.second.second,-top.first};
                    e++;
                    d[top.second.second]=1;
                    d[top.second.first]=1;
                    i = top.second.second;
                    ptr= graph.head[i];
                }
                p.pop();

            }

            Graph mst(edgemst,n-1,N);

            int a,b,c;
            cin>>a>>b>>c;
            stack<int> s;
            calldfs(a,b,mst,n,s,c);



        return 0;

    }
