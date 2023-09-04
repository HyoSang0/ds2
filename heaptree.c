#include <cstdio>
#define MAX_COUNT 100

typedef struct {
	int data[MAX_COUNT];
	int count;

}Heap;

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

	return 0;
}