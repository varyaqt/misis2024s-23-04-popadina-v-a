#include <iostream>
#include <vector>
int main() {
	int t = 0;
	std::cin >> t;
	int n = 0;
	int s = 0;
	int k = 0;
	int helps = 0;
	int flag = 0;
	std::vector<int> arr;
	std::vector<int> helper;
	for (int i = 0; i != t; ++i) {
		s = 0;
		flag = 0;
		std::cin >> n;
		arr.resize(n);
		for (int j = 0; j != n; ++j) {
			std::cin >> arr[j];
			s += arr[j];
		}
		k = s / n;
		helper.resize(0);
		for (auto c : arr) {
			helper.push_back(c - k);
		}
		if (arr[0] < k) flag = 1;
		if (arr[n - 1] > k) flag = 1;
		if (flag != 1) {
			for (int j = 1; j != n; j++) {
				helps = 0;
				for (int h = 0; h != j; h++) helps += helper[h];
				if (helps < helper[j]) flag = 1;
			}
		}
		if (flag == 0) std::cout << "YES" << std::endl;
		else std::cout << "NO" << std::endl;
	}
}
