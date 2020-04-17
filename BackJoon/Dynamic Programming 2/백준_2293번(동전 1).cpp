#include <iostream>

using namespace std;

int d[10001];
int coin[101];

int main(void){
	int n,k;
	cin >> n >> k;
	
	for(int i=1; i<=n; i++){
		cin >> coin[i];
	}
	
	d[0] = 1;
	
	for(int i=1; i<=n; i++){
		for(int j=coin[i]; j<=k; j++){
				d[j] += d[j-coin[i]];
		}
	}
	
	cout << d[k];
	
}
