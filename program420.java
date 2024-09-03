// Stack
class node
{
    public int data;
    public node Nnext; // reference 

    public node(int iValue)
    {
        data = iValue;
        Nnext = null;
    }
}

class Stack
{
    public node nFirst;
    public int iCount;

    public Stack()
    {
        System.out.println("...Object of Stack gets created successfully...");
        nFirst = null;
        iCount = 0;
    }

    public void Push(int No)
    {}

    public int Pop()
    {
        return 0;
    }

    public void Display()
    {}

    public int Count()
    {
        return iCount;
    }
}

class program420
{
    public static void main(String args[])
    {
        Stack sobj = new Stack();
    }
}