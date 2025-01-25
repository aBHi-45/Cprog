#include<iostream>
#include<climits>
using namespace std;

int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    int minV = INT_MAX;
    int posV = 0;
    for( int i=0; i<size; i++){
        if(minV>arr[i]){
            minV = arr[i];
            posV=i;
        }
    }
    cout<<minV<<" "<<posV+1<<endl;
}