#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct  Node* createList(int n) {
    struct Node* head = NULL, *temp = NULL, *prev = NULL;

    for (int i = 0; i <= n; i++)
    {   
        temp = (struct Node*)malloc(sizeof(struct Node));

        temp -> data = i;
        temp -> next = head;

        if (head == NULL) {
            head = temp;
        } else {
            prev -> next = temp;
        }
        prev = temp;
    }
    prev -> next = head;
    return head;

};

int josephus(int n, int k) {
    struct Node* head = createList(n);
    struct Node* ptr = head, *prev = NULL;

    while (ptr->next != ptr) {
        for (int count = 1; count < k; count++) {
            prev = ptr;
            ptr = ptr->next;
        }

        prev->next = ptr->next;
        printf("Eliminated : %d\n", ptr->data);

        free(ptr);
        ptr = prev->next;
    }
    int survivor = ptr->data;
    free(ptr);

    return survivor;
}

int main() {
    int n = 7, k = 3;
    printf("Survivor : %d\n", josephus(n, k));
    return 0;
}
