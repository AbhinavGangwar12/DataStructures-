#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 1e5
int N = 100,M = 100;
// dp array
vector<vector<int>> arr(N,vector<int>(M,INF));
int function(const vector<vector<int>> &grid,const int &rows,const int &cols,const int &c,const int &r){
    if(r >= rows || c >= cols)return INF;
    if(arr[r][c] == -1){
        // transition
        arr[r][c] = grid[r][c] + min(function(grid,rows,cols,c+1,r),function(grid,rows,cols,c,r+1));
        return arr[r][c];
    }
    else return arr[r][c];
}

int main(){
    cin>>N>>M;
    vector<vector<int>> grid(N,vector<int>(M));
    function(grid,N,M,0,0);
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            cin>>grid[i][j];
        }
    }
    // the first element contains the sum of the shortest path 
    cout<<arr[0][0]<<endl;
    // resetting grid for further use
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            arr[i][j] = INF;
        }
    }
    
    return 0;
}