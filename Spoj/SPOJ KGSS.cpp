#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define lli long long int

int n,m;
int a[100005];
pi tree[400005];

void buildTree(int l ,int r, int index)
{
    if(l==r)
    {
       tree[index]=make_pair(0,a[l]);
       return;
    }
    int mid = (l+r)/2;
    buildTree(l,mid,2*index);
    buildTree(mid+1,r,2*index+1);
    
    int b[4];
    b[0]=tree[2*index].first;
    b[1]=tree[2*index].second;
    b[2]=tree[2*index+1].first;
    b[3]=tree[2*index+1].second;
    sort(b,b+4);

    tree[index] = make_pair(b[2],b[3]);
    return;
}

void updateTree(int index,int l ,int r,int idx,int val)
{
    if(l==r)
    {
        a[idx]=val;
        tree[index]=make_pair(0,a[idx]);
        return;
    }

    int mid = (l+r)/2;
    if(idx <= mid) 
    {
       updateTree(2*index,l,mid,idx,val);
    }
    else
    {
       updateTree(2*index+1,mid+1,r,idx,val);
    }

    int b[4];
    b[0]=tree[2*index].first;
    b[1]=tree[2*index].second;
    b[2]=tree[2*index+1].first;
    b[3]=tree[2*index+1].second;
    sort(b,b+4);

    tree[index] = make_pair(b[2],b[3]);
    return;
}

pair<int,int> query(int l ,int r , int ql,int qr,int index)
{
    if(ql>r || qr<l)
    {
        return make_pair(0,0);
    }
    
    if(l >= ql && r<=qr)
    {
        return tree[index];
    }

 
    int mid = (l+r)/2;
    pi val1 = query(l,mid,ql,qr,2*index);
    pi val2 = query(mid+1,r,ql,qr,2*index+1);

    int b[4];
    b[0]=val1.first;
    b[1]=val1.second;
    b[2]=val2.first;
    b[3]=val2.second;
    sort(b,b+4);
    
    return make_pair(b[2],b[3]);
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    buildTree(0,n-1,1);
    /*for(int i=1;i<=4*n;i++)
    {
        cout<<tree[i].first<<" "<<tree[i].second<<"\n";
    }
    cout<<"\n";*/
    int m;
    cin>>m;

    for(int z=0;z<m;z++)
    {
        char p;
        int x,y;
        cin>>p>>x>>y;

        if(p=='U')
        {
            updateTree(1,0,n-1,x-1,y);
        }
        else
        {
           pi val = query(0,n-1,x-1,y-1,1);
           cout<<val.first + val.second<<"\n";
        }
    }
    return 0;
}
