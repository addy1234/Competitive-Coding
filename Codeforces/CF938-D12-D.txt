#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pi pair<lli,int>

int n,m;
vector<pi> v[200005];
priority_queue<pi,vector<pi>,greater<pi>> pq;
lli dist[200005];
bool visited[200005];

void Dijkstra()
{
    while(!pq.empty())
    {
        pi x  = pq.top();
        pq.pop();
        lli weight = x.first;
        int idx = x.second;
        
        if(visited[idx]==1)
        {
        	continue;
        }
        visited[idx]=1;

        for(pi i : v[idx])
        {
            lli w1 = i.first;
            int idx1 = i.second;

            if(dist[idx1] > dist[idx] + w1)
            {
                dist[idx1]=dist[idx]+w1;
                pq.push(make_pair(dist[idx1],idx1));
            }
         }
   }
   return;
}

int main()
{
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int x,y;
        lli w;
        cin>>x>>y>>w;
        w=2ll*w;
        v[x].push_back(make_pair(w,y));
        v[y].push_back(make_pair(w,x));
    }

    for(int i=1;i<=n;i++)
    {
        cin>>dist[i];
        pq.push(make_pair(dist[i],i));
    }

    Dijkstra();

    for(int i=1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<"\n";
    return 0;
}