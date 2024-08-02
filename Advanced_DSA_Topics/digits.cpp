#include<iostream>
#include<cmath>
using namespace std;
int count_digits(const int &num){
  return log10(num)+1;
}
int main(){
  cout<<count_digits(1234)<<endl;
  return 0;
}
