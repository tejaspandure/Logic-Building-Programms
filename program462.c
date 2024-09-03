#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * LCHILD;
    struct node * RCHILD;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Insert(PPNODE Root, int No)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->LCHILD = NULL;
    newn->RCHILD = NULL;

    if(*Root == NULL) //Tree is empty
    {
        *Root = newn;
    }
    else // Tree contains atleast one node
    {
        temp = *Root;

        while(1)
        {
            if(temp->data == No)
            {
                printf("Unable to insert node as element is already present");
                free(newn);
                break;
            }
            else if(No > temp->data)
            {
                if(temp->RCHILD == NULL)
                {
                    temp->RCHILD = newn;
                }
                temp = temp->RCHILD;
            }
            else if(No < temp->data)
            {
                if(temp->LCHILD == NULL)
                {
                    temp->LCHILD = newn;
                }
                temp = temp->LCHILD;
            }
        }
    }
}

int main()
{
    PNODE Head = NULL;

    Insert(&Head,21);
    Insert(&Head,15);
    Insert(&Head,52);
    
    return 0;
}