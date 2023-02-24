#include <iostream>
#include <fstream>
#include <vector>

int main() {
	std::vector<bool> a = {true, false, true};
	std::vector<bool> b = {false, true, false};
	std::vector<bool> c = a;
	c.insert(c.end(), b.begin(), b.end());

	for (bool x : c) {
		std::cout << x << std::endl;
	}

	return 0;
}