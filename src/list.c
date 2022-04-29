#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/list.h"
#include "../include/util.h"

/********************************************************************
 * LNode
 ********************************************************************/
 //TODO : commenter

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
    node->succ = newSucc;
}

void setPredecessor(LNode *node, LNode *newPred) {
    node->pred = newPred;
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

    } else {
        return 0;
    }
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
    assert(L);

    LNode *node;
    LNode *next;

    node = Head(L);

    while (node) {
        next = Successor(node);
        if (deleteData == 1) {
            L->freeData(getLNodeData(node));
        }
        free(node);
        node = next;
    }

    free(L);
    L = NULL;
}

void viewList(const List *L) {
    assert(L);

    LNode *N;

    printf("\n[ ");
    for (N = Head(L); N; N = Successor(N)) {
        (*L->viewData)(getLNodeData(N));
        printf(" ");
    }
    printf("]\n");
}

void listInsertFirst(List *L, void *data) {
    assert(L);

    LNode *newNode;

    newNode = newLNode(data);

    if (listIsEmpty(L)) {
        setHead(L, newNode);
        setTail(L, newNode);

    } else {
        setSuccessor(newNode, Head(L));
        setPredecessor(Head(L), newNode);
        setHead(L, newNode);
    }
    increaseListSize(L);
}

void listInsertLast(List *L, void *data) {
    assert(L);

    LNode *newNode;

    newNode = newLNode(data);

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
    if (!ptrelm) {
        setLNodeData(ptrelm, data);

    } else {
        struct ListNode *newNode;

        newNode = newLNode(data);

        if (listIsEmpty(L)) {
            setHead(L, newNode);
            setTail(L, newNode);

        } else {
            setSuccessor(newNode, Successor(ptrelm));
            setPredecessor(ptrelm, newNode);

            if (ptrelm == Tail(L)) {
                setTail(L, newNode);
            }
        }
        increaseListSize(L);
    }
}

void *listRemoveFirst(List *L) {
    assert(L);
    assert(Head(L));

    if (listIsEmpty(L)) {
        ShowMessage("La liste L est vide", 0);
    }

    void *dataTemp;
    void *succ;
    void *nodeToRemove;

    dataTemp = getLNodeData(Head(L));
    succ = Successor(Head(L));
    nodeToRemove = Head(L);

    setHead(L, succ);
    setPredecessor(Head(L), NULL);

    free(nodeToRemove);
    decreaseListSize(L);

    return dataTemp;
}

void *listRemoveLast(List *L) {
    assert(L);
    assert(Tail(L));

    if (listIsEmpty(L)) {
        ShowMessage("La liste est vide", 0);
    }

    void *dataTemp;
    void *pred;
    void *nodeToRemove;

    dataTemp = getLNodeData(Tail(L));
    pred = Predecessor(Tail(L));
    nodeToRemove = Tail(L);

    setTail(L, pred);
    setSuccessor(Tail(L), NULL);

    free(nodeToRemove);
    decreaseListSize(L);

    return dataTemp;
}

void *listRemoveNode(List *L, LNode *node) {
    assert(Head(L) && Tail(L));

    if (listIsEmpty(L)) {
        ShowMessage("La liste est vide", 0);
    }

    void *dataTemp;

    dataTemp = getLNodeData(node);

    if (node == Head(L)) {
        listRemoveFirst(L);

    } else if (node == Tail(L)) {
        listRemoveLast(L);

    } else {
        setSuccessor(Predecessor(node), Successor(node));
        setPredecessor(Successor(node), Predecessor(node));

        free(node);
        decreaseListSize(L);
    }

    return dataTemp;
}

List *listConcatenate(List *L1, List *L2) {
    assert(L1);
    assert(L2);

    if (listIsEmpty(L1)) {
        freeList(L1, 0);
        return L2;

    } else if (listIsEmpty(L2)) {
        freeList(L2, 0);
        return L1;

    } else {
        setSuccessor(Tail(L1), Head(L2));
        setPredecessor(Head(L2), Tail(L1));
        setListSize(L1, getListSize(L1) + getListSize(L2));
        //Pas de freeList
        free(L2);
        return L1;
    }
}
