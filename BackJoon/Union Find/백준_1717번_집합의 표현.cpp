#include <iostream>

using namespace std;

int m[100001],a,b,n,c;

int Find(int x){
	if(m[x] == x)
		return x;
	else{
		int p = Find(m[x]);
		m[x] = p;
		return p;
	}
}

void Union(int x, int y){
	x = Find(x);
	y = Find(y);
	
	m[y] = x; 
}

int main(void){
	int check;
	cin >> n >> c;
	
	for(int i=0; i<=n; i++){
		m[i] = i;
	}
	
	for(int i=0; i<c; i++){
		
		cin >> check >> a >> b;
		
		if(check == 0){
			Union(a,b);
		}
		else if(check == 1){
			int a_parent = Find(a);
			int b_parent = Find(b);
		
		if(a_parent == b_parent)
			cout << "Yes\n";
		else
			cout << "No\n";
		}
	}
}

