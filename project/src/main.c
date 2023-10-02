#include <stdio.h>
#include "ListOperationIO.h"

int main() {
    CountryNode *head = OrderedList();
    if (!head) {
        printf("can't get country list");
        return 1;
    }
    PrintList(head);
    FreeList(head);
    return 0;
}
