#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(char a, char b){
	if(a > b)
		return true;
	return false;
}

int main(void){
	string s;
	cin >> s;
	long long sum = 0;
	bool zero = false;
	
	for(int i=0; i<s.size(); i++){
		sum += s[i] - '0';
		if(!(s[i]-'0'))
			zero = true;
	}
	
	if(!zero != 0 || sum % 3 != 0)
		cout << "-1";
	else{
		sort(s.begin(),s.end(),cmp);
		for(int i=0; i<s.size(); i++)
			cout << s[i];
	}
}
