#include <iostream>
using namespace std;

class p
{
    public:
    int t;
    int l;
    int r;
};

p arr[200005];
int a[200005];
int n,q,m;

int main()
{
    cin>>n>>q>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    
    for(int i=0;i<q;i++)
    {
        cin>>arr[i].t;
        cin>>arr[i].l;
        cin>>arr[i].r;
    }

    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;

        for(int j=q-1;j>=0;j--)
        {
            if(x>=arr[j].l && x<=arr[j].r)
            {
                if(arr[j].t==1)
                {
                    if(arr[j].l==x)
                    {
                        x = arr[j].r;
                    }
                    else
                    {
                        x--;
                    }
                }
                else 
                {
                    x = arr[j].r + arr[j].l - x;
                }
            }
        }
        cout<<a[x]<<" ";
    }
    return 0;
}
