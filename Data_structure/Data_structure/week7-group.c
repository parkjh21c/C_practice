#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

// 사진찍은거 확인

typedef int element;

typedef struct GListNode {
	struct GListNode* prev;
	struct GListNode* next;
	struct GListNode* group;
	element data;
}GListNode;

typedef struct {
	GListNode* H;
	GListNode* T;
	int size;
}GListType;

void init(GListType* GL) {
	GL->H = NULL;
	GL->T = NULL;
	GL->size = 0;
}

int isEmpty(GListType* GL) {
	return GL->size == 0;
}

void insertFirst(GListType* GL, element e) {
	GListNode* p = GL->H;
	GListNode* node = (GListNode*)malloc(sizeof(GListNode));
	
	node->data = e;
	node->prev = NULL;
	node->next = p;

	if (p == NULL)
		GL->H = GL->T = node;
	else {
		p->prev = NULL;
	}


}

int main() {
	GListType GL;
	init(&GL);




	return 0;
}