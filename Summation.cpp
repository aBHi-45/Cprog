#include<iostream>
using namespace std;

int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    long long sum = 0;
    for( int i=0; i<size; i++){
        sum += arr[i];
    }
    cout<<abs(sum)<<endl;
}