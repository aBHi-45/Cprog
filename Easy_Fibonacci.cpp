#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n==1){
        cout<<0<<endl;
    }else if(n==2){
        cout<<0<<" "<<1<<endl;
    }else{
        int a = 0;
        int b = 1;
        cout<<a<<" "<<b<<" ";
        int c = a +b;
        for(int i=0;i<n-2;i++){
            cout<<c<<" ";
            a = b;
            b = c;
            c = a+b;
        }
        cout<<endl;
    }
}