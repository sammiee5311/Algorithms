#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check[26][26];
int MAP[26][26],num[1010],cnt,N;
int dy[]={0,0,-1,1};
int dx[]={1,-1,0,0};

vector <int> house;

void dfs(int x, int y){
	MAP[x][y] = 0;
	cnt++;
	
	for(int i=0; i<4; i++){
		if(x+dy[i]<0 || x+dy[i]>=N || y+dx[i]<0 || y+dx[i]>=N)
			continue;
		if(MAP[x+dy[i]][y+dx[i]] == 1)
			dfs(x+dy[i], y+dx[i]);
	}
}

int main(void){
	cin >> N;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			scanf("%1d", &MAP[i][j]);
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(MAP[i][j] == 1){
				cnt=0;
				dfs(i,j);
				house.push_back(cnt);
			}
		}		
	}
	
	sort(house.begin(),house.end());
	int ans = house.size();
	cout << ans << "\n";
	for(int i=0; i<ans; i++){
		cout << house[i] << "\n";
	}
	
	
}
