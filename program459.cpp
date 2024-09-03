// Generic Doubly Circular Linkedlist
#include<iostream>
using namespace std;

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

int main()
{
    
    int iRet = 0;
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

    return 0;
}