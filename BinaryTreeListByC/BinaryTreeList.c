#include "BinaryTreeList.h"
#define NODE_MAXCOUNT 100



static Node s_tree = NULL;

Node makeRoot(Data data) {
	s_tree = (struct _Node*)malloc(sizeof(struct _Node));
	s_tree->data = data;
	s_tree->lchild = s_tree->rchild = NULL;
	return s_tree;
}

void addNode(char* path, enum Direction direction, Data data) {
	Node trace = s_tree, newnode;
	if (trace->data != *path) {
		printf("%c가 없습니다.\n", *path);
		return;
	}
	path++;
	while (*path != '\0') {
		if (trace->lchild->data == *path) {
			trace = trace->lchild;
		}
		else if (trace->rchild->data == *path) {
			trace = trace->rchild;
		}
		path++;
	}
	newnode = (struct _Node*)malloc(sizeof(struct _Node));
	newnode->data = data;
	newnode->lchild = newnode->rchild = NULL;

	if (direction == left) {
		trace->lchild = newnode;
	}
	else {
		trace->rchild = newnode;
	}
}

Data getCurData(Node cur) {
	return cur->data;
}

Node getleftChild(Node cur) {
	return cur->lchild;
}

Node getRightChild(Node cur) {
	return cur->rchild;
}

int isTreeEmpty(Node root) {
	if (root == NULL)
		return 1;
	else
		return 0;
}