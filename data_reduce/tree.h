#ifndef TREE_H
#define TREE_H

typedef struct  Node
{
    int value;
    int frequency;
    struct Node* left;
    struct Node* right;
} node_t;

node_t* create_node(int start_value);
void tree_push(node_t* root,int value);
int search(node_t* root,int search_value);
void print_in_order(node_t* root);
void free_tree(node_t* root);
int count_nodes(node_t*root);
int convert_to_array(node_t* root,int i,int arr[]);
#endif