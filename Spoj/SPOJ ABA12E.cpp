#include <iostream>
using namespace std;
#define lli long long int

lli prefix[50005];
int n,k;

lli check(lli sum)
{
    lli res=0;
    for(int i=1;i<=n;i++)
    {
        lli mid,l=i,r=n+1;
        while(l<r)
        {
           mid = (l+r)/2;
           if(prefix[mid] - prefix[i-1] > sum)
           {
                r=mid;
           }
           else
           {
                l = mid+1;
           }
        }
        res+=(l-i);
        //cout<<res<<" ";
    }
    //cout<<"\n";
    return res;
}
lli binarySearch(lli l,lli r)
{
    lli mid;
    //cout<<l<<" "<<r<<"\n";
    while(l<r)
    {
        mid = (l+r)/(2ll);
        if(check(mid) >= k)
        {
           //cout<<"hi"<<" "<<check(mid)<<"\n";
           r = mid;
        }
        else
        { 
           //cout<<"hello"<<" "<<check(mid)<<"\n";
           l = mid+1;
        }
    }
    return l;
}
int main()
{
    cin>>n>>k;
    prefix[0]=0;
    for(int i=1;i<=n;i++)
    {
        lli x;
        cin>>x;
        prefix[i] = prefix[i-1] + x;
    }

   cout<<binarySearch(0ll,prefix[n])<<"\n";
   return 0;
}
