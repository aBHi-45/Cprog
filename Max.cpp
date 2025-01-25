#include<iostream>
using namespace std;

int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    int maxV = -5000;
    for( int i=0; i<size; i++){
        maxV = max(arr[i], maxV);
    }
    cout<<maxV<<endl;
}