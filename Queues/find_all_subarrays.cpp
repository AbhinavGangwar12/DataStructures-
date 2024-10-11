#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void subarrays(vector<int> &arr,vector<vector<int>> &ans){
    int n = arr.size();
    for(int i = 0;i<n;i++){
        vector<int> temp;
        for(int j=i;j<n;j++){
            temp.push_back(arr[j]);
            ans.push_back(temp);
        }
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    vector<vector<int>> ans;
    subarrays(arr,ans);
    // sort(ans.begin(),ans.end());
    for(auto i : ans){
        cout<<"(";
        for(auto x : i){
            cout<<x<<" ";
        }
        cout<<")\t";
    }
    return 0;
}