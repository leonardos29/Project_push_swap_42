#include<stdlib.h>
#include<stdio.h>

typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

int lst_size(t_list *begin_lst)
{
    int size = 0;
    while(begin_lst != NULL)
    {
        printf("%s \n",begin_lst ->content);
        size++;
        begin_lst = begin_lst -> next;
    }
    return(size);
}

int main()
{
    t_list *lista1;
    lista1 = malloc(sizeof(t_list));
    if(!lista1)
    return(0);
    lista1 -> content = "Leonardo";
    int size = lst_size(lista1);
    printf("%d \n",size);
}