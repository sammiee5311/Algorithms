#include <iostream>

using namespace std;

int fac(int a){
	if(a == 1 || a == 0)
		return 1;
	else
		return fac(a-1) * a;
}

int bin(int a, int b){
	
	return fac(a) / (fac(b) * fac(a-b));
}

int main(void){
	int a , b;
	cin >> a >> b;
	cout << bin(a,b);
}
