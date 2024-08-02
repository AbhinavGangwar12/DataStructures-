#include<iostream>
using namespace std;
void prime_factors(const int &num){
  int i;
  for(i = 1;i*i<=num;i++){
    if(num%i==0)cout<<i<<" ";
  }
  i--;
  for(;i>=1;i--){
    if(num%i==0)cout<<num/i<<" ";
  }
}
int main(){
  prime_factors(24);
  cout<<endl;
  return 0;
}
