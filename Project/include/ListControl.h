//
// Created by Ibragim on 13.03.2022.
//

#ifndef ADVANCED_C_CPP_IZ1_LISTCONTROL_H
#define ADVANCED_C_CPP_IZ1_LISTCONTROL_H

/*
 * Узел односвязного списка, в котором хранятся параметры страны и указатель на следующий элемент.
 */
typedef struct CountryNode {
    struct {
        size_t square;
        size_t population;
        double PopulationDensity;
        char *CountryName;
    } data;
    struct CountryNode *next;
} CountryNode;

/*
 * Создает новый узел.
 * Возвращает новый узел или NULL.
 */
CountryNode *CreateNode();

/*
 * Освобождает память, выделенную узлу.
 * Параметр node - узел, который нужно освободить. Если он равен нулю, то функция ничего не делает.
 */
void FreeNode(CountryNode *node);

/*
 * Добавляет вставляемый объект в связанный список перед первым узлом, большим или равным вставляемому.
 * Если такой узел является головным (или список пуст), то заголовок также будет перезаписан на вставляемый.
 * Параметр head — указатель на первый элемент в списке.
 * Параметр insertable - указатель на добавляемый элемент.
 * Возвращает 0, если узел добавлен в список или -1 в противном случае
 */
int InsertNode(CountryNode **head, CountryNode *insertable);

/*
 * Освобождает память, выделенную для узлов списка.
 * Параметр head - указатель на первый элемент в списке. Если он равен нулю, то функция ничего не делает.
 */
void FreeList(CountryNode *head);

/**
 * Реализация < сравнения для двух параметров
 * Параметр lhs - левый
 * Параметр rhs - правый
 * Вернуть 0, если левая и правая стороны почти равны или левый > правый. В противном случае вернуть 1
 */
int is_less(const double lhs, const double rhs);





#endif //ADVANCED_C_CPP_IZ1_LISTCONTROL_H
