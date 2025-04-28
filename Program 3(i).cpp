#include <bits/stdc++.h>
using namespace std;

//Question: Given an unsorted array of integers, design an algorithm and a program to sort the array using insertion sort. Your program should be able to find number of comparisons and shifts ( shifts - total number of times the array elements are shifted from their place) required for sorting the array.

pair<int, int> insertionSort (vector <int> & arr){
     int size = arr.size(), comparisons = 0, shifts = 0;
     if (size <= 1) return {0, 0};
     for (int i = 1; i < size; ++i){
          int key = arr[i], j = i - 1;
          while (j >= 0 && arr[j] > key) {++shifts; ++comparisons; arr[j + 1] = arr[j]; -- j;}
          arr[j + 1] = key; ++shifts;
     }
     return {shifts, comparisons};
}

int main(){
	int size;
     cout<<"\nEnter no. of elements : "; cin>>size; 
     cout<<"Enter elements : ";
     vector <int> arr (size);
     for (int i = 0; i < size; ++i) cin>>arr[i];
	pair<int, int> values = insertionSort(arr);
	cout << "\nSorted Array : ";
	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
	cout << "\nNo. of shifts : " << values.first;
	cout << "\nNo. of comparisons : " << values.second << endl;
	return 0;
}