#include <iostream>
#include <algorithm>

using namespace std;
 
int stairs[301];
int scores[301];

int main(void){
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> stairs[i];
	}
	
	scores[0] = stairs[0];
	scores[1] = stairs[0]+stairs[1];
	scores[2] = max(stairs[0]+stairs[2],stairs[1]+stairs[2]);
	
	for(int i=3; i<n; i++){
		scores[i] = max(scores[i-3] + stairs[i-1] + stairs[i],scores[i-2] + stairs[i]);
	}
	
	cout << scores[n-1];
}
