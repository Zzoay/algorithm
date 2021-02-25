
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;


template<typename T>
std::ostream & operator<<(std::ostream & os, std::vector<T> vec){
  os<<"{";
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(os," "));
  os<<"}";
  return os;
}

int biSearch(const vector<int> &arr, int num, int l, int h){
  if(l >= h) return -1;

  int mid = l + ((h-l)>>1);
  
  if(num == arr[mid]) return mid;
  else if(num < arr[mid]) return biSearch(arr, num, l, mid-1);
  else return biSearch(arr, num, mid+1, h);

}

int main(){
  vector<int> testSample = {1, 1, 2, 2, 3, 4, 6, 7, 8, 10, 14};

  cout << testSample << endl;

  int idx = biSearch(testSample, 2, 0, testSample.size()-1);
  cout << idx << endl;

  cout << "finished. " << endl; 
  return 0;
}