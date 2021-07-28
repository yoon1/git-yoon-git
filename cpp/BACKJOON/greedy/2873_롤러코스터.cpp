#include <iostream>
#include <string>

using namespace std;

typedef struct pos {
	int y;
	int x;
	int score;
}Pos;

bool isEven(int i) {
	if (i % 2 == 0) return true;
	return false;
}
bool isOdd(int i) {
	if (i % 2 == 0) return false;
	return true;
}
int map[1000][1000];
int main() {

	int R, C;
	string path= "";

	cin >> R >> C;

	if (isOdd(R)) { // Row : È¦
		for (int i = 0; i < R; i++) {
			if (isEven(i))
				path.append(C - 1, 'R');
			else 
				path.append(C - 1, 'L');
			if ( i != R - 1 )
				path.append(1, 'D');
		}
	} 
	else if (isOdd(C)) { // Col : È¦
		for (int i = 0; i < C; i++) {
			if ( isEven(i))
				path.append(R - 1, 'D');
			else 
				path.append(R - 1, 'U');
			if (i != C - 1)
				path.append(1, 'R');
		}
	}
	else { // Row, Col : Â¦
		Pos happy = { 0,0, 987654321};
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> map[i][j];
				if ( isOdd((i + j)) && happy.score > map[i][j]) 
					happy = { i,j, map[i][j] }; // ÃÖ¼Ò°ª ÀúÀå.
			}
		}	
		int happyR = isOdd(happy.y) ? happy.y - 1 : happy.y;
		for (int i = 0; i < happyR; i++) {
			if (isEven(i))
				path.append(C - 1, 'R');
			else
				path.append(C - 1, 'L');	
			path.append(1, 'D');
		}
		
		int happyC = happy.x;
		for (int i = 0; i < happyC; i++) {
			if (isEven(i))
				path += "DR";
			else
				path += "UR";
		}

		for (int i = happyC; i < C - 1; i++) {
			if (isEven(i))
				path += "RD";
			else
				path += "RU";
		}

		if (isEven(happy.y))
			happyR = R - (happy.y + 2);
		else
			happyR = R - (happy.y + 1);

		for (int i = 0; i < happyR; i++) {
			path.append(1, 'D');
			if (isEven(i))
				path.append(C - 1, 'L');
			else 
				path.append(C - 1, 'R');
		}
	}
	
	cout << path << endl;
		
	return 0;
}