#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/list.h"
#include "../include/util.h"

/********************************************************************
 * LNode
 ********************************************************************/

LNode *newLNode(void *data) {
    assert(data);
    LNode *LNode = (struct ListNode *) calloc(1, sizeof(struct ListNode));
    assert(LNode);
    LNode->data = data;
    return LNode;
}

void *getLNodeData(const LNode *node) {
    return node->data;
}

LNode *Successor(const LNode *node) {
    return node->succ;
}

LNode *Predecessor(const LNode *node) {
    return node->pred;
}

void setLNodeData(LNode *node, void *newData) {
    node->data = newData;
}

void setSuccessor(LNode *node, LNode *newSucc) {
    node->succ = newSucc->succ;
}

void setPredecessor(LNode *node, LNode *newPred) {
    node->pred = newPred->pred;
}

/********************************************************************
 * List
 ********************************************************************/

List *newList(void (*viewData)(const void *), void (*freeData)(void *)) {
    List *Lst = calloc(1, sizeof(struct List));
    //faire des vérifs si la liste est bien initialisé
    assert(Lst);
    //Initialisé les pointeurs de fonctions
    assert(viewData);
    assert(freeData);
    return Lst;
}

int listIsEmpty(List *L) {
    if (L->numelm == 0) {
        return 1;
    } else
        return 0;
}

int getListSize(const List *L) {
    return L->numelm;
}

LNode *Head(const List *L) {
    return L->head;
}

LNode *Tail(const List *L) {
    return L->tail;
}

void increaseListSize(List *L) {
    L->numelm = L->numelm + 1;
}

void decreaseListSize(List *L) {
    L->numelm = L->numelm - 1;
}

void setListSize(List *L, int newSize) {
    L->numelm = newSize;
}

void resetListSize(List *L) {
    L->numelm = 0;
}

void setHead(List *L, LNode *newHead) {
    L->head = newHead;
}

void setTail(List *L, LNode *newTail) {
    L->tail = newTail;
}

void freeList(List *L, int deleteData) {
    assert(deleteData == 0 || deleteData == 1);
    assert(L != NULL);
    if (deleteData == 1) {
        LNode *node = L->head;
        while (node != NULL) {
            LNode *next = node->succ;
            L->freeData(node->data);
            node = next;
        }
    }
    else if (deleteData == 0){
        free(L);
    }
}

void viewList(const List *L) {
    assert(L);
    LNode *N;
    printf("\n[ ");
    for (N = L->head; N; N = N->succ) {
        (*L->viewData)(N->data);
    }
    printf(" ]\n");
}

void listInsertFirst(List *L, void *data) {
    assert(L);
    LNode *newNode = newLNode(data);
    assert(newNode);
    if(listIsEmpty(L)){
        setHead(L,newNode);
    }
    else{
        setSuccessor(newNode, Successor(data));
    }
    increaseListSize(L);
}

void listInsertLast(List *L, void *data) {
    // TODO : Briçou

    LNode *nexN;

    newN = newLNode(data);


}

void listInsertAfter(List *L, void *data, LNode *ptrelm) {
    if (ptrelm == NULL){
        setLNodeData(ptrelm, data);
    }
    else{
        struct ListNode *newNode = newLNode(data);
        assert(newNode);
        if (listIsEmpty(L)){
            setHead(L,newNode);
        }
        else{
            setSuccessor(newNode, Successor(ptrelm));
            setSuccessor(ptrelm, newNode);
            if (ptrelm == Tail(L)){
                setTail(L, newNode);
            }
        }
        increaseListSize(L);
    }
}

void *listRemoveFirst(List *L) {
    assert(Head(L));
    // TODO
}

void *listRemoveLast(List *L) {
    assert(Head(L));
    // TODO
}

void *listRemoveNode(List *L, LNode *node) {
    assert(Head(L) && Tail(L));
    // TODO
}

List *listConcatenate(List *L1, List *L2) {
    // TODO
}