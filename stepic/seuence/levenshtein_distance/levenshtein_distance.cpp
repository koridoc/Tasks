#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <array>
using namespace std;

int get_levenshtein_distance(const std::string &str1, const std::string &str2) {
	// TODO optimize this function
	const size_t s1 = str1.size();
	const size_t s2 = str2.size();
	if (str1.empty() || str2.empty()) {
		return s1 + s2;
	}
	int a[101][101];

	for (size_t i = 0; i <= s1; i++)
		a[i][0] = i;

	for (size_t i = 0; i <= s2; i++)
		a[0][i] = i;

	for (size_t i = 1; i <= s1; i++)
		for (size_t j = 1; j <= s2; j++)
			a[i][j] = min(min(a[i][j - 1] + 1,
							a[i -1][j] + 1),
							a[i - 1][j - 1] + (int)(str1[i - 1] != str2[j - 1]));



	return a[s1][s2];
}

int main(void) {
	std::string str1;
	std::string str2;

	std::cin >> str1 >> str2;

	std::cout << get_levenshtein_distance(str1, str2) << std::endl;
}