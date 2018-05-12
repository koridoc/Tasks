#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k = 1;
	cin >> n;

	vector<int> r;

	int min = 1;

	while (n - min > min){
		r.push_back(min);
		n -= min;
		min++;
	} 

	r.push_back(n);
	cout << r.size() << endl;

	for (auto it : r)
		cout << it << " ";
	return 0;
}