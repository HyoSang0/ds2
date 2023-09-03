# 균형 이진 탐색 트리

## 균형 이진 탐색 트리의 필요성
- 이진 탐색 틀는 노드 삽입 순서에 따라 편향될 수 있다.
- 편향될 수록 이진 트리의 장점이 사라진다.

## 균형 이진 탐색 트리란
- 모든 노드에서 왼쪽 서브 트리의 높이와 오른쪽 서브 트리의 높이의 차이가 1이하인 이진 탐색 트리
- AVL 트리 (Adelson-Velskii, Landis Tree)
    - 대표적인 균형 이진 탐색 트리
    - 균형 인수 : 왼쪽 서브 트리의 높이 - 오른쪽 서브 트리의 높이
    - 모든 노드의 균형 인수를 -1, 0, 1로만 가지게 하여 균형을 유지
    - 노드 삽입/삭제 시 회전을 이용하여 균형 유지

## ABL트리 불균형의 유형과 회전방법

### LL유형 => LL회전
- 루트 노드의 균형인수가 2 이상일 때
```cpp
//		C		 B
//	  B		-> A	C
//  A
Node LL_rotate(Node C) {
	Node B = C->lchild;
	C->lchild = B->rchild; //B의 오른쪽 자식이 있을 지도 모르니 미리 C의 왼쪽 자식으로 넣어야함
	B->rchild = C;
	return B;
}
```


### RR유형 => RR회전
- 루트 노드의 균형인수가 -2 이상일 때

```cpp
//	A			  B
//	  B		->	A	C
//		C
Node RR_rotate(Node A) {
	Node B = A->rchild;
	A->rchild = B->lchild;
	B->lchild = A;
	return B;
}
```

### LR유형 => LR회전

```cpp
//		C		  B
//	  A		->	A	C
//		B
Node LR_rotate(Node C) {
	C->lchild = RR_rotate(C->lchild);
	return LL_rotate(C);
}
```

### RL유형 => LL회전

```cpp


//	A			  B
//	  C		->	A	C
//	B
Node RL_rotate(Node A) {
	A->rchild = LL_rotate(A->rchild);
	return RR_rotate(A);
}
```

## 노드별 리밸런스의 필요성 체크

```cpp
int GetHeight(Node p) {
	int height, lHeight, rHeight;
	if (p == NULL)
		return 0;
	lHeight = GetHeight(p->lchild);
	rHeight = GetHeight(p->rchild);
	height = (lHeight > rHeight) ? lHeight : rHeight;
	return height + 1;
}

int GetBF(Node p) {
	if (p == NULL)
		return 0;
	return GetHeight(p->lchild) - GetHeignt(p->rchild);
}

Node Rebalance(Node pNode) {
	int bf = GetBF(pNode);
	if (bf > 1) {
		if (GetBF(pNode->lchild) > 0)
			pNode = LL_rotate(pNode);
		else
			pNode = LR_rotate(pNode);
	}
	else if (bf < -1) {
		if (GetBF(pNode->rchild) < 0)
			pNode = RR_rotate(pNode);
		else
			pNode = RL_rotate(pNode);
	}
	return pNode;
}
```

## 노드 삽입 시 리밸런싱