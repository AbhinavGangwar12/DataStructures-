#include<iostream>
using namespace std;
int gcd(int num1,int num2){
  while(a!=b){
    if(a>b){
      a = a-b;
    }
    else b = b-a;
  }
  return a;
}
int main(){
  cout<<gcd(12,15)<<endl;
  return 0;
}
