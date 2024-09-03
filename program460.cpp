#include<iostream>
using namespace std;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//
// CODE OF SINGLY LINEAR LINKED LIST                                                                                      
//
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

template <class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template <class T>
class SinglyLL
{
    private:
        struct nodeSL<T> * First;
        int iCount;
    public:
        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    cout<<"Inside Constructor\n";
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    struct nodeSL<T> * temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"|-> ";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T> * newn = NULL;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct nodeSL<T>* newn = NULL;
    struct nodeSL<T> * temp = First;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSL <T>* newn = NULL;
    int i = 0;
    struct nodeSL <T> * temp;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else 
    {
        temp = First;
        
        newn = new nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp -> next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First -> next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp ->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSL<T> * temp1;
    struct nodeSL<T> * temp2;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else 
    {
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }    
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//
// CODE OF SINGLY CIRCULAR LINKED LIST                                                                                      
//
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

template <class T>
struct nodeSC
{
    T data;
    struct nodeSC<T> *next;
};

template <class T>
class SinglyCL
{
    private:
        struct nodeSC<T>* First;
        struct nodeSC<T>* Last;
        int iCount;

    public:
        SinglyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
SinglyCL<T>::SinglyCL()
{
    cout<<"Inside Constructor\n";
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL<T>::Display()
{
    if (First == NULL)
    {
        return;
    }

    struct nodeSC<T> * temp = First;

    do
    {
        cout<<"| "<<temp->data<<"|-> ";
        temp = temp -> next;
    } while (temp != First);

    cout<<"\n";
}

template <class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCL<T>::InsertFirst(T No)
{
    struct nodeSC<T>* newn = NULL;    // malloc

    newn = new nodeSC<T>;

    newn->data = No;
    newn->next = NULL;

    if (First == NULL) // if(iCount == 0)
    {
        First = newn;
        Last = newn;
        newn->next = First;
    }
    else
    {
        newn->next = First;
        First = newn;
        Last->next = First;
    }
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertLast(T No)
{
    struct nodeSC<T>* newn = NULL;    // malloc

    newn = new nodeSC<T>;

    newn->data = No;
    newn->next = NULL;

    if (First == NULL) // if(iCount == 0)
    {
        First = newn;
        Last = newn;
        newn->next = First;
    }
    else
    {
        Last->next = newn;
        Last = newn;
        Last->next = First;
    }
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T No, int iPos)
{
    if ((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        struct nodeSC<T> * newn = NULL;
        newn = new nodeSC<T>;
        newn->data = No;
        newn->next = NULL;

        struct nodeSC<T>* temp = First;
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if (First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if (First == Last) // Only one node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        struct nodeSC<T>* temp = First;
        First = First->next;
        delete temp;
        Last->next = First;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    if (First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if (First == Last) // Only one node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        struct nodeSC<T>* temp = First;

        while (temp->next != Last)
        {
            temp = temp->next;
        }

        delete Last;
        Last = temp;
        Last->next = First;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    if ((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeSC<T>* temp1 = First;

        for (int i = 1; i < iPos - 1; i++)
        {
            temp1 = temp1->next;
        }

        struct nodeSC<T>* temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
        iCount--;
    }
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//
// CODE OF DOUBLY LINEAR LINKED LIST                                                                                      
//
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

template <class T>
struct nodeDL{
    T data;
    struct nodeDL*next;
    struct nodeDL*prev;
};


template <class T>
class DoublyLL
{
    private:
        struct nodeDL<T> * First;
        int iCount;

    public:
        DoublyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);        
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T>::Display()
{
    struct nodeDL <T> * temp = First;

    cout << "NULL <=> ";
    while(temp != NULL)
    {
        cout << "| " << temp->data << " | <=> ";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T No)
{
    struct nodeDL <T> * newn = NULL;

    newn = new nodeDL<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
    struct nodeDL<T> * newn = NULL;

    newn = new nodeDL<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct nodeDL<T>* temp = First;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T No, int iPos)
{
    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout << "Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        struct nodeDL<T> * newn = NULL;
        
        newn = new nodeDL<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        struct nodeDL<T>* temp = First;
        for(int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        delete First->prev;
        First->prev = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct nodeDL<T>* temp = First;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    struct nodeDL<T> * temp1 = NULL;
    struct nodeDL<T> * temp2 = NULL;
    if((iPos < 1) || (iPos > iCount))
    {
        cout << "Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeDL<T> * temp1 = First;
        for(int i = 1; i < iPos - 1; i++)
        {
            temp1 = temp1->next;
        }
        struct nodeDL<T> *  temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->next->prev = temp1;
        delete temp2;

        iCount--;
    }
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//
// CODE OF DOUBLY CIRCULAR LINKED LIST                                                                                      
//
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

template <class T>
struct nodeDC
{
    T data;
    struct nodeDC<T> *next;
    struct nodeDC<T> *prev;
};

template <class T>
class DoublyCL
{
    private:
        struct nodeDC<T>* First;
        struct nodeDC<T> * Last;
        int iCount;

    public:
        DoublyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
DoublyCL<T> :: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"Linked List is emprty\n";
        return;
    }

    cout<<"<=> ";
    do
    {
        cout<<"| "<<First->data <<"| <=> ";
        First = First -> next;
    }while(Last -> next != First);

    cout<<"\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last ->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;    
}

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDC<T> * temp = NULL;
    struct nodeDC<T> * newn = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDC<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single nodeDC
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one nodeDC
    {
        First = First -> next;
        delete Last->next;
        First -> prev = Last;
        Last -> next = First;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single nodeDC
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one nodeDC
    {
        Last = Last -> prev;
        delete First -> prev;

        Last -> next = First;
        First -> prev = Last;
    }
    iCount--;    
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeDC<T> * temp = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }    
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//
// CODE OF STACK                                                                                     
//
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

template <class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};

template <class T>
class Stack
{
    private:
        struct nodeS<T> * First;
        int iCount;

    public:
        Stack();
        void Display();
        int Count();
        void Push(T No);  // InsertFirst()
        T Pop();   // DeleteFirst()
};

template <class T>
Stack<T>::Stack()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void Stack<T>::Display()
{
    cout << "Elements of stack are : \n";
    struct nodeS<T> * temp = First;

    while (temp != NULL)
    {
        cout << temp->data << "\n";
        temp = temp->next;
    }
    cout << "\n";
}

template <class T>
int Stack<T>::Count()
{
    return iCount;
}

template <class T>
void Stack<T>::Push(T No)
{
    struct nodeS<T> * newn = NULL;

    newn = new nodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
T Stack<T>::Pop()
{
    T iValue;
    struct nodeS<T> * temp = NULL;

    if (First == NULL)
    {
        cout << "Unable to pop the element as stack is empty\n";
        return -1; // Assuming T can be assigned -1, otherwise handle appropriately.
    }
    else
    {
        temp = First;

        iValue = First->data;
        First = First->next;
        delete temp;

        iCount--;
    }

    return iValue;
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//
// CODE OF QUEUE                                                                                     
//
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

template <class T>
struct nodeQ
{
    T data;
    struct nodeQ<T>*next;
};

template <class T>
class Queue
{
    private:
        struct nodeQ<T>* First;
        int iCount;

    public:
        Queue();
        void Display();
        int Count();
        void EnQueue(T No); //InsertLast()
        int DeQueue(); // DeleteFirst()
};

template <class T>
Queue<T>::Queue()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void Queue<T>::Display()
{
    cout<<"Elements of Queue are: \t";
    struct nodeQ<T>* temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\n";
        temp = temp->next;
    }
    cout<<"\n";
}

template <class T>
int Queue<T>::Count()
{
    return iCount;
}

template <class T>
void Queue<T>::EnQueue(T No)
{
    struct nodeQ<T>* newn = NULL;
    struct nodeQ<T>* temp = NULL;

    newn = new nodeQ<T>;

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

template <class T>
int Queue<T>::DeQueue()
{
    int iValue = 0;
    struct nodeQ<T>* temp = NULL;

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

/////////////////////////////////////
//
//  MAIN FUNCTION
//
/////////////////////////////////////

int main()
{
    int iRet = 0;
    float fRet = 0.0f;
    char cRet = 0;
    double dRet = 0.0;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//
// MAIN FUNCTION FOR SINGLY LINEAR LINKED LIST                                                                                      
//
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    // LL of Integer
    cout<<"\n";
    cout<<"<<<<<<<<<<<<<<<<<<<<--------------------SINGLY LINEAR LINKED LIST-------------------->>>>>>>>>>>>>>>>>>>>\n";
    cout<<"\n";
    cout<<"---------------INTEGER Linked List---------------\n";
    cout<<"\n";
    SinglyLL<int> *islobj = new SinglyLL<int>(); // dynamic // i = integer ; sl = singly linear linked list; obj = object;
    

    islobj->InsertFirst(51);
    islobj->InsertFirst(21);
    islobj->InsertFirst(11);

    islobj->Display();
    iRet = islobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    islobj->InsertLast(101);
    islobj->InsertLast(111);
    islobj->InsertLast(121);
    
    islobj->Display();
    iRet = islobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    islobj->InsertAtPos(105,5);

    islobj->Display();
    iRet = islobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    islobj->DeleteAtPos(5);
    islobj->Display();
    iRet = islobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;
    
    // LL of character
    cout<<"\n";
    cout<<"---------------CHARACTER Linked List---------------\n";
    cout<<"\n";
    SinglyLL<char> *cslobj = new SinglyLL<char>(); // dynamic 

    cslobj->InsertFirst('A');
    cslobj->InsertFirst('B');
    cslobj->InsertFirst('C');

    cslobj->Display();
    iRet = cslobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cslobj->InsertLast('D');
    cslobj->InsertLast('E');
    cslobj->InsertLast('F');
    
    cslobj->Display();
    iRet = cslobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cslobj->InsertAtPos('G',5);

    cslobj->Display();
    iRet = cslobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cslobj->DeleteAtPos(5);
    cslobj->Display();
    iRet = cslobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    // LL of Float
    cout<<"\n";
    cout<<"---------------FLOAT Linked List---------------\n";
    cout<<"\n";

    SinglyLL<float> *fslobj = new SinglyLL<float>(); // dynamic 

    fslobj->InsertFirst(12.30f);
    fslobj->InsertFirst(23.20f);
    fslobj->InsertFirst(12.36f);

    fslobj->Display();
    iRet = fslobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fslobj->InsertLast(45.62f);
    fslobj->InsertLast(78.69f);
    fslobj->InsertLast(78.69f);
    
    fslobj->Display();
    iRet = fslobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fslobj->InsertAtPos(45.56f,5);

    fslobj->Display();
    iRet = fslobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fslobj->DeleteAtPos(5);
    fslobj->Display();
    iRet = fslobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    // LL of double
    cout<<"\n";
    cout<<"---------------DOUBLE Linked List---------------\n";
    cout<<"\n";

    SinglyLL<double> *dslobj = new SinglyLL<double>(); // dynamic 

    dslobj->InsertFirst(12.3030);
    dslobj->InsertFirst(23.2030);
    dslobj->InsertFirst(12.3630);

    dslobj->Display();
    iRet = dslobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dslobj->InsertLast(45.6240);
    dslobj->InsertLast(78.6940);
    dslobj->InsertLast(78.6920);
    
    dslobj->Display();
    iRet = dslobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dslobj->InsertAtPos(45.5612,5);

    dslobj->Display();
    iRet = dslobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dslobj->DeleteAtPos(5);
    dslobj->Display();
    iRet = dslobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//
// MAIN FUNCTION FOR SINGLY CIRCULAR LINKED LIST                                                                                      
//
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    cout<<"\n";
    cout<<"<<<<<<<<<<<<<<<<<<<<--------------------SINGNLY CIRCULAR LINKED LIST-------------------->>>>>>>>>>>>>>>>>>>>\n";
    cout<<"\n";
    cout<<"---------------INTEGER Linked List---------------\n";
    cout<<"\n";
    SinglyCL<int> *iscobj = new SinglyCL<int>(); // dynamic //iscobj = i = integer ; sc = singly circular ; obj = object 

    iscobj->InsertFirst(51);
    iscobj->InsertFirst(21);
    iscobj->InsertFirst(11);

    iscobj->Display();
    iRet = iscobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iscobj->InsertLast(101);
    iscobj->InsertLast(111);
    iscobj->InsertLast(121);
    
    iscobj->Display();
    iRet = iscobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iscobj->InsertAtPos(105,5);

    iscobj->Display();
    iRet = iscobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iscobj->DeleteAtPos(5);
    iscobj->Display();
    iRet = iscobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;
    
    // LL of character
    cout<<"\n";
    cout<<"---------------CHARACTER Linked List---------------\n";
    cout<<"\n";

    SinglyCL<char> *cscobj = new SinglyCL<char>(); // dynamic 

    cscobj->InsertFirst('A');
    cscobj->InsertFirst('B');
    cscobj->InsertFirst('C');

    cscobj->Display();
    iRet = cscobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cscobj->InsertLast('D');
    cscobj->InsertLast('E');
    cscobj->InsertLast('F');
    
    cscobj->Display();
    iRet = cscobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cscobj->InsertAtPos('G',5);

    cscobj->Display();
    iRet = cscobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cscobj->DeleteAtPos(5);
    cscobj->Display();
    iRet = cscobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    // LL of Float
    cout<<"\n";
    cout<<"---------------FLOAT Linked List---------------\n";
    cout<<"\n";

    SinglyCL<float> *fscobj = new SinglyCL<float>(); // dynamic 

    fscobj->InsertFirst(12.30f);
    fscobj->InsertFirst(23.20f);
    fscobj->InsertFirst(12.36f);

    fscobj->Display();
    iRet = fscobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fscobj->InsertLast(45.62f);
    fscobj->InsertLast(78.69f);
    fscobj->InsertLast(78.69f);
    
    fscobj->Display();
    iRet = fscobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fscobj->InsertAtPos(45.56f,5);

    fscobj->Display();
    iRet = fscobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fscobj->DeleteAtPos(5);
    fscobj->Display();
    iRet = fscobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    // LL of double
    cout<<"\n";
    cout<<"---------------DOUBLE Linked List---------------\n";
    cout<<"\n";

    SinglyCL<double> *dscobj = new SinglyCL<double>(); // dynamic 

    dscobj->InsertFirst(12.3030);
    dscobj->InsertFirst(23.2030);
    dscobj->InsertFirst(12.3630);

    dscobj->Display();
    iRet = dscobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dscobj->InsertLast(45.6240);
    dscobj->InsertLast(78.6940);
    dscobj->InsertLast(78.6920);
    
    dscobj->Display();
    iRet = dscobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dscobj->InsertAtPos(45.5612,5);

    dscobj->Display();
    iRet = dscobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dscobj->DeleteAtPos(5);
    dscobj->Display();
    iRet = dscobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//
// MAIN FUNCTION FOR DOUBLY LINEAR LINKED LIST                                                                                      
//
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    cout<<"\n";
    cout<<"<<<<<<<<<<<<<<<<<<<<--------------------DOUBLY LINEAR LINKED LIST-------------------->>>>>>>>>>>>>>>>>>>>\n";
    cout<<"\n";
    cout<<"---------------INTEGER Linked List---------------\n";
    cout<<"\n";
    DoublyLL<int> *idlobj = new DoublyLL<int>(); // dynamic //idlobj = i = integer ; dl = doubly linear ; obj = object 

    idlobj->InsertFirst(51);
    idlobj->InsertFirst(21);
    idlobj->InsertFirst(11);

    idlobj->Display();
    iRet = idlobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    idlobj->InsertLast(101);
    idlobj->InsertLast(111);
    idlobj->InsertLast(121);
    
    idlobj->Display();
    iRet = idlobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    idlobj->InsertAtPos(105,5);

    idlobj->Display();
    iRet = idlobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    idlobj->DeleteAtPos(5);
    idlobj->Display();
    iRet = idlobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;
    
    // LL of character
    cout<<"\n";
    cout<<"---------------CHARACTER Linked List---------------\n";
    cout<<"\n";

    DoublyLL<char> *cdlobj = new DoublyLL<char>(); // dynamic 

    cdlobj->InsertFirst('A');
    cdlobj->InsertFirst('B');
    cdlobj->InsertFirst('C');

    cdlobj->Display();
    iRet = cdlobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cdlobj->InsertLast('D');
    cdlobj->InsertLast('E');
    cdlobj->InsertLast('F');
    
    cdlobj->Display();
    iRet = cdlobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cdlobj->InsertAtPos('G',5);

    cdlobj->Display();
    iRet = cdlobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cdlobj->DeleteAtPos(5);
    cdlobj->Display();
    iRet = cdlobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    // LL of Float
    cout<<"\n";
    cout<<"---------------FLOAT Linked List---------------\n";
    cout<<"\n";

    DoublyLL<float> *fdlobj = new DoublyLL<float>(); // dynamic 

    fdlobj->InsertFirst(12.30f);
    fdlobj->InsertFirst(23.20f);
    fdlobj->InsertFirst(12.36f);

    fdlobj->Display();
    iRet = fdlobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fdlobj->InsertLast(45.62f);
    fdlobj->InsertLast(78.69f);
    fdlobj->InsertLast(78.69f);
    
    fdlobj->Display();
    iRet = fdlobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fdlobj->InsertAtPos(45.56f,5);

    fdlobj->Display();
    iRet = fdlobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fdlobj->DeleteAtPos(5);
    fdlobj->Display();
    iRet = fdlobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    // LL of double
    cout<<"\n";
    cout<<"---------------DOUBLE Linked List---------------\n";
    cout<<"\n";

    DoublyLL<double> *ddlobj = new DoublyLL<double>(); // dynamic 

    ddlobj->InsertFirst(12.3030);
    ddlobj->InsertFirst(23.2030);
    ddlobj->InsertFirst(12.3630);

    ddlobj->Display();
    iRet = ddlobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    ddlobj->InsertLast(45.6240);
    ddlobj->InsertLast(78.6940);
    ddlobj->InsertLast(78.6920);
    
    ddlobj->Display();
    iRet = ddlobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    ddlobj->InsertAtPos(45.5612,5);

    ddlobj->Display();
    iRet = ddlobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    ddlobj->DeleteAtPos(5);
    ddlobj->Display();
    iRet = ddlobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//
// MAIN FUNCTION FOR DOUBLY CIRCULAR LINKED LIST                                                                                      
//
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    cout<<"\n";
    cout<<"<<<<<<<<<<<<<<<<<<<<--------------------DOUBLY CIRCULAR LINKED LIST-------------------->>>>>>>>>>>>>>>>>>>>\n";
    cout<<"\n";
    cout<<"---------------INTEGER Linked List---------------\n";
    cout<<"\n";
    DoublyCL<int> *idcobj = new DoublyCL<int>(); // dynamic //idcobj = i = integer ; dc = doubly circular ; obj = object 

    idcobj->InsertFirst(51);
    idcobj->InsertFirst(21);
    idcobj->InsertFirst(11);

    idcobj->Display();
    iRet = idcobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    idcobj->InsertLast(101);
    idcobj->InsertLast(111);
    idcobj->InsertLast(121);
    
    idcobj->Display();
    iRet = idcobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    idcobj->InsertAtPos(105,5);

    idcobj->Display();
    iRet = idcobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    idcobj->DeleteAtPos(5);
    idcobj->Display();
    iRet = idcobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;
    
    // LL of character
    cout<<"\n";
    cout<<"---------------CHARACTER Linked List---------------\n";
    cout<<"\n";

    DoublyCL<char> *cdcobj = new DoublyCL<char>(); // dynamic 

    cdcobj->InsertFirst('A');
    cdcobj->InsertFirst('B');
    cdcobj->InsertFirst('C');

    cdcobj->Display();
    iRet = cdcobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cdcobj->InsertLast('D');
    cdcobj->InsertLast('E');
    cdcobj->InsertLast('F');
    
    cdcobj->Display();
    iRet = cdcobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cdcobj->InsertAtPos('G',5);

    cdcobj->Display();
    iRet = cdcobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cdcobj->DeleteAtPos(5);
    cdcobj->Display();
    iRet = cdcobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    // LL of Float
    cout<<"\n";
    cout<<"---------------FLOAT Linked List---------------\n";
    cout<<"\n";

    DoublyCL<float> *fdcobj = new DoublyCL<float>(); // dynamic 

    fdcobj->InsertFirst(12.30f);
    fdcobj->InsertFirst(23.20f);
    fdcobj->InsertFirst(12.36f);

    fdcobj->Display();
    iRet = fdcobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fdcobj->InsertLast(45.62f);
    fdcobj->InsertLast(78.69f);
    fdcobj->InsertLast(78.69f);
    
    fdcobj->Display();
    iRet = fdcobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fdcobj->InsertAtPos(45.56f,5);

    fdcobj->Display();
    iRet = fdcobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fdcobj->DeleteAtPos(5);
    fdcobj->Display();
    iRet = fdcobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    // LL of double
    cout<<"\n";
    cout<<"---------------DOUBLE Linked List---------------\n";
    cout<<"\n";

    DoublyCL<double> *ddcobj = new DoublyCL<double>(); // dynamic 

    ddcobj->InsertFirst(12.3030);
    ddcobj->InsertFirst(23.2030);
    ddcobj->InsertFirst(12.3630);

    ddcobj->Display();
    iRet = ddcobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    ddcobj->InsertLast(45.6240);
    ddcobj->InsertLast(78.6940);
    ddcobj->InsertLast(78.6920);
    
    ddcobj->Display();
    iRet = ddcobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    ddcobj->InsertAtPos(45.5612,5);

    ddcobj->Display();
    iRet = ddcobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    ddcobj->DeleteAtPos(5);
    ddcobj->Display();
    iRet = ddcobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//
//  MAIN FUNCTION FOR STACK                                                                                
//
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    
    cout<<"\n";
    cout<<"<<<<<<<<<<<<<<<<<<<<--------------------STACK-------------------->>>>>>>>>>>>>>>>>>>>\n";
    cout<<"\n";
    cout<<"-----------------------STACK FOLLOWS LIFO ORDER-----------------------\n";
    cout<<"\n";
    cout<<"-----------------------INTEGER-----------------------\n";
    cout<<"\n";
    Stack<int> * isobj = new Stack<int>(); // i = integer , s = stack , obj = object

    isobj->Push(10);
    isobj->Push(20);
    isobj->Push(30);
    isobj->Push(40);

    isobj->Display();

    iRet = isobj->Count();
    cout << "Number of elements in the stack are : " << iRet << "\n";

    iRet = isobj->Pop();
    cout << "Popped element is : " << iRet << "\n";

    iRet = isobj->Pop();
    cout << "Popped element is : " << iRet << "\n";

    isobj->Display();

    iRet = isobj->Count();
    cout << "Number of elements in the stack are : " << iRet << "\n";

    isobj->Push(50);
    isobj->Display();

    iRet = isobj->Count();
    cout << "Number of elements in the stack are : " << iRet << "\n";

    delete isobj;

    cout<<"\n";
    cout<<"-----------------------FLOAT-----------------------\n";
    cout<<"\n";
    Stack<float> * fsobj = new Stack<float>(); // f = float, s = stack , obj = object

    fsobj->Push(10.90f);
    fsobj->Push(20.30f);
    fsobj->Push(30.25f);
    fsobj->Push(40.36f);

    fsobj->Display();

    fRet = fsobj->Count();
    cout << "Number of elements in the stack are : " << fRet << "\n";

    fRet = fsobj->Pop();
    cout << "Popped element is : " << fRet << "\n";

    fRet = fsobj->Pop();
    cout << "Popped element is : " << fRet << "\n";

    fsobj->Display();

    fRet = fsobj->Count();
    cout << "Number of elements in the stack are : " << fRet << "\n";

    fsobj->Push(50.36f);
    fsobj->Display();

    fRet = fsobj->Count();
    cout << "Number of elements in the stack are : " << fRet << "\n";

    delete fsobj;

    cout<<"\n";
    cout<<"-----------------------CHARACTER-----------------------\n";
    cout<<"\n";
    Stack<char> * csobj = new Stack<char>(); // f = float, s = stack , obj = object

    csobj->Push('A');
    csobj->Push('B');
    csobj->Push('C');
    csobj->Push('D');

    csobj->Display();

    cRet = csobj->Count();
    cout << "Number of elements in the stack are : " << cRet << "\n";

    cRet = csobj->Pop();
    cout << "Popped element is : " << cRet << "\n";

    cRet = csobj->Pop();
    cout << "Popped element is : " << cRet << "\n";

    csobj->Display();

    cRet = csobj->Count();
    cout << "Number of elements in the stack are : " << cRet << "\n";

    csobj->Push('T');
    csobj->Display();

    cRet = csobj->Count();
    cout << "Number of elements in the stack are : " << cRet << "\n";

    delete csobj;

    cout<<"\n";
    cout<<"-----------------------DOUBLE-----------------------\n";
    cout<<"\n";
    Stack<double> * dsobj = new Stack<double>(); // f = float, s = stack , obj = object

    dsobj->Push(10.908056);
    dsobj->Push(20.304563);
    dsobj->Push(30.253698);
    dsobj->Push(40.364567);

    dsobj->Display();

    dRet = dsobj->Count();
    cout << "Number of elements in the stack are : " << dRet << "\n";

    dRet = dsobj->Pop();
    cout << "Popped element is : " << dRet << "\n";

    dRet = dsobj->Pop();
    cout << "Popped element is : " << dRet << "\n";

    dsobj->Display();

    dRet = dsobj->Count();
    cout << "Number of elements in the stack are : " << dRet << "\n";

    dsobj->Push(50.367536);
    dsobj->Display();

    dRet = dsobj->Count();
    cout << "Number of elements in the stack are : " << dRet << "\n";

    delete dsobj;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//
//  MAIN FUNCTION FOR QUEUE                                                                                
//
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    cout<<"\n";
    cout<<"<<<<<<<<<<<<<<<<<<<<--------------------QUEUE-------------------->>>>>>>>>>>>>>>>>>>>\n";
    cout<<"\n";
    cout<<"-----------------------QUEUE FOLLOWS FIFO ORDER-----------------------\n";
    cout<<"\n";
    cout<<"-----------------------INTEGER-----------------------\n";
    cout<<"\n";
    Queue<int> * iqobj = new Queue<int>(); // i = integer , q = Queue , obj = object
    
    iqobj->EnQueue(10);
    iqobj->EnQueue(20);
    iqobj->EnQueue(30);
    iqobj->EnQueue(40);

    iqobj->Display();

    iRet = iqobj->Count();
    cout << "Number of elements in the Queue are : " << iRet << "\n";

    iRet = iqobj->DeQueue();
    cout << "DeQueued element is : " << iRet << "\n";

    iRet = iqobj->DeQueue();
    cout << "DeQueued element is : " << iRet << "\n";

    iqobj->Display();

    iRet = iqobj->Count();
    cout << "Number of elements in the Queue are : " << iRet << "\n";

    iqobj->EnQueue(50);
    iqobj->Display();

    iRet = iqobj->Count();
    cout << "Number of elements in the Queue are : " << iRet << "\n";

    cout<<"\n";
    cout<<"-----------------------FLOAT-----------------------\n";
    cout<<"\n";
    Queue<float> * fqobj = new Queue<float>(); // f = float, q = Queue , obj = object

    fqobj->EnQueue(10.90f);
    fqobj->EnQueue(20.30f);
    fqobj->EnQueue(30.25f);
    fqobj->EnQueue(40.36f);

    fqobj->Display();

    fRet = fqobj->Count();
    cout << "Number of elements in the Queue are : " << fRet << "\n";

    fRet = fqobj->DeQueue();
    cout << "DeQueued element is : " << fRet << "\n";

    fRet = fqobj->DeQueue();
    cout << "DeQueued element is : " << fRet << "\n";

    fqobj->Display();

    fRet = fqobj->Count();
    cout << "Number of elements in the Queue are : " << fRet << "\n";

    fqobj->EnQueue(50.36f);
    fqobj->Display();

    fRet = fqobj->Count();
    cout << "Number of elements in the Queue are : " << fRet << "\n";

    cout<<"\n";
    cout<<"-----------------------CHARACTER-----------------------\n";
    cout<<"\n";
    Queue<char> * cqobj = new Queue<char>(); // f = float, q = Queue , obj = object

    cqobj->EnQueue('A');
    cqobj->EnQueue('B');
    cqobj->EnQueue('C');
    cqobj->EnQueue('D');

    cqobj->Display();

    cRet = cqobj->Count();
    cout << "Number of elements in the Queue are : " << cRet << "\n";

    cRet = cqobj->DeQueue();
    cout << "DeQueued element is : " << cRet << "\n";

    cRet = cqobj->DeQueue();
    cout << "DeQueued element is : " << cRet << "\n";

    cqobj->Display();

    cRet = cqobj->Count();
    cout << "Number of elements in the Queue are : " << cRet << "\n";

    cqobj->EnQueue('T');
    cqobj->Display();

    cRet = cqobj->Count();
    cout << "Number of elements in the Queue are : " << cRet << "\n";

    cout<<"\n";
    cout<<"-----------------------DOUBLE-----------------------\n";
    cout<<"\n";
    Queue<double> * dqobj = new Queue<double>(); // f = float, q = Queue , obj = object

    dqobj->EnQueue(10.908056);
    dqobj->EnQueue(20.304563);
    dqobj->EnQueue(30.253698);
    dqobj->EnQueue(40.364567);

    dqobj->Display();

    dRet = dqobj->Count();
    cout << "Number of elements in the Queue are : " << dRet << "\n";

    dRet = dqobj->DeQueue();
    cout << "DeQueued element is : " << dRet << "\n";

    dRet = dqobj->DeQueue();
    cout << "DeQueued element is : " << dRet << "\n";

    dqobj->Display();

    dRet = dqobj->Count();
    cout << "Number of elements in the Queue are : " << dRet << "\n";

    dqobj->EnQueue(50.367536);
    dqobj->Display();

    dRet = dqobj->Count();
    cout << "Number of elements in the Queue are : " << dRet << "\n";

    return 0;
}