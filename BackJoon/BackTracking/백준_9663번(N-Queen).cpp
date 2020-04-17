#include <iostream>
#include <cmath>

using namespace std;

int N, ans;
int MAP[15];

bool can_pos(int line){
	for(int i=0; i<line; i++){
		if(MAP[i] == MAP[line] || abs(MAP[line] - MAP[i]) == line - i)
			return false;
	}
	return true;
}

void DFS(int line){
	if(line == N){
		ans++;
		return;
	}
	
	for(int i=0; i<N; i++){
		MAP[line] = i;
		if(can_pos(line) == 1)
			DFS(line+1);
	}
}

int main(void){
	cin >> N;
	DFS(0);
	
	cout << ans;
}
