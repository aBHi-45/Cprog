#include<iostream>
using namespace std;

int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    int search;
    cin>>search;
    for( int i=0; i<size; i++){
        if(search == arr[i]){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}