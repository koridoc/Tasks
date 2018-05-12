#include <iostream>
#include <utility>
#include <vector>
#include<algorithm>

using Segment = std::pair<int, int>;

bool cmp(Segment a, Segment b) {
	return a.second < b.second;
}

std::vector <int> get_covering_set(std::vector <Segment> segments) {
	std::vector <int> result;

	// fix this function
	std::sort(segments.begin(), segments.end(), cmp);
	
	auto it = segments.begin();

	while(it != segments.end()) {
		result.push_back(it->second);
		while (it != segments.end() && result.back() >= it->first)
			it++;
	}
	
	return result;
}

int main(void) {
	int segments_count;
	std::cin >> segments_count;
	std::vector <Segment> segments(segments_count);
	for (auto &s : segments) {
		std::cin >> s.first >> s.second;
	}

	auto points = get_covering_set(std::move(segments));
	std::cout << points.size() << std::endl;
	for (auto point : points) {
		std::cout << point << " ";
	}
	std::cout << std::endl;
}