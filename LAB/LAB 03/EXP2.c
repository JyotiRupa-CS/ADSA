#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node into BST
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        printf("Inserted %d into the tree.\n", data);
        return createNode(data);
    }
    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);
    else
        printf("Duplicate value %d not inserted.\n", data);
    return root;
}

// Find the minimum value node
struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete a node from BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        printf("Element %d not found in the tree.\n", data);
        return root;
    }
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        printf("Deleting %d from the tree.\n", data);
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Inorder Traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Preorder Traversal
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Postorder Traversal
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Print the tree structure sideways
void printTree(struct Node* root, int space) {
    if (root == NULL)
        return;

    space += 5;

    // Print right subtree
    printTree(root->right, space);

    // Print current node
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // Print left subtree
    printTree(root->left, space);
}

// Show tree structure and traversals
void showTree(struct Node* root) {
    printf("\nCurrent tree structure:\n");
    printTree(root, 0);
    printf("\nInorder Traversal:\n");
    inorderTraversal(root);
    printf("\nPreorder Traversal:\n");
    preorderTraversal(root);
    printf("\nPostorder Traversal:\n");
    postorderTraversal(root);
    printf("\n");
}

// Create Tree by inserting multiple nodes and show structure and traversals
struct Node* createTree() {
    int n, value;
    struct Node* root = NULL;
    printf("Enter number of elements to create the tree: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insertNode(root, value);
    }
    printf("\nTree created successfully!\n");
    showTree(root);
    return root;
}

int main() {
    struct Node* root = NULL;
    int operation, value, traversalType;

    while (1) {
        printf("\nSelect Operation:\n");
        printf("1. Create Tree\n");
        printf("2. Insert Node\n");
        printf("3. Delete Node\n");
        printf("4. Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &operation);

        switch (operation) {
            case 1:
                root = createTree();
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("\nAfter deletion:\n");
                showTree(root);
                break;
            case 4:
                if (root == NULL) {
                    printf("Tree is empty. Please create or insert nodes first.\n");
                    break;
                }
                printf("Select Traversal Type:\n");
                printf("1. Inorder\n");
                printf("2. Preorder\n");
                printf("3. Postorder\n");
                printf("Enter your choice: ");
                scanf("%d", &traversalType);
                printf("Traversal result:\n");
                if (traversalType == 1)
                    inorderTraversal(root);
                else if (traversalType == 2)
                    preorderTraversal(root);
                else if (traversalType == 3)
                    postorderTraversal(root);
                else
                    printf("Invalid traversal choice.\n");
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
