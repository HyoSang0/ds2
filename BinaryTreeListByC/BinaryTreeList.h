#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Data;
typedef struct _Node {
	Data data;
	struct _Node* lchild;
	struct _Node* rchild;
}*Node;

enum Direction {
	left, right
};

Node makeRoot(Data data);
void addNode(char* path, enum Direction direction, Data data);
Data getCurData(Node cur);
Node getleftChild(Node cur);
Node getRightChild(Node cur);
int isTreeEmpty(Node root);