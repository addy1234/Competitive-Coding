#include <bits/stdc++.h>
using namespace std;
#define lli long long int
 
int n,m;
lli a[2000010],tree[8000005];
lli lazy[8000005];
 
void buildTree(int l ,int r, int index)
{
    if(l>r){
        return;
    }
 
    if(l==r)
    {
       tree[index]=a[l];
       lazy[index]=0;
       return;
    }
    int mid = (l+r)/2;
    buildTree(l,mid,2*index);
    buildTree(mid+1,r,2*index+1);
    tree[index] = min(tree[2*index] ,tree[2*index+1]);
    lazy[index]=0;
    return;
}
 
void updateTree(int index,int l ,int r,int ql,int qr,int val)
{
    if(l>r){
        return;
    }
 
    if(lazy[index]!=0){
        tree[index]-=lazy[index];
        lazy[2*index]+=lazy[index];
        lazy[2*index+1]+=lazy[index];
        lazy[index]=0;
    }
 
    if(ql>r || qr<l)
    {
        return;
    }
    
    if(l >= ql && r<=qr)
    {
        lazy[index]=val;
        tree[index]-=lazy[index];
        lazy[2*index]+=lazy[index];
        lazy[2*index+1]+=lazy[index];
        lazy[index]=0;
        return;
    }
 
    int mid = (l+r)/2;
    updateTree(2*index,l,mid,ql,qr,val);
    updateTree(2*index+1,mid+1,r,ql,qr,val);
    
    tree[index] = min(tree[2*index],tree[2*index+1]);
    return;
}
 
lli query(int l,int r,int ql,int qr,int index)
{
    if(l>r){
        return LONG_MAX;
    }
    
    if(lazy[index]!=0){
        tree[index]-=lazy[index];
        lazy[2*index]+=lazy[index];
        lazy[2*index+1]+=lazy[index];
        lazy[index]=0;
    }
 
    if(ql>r || qr<l)
    {
        return LONG_MAX;
    }
    
    if(l >= ql && r<=qr)
    {
        return tree[index];
    }
 
    int mid = (l+r)/2;
    lli left = query(l,mid,ql,qr,2*index);
    lli right = query(mid+1,r,ql,qr,2*index+1);
    return min(left ,right);
}
 
int main()
{
    
   while(1){
            scanf("%d",&n);
            if(n==0){
                break;
            }
            memset(tree,0,sizeof(tree));
            memset(a,0,sizeof(a));
            memset(lazy,0,sizeof(lazy));
            lli b[n];
            for(int i=0;i<n;i++)
            {
                scanf("%lld",&b[i]);
            }
            /*for(int i=0;i<n;i++){
                cout<<b[i]<<" ";
            }
            cout<<"\n";*/
            a[0]=b[0];
            for(int i=1;i<(2*n);i++){
                a[i] = a[i-1] + b[(i%n)];
            }
            /*for(int i=0;i<(2*n);i++){
                cout<<a[i]<<" ";
            }
            cout<<"\n";*/
            int nn = 2*n - 1;
            buildTree(0,nn,1);
            /*for(int i=1;i<=4*n;i++)
            {
                cout<<tree[i]<<" ";
            }
            cout<<"\n";*/
            lli ans=0;
           
 
            for(int i=0;i<n;i++)
            {
               lli minel = query(0,nn,i,i+n-1,1);
               if(minel >=0){
                   ans++;
               }
               updateTree(1,0,nn,i,nn,b[i]);
              
 
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
            printf("%lld\n",ans);
    }
    return 0;
} 