#include <iostream>
#include <vector>

using namespace std;

int main(void){
	int A, B, C;
	cin >> A >> B >> C;
	
	long answer = 1;
	long multiply = A%C;
	
	while(B>0){
		if(B%2==1){
			answer *= multiply;
			answer %= C;
		}
		multiply = ((multiply%C)*(multiply%C))%C;
		B /=2;
	}
	
	cout << answer;
}
