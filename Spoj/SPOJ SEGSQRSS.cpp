#include <bits/stdc++.h>
using namespace std;
#define lli long long int
 
int n,m;
lli a[1000005],tree[4000005][2];
lli lazy[4000005][2];
 
 
void resolve(int index , int l , int r){
    if(lazy[index][0]==1){
         tree[index][1] += (2*lazy[index][1]*tree[index][0] + (r-l+1)*lazy[index][1]*lazy[index][1]);
         tree[index][0] += (r-l+1)*lazy[index][1];
    }else{
         tree[index][0] = 1ll*(r-l+1)*lazy[index][1];
         tree[index][1] = 1ll*(r-l+1)*lazy[index][1]*lazy[index][1];
    }
 
    if(lazy[index][0]==1){
        lazy[2*index][0] = 1;
        lazy[2*index][1] += lazy[index][1]; 
        lazy[2*index+1][0] = 1;
        lazy[2*index+1][1] += lazy[index][1]; 
    }else
    {
        lazy[2*index][0] = 2;
        lazy[2*index][1] = lazy[index][1]; 
        lazy[2*index+1][0] = 2;
        lazy[2*index+1][1] = lazy[index][1]; 
    }
    lazy[index][0]=0;
    lazy[index][1]=0;
}
 
void buildTree(int l ,int r, int index)
{
    if(l==r)
    {
       tree[index][0]=a[l];
       tree[index][1]=a[l]*a[l];
       lazy[index][0] = lazy[index][1] = 0;
       return;
    }
    int mid = (l+r)/2;
    buildTree(l,mid,2*index);
    buildTree(mid+1,r,2*index+1);
    tree[index][0] = tree[2*index][0] + tree[2*index+1][0];
    tree[index][1] = tree[2*index][1] + tree[2*index+1][1];
    lazy[index][0] = lazy[index][1] = 0;
    return;
}
 
void updateTree(int index,int l ,int r,int ql,int qr,int val,int type)
{
    
    if(lazy[index][0]!=0){
        resolve(index,l,r);
    }
 
    if(ql>r || qr<l)
    {
        return;
    }
    
    if(l >= ql && r<=qr)
    {
        lazy[index][0]=type;
        lazy[index][1]=val;
        resolve(index,l,r);
        lazy[index][0]=0;
        lazy[index][1]=0;
        return;
    }
 
    int mid = (l+r)/2;
    updateTree(2*index,l,mid,ql,qr,val,type);
    updateTree(2*index+1,mid+1,r,ql,qr,val,type);
    tree[index][0] = tree[2*index][0]+ tree[2*index+1][0];
    tree[index][1] = tree[2*index][1]+ tree[2*index+1][1];
    return;
}
 
lli query(int l,int r,int ql,int qr,int index)
{
    if(lazy[index][0]!=0){
        resolve(index,l,r);
    }
 
    if(ql>r || qr<l)
    {
        return 0ll;
    }
    
    if(l >= ql && r<=qr)
    {
        return tree[index][1];
    }
 
    int mid = (l+r)/2;
    lli left = query(l,mid,ql,qr,2*index);
    lli right = query(mid+1,r,ql,qr,2*index+1);
    return (lli)(left + right);
}
 
int main()
{
    int t;
    cin>>t;
    for(int z=1;z<=t;z++){
            cout<<"Case "<<z<<":"<<"\n";
            memset(tree,0,sizeof(tree));
            //memset(lazy,0,sizeof(lazy));
            scanf("%d%d",&n,&m);
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
                int type,l,r,x;
                scanf("%d",&type);
 
                if(type==0){
                    scanf("%d%d%d",&l,&r,&x);
                    l--;r--;
                    updateTree(1,0,n-1,l,r,x,2);
                }else if(type==1){
                    scanf("%d%d%d",&l,&r,&x);
                    l--;r--;
                    updateTree(1,0,n-1,l,r,x,1);
                }else if(type==2){
                     scanf("%d%d",&l,&r);
                     l--;r--;
                     lli ans = query(0,n-1,l,r,1);
                     printf("%lld\n",ans);
                }
 
                /*for(int i=0;i<k;i++)
                {
                    cout<<b[i]<<" ";
                }
                cout<<"\n";*/
                
               /*for(int i=0;i<n;i++)
                {
                    cout<<a[i]<<" ";
                }
                cout<<"\n";*/
            }
    }
    return 0;
}  
