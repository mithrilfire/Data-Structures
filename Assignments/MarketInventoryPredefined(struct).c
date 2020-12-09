#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LENGTH 256
#define MAX_NAME_SIZE 20
#define MAX_DATE_SIZE 16

struct product
{
    char product_category;
    void *product_data;
    struct product *next;
};

//Category Char : E
struct meat
{
    char product_name[MAX_NAME_SIZE];
    int price;
    char type; // 'R' : red meat, 'B' : fish, 'P' : chicken meat
    char pack_date[MAX_DATE_SIZE];
    char expiration_date[MAX_DATE_SIZE];
};

//Category Char : T
struct vegetable
{
    char product_name[MAX_NAME_SIZE];
    int price;
    char type; // 'M' : Fruit, 'S' : vegetable
    char pack_date[MAX_DATE_SIZE];
};

//Category Char : S
struct dairy_product
{
    char product_name[MAX_NAME_SIZE];
    int price;
    char expiration_date[MAX_DATE_SIZE];
};

//Category Char : K
struct canned_food
{
    char product_name[MAX_NAME_SIZE];
    int price;
    char expiration_date[MAX_DATE_SIZE];
    int aisle_number;
    char aisle_side; //'A' or 'B'
};

//Category Char : G
struct non_food
{
    char product_name[MAX_NAME_SIZE];
    int price;
    char type; // 'C' : Cleaning product, 'P' : Pharmacy products, 'D' : Others
    int aisle_number;
    char aisle_side; //'A' or 'B'
};

void add_product(struct product **head, char category, void *p_data)
{

    struct product * new_element = (struct product *) malloc(sizeof(struct product));
    struct product * iter;

    new_element->product_category = category;
    new_element->next = NULL;
    new_element->product_data = p_data;
    //strcpy(new_element->product_data->product_name, name);

    if (*head == NULL)
    {
        *head = new_element;
        return;
    }

    iter = *head;

    while (iter->next != NULL)
    {
        iter = iter->next;
    }

    iter->next = new_element;

}

void show_product(struct product *head)
{

    struct product * iter;

    iter = head;
    printf("\n-------------<Kayitli Urunler>-------------\n\n");
    while (iter != NULL)
    {
        char cat = iter->product_category;

        if (cat == 'E')
        {
            struct meat *data = (struct meat *) iter->product_data;

            printf("%s %d %c %s %s\n", data->product_name, data->price, data->type, data->pack_date, data->expiration_date);
        }
        else if (cat == 'T')
        {
            struct vegetable *data = (struct vegetable *) iter->product_data;

            printf("%s %d %c %s\n", data->product_name, data->price, data->type, data->pack_date);
        }
        else if (cat == 'S')
        {
            struct dairy_product *data = (struct dairy_product *) iter->product_data;

            printf("%s %d %s\n", data->product_name, data->price, data->expiration_date);
        }
        else if (cat == 'K')
        {
            struct canned_food *data = (struct canned_food *) iter->product_data;

            printf("%s %d %s %d %c\n", data->product_name, data->price, data->expiration_date, data->aisle_number, data->aisle_side);
        }
        else if (cat == 'G')
        {
            struct non_food *data = (struct non_food *) iter->product_data;

            printf("%s %d %c %d %c\n", data->product_name, data->price, data->type, data->aisle_number, data->aisle_side);
        }

        iter = iter->next;
    }

    printf("\n-------------------------------------------\n");
}

int main()
{
    struct product * head = NULL;

    printf("\n------------<1. Urun Bilgileri>------------\n");

    struct vegetable * example_product_1 = (struct vegetable *) malloc(sizeof(struct vegetable));
    strcpy(example_product_1->product_name, "Elma");
    printf("\nUrun adi -> %s\n",example_product_1->product_name);
    example_product_1->price = 5;
    printf("\nUrunun birim maliyeti -> %d\n",example_product_1->price);
    example_product_1->type = 'M';
    printf("\nTarim turu ('M' : Meyve, 'S' : Sebze) -> %c\n",example_product_1->type);
    strcpy(example_product_1->pack_date,"15-11-2020");
    printf("\nPaketlenme tarihi ( 'GG-AA-YYYY' ) -> %s\n",example_product_1->pack_date);
    add_product(&head,'T',example_product_1);

    printf("\n------------<2. Urun Bilgileri>------------\n");

    struct meat * example_product_2 = (struct meat *) malloc(sizeof(struct meat));
    strcpy(example_product_2->product_name, "Biftek");
    printf("\nUrun adi -> %s\n",example_product_2->product_name);
    example_product_2->price = 75;
    printf("\nUrunun birim maliyeti -> %d\n",example_product_2->price);
    example_product_2->type = 'R';
    printf("\nEt turu ('R' : Kirmizi et, 'B' : Balik, 'P' : Tavuk) -> %c\n",example_product_2->type);
    strcpy(example_product_2->pack_date,"15-11-2020");
    printf("\nPaketlenme tarihi ( 'GG-AA-YYYY' ) -> %s\n",example_product_2->pack_date);
    strcpy(example_product_2->expiration_date,"20-11-2020");
    printf("\nSon tuketim tarihi ( 'GG-AA-YYYY' ) -> %s\n",example_product_2->expiration_date);
    add_product(&head,'E',example_product_2);

    printf("\n------------<3. Urun Bilgileri>------------\n");

    struct canned_food * example_product_3 = (struct canned_food *) malloc(sizeof(struct canned_food));
    strcpy(example_product_3->product_name, "Bezelye");
    printf("\nUrun adi -> %s\n",example_product_3->product_name);
    example_product_3->price = 55;
    printf("\nUrunun birim maliyeti -> %d\n",example_product_3->price);
    strcpy(example_product_3->expiration_date,"20-11-2020");
    printf("\nSon tuketim tarihi ( 'GG-AA-YYYY' ) -> %s\n",example_product_3->expiration_date);
    example_product_3->aisle_side = 'A';
    printf("\nReyon tarafi ('A' ya da 'B') -> %c\n",example_product_3->aisle_side);
    example_product_3->aisle_number = 11;
    printf("\nReyon numarasi -> %d\n",example_product_3->aisle_side);
    add_product(&head,'K',example_product_3);

    show_product(head);

    return 0;
}
