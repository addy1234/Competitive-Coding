#include <bits/stdc++.h>
using namespace std;
 
int n,m;
int a[100005],tree[400005];
bool isPrime[1000005];
int lazy[400005];
 
void seive()
{
    memset(isPrime,1,sizeof(isPrime));
    isPrime[1]=0;
    for(int i=2;i<=1000000;i++){
        if(isPrime[i]==1){
            for(int j=2*i;j<=1000000;j+=i){
                isPrime[j]=0;
            }
        }
    }
    return;
}
 
void buildTree(int l ,int r, int index)
{
    if(l==r)
    {
       tree[index]=(isPrime[a[l]]==1);
       lazy[index]=-1;
       return;
    }
    int mid = (l+r)/2;
    buildTree(l,mid,2*index);
    buildTree(mid+1,r,2*index+1);
    tree[index] = tree[2*index] + tree[2*index+1];
    lazy[index]=-1;
    return;
}
 
void updateTree(int index,int l ,int r,int ql,int qr,int val)
{
    
    if(lazy[index]!=-1){
        if(lazy[index]){
            tree[index]=r-l+1;
            lazy[2*index]=lazy[2*index+1]=1;
        }else{
             tree[index]=0;
             lazy[2*index]=lazy[2*index+1]=0;
        }
        lazy[index]=-1;
    }
 
    if(ql>r || qr<l)
    {
        return;
    }
    
    if(l >= ql && r<=qr)
    {
        if(isPrime[val]){
           tree[index]=(r-l+1);
           lazy[2*index]=1;
           lazy[2*index+1]=1;
        }else{
           tree[index]=0;
           lazy[2*index]=0;
           lazy[2*index+1]=0;
        }
        return;
    }
 
    int mid = (l+r)/2;
    updateTree(2*index,l,mid,ql,qr,val);
    updateTree(2*index+1,mid+1,r,ql,qr,val);
    
    tree[index] = tree[2*index] + tree[2*index+1];
    return;
}
 
int query(int l,int r,int ql,int qr,int index)
{
    if(lazy[index]!=-1){
        if(lazy[index]){
            tree[index]=r-l+1;
            lazy[2*index]=lazy[2*index+1]=1;
        }else{
             tree[index]=0;
             lazy[2*index]=lazy[2*index+1]=0;
        }
        lazy[index]=-1;
    }
 
    if(ql>r || qr<l)
    {
        return 0;
    }
    
    if(l >= ql && r<=qr)
    {
        return tree[index];
    }
 
    int mid = (l+r)/2;
    int left = query(l,mid,ql,qr,2*index);
    int right = query(mid+1,r,ql,qr,2*index+1);
    return (left + right);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    seive();
    int t;
    cin>>t;
    for(int c=1;c<=t;c++){
             cout<<"Case "<<c<<":"<<"\n";
            memset(tree,0,sizeof(tree));
            cin>>n>>m;
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
            }
 
            buildTree(0,n-1,1);
         /*for(int i=1;i<=4*n;i++)
            {
                cout<<tree[i]<<" ";
            }
            cout<<"\n";*/
 
            for(int z=0;z<m;z++)
            {
                int x,l,r,v;
                cin>>x;
 
                if(x==0){
                    cin>>l>>r>>v;
                    l--;r--;
                    updateTree(1,0,n-1,l,r,v);
                }else{
                    cin>>l>>r;
                    l--;r--;
                    cout<<query(0,n-1,l,r,1)<<"\n";
                }
 
                /*for(int i=0;i<k;i++)
                {
                    cout<<b[i]<<" ";
                }
                cout<<"\n";*/
                
            /* for(int i=0;i<n;i++)
                {
                    cout<<a[i]<<" ";
                }
                cout<<"\n";*/
            }
    }
    return 0;
}