#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* newNode(int key) {
    Node *n = malloc(sizeof(Node));
    n->key = key;
    n->left = n->right = NULL;
    return n;
}

Node* rightRotate(Node *x) {
    Node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

Node* leftRotate(Node *x) {
    Node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

Node* splay(Node *root, int key) {
    if (!root || root->key == key)
        return root;

    if (key < root->key) {
        if (!root->left) return root;

        if (key < root->left->key) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        } else if (key > root->left->key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right)
                root->left = leftRotate(root->left);
        }
        return (root->left == NULL) ? root : rightRotate(root);

    } else {
        if (!root->right) return root;

        if (key > root->right->key) {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        } else if (key < root->right->key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left)
                root->right = rightRotate(root->right);
        }
        return (root->right == NULL) ? root : leftRotate(root);
    }
}

Node* insert(Node *root, int key) {
    if (!root) return newNode(key);

    root = splay(root, key);

    Node *n = newNode(key);
    if (key < root->key) {
        n->right = root;
        n->left = root->left;
        root->left = NULL;
    } else {
        n->left = root;
        n->right = root->right;
        root->right = NULL;
    }
    return n;
}

Node* search(Node *root, int key) {
    return splay(root, key);
}

void preorder(Node *root) {
    if (!root) return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node *root = NULL;
    int choice, key;

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Preorder\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &key);
            root = insert(root, key);
        }
        else if (choice == 2) {
            printf("Enter value to search: ");
            scanf("%d", &key);
            root = search(root, key);
            printf("Splayed %d to root.\n", key);
        }
        else if (choice == 3) {
            printf("Preorder: ");
            preorder(root);
            printf("\n");
        }
        else break;
    }
    return 0;
}
