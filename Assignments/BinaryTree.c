#include <stdio.h>
#include <stdlib.h>

struct binary_tree
{

    int value;
    struct binary_tree *left_child;
    struct binary_tree *right_child;

};

struct queue
{

    struct binary_tree *data;
    struct queue *next;
    
};

struct binary_tree *create_node(int value)
{

    struct binary_tree *new_node = (struct binary_tree *) malloc(sizeof(struct binary_tree));

    new_node->value = value;
    new_node->left_child = NULL;
    new_node->right_child = NULL;

    return new_node;

}

void insert_node_left(struct binary_tree *node, struct binary_tree *new_node)
{

    if (node->left_child)
    {

        new_node->left_child = node->left_child;
        node->left_child = new_node;

    }
    else
    {

        node->left_child = new_node;

    }

}

void insert_node_right(struct binary_tree *node, struct binary_tree *new_node)
{

    if (node->right_child)
    {

        new_node->right_child = node->right_child;
        node->right_child = new_node;

    }
    else
    {

        node->right_child = new_node;

    }

}

void print_pre_order(struct binary_tree *node)
{

    printf("[%d] ", node->value);

    if (node->left_child)
    {

        print_pre_order(node->left_child);

    }

    if (node->right_child)
    {

        print_pre_order(node->right_child);
        
    }

}

void print_in_order(struct binary_tree *node)
{

    if (node->left_child)
    {

        print_in_order(node->left_child);

    }

    printf("[%d] ", node->value);

    if (node->right_child)
    {

        print_in_order(node->right_child);

    }

}

void print_post_order(struct binary_tree *node)
{

    if (node->left_child)
    {

        print_post_order(node->left_child);

    }

    if (node->right_child)
    {

        print_post_order(node->right_child);

    }

    printf("[%d] ", node->value);

}

void enqueue(struct queue **queue_head, struct binary_tree *data)
{

    struct queue *new_e = (struct queue *) malloc(sizeof(struct queue));
    struct queue *iter;

    new_e->data = data;
    new_e->next = NULL;

    if (!(*queue_head))
    {

        *queue_head = new_e;
        return;

    }
    
    iter = *queue_head;

    while (iter->next)
    {

        iter = iter->next;

    }
    
    iter->next = new_e;

}

struct binary_tree *dequeue(struct queue **queue_head)
{

    struct binary_tree *result;

    if (!(*queue_head))
    {

        return NULL;

    }
    
    result = (*queue_head)->data;
    
    if ((*queue_head)->next)
    {

        *queue_head = (*queue_head)->next;

    }
    else
    {

        *queue_head = NULL;

    }

    return result;
}

void print_bfs(struct binary_tree *tree_head)
{

    struct queue *new_queue = NULL;
    struct binary_tree *node = NULL;

    node = tree_head;

    while (node != NULL)
    {

        printf("[%d] ", node->value);
        
        if (node->left_child)
        {

            enqueue(&new_queue, node->left_child);

        }
        
        if (node->right_child)
        {

            enqueue(&new_queue, node->right_child);
            
        }

        node = dequeue(&new_queue);

    }

}

int main()
{

    struct binary_tree *binary_list = NULL;

    binary_list = create_node(1);
    insert_node_left(binary_list, create_node(2));
    insert_node_right(binary_list, create_node(3));
    insert_node_left(binary_list->left_child, create_node(4));
    insert_node_right(binary_list->left_child, create_node(5));
    insert_node_left(binary_list->right_child, create_node(6));
    insert_node_right(binary_list->right_child, create_node(7));

    printf("\nPre-Order------------\n\n ");
    print_pre_order(binary_list);
    printf("\n\nIn-Order-------------\n\n ");
    print_in_order(binary_list);
    printf("\n\nPost-Order-----------\n\n ");
    print_post_order(binary_list);
    printf("\n\nBreadth-First Search-\n\n ");
    print_bfs(binary_list);
    printf("\n\n---------------------");

    return 0;

}