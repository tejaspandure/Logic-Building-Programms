// Doubly C L
class node
{
    public int data;
    public node next; // reference 
    public node prev;

    public node(int iValue)
    {
        data = iValue;
        next = null;
        prev = null;
    }
}

class DoublyCL
{
    public node First;
    public node Last;
    public int iCount;

    public DoublyCL()
    {
        System.out.println("...Object of DoublyCL gets created successfully...");
        First = null;
        Last = null;
        iCount = 0;
    }

    public void InsertFirst(int No)
    {
        node newn = null;

        newn = new node(No);

        if(First == null && Last == null)
        {
            First = newn;
            Last = newn;
        }
        else
        {
            newn.next = First;
            First.prev = newn;
            First = newn;
        }
        First.prev = Last;
        Last.next = First;

        iCount++;
    }

    public void InsertLast(int No)
    {
        node newn = null;

        newn = new node(No);

        if(First == null && Last == null)
        {
            First = newn;
            Last = newn;
        }
        else
        {
            Last.next = newn;
            newn.prev = Last;

            Last = newn;
        }
        First.prev = Last;
        Last.next = First;

        iCount++;

    }

    public void Display()
    {
        if(First == null && Last == null)
        {
            System.out.println("LL is empty");
            return;
        }
        System.out.println("Elements of LL are: ");

        System.out.print("<=>");
        do
        {
            System.out.print(" | "+First.data+" |<=>");
            First = First.next;
        }while(First!=Last.next);

        System.out.println();
    }

    public int Count()
    {
        return iCount;
    }

    public void DeleteFirst()
    {
        if(First == null && Last ==null)
        {
            return;
        }
        else if(First == Last)
        {
            First = null;
            Last = null;
        }
        else
        {
            First = First.next;

            Last.next = First;
            First.prev = Last;
        }
        iCount--;
    }

    public void DeleteLast()
    {
        if(First == null && Last ==null)
        {
            return;
        }
        else if(First == Last)
        {
            First = null;
            Last = null;
        }
        else
        {
            Last = Last.prev;

            Last.next = First;
            First.prev = Last;
        }
        iCount--;
    }

    public void InsertAtPos(int No, int iPos)
    {
        if(iPos < 1 || iPos > iCount+1)
        {
            System.out.println("Invalid Position");
            return;
        }

        if(iPos == 1)
        {
            InsertFirst(No);
        }
        else if(iPos == iCount +1)
        {
            InsertLast(No);
        }
        else
        {
            node newn = new node(No);
            node temp = First;
            int i = 0;

            for(i = 0; i< iPos-1; i++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next.prev=newn;
            temp.next = newn;
            newn.prev = temp;

            iCount++;
        }
    }
    
    public void DeleteAtPos(int iPos)
    {
         if(iPos < 1 || iPos > iCount)
        {
            System.out.println("Invalid Position");
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
            node temp = First;
            int i = 0;

            for(i = 0; i< iPos-1; i++)
            {
                temp = temp.next;
            }
            temp.next = temp.next.next;
            temp.next.prev = temp;

            iCount--;
        }
    }
}

class program419
{
    public static void main(String args[])
    {
        int iRet = 0;
        DoublyCL dobj = new DoublyCL();

        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);

        dobj.InsertLast(101);
        dobj.InsertLast(121);
        dobj.InsertLast(151);

        dobj.Display();
        iRet = dobj.Count();
        System.out.println("Number of elements are : "+iRet);

        dobj.InsertAtPos(105,4);
        dobj.Display();
        iRet = dobj.Count();
        System.out.println("Number of elements are : "+iRet);

        dobj.DeleteAtPos(4);
        dobj.Display();
        iRet = dobj.Count();
        System.out.println("Number of elements are : "+iRet);
    }
}