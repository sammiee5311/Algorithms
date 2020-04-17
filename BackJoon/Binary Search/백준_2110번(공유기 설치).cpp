#include <iostream>
#include <algorithm>

using namespace std;

int N,C;
int house[200000];

int check(int mid){
	int cnt=1;
	int prev = house[0];
	for(int i=0; i<N; i++){
		if(house[i] - prev >= mid){
			cnt++;
			prev = house[i];
		}
	}
	
	return cnt >= C;
}

int main(void){
    ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> C;
	
	for(int i=0; i<N; i++){
		cin >> house[i];
	}
	
	sort(house,house + N);
	
	long long low=1, high = house[N-1] - house[0];
	long long result = 0;
	while(low <= high){
		long long mid = (low + high) / 2;
		
		if(check(mid)){
			result = max(result,mid);
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << result;
}
