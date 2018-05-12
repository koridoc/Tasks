#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> d(n+1);
	
	d[0] = d[1] = 0;
	for (int i = 2; i <= n; i++){
		d[i] = d[i - 1] + 1;
		if(i % 3 == 0)
			d[i] = min(d[i], d[i / 3] + 1);

		if(i % 2 == 0)
			d[i] = min(d[i], d[i / 2] + 1);
	}
	cout<<d[n]<<endl;
	vector<int> ans(d[n]+1);
	ans[0] = n;
	for (size_t i = 1; i < ans.size(); i++){
		int dt = d[n - 1],
			dn = n - 1;
		if(n % 3 == 0 && dt > d[n / 3])
			dt = d[n / 3], dn = n / 3;

		if(n % 2 == 0 && dt > d[n / 2])
			dt = d[n / 2], dn = n / 2;
		ans[i] = dn;
		n = dn;
	}
	for(int i = ans.size() -1; i >= 0; i--)
		cout<<ans[i]<<" ";

	return 0;
}