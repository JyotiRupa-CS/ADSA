#include <stdio.h>
#include <stdlib.h>

typedef struct FibNode {
    int key;
    struct FibNode *left, *right;
} FibNode;

typedef struct FibHeap {
    FibNode *min;
} FibHeap;

FibHeap* make_heap() {
    FibHeap *H = malloc(sizeof(FibHeap));
    H->min = NULL;
    return H;
}

FibNode* create_node(int key) {
    FibNode *x = malloc(sizeof(FibNode));
    x->key = key;
    x->left = x->right = x;
    return x;
}

void fib_heap_insert(FibHeap *H, int key) {
    FibNode *x = create_node(key);
    if (H->min == NULL) {
        H->min = x;
    } else {
        x->right = H->min->right;
        H->min->right->left = x;
        x->left = H->min;
        H->min->right = x;

        if (x->key < H->min->key)
            H->min = x;
    }
}

int main() {
    FibHeap *H = make_heap();
    int choice, key;

    while (1) {
        printf("\n1. Insert\n2. Get Minimum\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter key to insert: ");
            scanf("%d", &key);
            fib_heap_insert(H, key);
        } 
        else if (choice == 2) {
            if (H->min)
                printf("Minimum key = %d\n", H->min->key);
            else
                printf("Heap is empty.\n");
        }
        else
            break;
    }
    return 0;
}
