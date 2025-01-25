#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int numArray;
        cin>>numArray;
        vector<int> arr(numArray, 0);
        for(int i=0; i<numArray; i++){
            int ele;
            cin>>ele;
            arr[i] = ele;
        }

        vector<vector<int>> answer(numArray, vector<int> (numArray, 0));
        for(int i=0; i<numArray; i++){
            answer[i][i] = arr[i];
            cout<<answer[i][i]<<" ";
        }

        for(int i=1; i<numArray; i++){
            for(int j=0; j<numArray-i; j++){
                answer[j][j+i] = max(answer[j][j+i-1], answer[j+1][j+i]);
                cout<<answer[j][j+i]<<" ";
            }
        }
        cout<<"\n";
    }
}