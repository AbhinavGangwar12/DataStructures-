#include<iostream>
using namespace std;
int power(int num,int power){
  int res = 1;
  while(power>0){
    if(power&1)res *= num;
    num *= num;
    power >>= 1;//p = p / 2;
  }
  return res;
}
int main(){

  cout<<power(2,5);
  return 0;
}
