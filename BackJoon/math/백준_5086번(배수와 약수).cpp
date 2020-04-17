#include <iostream>

using namespace std;

int main(void){
	while(1){
		int num1,num2;
		cin >> num1 >> num2;
		
		if(num1 == 0, num2 == 0)
			break;		
		
		if(num1 % num2 == 0)
			cout << "multiple" << "\n";

		else if(num2 % num1 == 0)
			cout << "factor" << "\n";
		
		else
			cout << "neither" << "\n";
			
	}
}
