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

	//�Է�
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

		// �ʱ�ȭ
		code_str = "";
		ori_str = "";

		/* 1. ori -> code */
		// val : ���� ���� ��
		for (int val : input_str) {
			// t : �ӽð��� ���� temp ����
			char t;
			// val�� ���� 'A' ~ 'Z'�� ���(�ƽ�Ű�ڵ� 65 ~ 90)
			if (val >= 65 && val <= 90) {
				// �ƽ�Ű �ڵ� ���� ����( - 65 )
				// code_book���� �빮�� 'A' ~ 'Z'�� �ҹ��� �ڿ� ��ġ( + 26 )
				t = (char)code_book[val - 65 + 26];
			}
			// val�� ���� 'a' ~ 'z'�� ���(�ƽ�Ű�ڵ� 97 ~ 122)
			else if (val >= 97 && val <= 122) {
				// �ƽ�Ű �ڵ� �� ���� ( - 97 )
				t = (char)code_book[val - 97];
			}
			// �̿��� ���̸� �״�� ���(���� ��)
			else {
				t = (char)val;
			}
			code_str += t;
		}
		// �ڵ� �� ���
		cout << code_str << endl;

		/* 2. code -> ori */
		// val : ���� ���� ��
		for (int val : code_str ){
			// exists : code_book�� �����ϴ� �������� Ȯ���ϴ� ����
			bool exists = false;
			// idx : code_book�� �ε��� ��
			for (int idx = 0; idx < code_book.size(); idx++) {
				// ���� code_book�� ���� ���� ���� ���� ������ ��� : ��
				if (val == code_book[idx]) {
					// oribook���� �ش� ���� ���� ori_str�� �߰�
					ori_str += oribook[idx];
					// code_book�� �����ϴ� ���� ���θ� �������� ����
					exists = true;
					break;
				}
			}
			// code_book�� �������� �ʾҴ� ������ ���
			if (!exists) {
				// �״�� �� ���
				ori_str += val;
			}
		}
		
		// ���� �� ���
		cout << ori_str << endl;
	}
}