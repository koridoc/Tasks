#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(const int a, const int b) {
	return a > b;
}

#define MAX 2000000002
int main() {
	int n, ans = 0;
	cin >> n;

	vector<int> d(n + 2, -1), p(n + 2, MAX), a(n), pa(n);
	d[0] = MAX; p[0] = -1; pa[0] = -1;

	for (int i = 0; i < n; i++) {
		cin>>a[i];

		auto j = upper_bound(d.begin(), d.end(), a[i], cmp);
		int pj = static_cast<int>(j - d.begin());

		if (a[i] <= *(j - 1) && *j < a[i]) {
			*j = a[i];
			p[pj] = i;
			pa[i] = p[pj - 1];

			if(ans < pj) ans = pj; 
		}
	}
	cout<<ans<<endl;

	int i = p[ans];
	vector<int> res;
	res.reserve(ans);
	res.emplace_back(i+1);

	while (pa[i] != -1){
		i = pa[i];
		res.emplace_back(i + 1);
	}
	for (int i = res.size() -1; i >= 0; i--)
		cout<<res[i]<<" ";

	return 0;
}