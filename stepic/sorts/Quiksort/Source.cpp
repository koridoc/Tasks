#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int search(vector<int> &src, int key){
	auto it = lower_bound(src.begin(),src.end(),key);
	return static_cast<int>(it - src.begin());
}

int main(){
	int n, m, at,bt;

	cin>>n>>m;
	vector<int> a;	a.reserve(n);
	vector<int> b ;	b.reserve(n);
	for (size_t i = 0; i < n; i++){
		cin>>at>>bt;
		a.emplace_back(at);
		b.emplace_back(bt);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for(int i = 0; i < m; i++){
		cin>>at;
		cout<<search(a,at + 1) - search(b,at)<<" ";
	}

	return 0;
}