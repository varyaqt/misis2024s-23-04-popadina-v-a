#include <iostream>
#include <string>

int main() {
	int t = 0;
	std::cin >> t;
	std::string s0;
	int count = 0;
	std::string s;
	char answer = '1';
	for (int i = 0; i != t; i++) {
		count = 0;
		for (int j = 0; j != 8; j++) {
			std::cin >> s;
			if (s == "RRRRRRRR") {
				count++;
			}
		}
		if (count != 0) {
			answer = 'R';
		}
		else {
			answer = 'B';
		}
		std::cout << answer << std::endl;
	}
}
