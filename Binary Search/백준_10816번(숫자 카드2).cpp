#include <iostream>
#include <algorithm>

using namespace std;

int arr1[500001];
int arr2[500001];
int result[500001];

int lower_binary(int*arr,int target,int size) {
    int mid, start, end;
    start = 0, end = size - 1;
 
    while (end > start){
        mid = (start + end) / 2;
        if (arr[mid] >= target)
            end = mid;
        else start = mid + 1;
    }
    return end;
}
 
int upper_binary(int*arr, int target,int size) {
    int mid, start, end;
    start = 0, end = size - 1;
 
    while (end > start) {
        mid = (start + end) / 2;
        if (arr[mid] > target)
            end = mid;
        else start = mid + 1;
    }
    return end;
}

int main(void){
	int N,M;
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> arr1[i];
	}

	sort(arr1, arr1 + N);
	
	cin >> M;
	
	for(int i=0; i<M; i++){
		cin >> arr2[i];
	}
	
    for (int i = 0; i < M; i++) {
        int lower = lower_binary(arr1, arr2[i], N);
        int upper = upper_binary(arr1, arr2[i], N);
        if (upper == N - 1 && arr1[N - 1] == arr2[i])
            upper++;
        result[i] = upper - lower;
    }
 
    for (int i = 0; i < M; i++) {
        printf("%d ", result[i]);
    }
}
