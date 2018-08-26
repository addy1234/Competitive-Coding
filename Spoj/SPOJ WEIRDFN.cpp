#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mod 1000000007

priority_queue <lli> maxHeap;
priority_queue <lli, vector<lli>, greater<lli>> minHeap;
lli median[200005];
lli f[200005];

void addNumber(lli x)
{
    if(x < maxHeap.top())
    {
       maxHeap.push(x);
    }
    else
    {
        minHeap.push(x);
    }
}

void rebalance()
{

    if(maxHeap.size() > minHeap.size() && (maxHeap.size() - minHeap.size()> 1))
    {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    else if(minHeap.size() > maxHeap.size() && (minHeap.size() - maxHeap.size()> 1))
    {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
    else
    {
        return;
    }
}

lli getMedian()
{
    if(maxHeap.size() == minHeap.size())
    {
        return maxHeap.top();
    }
    else
    {
        if(minHeap.size() > maxHeap.size())
        {
            return minHeap.top();
        }
        else
        {
            return maxHeap.top();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--){
        lli sum=0;
        lli n,a,b,c;
        cin>>a>>b>>c>>n;

        if(n==1)
        {
            cout<<"1\n";
            continue;
        }
        maxHeap.push(1);
        sum+=1;
        median[1]=1;
        

        //cout<<sum<<"\n";
        for(int i=2;i<=n;i++){
            lli val = (1ll*a*median[i-1] + i*b + c)%mod;
            sum += val;
            addNumber(val); // inserting the number!!
            rebalance();
            median[i] = getMedian();
           // cout<<sum<<"\n";
        }
        
        cout<<sum<<"\n";
        maxHeap = priority_queue <lli>();
        minHeap = priority_queue <lli, vector<lli>, greater<lli>>() ;
    }
    return 0;
}
