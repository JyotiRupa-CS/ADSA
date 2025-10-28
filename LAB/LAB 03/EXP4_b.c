#include <stdio.h>
#include <stdlib.h>

#define MAX 3  // Maximum keys in a node (order t=2)
#define MIN 1  // Minimum keys in a node (t-1)

struct BTreeNode {
    int keys[MAX+1];
    int count;
    struct BTreeNode *child[MAX+2];
    int leaf;
};

typedef struct BTreeNode Node;

// Create a new B-Tree node
Node* createNode(int leaf) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->leaf = leaf;
    node->count = 0;
    for(int i=0; i<MAX+2; i++)
        node->child[i] = NULL;
    return node;
}

// Inorder traversal
void traverse(Node* root) {
    if(root != NULL) {
        int i;
        for(i=0; i<root->count; i++) {
            if(!root->leaf)
                traverse(root->child[i]);
            printf("%d ", root->keys[i]);
        }
        if(!root->leaf)
            traverse(root->child[i]);
    }
}

// Split child y of node x at index i
void splitChild(Node* x, int i, Node* y) {
    Node* z = createNode(y->leaf);
    z->count = MIN;

    for(int j=0; j<MIN; j++)
        z->keys[j] = y->keys[j+MIN+1];

    if(!y->leaf) {
        for(int j=0; j<=MIN; j++)
            z->child[j] = y->child[j+MIN+1];
    }

    y->count = MIN;

    for(int j=x->count; j>=i+1; j--)
        x->child[j+1] = x->child[j];
    x->child[i+1] = z;

    for(int j=x->count-1; j>=i; j--)
        x->keys[j+1] = x->keys[j];
    x->keys[i] = y->keys[MIN];
    x->count++;
}

// Insert key into non-full node
void insertNonFull(Node* x, int k) {
    int i = x->count - 1;

    if(x->leaf) {
        while(i>=0 && k<x->keys[i]) {
            x->keys[i+1] = x->keys[i];
            i--;
        }
        x->keys[i+1] = k;
        x->count++;
    } else {
        while(i>=0 && k<x->keys[i])
            i--;
        i++;
        if(x->child[i]->count == MAX) {
            splitChild(x, i, x->child[i]);
            if(k > x->keys[i])
                i++;
        }
        insertNonFull(x->child[i], k);
    }
}

// Insert key into B-Tree
Node* insert(Node* root, int k) {
    if(root == NULL)
        return createNode(1);

    if(root->count == MAX) {
        Node* s = createNode(0);
        s->child[0] = root;
        splitChild(s, 0, root);

        int i = 0;
        if(s->keys[0] < k)
            i++;
        insertNonFull(s->child[i], k);
        return s;
    } else {
        insertNonFull(root, k);
        return root;
    }
}

// Find key index in node
int findKey(Node* root, int k) {
    int idx = 0;
    while(idx < root->count && root->keys[idx] < k)
        ++idx;
    return idx;
}

// Forward declaration
void removeKey(Node* root, int k);

// Remove from leaf node
void removeFromLeaf(Node* node, int idx) {
    for(int i = idx+1; i < node->count; i++)
        node->keys[i-1] = node->keys[i];
    node->count--;
}

// Remove from non-leaf node (simple predecessor replacement)
void removeFromNonLeaf(Node* node, int idx) {
    int k = node->keys[idx];
    Node* predNode = node->child[idx];
    while(!predNode->leaf)
        predNode = predNode->child[predNode->count];
    int pred = predNode->keys[predNode->count-1];

    node->keys[idx] = pred;
    removeKey(node->child[idx], pred);
}

// Remove key from B-Tree node
void removeKey(Node* node, int k) {
    int idx = findKey(node, k);

    if(idx < node->count && node->keys[idx] == k) {
        if(node->leaf)
            removeFromLeaf(node, idx);
        else
            removeFromNonLeaf(node, idx);
    } else {
        if(node->leaf) {
            printf("Key %d not found in tree\n", k);
            return;
        }

        int flag = ((idx == node->count) ? 1 : 0);
        removeKey(node->child[idx], k);
    }
}

// Main program
int main() {
    Node* root = NULL;
    int n, key, del_n, del_key;

    // Insert elements
    printf("Enter number of elements to insert: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for(int i=0; i<n; i++) {
        scanf("%d", &key);
        root = insert(root, key);
    }

    printf("B-Tree inorder traversal after insertion: ");
    traverse(root);
    printf("\n");

    // Delete elements
    printf("Enter number of elements to delete: ");
    scanf("%d", &del_n);
    if(del_n > 0) {
        printf("Enter %d elements to delete: ", del_n);
        for(int i=0; i<del_n; i++) {
            scanf("%d", &del_key);
            removeKey(root, del_key);
        }
    }

    printf("B-Tree inorder traversal after deletion: ");
    traverse(root);
    printf("\n");

    return 0;
}
