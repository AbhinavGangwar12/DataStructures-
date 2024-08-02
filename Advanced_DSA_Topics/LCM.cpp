#include<iostream>
using namespace std;

int gcd(const int num1,const int num2){
  if(num2 == 0)return num1;
  return gcd(num2,num1%num2);
}

int main(){
  int a = 3,b=5;
  int lcm = (a*b)/gcd(a,b);
  cout<<lcm<<endl;
  return 0;
}
