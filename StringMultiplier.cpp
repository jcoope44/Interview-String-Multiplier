//James Cooper
//4-5-18

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int StringMultiplier(std::string s, char delim) {
	int result = 0;
	
	std::vector<int> negatives;
	bool areNegatives = false;

	int prevDelim = -1;
	for (int i = 0; i < s.size(); ++i) {
		int tmp = 0;
		bool found = false;
		if (s[i] == delim || i == s.size() - 1) {
			int nextDelim = i == s.size() - 1 ? i + 1 : i;
			while (s[prevDelim + 1] == ' ')
				++prevDelim;
			while (s[nextDelim - 1] == ' ')
				--nextDelim;
			tmp = stoi(s.substr(prevDelim + 1, nextDelim - prevDelim - 1));
			prevDelim = i;
			found = true;
		}
		if (found && tmp < 0) {
			negatives.push_back(tmp);
			areNegatives = true;

		}
		else if (found && tmp <= 100) {
			if (result == 0) ++result;
			result *= tmp;
		}
	}

	if (areNegatives) {
		std::sort(negatives.begin(), negatives.end());
		std::cout << "Negatives are not allowed: ";
		for (int i = negatives.size() - 1; i >= 0; --i) {
			std::cout << negatives[i];
			if (i > 0)
				std::cout << ", ";
		}
		return -1;
	}

	else
		return result;
}

int main() {
	std::string mString;
	char delimUsed;
	std::cout << "Enter Multiplication String: ";
	std::getline(std::cin, mString);
	std::cout << "Enter Delimiter used: ";
	std::cin >> delimUsed;
	int tmp = StringMultiplier(mString, delimUsed);
	if (tmp > -1)
		std::cout << tmp;
}
