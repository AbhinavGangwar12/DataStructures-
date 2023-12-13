#include<iostream>
using namespace std;

int search(int arr[][5],int row,int col,int key){
    int row_number = 0;
    int comparisions = 0;
    int col_number = col-1;
    while(row_number < row && col_number > -1){
        if(arr[row_number][col_number] == key){
            cout<<comparisions<<endl;
            return 1;
        }
        else if(arr[row_number][col_number] < key){
            row_number++;
            comparisions++;
        }
        else {
            comparisions++;
            col_number--;
        }
    }
    cout<<comparisions<<endl;
    return 0;
}

int main(){
    int arr[5][5] = { {1,4,7,11,15} , {2,5,8,12,19} , {3,6,9,16,22} , {10,13,14,17,24} , {18,21,23,26,30}};
    cout<<search(arr,5,5,10);
    return 0;
}

/*
it has a simple approach 
if key element is greater than current element then no element in that row should be greater then current ele so we increased row number
and if key is smaller than current ele then it must be present on the left of current column so we decreased the column number by one 
K.I.M. that we have to start with the element which is present on the top right corner i.e. row_number = 0 and column_number = number of columns - 1
do it till row_number reaches to number of rows - 1 and column_number reaches to -1.
*/