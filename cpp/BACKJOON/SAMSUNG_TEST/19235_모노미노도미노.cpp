#include <iostream>

const int BLUE = 0;
const int GREEN = 1;

int N;
int score, count;
int board[2][10][4]; // 하나는 blue, 하나는 green

// 1칸짜리 블록을 y좌표, x좌표, color를 주어지면 그 맵에서 이동할 수 있을 만큼 이동시키는 함수
void move_point(int y, int x, int color) {
	int label = board[color][y][x];
	board[color][y][x] = 0;
	while ( y < 10 ) {
		if (board[color][y][x] != 0) {
			break;
		}
		++y;
	}
	--y;
	board[color][y][x] = label;
}


void move_h_block(int y, int x, int color) {
	int label = board[color][y][x];
	board[color][y][x] = 0;
	board[color][y - 1][x] = 0;
	while (y < 10) {
		if (board[color][y][x] != 0) {
			break;
		}
		++y;
	}
	--y;
	board[color][y][x] = label;
	board[color][y-1][x] = label;
}

void move_w_block(int y, int x, int color) {
	int label = board[color][y][x];
	board[color][y][x] = 0;
	board[color][y][x + 1] = 0;
	while (y < 10) {
		if (board[color][y][x] != 0 || board[color][y][x + 1] != 0) {
			break;
		}
		++y;
	}
	--y;
	board[color][y][x] = label;
	board[color][y][x+1] = label;
}

void remove(int y, int color) {
	for (int x = 0; x < 4; x++) {
		board[color][y][x] = 0; // 지움
	}
}

void move(int start_y, int color) {
	const int dy[2] = { -1, 0 };
	const int dx[2] = { 0 , 1 };
	for (int y = start_y; y >= 4; --y) {
		for (int x = 0; x < 4; x++) {
			if (board[color][y][x] == 0) {
				continue;
			}
			// type == 1 ? one block
			// type == 2 ? h block (세로) 
			// type == 3 ? w block (가로)
			int type = 1;
			for (int d = 0; d < 2; d++) {
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (ny < 4 || nx >= 4) {
					continue;
				}
				if (board[color][y][x] == board[color][ny][nx]) {
					if (d == 0) {
						type = 2;
					}
					else {
						type = 3;
					}
				}
			}
			if (type == 1) {
				move_point(y, x, color);
			}
			else if (type == 2) {
				move_h_block(y, x, color);
			}
			else if (type == 3) {
				move_w_block(y, x, color);
			}
		}
	}
}

// 블록이 꽉차있으면 제거해주는 함수
void delete_filled_block(int color) {
	bool is_remove = false;
	for (int y = 6; y < 10; y++) {
		int count = 0;
		for (int x = 0; x < 4; x++) {
			if (board[color][y][x] != 0) {
				count++;
			}
		}
		if (count == 4) {	
			is_remove = true;
			score++;
			remove(y, color);
			move(y - 1, color);
		}
	}
	
	// 꽉 찼으면 지우고 라인을 밑으로 옮겨줘야 한다.
	if (is_remove) {
		delete_filled_block(color);
	}
}

// overflow가 생기면, (옅은 부분) count만큼 세서 밑으로 내려줘야 한다.
void delete_overflow_block(int color) {
	int remove_count = 0;
	for (int y = 4; y <= 5; y++ ) {
		bool has_block = false;
		for (int x = 0; x < 4; x++) {
			if (board[color][y][x] != 0) {
				has_block = true;
				break;
			}
		}
		if (has_block) {
			++remove_count;
		}
	}

	if (remove_count > 0) {
		for (int y = 9; y >= 6; --y) {
			for (int x = 0; x < 4; x++) {
				board[color][y][x] = board[color][y - remove_count][x];
			}
		}

		for (int y = 4; y <= 5; y++) {
			for (int x = 0; x < 4; x++) {
				board[color][y][x] = 0;
			}
		}
	}
}

// 블럭을 놓는 함수
void put(int type, int target, int color, int label) { 
	// 블록 모양, 타겟, 색깔, 라벨
	if (type == 1) { // 1개짜리 블록
		board[color][0][target] = label;
		move_point(0, target, color);
	}
	else if (( type == 2 && color == BLUE ) || (type == 3 && color == GREEN)) { // 세로
		board[color][0][target] = label;
		board[color][1][target] = label;
		move_h_block(1, target, color);
	}
	else if (( type == 3 && color == BLUE ) || (type == 2 && color == GREEN)) { // 가로
		board[color][0][target] = label;
		board[color][0][target + 1] = label;
		move_w_block(0, target, color);
	}

	delete_filled_block(color); // 블록이 꽉차있으면 제거해주는 함수
	delete_overflow_block(color);
} 

int main() {
	score = 0, count = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int t, x, y;
		scanf("%d %d %d", &t, &y, &x);
		put(t, y, BLUE, i + 1); // type, 위치, 색깔, 레이블
		put(t, x, GREEN, i + 1);
	}
	
	for (int color = 0; color < 2; color++) {
		for (int y = 4; y < 10; y++) {
			for (int x = 0; x < 4; x++) {
				if (board[color][y][x] != 0) {
					++count;
				}
			}
		}
	}

	printf("%d\n%d\n", score, count);

	return 0;
}