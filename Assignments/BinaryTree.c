#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *left_child;
    struct node *right_child;
};

/*
void insert_node_left(struct node *node, int value)
{

    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->value = value;

    if (node->left_child)
    {
        new_node->left_child = node->left_child;
    }
    else
    {
        node->left_child = new_node;
    }

}

void insert_node_right(struct node *node, int value)
{

    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    node->right_child->value = value;

    if (node->right_child)
    {
        new_node->right_child = node->right_child;
    }
    else
    {
        node->right_child = new_node;
    }

}
*/

void print_pre_order_dfs(struct node *head_node)
{

    printf("%d\n", head_node->value);

    if (head_node->left_child)
    {
        print_pre_order_dfs(head_node->left_child);
    }

    if (head_node->right_child)
    {
        print_pre_order_dfs(head_node->right_child);
    }

}

void print_in_order_dfs(struct node *head_node)
{

    if (head_node->left_child)
    {
        print_in_order_dfs(head_node->left_child);
    }

    printf("%d\n", head_node->value);

    if (head_node->right_child)
    {
        print_in_order_dfs(head_node->right_child);
    }

}

void print_post_order_dfs(struct node *head_node)
{

    if (head_node->left_child)
    {
        print_in_order_dfs(head_node->left_child);
    }

    if (head_node->right_child)
    {
        print_in_order_dfs(head_node->right_child);
    }

    printf("%d\n", head_node->value);

}
/*
void print_bfs()
{

}
*/
int main() {

    struct node * binary_list = NULL;

    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->right_child = NULL;
    new_node->left_child = NULL;
    new_node->value = 2;
    struct node *new_node2 = (struct node *) malloc(sizeof(struct node));
    new_node2->right_child = NULL;
    new_node2->left_child = NULL;
    new_node2->value = 3;
    struct node *new_node3 = (struct node *) malloc(sizeof(struct node));
    new_node3->right_child = NULL;
    new_node3->left_child = NULL;
    new_node3->value = 1;
    struct node *new_node4 = (struct node *) malloc(sizeof(struct node));
    new_node4->right_child = NULL;
    new_node4->left_child = NULL;
    new_node4->value = 4;

    new_node2->right_child = new_node4;
    new_node->right_child = new_node2;
    new_node->left_child = new_node3;

    binary_list = new_node;

    print_in_order_dfs(binary_list);
    print_pre_order_dfs(binary_list);
    print_post_order_dfs(binary_list);
    printf("end");

    return 0;
}
