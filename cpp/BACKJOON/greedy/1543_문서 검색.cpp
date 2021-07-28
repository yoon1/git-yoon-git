#include <iostream>
#include <string>

using namespace std;

bool searchString(string str, string word) {
	if (str == word) return true;
	else return false;
}

int main() {
	string str, word = "";
	int count = 0;
	getline(cin, str);
	getline(cin, word);
	if (str != "" && word != "" && str.length() >= word.length()) {
		for (int i = 0; i <= (str.length() - word.length()); i++) {
			string temp = str.substr(i, word.length());
			if (searchString(temp, word)) {
				count++;
				i = i + word.length() - 1;
			}
		}
	}
	cout << count << endl;

	return 0;
}
