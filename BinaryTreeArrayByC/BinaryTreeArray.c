#include "BinaryTreeArray.h"
#define NODE_MAXCOUNT 100

typedef char Data;
static Data s_tree[NODE_MAXCOUNT] = { 0, };

Node makeRoot(Data data) {
	s_tree[1] = data;
	return 1;
}

void addNode(char* path, enum Direction direction, Data data) {
	Node trace = 1;
	if (s_tree[trace] != *path) {
		printf("%c가 없습니다.\n", *path);
		return;
	}
	path++;
	while (*path != '\0') {
		if (s_tree[trace * 2] == *path) {
			trace = trace * 2;
		}
		else if (s_tree[trace * 2 + 1] == *path) {
			trace = trace * 2 + 1;
		}
		path++;
	}
	if (direction == left) {
		s_tree[trace * 2] = data;
	}
	else {
		s_tree[trace * 2 + 1] = data;
	}
}

Data getCurData(Node cur) {
	return s_tree[cur];
}

Node getleftChild(Node cur) {
	return cur * 2;
}

Node getRightChild(Node cur) {
	return cur * 2 + 1;
}

int isTreeEmpty(Node root) {
	if (s_tree[root] == 0)
		return 1;
	else
		return 0;
}