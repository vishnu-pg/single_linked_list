#include <stdio.h>
#include <stdlib.h>

// Definition of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to merge two unsorted linked lists into one sorted linked list
struct Node* mergeAndSort(struct Node* list1, struct Node* list2) {
    struct Node* mergedList = NULL;
    struct Node* temp1 = list1;
    struct Node* temp2 = list2;

    // Merging the two linked lists
    while (temp1 != NULL) {
        insertAtEnd(&mergedList, temp1->data);
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        insertAtEnd(&mergedList, temp2->data);
        temp2 = temp2->next;
    }

    // Sorting the merged linked list using bubble sort (for simplicity)
    struct Node *i, *j;
    int temp;
    for (i = mergedList; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                // Swap data of i and j nodes
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    return mergedList;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Inserting elements in the first linked list
    insertAtEnd(&list1, 7);
    insertAtEnd(&list1, 2);
    insertAtEnd(&list1, 9);
    insertAtEnd(&list1, 5);

    // Inserting elements in the second linked list
    insertAtEnd(&list2, 3);
    insertAtEnd(&list2, 6);
    insertAtEnd(&list2, 4);
    insertAtEnd(&list2, 8);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    // Merging and sorting the linked lists
    struct Node* mergedList = mergeAndSort(list1, list2);

    printf("Merged and Sorted List: ");
    printList(mergedList);

    return 0;
}
