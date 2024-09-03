// Stack
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

class Stack //LIFO
{
    public node First;
    public int iCount;

    public Stack()
    {
        System.out.println("...Object of Stack gets created successfully...");
        First = null;
        iCount = 0;
    }

    public void Push(int No) // InsertFirst
    {
        node newn = new node(No);

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

    public int Pop() // Delte First;
    {
        int iValue = 0;

        if(First == null)
        {
            System.out.println("Stack is empty...");
            return -1;
        }
        else
        {
            iValue = First.data;
            First = First.next;
        }
        iCount--;
        return iValue;
    }   
    
    public void Display()
    {
        System.out.println("Elements of stack are: ");
        node temp = First;

        while(temp!=null)
        {
            System.out.println(temp.data);
            temp = temp.next;
        }
    }

    public int Count()
    {
        return iCount;
    }
}

class program421
{
    public static void main(String args[])
    {
        Stack sobj = new Stack();
        int iRet = 0;

        sobj.push(11);
        sobj.push(21);
        sobj.push(31);
        sobj.push(41);

        sobj.Display();

        iRet = sobj.Pop();
        System.out.println("Poped element is: "+iRet);
        sobj.display();
    }
}