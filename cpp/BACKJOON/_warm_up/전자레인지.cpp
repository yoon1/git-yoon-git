#include <iostream>

using namespace std;

int H, m;
int addH, addM;
int resultH, resultM;
int main() {
	cin >> H >> m >> addM;
	addH = addM / 60;
	addM = addM % 60;
	if (addM + m >= 60)
	{
		resultH = H + addH + 1;
		resultM = addM + m - 60;
	}
	else
	{
		resultH = H + addH;
		resultM = addM + m;
	}

	resultH %= 24;
	cout << resultH << " " << resultM << endl;
	return 0;

}