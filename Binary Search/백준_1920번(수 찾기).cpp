#include <iostream>
#include <algorithm>

using namespace std;

int arr1[100001];
int arr2[100001];

void BinaryExist(int *arr, int start, int end, int x)
{
	if (start > end)
	{
        cout << "0\n";
		return;
	}
	else
	{
		int mid = (start + end) / 2;
		if (x > arr[mid])
		{
			return BinaryExist(arr, mid+1, end, x);
		}
		else if (x < arr[mid])
		{
			return BinaryExist(arr, 0, mid-1, x);
		}
		else
		{
            cout << "1\n";
			return;
		}
	}
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
	
	for(int i=0; i<M; i++){
  		BinaryExist(arr1, 0, N - 1, arr2[i]);		
	}

}
