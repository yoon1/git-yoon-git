#include <iostream>     // std::cin, std::cout
#include <sstream>

using namespace std;

int main() {
	string str = "10S2D*3T";
	stringstream ss(str);
	for (int i = 0; i < 3; i++) { // 3°³, [ 10S | 2D* | 3T ] 
		int score;
		char bonus, option;
		ss >> score;
		bonus = ss.get();
		option = ss.get();
		/* if (option != '*' && option != '#') {
			ss.unget();
		} */
		cout << score << "," << bonus << "," << option << endl;
	}
}