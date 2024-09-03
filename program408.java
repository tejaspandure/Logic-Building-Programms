class node
{
    public int data;
    public node next; // reference 
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

        newn = new node();

        newn.data = No;
        newn.next = null;

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
        newn = new node();

        newn.data = No;
        newn.next = null;

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
}

class program408
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

        sobj.Display();
        iRet = sobj.Count();

        System.out.println("Number of elements are: "+iRet);
    }
}