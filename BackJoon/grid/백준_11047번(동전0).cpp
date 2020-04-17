#include <iostream>

using namespace std;

int main(void){
	int num,price;
	cin >> num >> price;
	
	int arr[num];
	int cnt=0;
	
	for(int i=0; i<num; i++){
		cin >> arr[i];
	}
	
	for(int i=num-1; i>=0; i--){
		if(price - arr[i] >= 0){
			while(price>=0){
				cnt++;
				price = price - arr[i];
				cout << price << "\n";
			}
			
			if(price < 0){
				cnt--;
				price = price + arr[i];
			}
		}
	}
	cout << cnt;
}
