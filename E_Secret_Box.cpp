#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long x, y, z, k;
        cin>>x;
        cin>>y;
        cin>>z;
        cin>>k;
        long long ans = 0;
        for(long long a = 1; a<=x; a++){
            for(long long b = 1; b<=y; b++){
                if(k%(a*b) == 0){
                    long long c = k/(a*b);
                    if(c<=z) {
                        long long ways = (long long) (x-a+1)*(y-b+1)*(z-c+1);
                        ans = max(ans, ways);
                    } 
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}