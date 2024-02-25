#include <iostream>
#include <vector>

int main() {
	int t = 0;
	std::cin >> t;
	char current = '1';
	int n = 0;
	int k = 0;
	std::vector<int> str;
	str.resize(26);
	int number = 0;
	int count = 0;
	for (int i = 0; i != t; ++i) {
		count = 0;
		std::cin >> n >> k;
		for (int j = 0; j != n; ++j) {
			std::cin >> current;
			number = current - 'a';
			str[number] += 1;
		}
		std::cout << i + 1;
		for (int j = 0; j != 26; j++) {
			count += str[j] % 2;
		}
		if ((n - k) % 2 == 0) {
			if ((k - count) >= 0 && (k - count) % 2 == 0) {
				std::cout << "yes";
			}
			else {
				std::cout << "no";
			}
		}
		else {
			if ((k - count >= -1) && (k - count) % 2 != 0) {
				std::cout << "yes";
			}
			else {
				std::cout << "no";
			}
		}
		std::cout << std::endl;

	}
}
