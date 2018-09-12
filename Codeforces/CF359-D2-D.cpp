/* I have build a segment tree that will answer the  gcd of the range in O(logn) per query . Now what i want is to check if this gcd is
present in that range or not , if it is present then we can add it to the answer for that i have created an array that will be like a
sliding window and we will update the array accordingly and see whether the gcd is present or not in O(1).*/
#include <bits/stdc++.h>
using namespace std;

int n;
int a[300005],tree[10000005];

int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

void buildTree(int l ,int r, int index)
{
    if(l==r)
    {
       tree[index]=a[l];
       return;
    }
    int mid = (l+r)/2;
    buildTree(l,mid,2*index);
    buildTree(mid+1,r,2*index+1);
    tree[index] = gcd(tree[2*index],tree[2*index+1]);
    return;
}

int query(int l,int r,int ql,int qr,int index)
{
    if(ql>r || qr<l)
    {
        return -1;
    }
    
    if(l >= ql && r<=qr)
    {
        return tree[index];
    }

    int mid = (l+r)/2;
    int left = query(l,mid,ql,qr,2*index);
    int right = query(mid+1,r,ql,qr,2*index+1);
    if(left==-1 && right==-1){
        return -1;
    }else if(left==-1){
        return right;
    }else if(right==-1){
        return left;
    }
    return gcd(left,right);
}

bool check(int l ,int r, int mid){
    int cnt[1000001]={0};
    for(int i=0;i<mid;i++){
        cnt[a[i]]++;
    }

    for(int i=0;i<=(n-mid);i++){
        int x = query(0,n-1,i,i+mid-1,1);
        if(cnt[x]!=0){
            return 1;
        }
        if(i+mid<n){
            cnt[a[i]]--;
            cnt[a[i+mid]]++;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    //cout<<n<<"\n";
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


    int l=1,r=n,mid=-1,ans=-1;
    while(l<=r){
        mid = (l+r)/2;
        if(check(l,r,mid))
        {
           //cout<<mid<<"\n";
           ans = mid;
           l=mid+1;
        }else{
            //cout<<mid<<"\n";
            r=mid-1;
        }
    }
    //cout<<ans<<"\n";
    vector<int> v;
    int cnt[1000001]={0};
    for(int i=0;i<ans;i++){
        cnt[a[i]]++;
    }
    for(int i=0;i<=(n-ans);i++){
        int x = query(0,n-1,i,i+ans-1,1);
        if(cnt[x]!=0){
            v.push_back(i+1);
        }
        if(i+ans<n){
            cnt[a[i]]--;
            cnt[a[i+ans]]++;
        }
    }
    cout<<v.size()<<" "<<ans-1<<"\n";
    for(int i : v){
        cout<<i<<" ";
    }
    cout<<"\n";
    return 0;
}
