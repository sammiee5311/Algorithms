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
	
    for (int i = num; i > 0; i--)
    {
        cnt = cnt + price / arr[i];
        price = price % arr[i];
    }
    
	cout << cnt;
}
