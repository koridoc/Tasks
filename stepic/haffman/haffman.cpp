#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct HaffNode {
	int f;
	char c;
	HaffNode *left, *right;
};

bool cmp(const HaffNode a, const HaffNode b) {
	return a.f < b.f;
}

int main() {
	string s;
	map<char, int> tree;

	getline(cin, s);

	for (auto i : s)
		tree[i]++;

	priority_queue<HaffNode>;

	return 0;
}