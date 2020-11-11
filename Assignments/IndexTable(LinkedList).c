#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CUSTCOUNT 15
#define MAXLENGTH 8

const char *customer_names[CUSTCOUNT] = {"Ahmet","Bilal","Cemal","Adem","Yasin","Esin","Emel","Mustafa","Ayten","Ceylan","Nesrin","Bekir","Emin","Hakan","Hatice"};
const int invoice_prices[CUSTCOUNT] = {100,1000,600,650,350,270,410,750,600,1000,900,850,790,610,550};

struct customer_list
{
    char customer_name[MAXLENGTH];
    int invoice_price;
    struct customer_list *next;
};

struct index_list
{
    struct customer_list *customer_address;
    struct index_list *next;
};

void ekle(struct customer_list **customerlist_head, const char *new_customer_name, int new_invoice_price)
{

    struct customer_list *new_customer = (struct customer_list*) malloc(sizeof(struct customer_list));
    struct customer_list *iter = NULL;

    strcpy(new_customer->customer_name,new_customer_name);
    new_customer->invoice_price = new_invoice_price;
    new_customer->next = NULL;

    if(*customerlist_head == NULL)
    {
        *customerlist_head = new_customer;
        return;
    }

    iter = *customerlist_head;

    while (iter->next) {
        iter = iter->next;
    }
    iter->next = new_customer;

}

void ekle_index_isim(struct index_list **indexlist_head, struct customer_list *new_customer_address)
{

    struct index_list *new_index_element = (struct index_list*) malloc(sizeof(struct index_list));
    struct index_list *iter = NULL;

    new_index_element->customer_address = new_customer_address;
    new_index_element->next = NULL;

    if(*indexlist_head == NULL)
    {
        *indexlist_head = new_index_element;
        return;
    }

    iter = *indexlist_head;

    const char *newc = new_index_element->customer_address->customer_name;

    while (iter != NULL)
    {

        if (iter->next == NULL)
        {
            break;
        }

        const char *curr = iter->customer_address->customer_name;
        const char *next = iter->next->customer_address->customer_name;

        if (strcmp(newc,curr) >= 0 && strcmp(newc,next) < 0)
        {
            break;
        }

        (iter) = (iter)->next;

    }

    const char *head = (*indexlist_head)->customer_address->customer_name;

    if (strcmp(newc,head) < 0) {
        new_index_element->next = (*indexlist_head);
        (*indexlist_head) = new_index_element;
        return;
    }

    new_index_element->next = iter->next;
    iter->next = new_index_element;

}

void ekle_index_fatura(struct index_list **indexlist_head, struct customer_list *new_customer_address)
{

    struct index_list *new_index_element = (struct index_list*) malloc(sizeof(struct index_list));
    struct index_list *iter = NULL;

    new_index_element->customer_address = new_customer_address;
    new_index_element->next = NULL;

    if(*indexlist_head == NULL)
    {
        *indexlist_head = new_index_element;
        return;
    }

    iter = *indexlist_head;

    int newc = new_index_element->customer_address->invoice_price;

    while (iter != NULL)
    {

        if (iter->next == NULL)
        {
            break;
        }

        int curr = iter->customer_address->invoice_price;
        int next = iter->next->customer_address->invoice_price;

        if (newc <= curr && newc > next)
        {
            break;
        }

        (iter) = (iter)->next;

    }

    int head = (*indexlist_head)->customer_address->invoice_price;

    if (newc > head) {
        new_index_element->next = (*indexlist_head);
        (*indexlist_head) = new_index_element;
        return;
    }

    new_index_element->next = iter->next;
    iter->next = new_index_element;

}

void yazdir(struct index_list **name_indexlist_head, struct index_list **invoice_indexlist_head)
{

    struct index_list *iter = NULL;

    iter = *name_indexlist_head;

    printf("----------------------------\n");
    while(iter != NULL)
    {
        printf("Name : %s \tInvoice price: %d\n", iter->customer_address->customer_name,iter->customer_address->invoice_price);
        iter = iter->next;
    }
    printf("----------------------------\n");

    iter = *invoice_indexlist_head;

    while(iter != NULL)
    {
        printf("Name : %s \tInvoice price: %d\n", iter->customer_address->customer_name,iter->customer_address->invoice_price);
        iter = iter->next;
    }

    printf("----------------------------\n");

}

int main()
{

    struct customer_list *_customer_list = NULL;
    struct index_list *index_list_name = NULL;
    struct index_list *index_list_invoice = NULL;

    int i;
    for (i = 0; i <CUSTCOUNT; i++) {
        ekle(&_customer_list, customer_names[i], invoice_prices[i]);
    }

    struct customer_list *iter = NULL;
    iter = _customer_list;

    while (iter != NULL) {

        ekle_index_isim(&index_list_name, iter);
        ekle_index_fatura(&index_list_invoice, iter);
        iter = iter->next;
    }

    yazdir(&index_list_name,&index_list_invoice);

    return 0;

}
