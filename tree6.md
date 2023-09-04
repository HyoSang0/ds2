# 힙 트리

## 힙 트리란
1. 완전 이진 트리
2. 아래 아래 2가지 조건 중 하나를 충족
    - 부모노드의 키값 >= 자식노드의 키값 => max 힙
    - 부모노드의 키값 <= 자식노드의 키값 => min 힙
3. 중복된 데이터 허용
4. 탐색, 운행이 없고 삭제는 있다.

## 힙 트리의 활용

### 정렬
- 모든 원소를 차례로 삽입했다가
- 차례로 삭제하면
- min 힙은 오름차순으로
- max 힙은 내림차순으로 정렬된 데이터를 얻음

### 우선순위 큐
- 우선순위 큐란
    - 선입선출 대신 각 데이터가 가지는 우선순위에 의해 삭제순서가 정해짐. (우선순위가 높은 데이터가 먼저 나감)
- 힙 트리를 우선순위 큐의 구현 도구로 사용

## 힙 트리의 원소 삽입
- 완전 이진 트리, 부모/자식 관계 유지가 관건
- 마지막 노드번호 다음 자리에 새 노드 삽입 후
- 현재 노드와 부모 노드 값을 비교하며 루트노드까지 아래 작업을 진행
    - 교환이 필요하면 교환하고 부모노드가 현재노드가 됨
    - 교환이 필요없으면 중지

```cpp
#include <cstdio>
#define MAX_COUNT 100

typedef struct {
	int data[MAX_COUNT];
	int count;

}Heap;

int DeleteHeap(Heap* pH) { 
	int topdata = pH->data[1];
	int cur = 1;

	if (pH->count == 0) {
		printf("Heap is empty!\n");
		return 0;
	}
	pH->data[1] = pH->data[pH->count];
	pH->count--;

	while (cur * 2 <= pH->count) {
		int child = cur * 2, temp;
		// 오른쪽 자식이 있다 && 오른쪽 자식이 더 크다
		if ((child + 1) <= pH->count && (pH->data[child] < pH->data[child + 1]))
			child++;
		if (pH->data[child] <= pH->data[cur])
			break;
		temp = pH->data[child];
		pH->data[child] = pH-> data[cur];
		pH->data[cur] = temp;
	}
	return topdata;
}

void InsertHeap(Heap* pH, int data) {
	int cur;
	if (pH->count >= (MAX_COUNT - 1)) {
		printf("Heap is full!\n");
		return;
	}
	pH->data[++pH->count] = data;
	cur = pH->count;
	while (cur > 1 && pH->data[cur / 2] < pH->data[cur]) {
		// 교환
		int temp = pH->data[cur / 2];
		pH->data[cur / 2] = pH->data[cur];
		pH->data[cur] = temp;
		// 부모로 이동
		cur = cur / 2;
	}
}

void PrintHeap(Heap* pH) {
	printf("Heap [");
	for (int i = 1; i <= pH->count; i++) {
		printf("%d ", pH->data[i]);
	}
	printf("]\n");
}

int main() {
	Heap heap = { 0 };
	InsertHeap(&heap, 54);
	InsertHeap(&heap, 47);
	InsertHeap(&heap, 20);
	InsertHeap(&heap, 32);
	InsertHeap(&heap, 40);
	InsertHeap(&heap, 7);
	PrintHeap(&heap); 
	InsertHeap(&heap, 60);
	PrintHeap(&heap);
	printf("	out : %d\n", DeleteHeap(&heap));
	PrintHeap(&heap);

	while (heap.count > 0) {
		printf("	out : %d\n", DeleteHeap(&heap));
	}

	return 0;
}
```

## 힙 트리의 원소 삭제
- 완전 이진 트리, 부모/자식 관계 유지가 관건
- 루트 노드를 삭제 + 마지막 노드 번호의 원소를 루트 자리로 옮김
- 현재 노드와 자식 노드(두 개 중 더 큰 자식) 값을 비교하며 단말노드까지 아래 작업을 진행
    - 교환이 필요하면 교환하고 자식노드가 현재노드가 됨
    - 교환이 필요없으면 중지