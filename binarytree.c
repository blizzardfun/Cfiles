// The operations performed on trees requires searching in one of two main ways: 
// Depth First Search and Breadth-first search. Depth-first search (DFS) is an algorithm 
// for traversing or searching tree or graph data structures. One starts at the root and 
// explores as far as possible along each branch before backtracking. There are three 
// types of depth first search traversal: 
// pre-order visit, left, right, 
// in-order left, visit, right, 
// post-order left, right, visit. 
// Breadth-first search (BFS) is an algorithm for traversing or searching tree or graph structures. 
// In level-order, where we visit every node on a level before going to a lower level.

// Below is an implementation of a binary tree that has insertion and printing capabilities. 
// This tree is ordered but not balanced. This example maintains its ordering at insertion time.

// printDFS is depth-first pre-order
// print_tree is depth first in-order 
#include <stdio.h>
#include <stdlib.h>

typedef struct node  //tree node
{
  int val;
  struct node * left;
  struct node * right;
} node_t;

void insert(node_t * tree,int val);
void print_tree(node_t * current);
void printDFS(node_t * current);

int main()
{
  node_t * test_list = malloc(sizeof(node_t));
  /* set values explicitly, alternative would be calloc() */
  test_list->val = 0;
  test_list->left = NULL;
  test_list->right = NULL;

  insert(test_list,5);
  insert(test_list,8);
  insert(test_list,4);
  insert(test_list,3);
  insert(test_list,7);
  insert(test_list,10);
  insert(test_list,3);

  printDFS(test_list);
  printf("\n");
  print_tree(test_list);
}

void insert(node_t * tree, int val)
{
  if (tree->val == 0)
  {
    /* insert on current (empty) position */
    tree->val=val;
  }
  else
  {
    if (val < tree->val)
    {
        /* insert left */
            if (tree->left != NULL)
                {
                    insert(tree->left, val);
                }
            else
            {
                tree->left = malloc(sizeof(node_t));
            /* set values explicitly, alternative would be calloc() */
                tree->left->val = val;
                tree->left->left = NULL;
                tree->left->right = NULL;
            }
    }
    else
    {
      if (val >= tree->val)
      {
            /* insert right */
            if (tree->right != NULL)
                {
                insert(tree->right,val);
                }
            else
                {
                tree->right=malloc(sizeof(node_t));
                /* set values explicitly, alternative would be calloc() */
                tree->right->val=val;
                tree->right->left = NULL;
                tree->right->right = NULL;
                }
      }
    }
  }
}

/* depth-first search */
void printDFS(node_t * current)
{
// print current, left, right
  if (current != NULL)         
  {
        printf("%d ", current->val); 
        if (current->left != NULL)   printDFS(current->left);
        if (current->right != NULL)  printDFS(current->right);
  }
 
}

void print_tree(node_t * current)
{
 // print in order left, current, right
  if (current != NULL) 
  {
        if (current->left != NULL)  print_tree(current->left); 
        printf("%d ", current->val);
        if (current->right != NULL)  print_tree(current->right);   
    } 
}