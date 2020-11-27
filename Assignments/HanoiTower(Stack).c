#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int value;
    struct stack *next;
};

struct stack ** stacks[3];

//EKLE: Onceden olusturulmus bir nodu sartlar saglaniyor ise stackin sonuna ekler.
int push(struct stack **stack_head, struct stack *new_element)
{

    struct stack *iter = NULL;

    new_element->next = NULL;

    //stack bos ise ilk eleman olarak eklenir.
    if(*stack_head == NULL)
    {

        *stack_head = new_element;

        return 0;

    }

    iter = *stack_head;

    while (iter != NULL)
    {

        //eger hedef stackteki son eleman(varsa) eklenecek elemandan buyuk ise
        //-1 degeri doner.
        if (iter->next == NULL && iter->value < new_element->value) {

            return -1;

        }

        if (iter->next == NULL) {

            break;

        }

        iter = iter->next;

    }

    iter->next = new_element;

    return 0;

}

//AL: Stackten son elemani alir.
struct stack *pop(struct stack **stack_head)
{

    struct stack *result = NULL;
    struct stack *iter = NULL;
    struct stack *prev = NULL;

    //bos liste ise hata mesaji yazdirir ve NULL deger dondurur.
    if (*stack_head == NULL)
    {
        printf("%s\n", "ERROR! Stack is empty");
        return NULL;
    }

    iter = *stack_head;

    while (iter->next)
    {

        prev = iter;
        iter = iter->next;

    }

    //stackte sadece bir eleman olmasi durumunda stackin ilk elemani NULL olur.
    if ((*stack_head)->next == NULL)
    {

        result = (*stack_head);
        (*stack_head) = NULL;

        return result;

    }

    result = iter;
    prev->next = NULL;

    return result;

}

//hedef stacke belirli bir stackteki son elemani aktarir.
void transfer(struct stack **from, struct stack **to)
{

    struct stack *element = NULL;

    element = pop(from);

    if (element == NULL) {

        return;

    }

    if (push(to, element) == -1)
    {

        push(from, element);

    }

}

//Tum stackleri ekrana yazdirir.
void print_all()
{
    int towers[3][5] = {0};
    int i,j = 0;

    for (i = 0; i < 3; i++) {

        struct stack *iter = *stacks[i];

        j = 0;

        while (iter != NULL)
        {

            towers[i][j] = iter->value;
            iter = iter->next;

            j = j + 1;

        }

    }
    printf("\n");
    for (i = 4; i >= 0; i--)
    {

        printf("    ");

        for (j = 0; j < 3; j++)
        {

            if (towers[j][i] == 0)
            {
                printf("    |    ");
            }
            else
            {
                printf("  %s%s%d%s%s  ","|","#",towers[j][i],"#","|");
            }

        }

        printf("    \n");

    }

    printf("///////////////////////////////////\n");

}

int main()
{

    struct stack *tower_first = NULL;
    struct stack *tower_second = NULL;
    struct stack *tower_third = NULL;

    stacks[0] = &tower_first;
    stacks[1] = &tower_second;
    stacks[2] = &tower_third;

    for (int i = 0; i < 3; i++)
    {

        struct stack *temp = (struct stack *) malloc(sizeof(struct stack));
        temp->value = 3-i;
        temp->next = NULL;

        push(&tower_first, temp);

    }

    print_all();
    transfer(&tower_first,&tower_third);
    print_all();
    transfer(&tower_first,&tower_second);
    print_all();
    transfer(&tower_third,&tower_second);
    print_all();
    transfer(&tower_first,&tower_third);
    print_all();
    transfer(&tower_second,&tower_first);
    print_all();
    transfer(&tower_second,&tower_third);
    print_all();
    transfer(&tower_first,&tower_third);
    print_all();

    return 0;
}
