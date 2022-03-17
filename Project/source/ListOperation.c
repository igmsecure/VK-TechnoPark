//
// Created by Ibragim on 13.03.2022.
//

#include <stdio.h>
#include "ListOperation.h"

/* Количество параметров для чтения в структуре CountryNode */
const int PARAMETERS_TO_READ_COUNT = 3;

CountryNode *ReadCountryNode() {
    CountryNode *node = CreateNode();
    if (!node) {
        return NULL;
    }
    if (scanf("%zd %zd %ms", &node->data.square, &node->data.population, &node->data.CountryName)
        != PARAMETERS_TO_READ_COUNT || !node->data.square || !node->data.population) {
        FreeNode(node);
        return NULL;
    }
    node->data.PopulationDensity = ((double) node->data.population) / node->data.square;
    return node;
}

void PrintList(const CountryNode *head) {
    while (head) {
        if (head->data.CountryName) {
            printf("%zd %zd %.2f %s\n", head->data.square, head->data.population,
                   head->data.PopulationDensity, head->data.CountryName);
        } else {
            printf("%zd %zd %.2f Ошибка в названии страны\n", head->data.square, head->data.population, head->data.PopulationDensity);
        }
        head = head->next;
    }
}

CountryNode *OrderedList() {
    CountryNode *head = NULL;
    CountryNode *new = ReadCountryNode();
    while (new) {
        if (InsertNode(&head, new) < 0) {
            FreeList(head);
            FreeNode(new);
            head = NULL;
            break;
        }
        new = ReadCountryNode();
    }
    return head;
}
