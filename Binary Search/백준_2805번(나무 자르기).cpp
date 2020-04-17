#include <iostream>

using namespace std;

long long N,M;
long long lan[1000001];

bool cnt(long long mid){
	long long cnt = 0;
	
	for(int i=0; i<N; i++){
		if(mid < lan[i])
			cnt += lan[i] - mid;
	}
	
	return cnt >= M;
}

int main(void){
	cin >> N >> M;
	
	long long max = 0;
	
	for(int i=0; i<N; i++){
		cin >> lan[i];
		if(max < lan[i])
			max = lan[i];
	}
	
	long long left = 0, right = max;
	
	long long ans = 0;
	
	while(left <= right){
		long long mid = (left+right) / 2;
		
		if(cnt(mid)){
			if(mid > ans)
				ans = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	
	cout << ans;
}
