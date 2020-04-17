#include <iostream>

using namespace std;

int N,M;
int parent[1001];

int Find(int x){
	if(parent[x] == x)
		return x;
	
	else
		return parent[x] = Find(parent[x]);
}

int Union(int x, int y){
	x = Find(x);
	y = Find(y);
	parent[y] = x;
}

int main(void){
	cin >> N >> M;
	
	for(int i=1; i<=N; i++){
		parent[i] = i;
	}
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			int x;
			cin >> x;
			if(x == 1){
				if(Find(i) != Find(j))
					Union(i,j);
			}
		}
	}
	
	int k;
	cin >> k;
	k = Find(k);
	for(int i=1; i<M; i++){
		int x;
		cin >> x;
		if(k != Find(x))
			cout << "No\n";
	}
	
	cout << "Yes\n";
}
