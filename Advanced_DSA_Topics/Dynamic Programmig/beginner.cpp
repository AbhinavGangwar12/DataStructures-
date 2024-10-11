// fibonacci without using dp 
#include<iostream>
#include<vector>

using namespace std;

int function_calls = 0;
int function = 0;
int fib(int n){
    function_calls++;
    if(n == 1 || n == 2)return 1;
    return fib(n-1)+fib(n-2);
}
// using dp
vector<int> dp(40,-1);
int dfib(int n){
    function++;
    if(n == 1 || n == 2){
        return 1;
    }
    if(dp[n] != -1)return dp[n];
    else {
        return dp[n] = dfib(n-1) + dfib(n-2);
    }
}

int main(){
    int n = 25;
    std::cout<<fib(n)<<endl;
    std::cout<<function_calls<<endl;
    // using dp
    std::cout<<dfib(n)<<endl;
    std::cout<<function<<endl;

    return 0;
}
