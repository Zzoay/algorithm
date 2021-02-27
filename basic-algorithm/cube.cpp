
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;


float cubeBisearch(int num){
  float l=0, r=num, mid, tmp;
  float epsilon = 1e-6;

  l = num > 0? 0: num;
  r = num > 0? num: 0;

  while(l<r){
    mid = l + (r-l)/2;
    tmp = num/mid/mid - mid;

    if(abs(tmp) < epsilon) return mid;
    else if(tmp > 0) l = mid;
    else r = mid;
  }
}

float cubeNewton(int num){
  float res = num / 2;
  float epsilon = 1e-6;
  
  while(true){
    res = (2*res + num/res/res) / 3;
    if(abs(num/res/res-res) < epsilon) return res;
  }
}

int main(){
  int num = -900;
  float res;
  // res = cubeBisearch(num);
  res = cubeNewton(num);
  cout << res << endl;
}