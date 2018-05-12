#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

void LIMSBottomUp(const vector<int> &a)
{
	vector<int> D, prev;
	for (auto i = 0; i < a.size(); ++i) {
		D.push_back(1);
		prev.push_back(-1);
		int j = (int)(upper_bound(D.begin(),D.end(),a[i]) - D.begin());
		//for (auto j = 0; j <= i - 1; ++j)
			if ((a[i] <= a[j]) && ((D[j] + 1) > D[i])) {
				D[i] = D[j] + 1;
				prev[i] = j;
			}
	}
	int ans = D[0], pos	= 0;
	for (size_t i = 0; i < a.size(); i++){
		if (D[i] > ans) {
			ans = D[i];
			pos = i;
		}
	}

	vector<int> path;
	while (pos != -1){
		path.emplace_back(pos+1);
		pos = prev[pos];
	};
	cout<<path.size()<<endl;
	for(int i = path.size() -1 ; i >= 0 ;i--)
		cout<<path[i]<<" ";
}

int main(void) {
	size_t number_count;
	std::cin >> number_count;
	std::vector<int> numbers(number_count);
	for (auto &number : numbers) {
		std::cin >> number;
	}

	LIMSBottomUp(numbers);
}