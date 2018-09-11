#include <bits/stdc++.h>
using namespace std;


double check(int n , double x , double y){
    double val=0;
    //cout<<n<<" "<<x<<" "<<y<<"\n";
   for(int i=3;i<=n;i++){
        val = 2*y + 2 - x;
       //cout<<val<<"\n";
       if(val < 0 ){
           return -1;
       } 
       x = y;
       y = val;
   }
   return val;
}

int main()
{
    double A;
    int n;
    while(scanf("%d%lf",&n,&A)==2){
        //cout<<n<<" "<<A<<"\n";
        double l=0,r=A,mid=-1;
        double minval = 0;
        for(int i=1;i<=50;i++){
            mid = (l+r)/2;
            double v = check(n,A,mid);
            //cout<<v<<"\n";
            if(v >=0){
                r=mid;
                minval=v;
            }else{
                l = mid;
            }
        }
        printf ( "%.2lf\n" , minval); 
    }
    return 0;
}
