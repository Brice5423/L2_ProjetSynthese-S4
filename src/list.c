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

    LNode *LNode;

    LNode = (struct ListNode *) calloc(1, sizeof(struct ListNode));
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
    List *Lst;

    Lst = (List *) calloc(1, sizeof(struct List));
    assert(Lst);

    Lst->viewData = viewData;
    Lst->freeData = freeData;

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
    // @TODO freeList : voir si la mémoire est bien libérée
    assert(deleteData == 0 || deleteData == 1);
    assert(L != NULL);

    LNode *node;

    node = Head(L);

    if (deleteData == 1) {
        while (node != NULL) {
            LNode *next;

            next = Successor(node);
            L->freeData(getLNodeData(node));
            node = next;
        }
    } else if (deleteData == 0) {
        while (node != NULL) {
            free(node);
        }
        free(L);
    }
}

void viewList(const List *L) {
    assert(L);

    LNode *N;

    printf("\n[ ");
    for (N = Head(L); N; N = Successor(N)) {
        (*L->viewData)(getLNodeData(N));
    }
    printf(" ]\n");
}

void listInsertFirst(List *L, void *data) {
    assert(L);

    LNode *newNode;

    newNode = newLNode(data);
    assert(newNode);

    if (listIsEmpty(L)) {
        setHead(L, newNode);
        setTail(L, newNode);

    } else {
        setSuccessor(newNode, Successor(data));
        setPredecessor(Head(L), newNode);
        setHead(L, newNode);
    }
    increaseListSize(L);
}

void listInsertLast(List *L, void *data) {
    assert(L);

    LNode *newNode;

    newNode = newLNode(data);
    assert(newNode);

    if (listIsEmpty(L)) {
        setTail(L, newNode);
        setHead(L, newNode);

    } else {
        setSuccessor(Tail(L), newNode);
        setPredecessor(newNode, Tail(L));
        setTail(L, newNode);
    }
    increaseListSize(L);
}

void listInsertAfter(List *L, void *data, LNode *ptrelm) {
    // @TODO listInsertAfter : si on met l'élément à la bonne place
    if (ptrelm == NULL) {
        setLNodeData(ptrelm, data);

    } else {
        struct ListNode *newNode;

        newNode = newLNode(data);
        assert(newNode);

        if (listIsEmpty(L)) {
            setHead(L, newNode);
            setTail(L, newNode);
        } else {
            setSuccessor(newNode, Successor(ptrelm));
            setSuccessor(ptrelm, newNode);

            if (ptrelm == Tail(L)) {
                setTail(L, newNode);
            }
        }
        increaseListSize(L);
    }
}

void *listRemoveFirst(List *L) {
    assert(Head(L));
    // TODO listRemoveFirst
}

void *listRemoveLast(List *L) {
    assert(Head(L));
    // TODO listRemoveLast
}

void *listRemoveNode(List *L, LNode *node) {
    assert(Head(L) && Tail(L));
    // TODO listRemoveNode
}

List *listConcatenate(List *L1, List *L2) {
    // TODO listConcatenate
}