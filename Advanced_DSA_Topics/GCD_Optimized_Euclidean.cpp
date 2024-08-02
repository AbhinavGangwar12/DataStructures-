#include<iostream>
using namespace std;

int gcd(const int num1,const int num2){
  if(b == 0)return a;
  return gcd(b,a%b);
}

int main(){
  cout<<gcd(12,15)<<endl;
  return 0;
}
