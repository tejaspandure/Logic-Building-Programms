
import java.util.*;

class program212
{
    public static int SumDifference(int iNo)
    {
        int iDigit = 0;
        int iSumE = 0;
        int iSumO = 0;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if((iDigit %iNo )==2)
            {
                iSumE = iSumE + iDigit;
            }
            else
            {
                iSumO = iSumO + iDigit;
            }
        }
        return iSumO- iSumE;
    }
    public static void main(String args[])
    {
        int iValue = 0;
        int iRet = 0;

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the number: ");
        iValue = sobj.nextInt();

        iRet = SumDifference(iValue);

        System.out.println("Difference is: "+iRet);


    }
}