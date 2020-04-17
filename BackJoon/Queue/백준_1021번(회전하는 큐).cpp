#include <iostream>
#include <deque>

using namespace std;

int N,M;

deque<int> dq;
deque<int> place;

/*
int where(deque<int> dq, int which){
	int cnt = 0;
	
	for(int i=0; i<=N; i++){
		int y = dq.front();
		cout << which << "=" << y <<"\n";
		dq.pop_front();
		if(y == which){
			break;
		}
		else{
			dq.push_back(y);
			cnt++;
		}
	}
	return cnt;
}
*/



int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	cin >> M;
	
	int howmany;
	
	for(int i=1; i<=N; i++){
		dq.push_back(i);
	}
	
	for(int i=1; i<=M; i++){
		int x;
		cin >> x;
		place.push_back(x);
	}
	
	int cnt1[M] = {0};
	
	for(int i=0; i<M; i++){
	
	int x = place.front();
	place.pop_front();
	int left_cnt = 0;
	int right_cnt = 0;
	
	for(int i=0; i<N; i++){
		int y = dq.front();
		dq.pop_front();
//		cout << y << "=" << x << "\n";
		if(y == x){	
			dq.push_back(y);		
			break;
		}
		else{
			dq.push_back(y);
			left_cnt++;
		}
	}
	
	for(int i=0; i<N; i++){
		int z = dq.back();
		dq.pop_back();
		cout << "----------";
		cout << z << "=" << x << "\n";
		if(z == x){	
			dq.push_front(z);		
			break;
		}
		else{
			dq.push_front(z);
			right_cnt++;
		}
	}
	
	if(right_cnt >= left_cnt)
		cnt1[i] += left_cnt;
		
	if(right_cnt < left_cnt)
		cnt1[i] += right_cnt;
	
	place.push_back(x);
}
	
	for(int i=0; i<M; i++){
		cout << cnt1[i] << " ";
	}
}
