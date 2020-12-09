#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LENGTH 256
#define MAX_NAME_SIZE 20
#define MAX_DATE_SIZE 16

struct product
{
    char product_name[MAX_NAME_SIZE];
    int price;
    char product_category;
    void *product_data;
    struct product *next;
};

//Category Char : E
struct meat
{
    char type; // 'R' : red meat, 'B' : fish, 'P' : chicken meat
    char pack_date[MAX_DATE_SIZE];
    char expiration_date[MAX_DATE_SIZE];
};

//Category Char : T
struct vegetable
{
    char type; // 'M' : Fruit, 'S' : vegetable
    char pack_date[MAX_DATE_SIZE];
};

//Category Char : S
struct dairy_product
{
    char expiration_date[MAX_DATE_SIZE];
};

//Category Char : K
struct canned_food
{
    char expiration_date[MAX_DATE_SIZE];
    int aisle_number;
    char aisle_side; //'A' or 'B'
};

//Category Char : G
struct non_food
{
    char type; // 'C' : Cleaning product, 'P' : Pharmacy products, 'D' : Others
    int aisle_number;
    char aisle_side; //'A' or 'B'
};

int add_product(struct product **head, char category)
{
    struct product * new_element = (struct product *) malloc(sizeof(struct product));
    struct product * iter;

    char name[MAX_NAME_SIZE];
    char buf[BUFFER_LENGTH];

    printf("\nUrun adi -> ");

    if (fgets(buf, BUFFER_LENGTH, stdin)) {
        sscanf(buf,"%s",name);
    }

    printf("\nUrunun birim maliyeti -> ");

    if (fgets(buf, BUFFER_LENGTH, stdin)) {
        sscanf(buf,"%d",&new_element->price);
    }

    strcpy(new_element->product_name, name);
    new_element->product_category = category;
    new_element->next = NULL;

    if (category == 'E' || category == 'e')
    {
        struct meat * new_data = (struct meat *) malloc(sizeof(struct meat));
        char type, p_date[MAX_DATE_SIZE], e_date[MAX_DATE_SIZE];

        printf("\nEt turu ('R' : Kirmizi et, 'B' : Balik, 'P' : Tavuk) -> ");

        if (fgets(buf, BUFFER_LENGTH, stdin)) {
            sscanf(buf,"%c",&type);
        }

        printf("\nPaketlenme tarihi ( 'GG-AA-YYYY' ) -> ");

        if (fgets(buf, BUFFER_LENGTH, stdin)) {
            sscanf(buf,"%s",p_date);
        }

        printf("\nSon tuketim tarihi ( 'GG-AA-YYYY' ) -> ");

        if (fgets(buf, BUFFER_LENGTH, stdin)) {
            sscanf(buf,"%s",e_date);
        }

        new_data->type = type;
        strcpy(new_data->pack_date, p_date);
        strcpy(new_data->expiration_date, e_date);

        new_element->product_data = new_data;
    }
    else if (category == 'T' || category == 't')
    {
        struct vegetable * new_data = (struct vegetable *) malloc(sizeof(struct vegetable));
        char type, p_date[MAX_DATE_SIZE];

        printf("\nTarim turu ('M' : Meyve, 'S' : Sebze) -> ");

        if (fgets(buf, BUFFER_LENGTH, stdin)) {
            sscanf(buf,"%c",&type);
        }

        printf("\nPaketlenme tarihi ( 'GG-AA-YYYY' ) -> ");

        if (fgets(buf, BUFFER_LENGTH, stdin)) {
            sscanf(buf,"%s",p_date);
        }

        new_data->type = type;
        strcpy(new_data->pack_date, p_date);

        new_element->product_data = new_data;
    }
    else if (category == 'S' || category == 's')
    {
        struct dairy_product * new_data = (struct dairy_product *) malloc(sizeof(struct dairy_product));
        char e_date[MAX_DATE_SIZE];

        printf("\nSon tuketim tarihi ( 'GG-AA-YYYY' ) -> ");

        if (fgets(buf, BUFFER_LENGTH, stdin)) {
            sscanf(buf,"%s",e_date);
        }

        strcpy(new_data->expiration_date, e_date);

        new_element->product_data = new_data;
    }
    else if (category == 'K' || category == 'k')
    {
        struct canned_food * new_data = (struct canned_food *) malloc(sizeof(struct canned_food));
        char a_side, e_date[MAX_DATE_SIZE];
        int a_number;
        printf("\nSon tuketim tarihi ( 'GG-AA-YYYY' ) -> ");

        if (fgets(buf, BUFFER_LENGTH, stdin)) {
            sscanf(buf,"%s",e_date);
        }

        printf("\nReyon numarasi -> ");

        if (fgets(buf, BUFFER_LENGTH, stdin)) {
            sscanf(buf,"%d", &a_number);
        }

        printf("\nReyon tarafi ('A' ya da 'B') -> ");

        if (fgets(buf, BUFFER_LENGTH, stdin)) {
            sscanf(buf,"%c", &a_side);
        }

        strcpy(new_data->expiration_date, e_date);
        new_data->aisle_number = a_number;
        new_data->aisle_side = a_side;

        new_element->product_data = new_data;
    }
    else if (category == 'G' || category == 'g')
    {
        struct non_food * new_data = (struct non_food *) malloc(sizeof(struct non_food));
        char a_side, type;
        int a_number;
        printf("\nTuru ('C' : Temizlik, 'P' : Eczane, 'D' : Diger) -> ");

        if (fgets(buf, BUFFER_LENGTH, stdin)) {
            sscanf(buf,"%c", &type);
        }

        printf("\nReyon numarasi -> ");

        if (fgets(buf, BUFFER_LENGTH, stdin)) {
            sscanf(buf,"%d", &a_number);
        }

        printf("\nReyon tarafi ('A' ya da 'B') -> ");

        if (fgets(buf, BUFFER_LENGTH, stdin)) {
            sscanf(buf,"%c", &a_side);
        }

        new_data->type = type;
        new_data->aisle_number = a_number;
        new_data->aisle_side = a_side;

        new_element->product_data = new_data;
    }
    else
    {
        free(new_element);

        return 1;
    }

    if (*head == NULL)
    {

        *head = new_element;

        return 0;

    }

    iter = *head;

    while (iter->next != NULL)
    {
        iter = iter->next;
    }

    iter->next = new_element;

    return 0;
}

