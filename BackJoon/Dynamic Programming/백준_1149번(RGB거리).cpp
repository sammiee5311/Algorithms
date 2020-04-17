#include <iostream>
#include <algorithm>

using namespace std;

int cost[1001][3];
int house[1001][3];

int main(void){
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++){
			cin >> cost[i][j];
		}
	}
	
	house[0][0] = cost[0][0];
	house[0][1] = cost[0][1];
	house[0][2] = cost[0][2];
	
	for(int i=1; i<n; i++){
		house[i][0] = min(house[i-1][1],house[i-1][2]) + cost[i][0];
		house[i][1] = min(house[i-1][0],house[i-1][2]) + cost[i][1];
		house[i][2] = min(house[i-1][0],house[i-1][1]) + cost[i][2];
	}
	
	cout << min(min(house[n-1][0],house[n-1][1]),house[n-1][2]);;
		
}
