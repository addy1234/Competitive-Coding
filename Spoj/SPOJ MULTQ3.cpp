#include <bits/stdc++.h>
using namespace std;
 
int n,m;
int a[1000005],tree[4000005][3];
int lazy[4000005];
 

void resolve(int index){
    lazy[index]%=3;
    int b[6];
    for(int i=0;i<6;i++){
        b[i] = tree[index][i%3];
    }
    for(int i =lazy[index];i<(lazy[index]+3);i++){
        tree[index][i-lazy[index]]  = b[i];
    }
    lazy[2*index]+=lazy[index];
    lazy[2*index+1]+=lazy[index];
    lazy[index]=0;
}

void buildTree(int l ,int r, int index)
{
    if(l==r)
    {
       tree[index][0]=1;
       tree[index][1]=tree[index][2]=0;
       lazy[index]=0;
       return;
    }
    int mid = (l+r)/2;
    buildTree(l,mid,2*index);
    buildTree(mid+1,r,2*index+1);
    tree[index][0] = tree[2*index][0] + tree[2*index+1][0];
    tree[index][1] = tree[2*index][1] + tree[2*index+1][1];
    tree[index][2] = tree[2*index][2] + tree[2*index+1][2];
    lazy[index]=0;
    return;
}
 
void updateTree(int index,int l ,int r,int ql,int qr,int val)
{
    
    if(lazy[index]!=0){
        resolve(index);
    }
 
    if(ql>r || qr<l)
    {
        return;
    }
    
    if(l >= ql && r<=qr)
    {
        lazy[index]=1;
        resolve(index);
        lazy[index]=0;
        return;
    }
 
    int mid = (l+r)/2;
    updateTree(2*index,l,mid,ql,qr,val);
    updateTree(2*index+1,mid+1,r,ql,qr,val);
    tree[index][0] = tree[2*index][0]+ tree[2*index+1][0];
    tree[index][1] = tree[2*index][1]+ tree[2*index+1][1];
    tree[index][2] = tree[2*index][2]+ tree[2*index+1][2];
    return;
}
 
int query(int l,int r,int ql,int qr,int index)
{
     if(lazy[index]!=0){
        resolve(index);
    }
 
    if(ql>r || qr<l)
    {
        return 0;
    }
    
    if(l >= ql && r<=qr)
    {
        return tree[index][0];
    }
 
    int mid = (l+r)/2;
    int left = query(l,mid,ql,qr,2*index);
    int right = query(mid+1,r,ql,qr,2*index+1);
    return (left + right);
}
 
int main()
{
            memset(tree,0,sizeof(tree));
            scanf("%d%d",&n,&m);
            for(int i=0;i<n;i++)
            {
                a[i]=0;
            }
 
            buildTree(0,n-1,1);
         /*for(int i=1;i<=4*n;i++)
            {
                cout<<tree[i]<<" ";
            }
            cout<<"\n";*/
 
            for(int z=0;z<m;z++)
            {
                int x,l,r;
                scanf("%d",&x);
 
                if(x==0){
                    scanf("%d%d",&l,&r);
                    updateTree(1,0,n-1,l,r,1);
                }else{
                    scanf("%d%d",&l,&r);
                    cout<<query(0,n-1,l,r,1)<<"\n";
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
    
    return 0;
}