//
// Created by Ibragim on 13.03.2022.
//

#ifndef ADVANCED_C_CPP_IZ1_LISTOPERATION_H
#define ADVANCED_C_CPP_IZ1_LISTOPERATION_H

#include "ListControl.h"

/*
 * Создает узел и считывает в него параметры страны со стандартного ввода
 * Возвращает созданный узел или NULL
 */
CountryNode *ReadCountryNode();

/**
 * Выводит параметры страны на стандартный вывод. Если название страны представлено пустым указателем,
 * вместо этого будет напечатано "Ошибка в названии страны".
 * Параметр head — указатель на первый элемент в списке. Если он равен нулю,
 * то функция ничего не возвращает.
 */
void PrintList(const CountryNode *head);

/**
 * Генерирует упорядоченный список стран на основе данных из стандартного ввода
 * Возвращает указатель на первый элемент в списке или NULL
 */
CountryNode *OrderedList();



#endif //ADVANCED_C_CPP_IZ1_LISTOPERATION_H
