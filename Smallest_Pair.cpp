#include<iostream>
#include<climits>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int size;
    cin>>size;
    int arr[size];
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    int minV = INT_MAX;
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            minV = min(arr[i]+arr[j]+j-i, minV);
        }
    }
    cout<<minV<<endl;
    }
}