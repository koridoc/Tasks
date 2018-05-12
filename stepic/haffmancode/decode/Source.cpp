#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


int main() {
unordered_map<string,string> t;
	int n, len;
	cin>>n>>len;
	
	for (size_t i = 0; i < n; i++){
		string s, code;
		cin>>s>>code;
		t[code] = s[0];
	}

	string s, tmp, r;

	cin >> s;

	for (auto i:s){
		tmp+=i;
		if (t.find(tmp) != t.end()) {
			r+=t[tmp];
			tmp.clear();
		}
	}
	cout<<r;
	return 0;
}