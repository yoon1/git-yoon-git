#include <vector>

using namespace std;

//���� ���� ���ؼ� �׳� bfs���ʴ�� ������ ���� ���ϸ� �� �� ����-��-
// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	vector<int> answer(2);
	vector<vector<int>> v(10,(10,0));
	

	//	for(:int i)
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;

}
int main() {
	solution(6,4,{ {1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3} });
	return 0;

}