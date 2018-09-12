#include <bits/stdc++.h>
using namespace std;

map<int,int> m;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        a[i]=x;
        m[x]++;
    }
    //sort(a,a+n);
    /*for(auto i : m){
        cout<<i.first<<" "<<i.second<<"\n";
    }
    cout<<"\n";*/
    int maxval=2;
    if(m.find(0)!=m.end()){
      maxval=max(2,m[0]);
    }
   
    /*for(auto i : m){
        cout<<i.first<<" "<<i.second<<"\n";
    }
    cout<<"\n";*/
    //cout<<maxval<<"\n";
    for(int i=0;i<n;i++){
      
        for(int j=0;j<n;j++){
            int x = a[i];
            int y = a[j];
            if(i==j){
                continue;
            }

            if(x==0 && y==0){
                continue;
            }

            int b[1005];
            int k=0;
        
            b[0]=a[i];k++;
            b[1]=a[j];k++;
            m[x]--;m[y]--;
             /*for(auto i : m){
                 cout<<i.first<<" "<<i.second<<"\n";
            }
            cout<<"\n";*/
            
            int count=2;
            //cout<<x<<" "<<y<<"\n";
            while(1){
                    //cout<<count<<"\n";
                    int temp = x + y;
                    if(m.find(temp)!=m.end() && m[temp]>0){
                        //cout<<i<<" "<<j<<" "<<temp<<" "<<count<<"\n";
                        m[temp]--;
                        count++;
                        x = y;
                        y = temp;
                        b[k]=temp;
                        k++;
                    }else{
                        break;
                    }                   
            }
            if(count > maxval){
                //cout<<i<<" "<<j<<" "<<count<<"\n";
                maxval = count;
            }

            for(int g=0;g<k;g++){
                m[b[g]]++;
            }
        }
    }
    printf("%d\n",maxval);
    return 0;
}