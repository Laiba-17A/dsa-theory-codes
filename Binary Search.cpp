#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int x) {

  while (left <= right) {
  	cout<<"Low value is "<<left<<" High value is "<<right<<endl;
    int mid = left + (right - left) / 2;

    if (arr[mid] == x) {
      return mid;
    } else if (arr[mid] < x) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1;
}

int main() {

  int num;
  int output;
  int n=20;
  int myarr[20]={0,5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95};  
  cout << "Please enter an element to search" << endl;
  cin >> num;

  output = binarySearch(myarr, 0, 19, num);

  if (output == -1) {
    cout << "No Match Found" << endl;
  } else {
    cout << "Match found at position: " << output << endl;
  }

  return 0;
}
