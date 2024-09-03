#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class Queue
{
    private:
        PNODE First;
        int iCount;

    public:
        Queue();
        void Display();
        int Count();
        void EnQueue(int No); //InsertLast()
        int DeQueue(); // DeleteFirst()
};

Queue::Queue()
{
    First = NULL;
    iCount = 0;
}

void Queue::Display()
{
    cout<<"Elements of Queue are: \t";
    PNODE temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\n";
        temp = temp->next;
    }
    cout<<"\n";
}

int Queue::Count()
{
    return iCount;
}

void Queue::EnQueue(int No)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = new NODE;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

int Queue::DeQueue()
{
    int iValue = 0;
    PNODE temp = NULL;

    if(First == NULL)
    {
        cout<<" Unable to remove the element as Queue is empty\t";
        return -1;
    }
    else
    {
        temp = First;

        iValue = First -> data;
        First = First -> next;
        delete temp;

        iCount--;
    }
    return iValue;
}

int main()
{
    Queue sobj;
    int iNo;
    int iChoice = 0;

    cout<<"----------Implementation of Queue-------------\n";

    while(iChoice != 5)
    {
        cout<<"Please select your choice: \n";
        cout<<"1: Insert new element in Queue\n";
        cout<<"2: Remove the element in Queue\n";
        cout<<"3: Display element in Queue\n";
        cout<<"4: Count number in Queue\n";
        cout<<"5: Exit\n";
        cin>>iChoice:

        switch(iChoice)
        {
            case 1:
                cout<<"Enter the element that you want to Insert: \n";
                cin>>iNo;
                sobj.EnQueue(iNo);
            break;

            case 2:
                iNo = sobj.Dequeue()
                if(iNo != -1)
                {
                    cout<<"Removed elements from Queue is: "<<iNo<<"\n";
                }
            break;

            case 3:
                sobj.Display(;)
            break;

            case 4:
                iNo = sobj.Count();
                cout<<"Number of elements in Queue are :"<<iNo<<"\n";
            break;

            case 5:
                cout<<"Thank you for using our application\n";
            break;
        }
    }

    return 0;
}