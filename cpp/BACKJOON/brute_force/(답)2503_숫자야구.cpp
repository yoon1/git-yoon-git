#include <iostream>
#include <string>
#define BEGIN_NUM 123
#define END_NUM 999
using namespace std;

bool answer[1000];

int main() {
	int N;
	int count = 0;
	cin >> N;
	
	for (int i = 0; i <= END_NUM; i++) {
		answer[i] = true;
	}

	for (int i = BEGIN_NUM; i < END_NUM; i++) {
		string tmp = to_string(i);
		if (tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2]) {
			answer[i] = false;
		} 
		if (tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0') {
			answer[i] = false;
		}
	}

	
	for (int i = 0; i < N; i++) {
		int questionNumber;
		int strike;
		int ball;
		cin >> questionNumber >> strike >> ball;
		for(int j = BEGIN_NUM; j < END_NUM; j++ )
		{
			int strikeCount = 0;
			int ballCount = 0;
			if (answer[j]) {
				string strQNumber= to_string(questionNumber);
				string strCurNumber = to_string(j);

				for (int n= 0; n < 3; n++) {
					for (int m = 0; m < 3; m++) {
						if (n == m && strQNumber[n] == strCurNumber[m])
							strikeCount++;
						if (n != m && strQNumber[n] == strCurNumber[m])
							ballCount++;
					}
				}
				if (strikeCount != strike || ballCount != ball)
					answer[j] = false;
			}

		}
	}
	for (int i = BEGIN_NUM; i < END_NUM; i++)
	{
		if (answer[i])
			count++;
	}
	cout << count;
	return 0;
}