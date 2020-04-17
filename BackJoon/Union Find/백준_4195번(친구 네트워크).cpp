#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n;
char Friend1[21], Friend2[21];
int Friend[200002];
int parent[200002];

int Find(int x){
	
	if(x == parent[x])
		return x;
	else
		parent[x] = Find(parent[x]);
}

int Union(int x, int y){
	x = Find(x);
	y = Find(y);
	
	if(x != y){
		parent[x] = y;
		Friend[y] += Friend[x];
		Friend[x] = 1;
	}
	
	return Friend[y];
}

int main(void){
	int T;
	cin >> T;
	
	for(int i=0; i<T; i++){
		int cnt = 1;
		
		map<string,int> Friend_set;
		cin >> n;
		
		for(int i=1; i<=(2*n); i++){
			parent[i] = i;
			Friend[i] = 1;
		}
		
		for(int i=0; i<n; i++){
			cin >> Friend1 >> Friend2;
			if(Friend_set.count(Friend1) == 0)
				Friend_set[Friend1] = cnt++;
			
			if(Friend_set.count(Friend2) == 0)
				Friend_set[Friend2]= cnt++;
				
			cout << Union(Friend_set[Friend1],Friend_set[Friend2]);
		}
		
	}
	
}
