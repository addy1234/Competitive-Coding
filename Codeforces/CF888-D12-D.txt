#include <iostream>
using namespace std;
#define lli long long int

lli n;

lli func(int k)
{
    if(k==1)
    {
        return 1;
    }
    else if(k==2)
    {
        return (1 + 1ll*n*(n-1)/2);
    }
    else if(k==3)
    {
        return (1 + 1ll*n*(n-1)/2 + 1ll*n*(n-1)*(n-2)/3 );
    }
    else
    {
        return (1 + 1ll*n*(n-1)/2 + 1ll*n*(n-1)*(n-2)/3 + 3ll*n*(n-1)*(n-2)*(n-3)/8);
    }
}
int main()
{
    cin>>n;
    int k;
    cin>>k;

    cout<<func(k)<<"\n";
    return 0;
}
