#include <stdio.h>
#include "graph.h"


int main() {
    initQ();

    node n1 = {3, "A"};
    adj a1 = {&n1, 0};
    insertQ(n1.priority, &a1);

    node n2 = {1, "B"};
    adj a2 = {&n2, 0};
    insertQ(n2.priority, &a2);

    node *del = deleteQ();
    printf("Deleted: priority=%d, data=%s\n", del->priority, (char*)del->data);

    return 0;
}
