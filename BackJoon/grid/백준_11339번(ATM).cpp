#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	
	int num;
	cin >> num;
	int sum = 0;
	int arr[num];
	
	for(int i=0; i<num; i++){
		cin >> arr[i];
	}
	
	sort(arr,arr+num);
	
	for(int i=0; i<num-1; i++){
		arr[i+1] = arr[i] + arr[i+1];
		sum += arr[i+1];
	}
	
	cout << sum+arr[0];
}
