#include<iostream>
using namespace std;
void printArr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
int binarySearch(int arr[], int begin, int end, int x){
	int pos=-1;
	do{
		int mid=(begin+end)/2;
		if(arr[mid]==x){
			pos=mid;
			return mid;
		}
		if(x> arr[mid]){
			begin=mid+1;
		}
		else if( x< arr[mid]){
			end=mid-1;
		}
	}
	while(begin<=end);
	return pos;
}

int linearSearch(int arr[], int x){
    int length=sizeof(arr)/sizeof(int);
    for(int i=0; i<=length; i++){
        if(arr[i] == x){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[]= {3, 4, 6, 10, 11, 15, 18, 21};
    int length=sizeof(arr)/sizeof(int);
    printArr(arr, length);
    int x, pos;
    cout<<"\nNhap gia tri can tim: ";
    cin >> x;
    pos = binarySearch(arr, 0, length, x);
    cout<<"Binary search: "<< pos;
    cout<<"\nNhap gia tri can tim: ";
    cin >> x;
    pos= linearSearch(arr, x);
    cout<<"Linear search: "<< pos;
    return 0;
}