#include <iostream>

using namespace std;

int result[100][100];
int arr1[100][100];
int arr2[100][100];

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N,M,K;
	cin >> N >> M;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> arr1[i][j];
		}
	}
	
	cin >> M >> K;
	
	for(int i=0; i<M; i++){
		for(int j=0; j<K; j++){
			cin >> arr2[i][j];
		}
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<K; j++){
			for(int p=0; p<M; p++){
				result[i][j] += arr1[i][p] * arr2[p][j];
			}
		}
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<K; j++){
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
	
}