void show_product(struct product *head)
{

    struct product * iter;

    iter = head;
    printf("\n------------<Kayitli-Urunler>------------\n\n");
    while (iter != NULL)
    {
        char cat = iter->product_category;

        if (cat == 'E' || cat == 'e')
        {
            struct meat *data = (struct meat *) iter->product_data;

            printf("%s %d %c %s %s\n", iter->product_name, iter->price, data->type, data->pack_date, data->expiration_date);
        }
        else if (cat == 'T' || cat == 't')
        {
            struct vegetable *data = (struct vegetable *) iter->product_data;

            printf("%s %d %c %s\n", iter->product_name, iter->price, data->type, data->pack_date);
        }
        else if (cat == 'S' || cat == 's')
        {
            struct dairy_product *data = (struct dairy_product *) iter->product_data;

            printf("%s %d %s\n", iter->product_name, iter->price, data->expiration_date);
        }
        else if (cat == 'K' || cat == 'k')
        {
            struct canned_food *data = (struct canned_food *) iter->product_data;

            printf("%s %d %s %d %c\n", iter->product_name, iter->price, data->expiration_date, data->aisle_number, data->aisle_side);
        }
        else if (cat == 'G' || cat == 'g')
        {
            struct non_food *data = (struct non_food *) iter->product_data;

            printf("%s %d %c %d %c\n", iter->product_name, iter->price, data->type, data->aisle_number, data->aisle_side);
        }

        iter = iter->next;
    }

    printf("\n-----------------------------------------\n\n");
}

int main()
{
    struct product * head = NULL;
    int input = 0;
    char buf[BUFFER_LENGTH];
    int product_counter = 1;
    while (1) {

        input = 0;
        printf("\n(0) Urun Ekle, (1) Urunleri Listele, (2) Cikis -> ");

        if (fgets(buf, BUFFER_LENGTH, stdin)) {
            sscanf(buf,"%d",&input);
        }

        if (input == 0) // Add New Product
        {

            char test;

            printf("\n------------<%d. Urun Bilgileri>------------\n", product_counter);

            printf("\nE: Et, T: Tarim, S: Sut, K: Konserve, G: Gida-disi -> ");

            if (fgets(buf, BUFFER_LENGTH, stdin)) {
                sscanf(buf,"%c",&test);
            }

            if( add_product(&head, test) == 0 )
            {
                product_counter++;
            }

        }
        else if (input == 1) // Show Products
        {
            show_product(head);
        }
        else if (input == 2) // Exit
        {
            break;
        }
        else // Incorrect input
        {
            printf("\nHatali giris!\n");
        }

    }

    return 0;
}
