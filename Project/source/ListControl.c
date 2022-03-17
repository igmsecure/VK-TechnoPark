//
// Created by Ibragim on 13.03.2022.
//
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "ListControl.h"

CountryNode *CreateNode() {
    return calloc(1, sizeof(CountryNode));
}

void FreeNode(CountryNode *node) {
    if (!node) { return; }
    if (node->data.CountryName) {
        free(node->data.CountryName);
    }
    free(node);
}

int InsertNode(CountryNode **head, CountryNode *insertable) {
    if (!head || !insertable) { return -1; }
    CountryNode *previous = NULL;
    CountryNode *current = *head;
    while (current && is_less(current->data.PopulationDensity, insertable->data.PopulationDensity)) {
        previous = current;
        current = current->next;
    }
    if (previous) {
        previous->next = insertable;
    } else {
        *head = insertable;
    }
    insertable->next = current;
    return 0;
}

void FreeList(CountryNode *head) {
    CountryNode *NodeToFree = NULL;
    while (head) {
        NodeToFree = head;
        head = head->next;
        FreeNode(NodeToFree);
    }
}

int is_less(const double lhs, const double rhs) {
    return !(fabs(lhs - rhs) < DBL_EPSILON || lhs > rhs);
}
