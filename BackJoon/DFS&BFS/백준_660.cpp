#include <iostream>

using namespace std;

int lotto[13];
int combi[13];
int k;

void dfs(int start, int depth){
	
	if(depth == 6){
		for(int i=0; i<6; i++){
			cout << combi[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for(int i=start; i<k; i++){
		combi[depth] = lotto[i];
		dfs(i+1, depth+1);
	}
}

int main(void){
	while(cin >> k && k){
		for(int i=0; i<k; i++)
			cin >> lotto[i];
		
		dfs(0,0);
		cout << "\n";
	}
}
