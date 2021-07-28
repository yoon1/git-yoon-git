#include "pch.h"
#include <stdio.h>

int number = 9;
int heap[9] = { 7, 6, 5, 8, 3, 5, 9, 1, 6 };

int main(void) {
	// 먼저 전체 트리 구조를 최대 힙구조로 바꿉니다.
	for (int i = 1; i < number; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2; // root라는 값이 나오는데 root는 자기 부모를 의미해요.
			if (heap[root] < heap[c]) { // 부모 노드보다 자식이 크면 자리 바꿔주기.
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root; // 재귀적으로 계속 부모와 자식의 위치를 바꿔주는거에요.
		} while (c != 0);
	}
	// 계속 자기 부모 노드와 바꿔줌으로써 최대 힙을 만들어주었습니다..
	// 크기를 줄여가면서 반복적으로 힙을 구성.
	for (int i = 0; i < number; i++) {
		printf("%d ", heap[i]);
	}

	/* START 가장 큰 값을 맨 뒤로 보내는 것 */
	for (int i = number - 1; i >= 0; i--) { //루트 노드와 가장 마지막에 있는 원소를 바꿔줍니다. 
		int temp = heap[0]; // 즉, 0번째 인덱스에 있는 값은 가장 큰 값이기 때문에 맨 뒤로 바꿔주기만 해주면 자연스럽게 오름차순이 이루어진다.
		heap[0] = heap[i];
		heap[i] = temp; // 0번째 인덱스의 값과 가장 마지막 원소의 값을 바꿔주었습니다.
		/* END 가장 큰 값을 맨 뒤로 보내는 것 */
		int root = 0;
		int c = 1;
		/* START : 힙 구조를 만들어주는 부분 */
		do {
			c = 2 * root + 1; // c는 root의 자식이 됨.
			// 자식 주에 더 큰 값을 찾기
			if (heap[c] < heap[c + 1] && c < i - 1) { // c와 c+1을 비교하고 기본적으로 c가 i-1보다 커질 수는 없도록 한다. 범위를 벗어나지 않게 한다.
				c++;
			}
			// 루트보다 자식이 더 크다면 교환.
			if (heap[root] < heap[c] && c < i) {
				int temp = heap[root]; 
				heap[root] = heap[c];
				heap[c] = temp; 
			}
			root = c; // 한번 바뀐 후에는 다시 c를 root로 옮겨서 마치 재귀적으로 힙 구조를 만들어주시면 됩니다. 즉, 계속해서 연산해서 힙 구조를 만들어주는 겁니다. 
		} while (c < i);
		/* END : 힙 구조를 만들어주는 부분 */
	}
	
	return 0;
}