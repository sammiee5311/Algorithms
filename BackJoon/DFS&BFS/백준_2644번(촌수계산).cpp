#include <iostream>
#include <queue>

using namespace std;

int n,m,x,y;
int num1,num2;
int MAP[101][101];
int chonsu[101];
bool visited[101];

queue<int> q;

int bfs(int num){
	visited[num] = 1;
	q.push(num);
	int temp;
	
	while(!q.empty()){
		temp = q.front();
		q.pop();
		
		for(int i=1; i<=m; i++){
			if(MAP[temp][i] == 1 && !visited[i]){
				visited[i] = 1;
				chonsu[i] = chonsu[temp] + 1;
				q.push(i);
			}
		}
	}
}

int main(void){
	cin >> n;
	cin >> num1 >> num2;
	cin >> m;
	
	for(int i=1; i<=m; i++){
		cin >> x >> y;
		MAP[x][y] = 1;
		MAP[y][x] = 1;
	}
	
	bfs(num1);
	
	if(chonsu[num2] != 0){
		cout << chonsu[num2] << "\n";
	}
	else
		cout << "-1" << "\n";
}
