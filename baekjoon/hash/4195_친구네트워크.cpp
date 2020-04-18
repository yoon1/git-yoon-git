#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <memory.h>
#define MAX 100001

using namespace std;

vector<string> networkVector[MAX];
map<string, int> networkMap;

bool isNetworkName(string name) {
	map<string, int>::iterator it;
	it = networkMap.find(name);
	if (it != networkMap.end()) return true;
	else return false;
}

int getNetworkValue(string name) {
	if (isNetworkName(name))
		return networkMap.find(name)->second;
	else
		return -1;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// testCase �Է� ����.
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		// memory �ʱ�ȭ
		memset(networkVector, 0, sizeof(networkVector));
		networkMap.clear();

		// network �Է� ����.
		int N;
		int keyId = 1;
		cin >> N;
		for (int i = 0; i < N; i++) {
			pair<string, string> str;
			cin >> str.first >> str.second;
			pair<int, int> val;
			val.first = getNetworkValue(str.first);
			val.second = getNetworkValue(str.second);
			// #1  �� �� �ϳ� �̻� ��Ʈ��ũ�� �����ִ°�?
			if (val.first + val.second > -2) {
				// ##1-1 ��� Map�� �����ִ°�?
				if (val.first != -1 && val.second != -1) {
					// ###1-1-1 Value���� �ٸ���?
					if (val.first != val.second) {
						for (int i = 0; i < networkVector[val.second].size(); i++) {
							networkVector[val.first].push_back(networkVector[val.second][i]);
							networkMap[networkVector[val.second][i]] = val.first;
						}
					}
					// ###1-1-2 Value���� ������?
					else {
						// �ƹ��͵� ���� ����.
					}
				}
				else {
					// ##1-2 �����ִ� Key���� value�� ���ͼ� map, vector�� ���� �߰��Ѵ�.
					if (val.first > val.second) {
						pair<string, int> temp;
						temp.first = str.first;
						temp.second = val.first;

						str.first = str.second;
						val.first = val.second;

						str.second = temp.first;
						val.second = temp.second;
					}
					networkMap[str.first] = val.second;
					networkVector[val.second].push_back(str.first);
				}
			}
			else {
				// #2 ���ο� key���� �Ҵ��ؼ� map, vector�� ���� �߰�.
				networkMap[str.first] = keyId;
				networkVector[keyId].push_back(str.first);
				networkMap[str.second] = keyId;
				networkVector[keyId].push_back(str.second);

				keyId++;
			}
			// result : 
			int resultValue = getNetworkValue(str.first);
			if(resultValue != -1) {
				cout << networkVector[resultValue].size() << endl;
			}
			else cout << "0" << endl;
		}
	}
	return 0;
}