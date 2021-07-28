#include <iostream>
#include <fstream>
#define MAX 100

using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	int verN = 0;
	int edgeN = 0;
	int x, y;
	int arr[MAX][MAX] = { 0, };

	fin.open("graph.txt");

	fin >> verN;
	fin >> edgeN;

	for (int i = 0; i < edgeN; i++) /* 파일에서 그래프 그리기 */
	{
		fin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	for (int i = 1; i <= verN; i++) /* 그래프 그리기... */
	{
		for (int j = 1; j <= verN; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	fin.close();
	return 0;
}


//visit == 0 --> 방문하지 않았음을 의미
//visit == 1 --> 방문했음을 의미!
/* 
void dfs(int w) {
	int i;
	Visit[w] = 1;
	Outp[Cnt_Outp++] = w;
	for (i = 1; i <= N; i++) {
		if (Table[w][i] == 1 && Visit[i] == 0)
			dfs(i);
	}
}
*/