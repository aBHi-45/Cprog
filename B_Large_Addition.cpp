#include<bits/stdc++.h>
using namespace std;
using ull = long long;

int main(){
    int t;
    cin>>t;
    while(t--){
        ull num;
        cin>>num;
        bool yn = true;
        while(num){
            int val = num>10? num%10 + 10 : num;
            num = num/10 - 1;
            if(val >= 10 && val<19 && num >= 0){
                continue;
            }else {
                yn=false;
                break;
            }
        }
        string ans = yn? "YES":"NO";
        cout<<ans<<endl;
    }
}