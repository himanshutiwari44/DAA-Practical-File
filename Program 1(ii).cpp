#include <iostream>
#include <vector>
//#include <algorithm>
using namespace std;

//Question: Given an already sorted array of positive integers, design an algorithm and implement it using a program to find whether given key element is present in the array or not. Also, find total number of comparisons for each input case. (Time Complexity = O(logn), where n is the size of input).

int binarySearch (vector <int> & arr, int target){
     int i = 0, j = arr.size() - 1, noOfComparisons = 0;
     if (j == 0) {cout << "Not Present "; return noOfComparisons;}
     while (i <= j){
          int mid = i + (j - i)/2;
          ++noOfComparisons;
          if (arr[mid] == target){cout<<"Present "; return noOfComparisons;}
          else if (arr[mid] > target) j = mid - 1;
          else i = mid + 1;
     }
     cout<<"Not Present ";
     return noOfComparisons;
}

int main (){
     int size, target;
     cout<<"\nEnter no. of elements : "; cin>>size; 
     cout<<"Enter elements : ";
     vector <int> arr (size);
     for (int i = 0; i < size; ++i) cin>>arr[i];
     cout<<"Enter element to search : "; cin>>target;
     //sort(arr.begin(), arr.end()); //If array is not already sorted use sort for binary search
     cout<<endl<<binarySearch(arr, target)<<endl;
     return 0;
}