#include <cstdio>
char cal[51];
int ret, n, i;
bool flag; // false : plus, ture : minus
int main() {
	scanf("%s", cal);
	while (cal[i] != 0) {
		// 숫자
		if (cal[i] >= '0' && cal[i] <= '9') {
			n *= 10;
			n += cal[i] - '0';
		}
		// 기호
		else {
			if (!flag) ret += n;
			else ret -= n;
			if (cal[i] == '-' && !flag) // minus 연산자를 만나면 flag = 1로 변환
				flag = !flag;
			n = 0;  
		}
		i++;
	}
	
	if (!flag ) ret += n;
	else if (flag) ret -= n;
	printf("%d", ret);
}