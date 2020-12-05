#include <iostream>
using namespace std;
    void Bubble_sort(int arr[] , int n) {
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(arr[j] > arr[j+1]){
                    swap(arr[j]  , arr[j+1]);
                }
            }
        }

    }

int main(int argc, char** argv) {
    int n;  cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++)cin>>arr[i];
    Bubble_sort(arr , n);
    for(int i = 0;i<n;i++)cout<<arr[i]<<" ";


    return 0;
}
