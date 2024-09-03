// Queue
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

class Queue //FIFO
{
    public node First;
    public int iCount;

    public Queue()
    {
        System.out.println("...Object of Queue gets created successfully...");
        First = null;
        iCount = 0;
    }

    public void push(int No) // InsertLast
    {
        node newn = new node(No);

        if(First == null)
        {
            First = newn;
        }
        else
        {
           node temp = First;
           while(temp.next!= null)
           {
               temp= temp.next;
           }
           temp.next = newn;
        }
        iCount++;
    }

    public int Dequeue() //DeleteFirst
    {
        int iValue = 0;

        if(First == null)
        {
            System.out.println("Queue is empty...");
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
        System.out.print("Elements of stack are: ");
        node temp = First;

        while(temp!=null)
        {
            System.out.print(temp.data+"\t");
            temp = temp.next;
        }
    }

    public int Count()
    {
        return iCount;
    }
}

class program422
{
    public static void main(String args[])
    {
        Queue qobj = new Queue();
        int iRet = 0;

        qobj.Enqueue(11);
        qobj.Enqueue(21);
        qobj.Enqueue(31);
        qobj.Enqueue(41);

        qobj.Display();

        iRet = qobj.Pop();
        System.out.println("Removed element is: "+iRet);
        qobj.display();
    }
}