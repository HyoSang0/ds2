#include "BinaryTreeList.h"
/*
Node makeRoot(Data data);
void addNode(char* path, enum Direction direction, Data data);
Data getCurData(Node cur);
Node getleftChild(Node cur);
Node getRightChild(Node cur);
*/

int main() {
	Node root = makeRoot('-');
	addNode("-", left, '*');
	addNode("-", right, '/');
	addNode("-*", left, 'A');
	addNode("-*", right, 'B');
	addNode("-/", left, 'C');
	addNode("-/", right, 'D');
	printf("root = %c\n", getCurData(root));
	printf("root's left = %c\n", getCurData(getleftChild(root)));
	printf("root's right = %c\n", getCurData(getRightChild(root)));
	printf("root's left's left = %c\n", getCurData(getleftChild(getleftChild(root))));
	printf("root's left's right = %c\n", getCurData(getRightChild(getleftChild(root))));
	printf("root's right's left = %c\n", getCurData(getleftChild(getRightChild(root))));
	printf("root's right's right = %c\n", getCurData(getRightChild(getRightChild(root))));
	return 0;
}