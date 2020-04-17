#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	char cha;
	cin >> n;
	
	stack<char> s;
	
	for(int i=0; i<n; i++){
		int left=0,right=0;
		string str;
		cin >> str;
		
		for(int j=0; j<str.size(); j++){
			s.push(str[j]);
		}
		
		while(!s.empty()){
			if(s.top() == '('){
				left++;
				s.pop();
			}
			else if(s.top() == ')'){
				right++;
				s.pop();
			}
		}
		if(left+right >= 2){
		if(left == right)	
			cout << "YES" << "\n";
		else if(left != right)
			cout << "NO" << "\n";
		}
	}
}
