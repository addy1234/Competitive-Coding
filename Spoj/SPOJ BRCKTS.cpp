
#include <bits/stdc++.h>
using namespace std;
 
int n,m;
int a[200005],tree[800005][2];
char str[200005];
 
void buildTree(int l ,int r, int index)
{
    if(l==r)
    {
       tree[index][0]=(str[l]=='(');
       tree[index][1]=(str[l]==')');
       return;
    }
    int mid = (l+r)/2;
    buildTree(l,mid,2*index);
    buildTree(mid+1,r,2*index+1);
    int val = min(tree[2*index][0],tree[2*index+1][1]);
    tree[index][0] = tree[2*index][0] + tree[2*index+1][0] - val;
    tree[index][1] = tree[2*index][1] + tree[2*index+1][1] - val;
    return;
}
 
void updateTree(int index,int l ,int r,int idx)
{
    if(l==r)
    {
        if(str[idx]==')'){
           tree[index][0]=1;
           tree[index][1]=0;
           str[idx]='(';
        }else{
           tree[index][0]=0;
           tree[index][1]=1;
           str[idx]=')';
        }
        return;
    }
 
    int mid = (l+r)/2;
    if(idx <= mid) 
    {
       updateTree(2*index,l,mid,idx);
    }
    else
    {
       updateTree(2*index+1,mid+1,r,idx);
    }
 
    int val = min(tree[2*index][0],tree[2*index+1][1]);
    tree[index][0] = tree[2*index][0] + tree[2*index+1][0] - val;
    tree[index][1] = tree[2*index][1] + tree[2*index+1][1] - val;
    return;
}
 
 
 
int main()
{
   
    for(int c=1;c<=10;c++){
            //memset(tree,0,sizeof(tree));
            cout<<"Test "<<c<<":"<<"\n";
            scanf("%d",&n);
            scanf("%s",str);
 
            buildTree(0,n-1,1);
        /* for(int i=1;i<=4*n;i++)
            {
                cout<<tree[i]<<" ";
            }
            cout<<"\n";*/
            int m;
            scanf("%d",&m);
 
            for(int z=0;z<m;z++)
            {
                int k;
                scanf("%d",&k);
                if(k!=0){
                    updateTree(1,0,n-1,k-1);
                }else{
                    if(tree[1][0]==0 && tree[1][1]==0){
                        cout<<"YES\n";
                    }else{
                        cout<<"NO\n";
                    }
                }
            }
    }
    return 0;
}
