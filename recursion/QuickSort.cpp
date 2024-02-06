// Keep it up Champ ;)
#include <iostream>
#include <bits/stdc++.h>
#include <array>


using namespace std;

void printAr(int *arr , int Start  ,  int End){
    for(int i = Start ; i <=  End ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int *arr , int low , int high){

        // picking a pivot element
            // pivot can be any element , 1st , last, middle , random ...
            // here pivot = first element 
    int i = low +1 , j = high , pivot = arr[low];
    
    while (i <= j){
        while(arr[i] <= pivot && i <= high){
            i++;
        }
        while(arr[j] > pivot && j >= low){
            j--;
        } 

        if(i <= j){
            swap(arr[i] , arr[j]);
        }
    }
    swap(arr[low] , arr[j]);
    return j;
}

void quick(int *arr , int low , int high){

    if(low <= high) {

        int pivot = partition( arr, low , high);

        quick(arr , low , pivot-1 );
        quick(arr , pivot +1 , high );
    }
}

int main() {

    int arr[] = {9,9,9,9,9,9,9,9,9};
    int size = sizeof(arr) / sizeof(int);
    int n = size -1 ;

    cout<< "before : ";
    printAr(arr , 0, n);

    quick(arr , 0, n);

    cout << "after : ";
    printAr(arr , 0 , n); 

    return 0;

}

// Time Complexity : O(n log n)  , worst case : O(n^2)
// Space Complexity :  O(1)
