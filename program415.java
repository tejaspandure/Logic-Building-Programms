class node
{
    public int data;
    public node next; // reference 

    public node(int iValue)
    {
        data = iValue;
        next = null;
    }
}

class SinglyLL
{
    public node First;
    public int iCount;

    public SinglyLL()
    {
        System.out.println("Object of SinglyLL gets created successfully");
        First = null;
        iCount = 0;
    }

    public void InsertFirst(int No)
    {
        node newn = null;

        newn = new node(No);

        if(First == null)
        {
            First = newn;
        }
        else
        {
            newn.next = First;
            First = newn;
        }
        iCount++;
    }

    public void Display()
    {
        System.out.println("Elements of the LinkedList are: ");

        node temp = First;

        while(temp!=null)
        {
            System.out.print("| "+temp.data+" |->");
            temp = temp.next;
        }
        System.out.println("null");
    }
    
    public void InsertLast(int No)
    {
        node newn = null;
        node temp = null;

        newn = new node(No);

        if(First == null)
        {
            First = newn;
        }
        else
        {
            temp = First;
            while(temp.next!=null)
            {
                temp = temp.next;
            }
            temp.next = newn;
        }
        iCount++;
    }
    
    public int Count()
    {
        return iCount;
    }

    public void DeleteFirst()
    {
        if(First == null)
        {
            System.out.println("Linked list is empty");
            return;
        }
        else if(First.next == null) // singl node;
        {
            First = null;
        }
        else
        {
            First = First.next;
        }
        iCount--;
    }

    public void DeleteLast()
    {
        if(First == null)
        {
            System.out.println("LL is emtpy");
            return;
        }
        else if(First.next == null)
        {
            First = null;
        }
        else
        {
            node temp = First;
            while(temp.next.next != null)
            {
                temp = temp.next;
            }
            temp.next = null;
        }
        iCount--;
    }

    public void InsertAtPos(int No, int iPos)
    {
        if((iPos < 1) || (iPos > iCount +1))
        {
            System.out.println("Invalid Position");
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
            int i =0;
            node temp = First;

            node newn = new node(No);

            for(i = 1; i < iPos-1; i++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next = newn;
            iCount++;
        }
    }

    public void DeleteAtPos(int iPos)
    {
        if((iPos < 1) || (iPos > iCount))
        {
            System.out.println("Invalid Position");
            return;
        }
        if(iPos == 1)
        {
            DeleteFirst();
        }
        else if(iPos == iCount )
        {
            DeleteLast();
        }
        else
        {
            int i = 0;
            node temp = First;

            for(i = 1; i < iPos-1; i++)
            {
                temp = temp.next;
            }
            temp.next = temp.next.next;
            iCount--;
        }
    }
}

class program415
{
    public static void main(String args[])
    {
        SinglyLL sobj = new SinglyLL();
        int iRet = 0;

        sobj.InsertFirst(101);
        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);

        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of elements are: "+iRet);

        sobj.InsertLast(111);
        sobj.InsertLast(121);
        sobj.InsertLast(151);

        sobj.InsertAtPos(105,5);
        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of elements are: "+iRet);

        sobj.DeleteAtPos(3);
        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of elements are: "+iRet);

        sobj.DeleteFirst();
        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of elements are: "+iRet);

        sobj.DeleteLast();
        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of elements are: "+iRet);
    }
}