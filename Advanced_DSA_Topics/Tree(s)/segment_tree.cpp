#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// function to build a tree
void build_tree(const vector<int> &arr,const int &low,const int &high,const int &idx,vector<int> &seg){
    if(low == high){
        seg[idx] = arr[low];
    }
    else {
        int mid = low + (high - low)/2;
        build_tree(arr,low,mid,2*idx+1,seg);
        build_tree(arr,mid+1,high,2*idx+2,seg);
        seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
    }
}

// function to handle a query
int query(const vector<int> &seg,const int &left,const int &right,const int &low,const int &high,const int &idx){
    if(low == high){
        return seg[idx];
    }
    else if(low >= left && high <= right)return INT_MAX;
    else {
        int mid = low + (high - low)/2;
        int left_sub = query(seg,left,right,low,mid,2*idx+1);
        int right_sub = query(seg,left,right,mid+1,high,2*idx+2);
        return min(left_sub,right_sub);
    }
}

// function to update the tree
void update(vector<int> &seg,const int &idx,const int &low,const int &high,const int &i,const int &val){
    if(low == high){
        seg[idx] = val;
        return;
    }
    else {
        int mid = low + (high - low)/2;
        if(i <= mid)update(seg,2*idx+1,low,mid,i,val);
        else update(seg,2*idx+2,mid+1,high,i,val);
    }
    seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
}

int main(){
    int size;
    cin>>size;
    vector<int> arr(size);
    for(auto &ele : arr){
        cin>>ele;
    }
    vector<int> seg(4*size,INT_MAX);
    return 0;
}