#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Data;
typedef int Node; // 배열 index값

enum Direction {
	left, right
};

Node makeRoot(Data data);
void addNode(char* path, enum Direction direction, Data data);
Data getCurData(Node cur);
Node getleftChild(Node cur);
Node getRightChild(Node cur);
int isTreeEmpty(Node root);