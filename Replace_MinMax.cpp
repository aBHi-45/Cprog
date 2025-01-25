#include<bits/stdc++.h>
using namespace std;

int main(){
    int t=1;
    while(t--){
        int numArray;
        cin>>numArray;
        vector<int> arr(numArray, 0);
        int minV = INT_MAX;
        int maxV = INT_MIN;
        for(int i=0; i<numArray; i++){
            int ele;
            cin>>ele;
            arr[i] = ele;
            minV = min(minV, ele);
            maxV = max(maxV, ele);
        }

        for(auto i:arr){
            if(i == minV) i = maxV;
            else if(i == maxV) i = minV;

            cout<<i<<" ";
        }
    }
}