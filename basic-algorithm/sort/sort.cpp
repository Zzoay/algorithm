
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

void swap(vector<int> &arr, int i, int j){
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

void insertSort(vector<int> &arr){
  int n = arr.size();
  int i, j, tmp;

  for(i=1; i<n; i++){
    tmp = arr[i];

    for(j=i-1; j>=0 && tmp < arr[j]; j--){
      arr[j+1] = arr[j];
    }

    if(j != (i-1)) arr[j+1] = tmp;
  }
}

void bubbleSort(vector<int> & arr){
  int n = arr.size();
  int i, j, tmp;

  for(i = 1; i < n; i++){
    for(j = 0; j < i; j++){
      if(arr[j] > arr[i]) swap(arr, i, j);
    }
  }
}

void selectSort(vector<int> &arr){
  int n = arr.size();
  int i, j, idx;

  for(i = 0; i < n; i++){
    idx = i;

    for(j = i+1; j < n; j++){
      if(arr[j] < arr[idx]) idx = j;
    }
  
    swap(arr, i, idx);
  }
}

void merge(vector<int> &arr, int l, int mid,int h){
  int i=l, j=mid+1, k=0;  
  vector<int> tmp;
  tmp.resize(h-l+1, 0);

  // double pointer
  while(i<=mid && j<=h){  
    if(arr[i] <= arr[j]) 
      tmp[k++] = arr[i++];
    else
      tmp[k++] = arr[j++];
  }

  while(i<=mid)  // add the remaining elements
    tmp[k++] = arr[i++];

  while(j<=h)
    tmp[k++] = arr[j++];

  for(i=l,k=0; i<=h; i++,k++)
    arr[i] = tmp[k];
}

void mergeSort(vector<int> &arr, int l, int h) {
  if(l >= h) return; 
  int mid =  l + ((h - l)>>1);  
  mergeSort(arr, l, mid); 
  mergeSort(arr, mid+1, h);  
  merge(arr, l, mid, h);   
}

int main(){
  vector<int> testSample = {1, 4, 7, 2, 14, 8, 10, 3, 2, 1, 6};

  cout << testSample << endl;

  // insertSort(testSample);
  // bubbleSort(testSample);
  // selectSort(testSample);
  mergeSort(testSample, 0, testSample.size()-1);
  cout << testSample << endl;

  cout << "finished. " << endl; 
  return 0;
}