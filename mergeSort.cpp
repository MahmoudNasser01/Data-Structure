#include <iostream>
using namespace std;

void merge(int arr[] , int l , int r){
    //Get the mid
    int mid = (l+r) / 2;
    
    //the index of starting the left sub-array
    int i = l;
    
    //index of starting the right sub array
    int j = mid+1;
    
    //an var to iterate through the temprary array
    int k = l;
    
    //Init the temprary array
    int temp[100];
    
    //compare the vales in the both array
    while(i<=mid && j<=r){
        if(arr[i] < arr[j])temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    
    //Get the remning values from the left array
    while(i<=mid)temp[k++] = arr[i++];
    
    //get the remaining values from the right array
    while(j<=r)temp[k++] = arr[j++];

    //Copy the Temp array into the orignal one
    for(int i = l;i<=r;i++)arr[i] = temp[i];

}

void mergeSort(int arr[] , int l ,int r){
    
    if(l>=r)return;//The Base Case
    
    int mid = (l+r)/2;//Get the mid
    
    //recall the function with the first half
    mergeSort(arr , l ,mid );
    
    //recal the function with the second half
    mergeSort(arr , mid+1, r);

    //Call the merg sort
    merge(arr , l  , r);

}

int main(){
    int n ; cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++)cin>>arr[i];
    mergeSort(arr , 0 , n-1);
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
