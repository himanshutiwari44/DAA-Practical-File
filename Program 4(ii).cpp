#include <iostream>
#include <vector>
using namespace std;

//Question: Given an unsorted array of integers, design an algorithm and implement it using a program to sort an array of elements by partitioning the array into two subarrays based on a pivot element such that one of the sub array holds values smaller than the pivot element while another sub array holds values greater than the pivot element. Pivot element should be selected randomly from the array. Your program should also find number of comparisons and swaps required for sorting the array.

void swap (int & a, int & b){
     int temp = a; a = b; b = temp;
}

int partition (vector <int> & arr, int start, int end, int & comparisons, int & swaps){
     int size = end - start + 1, randomNum = rand() % size + start;
	swap(arr[end], arr[randomNum]); ++swaps;
     int pivot = arr[end], i = start - 1;
     for (int j = start; j <= end - 1; ++j) {
          ++comparisons;
          if (arr[j] < pivot) {++swaps; swap(arr[++i], arr[j]);}
     }
     swap(arr[end], arr[i + 1]); ++swaps;
     return i + 1;
}

pair <int, int> quickSort (vector <int> & arr, int start, int end){
     if (start >= end) return {0, 0};
     int comparisons = 0, swaps = 0;
     int pivot = partition(arr, start, end, comparisons, swaps);
     pair <int, int> result;
     result = quickSort(arr, start, pivot - 1); comparisons += result.first; swaps += result.second;
     result = quickSort(arr, pivot + 1, end); comparisons += result.first; swaps += result.second;
     return {comparisons, swaps};
}

int main (){
     srand(time(0));
	int size;
     cout<<"\nEnter no. of elements : "; cin>>size; 
     cout<<"Enter elements : ";
     vector <int> arr (size);
     for (int i = 0; i < size; ++i) cin>>arr[i];
	pair <int, int> values = quickSort(arr, 0, arr.size() - 1);
	cout << "\nSorted Array : ";
	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
	cout << "\nNo. of inversions : " << values.first;
	cout << "\nNo. of comparisons : " << values.second << endl;
	return 0;
}