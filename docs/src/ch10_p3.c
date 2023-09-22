#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node_t;

void insert_node(node_t **tree_ptr, int value);
void inorder(node_t *tree_ptr);
void preorder(node_t *tree_ptr);
void postorder(node_t *tree_ptr);

int main(void) {
  node_t *root_ptr = NULL;
  int values[] = {5, 16, 8, 3, 7, 9, 11, 1, 2, 22};
  for (int i = 0; i < 10; i++) {
    insert_node(&root_ptr, values[i]);
  }

  printf("Inorder traversal\n");
  inorder(root_ptr);

  printf("\nPreorder traversal\n");
  preorder(root_ptr);

  printf("\nPostorder traversal\n");
  postorder(root_ptr);

  return 0;
}

void insert_node(node_t **tree_ptr, int value) {
  if (*tree_ptr == NULL) {
    *tree_ptr = malloc(sizeof(node_t));
    if (tree_ptr == NULL) {
      printf("Unable to allocate memory\n");
      exit(-1);
    }
    (*tree_ptr)->data = value;
    (*tree_ptr)->left = NULL;
    (*tree_ptr)->right = NULL;
    return;
  }
  if (value < (*tree_ptr)->data) {
    insert_node(&((*tree_ptr)->left), value);
  } else if (value > (*tree_ptr)->data) {
    insert_node(&((*tree_ptr)->right), value);
  }
}

void inorder(node_t *tree_ptr) {
  if (tree_ptr != NULL) {
    inorder(tree_ptr->left);
    printf("%2d ", tree_ptr->data);
    inorder(tree_ptr->right);
  }
}

void preorder(node_t *tree_ptr) {
  if (tree_ptr != NULL) {
    printf("%2d ", tree_ptr->data);
    preorder(tree_ptr->left);
    preorder(tree_ptr->right);
  }
}

void postorder(node_t *tree_ptr) {
  if (tree_ptr != NULL) {
    postorder(tree_ptr->left);
    postorder(tree_ptr->right);
    printf("%2d ", tree_ptr->data);
  }
}
