#include <iostream>
#include <vector>
using namespace std;

int sumNum(int a, int b, int c, int M)
{
	int result = a + b + c;
	if (result <= M)  return result;
	else return 0;
}

int main() {
	int N, M;
	int result = 0;
	vector<int> vNum;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		vNum.push_back(num);
	}
	
	for (int i = 0; i < vNum.size() - 2; i++) {
		for (int j = i+1; j < vNum.size() - 1; j++) {
			for (int k = j+1; k < vNum.size(); k++) {
				int temp = sumNum(vNum[i], vNum[j], vNum[k], M);
				if (result < temp) result = temp;
			}
		}
	}
	cout << result << endl;
	return 0;
}