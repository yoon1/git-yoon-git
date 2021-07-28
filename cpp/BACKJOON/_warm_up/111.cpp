#include <iostream>
using namespace std;
#include <array>
#include <algorithm>
#include <random>
#include <time.h>
#include <string>

// array<int,100> array_data;

void shuffle_array(array<int, 100>&array_data, unsigned int seed) {
	shuffle(array_data.begin(), array_data.end(), default_random_engine(seed));
}

void generate_code_book(array<int, 26 * 2>&book) {
	static clock_t seed = clock();
	for (int i = 0; i < 26; ++i) {
		book[i] = 97 + i;
	}
	for (int i = 0; i < 26; ++i) {
		book[26 + i] = 65 + i;
	}
	shuffle(book.begin(), book.end(), default_random_engine(seed));
}

void generate_book(array<int, 26 * 2>&book) {

	for (int i = 0; i < 26; ++i) {
		book[i] = 97 + i;
	}
	for (int i = 0; i < 26; ++i) {
		book[26 + i] = 65 + i;
	}
}

int main() {
	string input_str;
	string code_str = "";
	string ori_str = "";
	array<int, 26 * 2>code_book;
	array<int, 26 * 2>oribook;
	generate_book(oribook);
	generate_code_book(code_book);

	//입력
	for (int val : oribook) {
		cout << (char)val;
	}
	cout << endl;

	for (int val : code_book) {
		cout << (char)val;
	}
	cout << endl;

	while (true){
		getline(cin, input_str);

		// 초기화
		code_str = "";
		ori_str = "";

		/* 1. ori -> code */
		// val : 현재 원소 값
		for (int val : input_str) {
			// t : 임시값을 담을 temp 변수
			char t;
			// val의 값이 'A' ~ 'Z'인 경우(아스키코드 65 ~ 90)
			if (val >= 65 && val <= 90) {
				// 아스키 코드 값을 빼기( - 65 )
				// code_book에서 대문자 'A' ~ 'Z'는 소문자 뒤에 위치( + 26 )
				t = (char)code_book[val - 65 + 26];
			}
			// val의 값이 'a' ~ 'z'인 경우(아스키코드 97 ~ 122)
			else if (val >= 97 && val <= 122) {
				// 아스키 코드 값 빼기 ( - 97 )
				t = (char)code_book[val - 97];
			}
			// 이외의 값이면 그대로 사용(공백 등)
			else {
				t = (char)val;
			}
			code_str += t;
		}
		// 코드 값 출력
		cout << code_str << endl;

		/* 2. code -> ori */
		// val : 현재 원소 값
		for (int val : code_str ){
			// exists : code_book에 존재하는 문자인지 확인하는 변수
			bool exists = false;
			// idx : code_book의 인덱스 값
			for (int idx = 0; idx < code_book.size(); idx++) {
				// 현재 code_book의 값과 현재 원소 값이 동일할 경우 : 참
				if (val == code_book[idx]) {
					// oribook에서 해당 원소 값을 ori_str에 추가
					ori_str += oribook[idx];
					// code_book에 존재하는 문자 여부를 참값으로 변경
					exists = true;
					break;
				}
			}
			// code_book에 존재하지 않았던 문자의 경우
			if (!exists) {
				// 그대로 값 사용
				ori_str += val;
			}
		}
		
		// 원본 값 출력
		cout << ori_str << endl;
	}
}