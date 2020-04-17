#include <iostream>
#include <String>

using namespace std;

int N[10001];

int gcd(int a, int b){
	if (a%b == 0)
		return b;
	else
		return gcd(b,a%b);
}

int main(void){
	int A,B,ans1,ans2;
	cin >> A >> B;
	
	if(A>B)
		ans1 = gcd(A,B);
	else
		ans1 = gcd(B,A);
	
	ans2 = A*B/ans1;
	
	cout << ans1 << "\n";
	cout << ans2 << "\n";
}
