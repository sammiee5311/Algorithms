#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int num;
	cin >> num;
	
	for(int i=1; i<=num; i++){
		q.push(i);
	}
	
	while(q.size() != 1){
		int x;
		q.pop();
		x = q.front();
		q.pop();
		q.push(x);
	}
	
	cout << q.front(); 
	
}
