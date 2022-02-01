#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/list.h"
#include "../include/util.h"

/********************************************************************
 * LNode
 ********************************************************************/

LNode * newLNode(void* data) {
    struct ListNode *L = (struct ListNode *)calloc(1, sizeof(struct ListNode));
    assert(data);
    L->data = data;
    return L;
}

void* getLNodeData(const LNode* node) {
    return node->data;
}

LNode* Successor(const LNode* node) {
	return node->succ;
}

LNode* Predecessor(const LNode* node) {
    return node->pred;
}

void setLNodeData(LNode* node, void* newData) {
	node->data = newData;
}

void setSuccessor(LNode* node, LNode* newSucc) {
	node->succ = newSucc->succ;
}

void setPredecessor(LNode* node, LNode* newPred) {
	node->pred = newPred->pred;
}

/********************************************************************
 * List
 ********************************************************************/

List * newList(void (*viewData)(const void*), void (*freeData)(void*)) {
	// TODO
}

int listIsEmpty(List* L) {
	// TODO
}

int getListSize(const List* L) {
	// TODO
}

LNode* Head(const List* L) {
	// TODO
}

LNode* Tail(const List* L) {
	// TODO
}

void increaseListSize(List* L) {
	// TODO
}

void decreaseListSize(List* L) {
	// TODO
}

void setListSize(List* L, int newSize) {
	// TODO
}

void resetListSize(List* L) {
	// TODO
}

void setHead(List* L, LNode* newHead) {
	// TODO
}
void setTail(List* L, LNode* newTail) {
	// TODO
}

void freeList(List * L, int deleteData) {
	assert(deleteData == 0 || deleteData == 1);
	// TODO
}

void viewList(const List * L) {
	// TODO
}

void listInsertFirst(List * L, void * data) {
	// TODO
}

void listInsertLast(List * L, void * data) {
	// TODO
}

void listInsertAfter(List * L, void * data, LNode * ptrelm) {
	// TODO
}

void* listRemoveFirst(List * L) {
	assert(Head(L));
	// TODO
}

void* listRemoveLast(List * L) {
	assert(Head(L));
	// TODO
}

void* listRemoveNode(List * L, LNode * node) {
	assert(Head(L) && Tail(L));
	// TODO
}

List* listConcatenate(List* L1, List* L2) {
	// TODO
}