#include<iostream>
using namespace std;

int Addition(int Arr[], int iSize)
{
    int iCnt = 0;
    int iSum = 0;
    for(iCnt = 0; iCnt < iSize; iCnt++)
    {   
        iSum = iSum + Arr[iCnt];
    }
    return iSum;
}

int main()
{
    int iLength = 0;
    int *ptr = NULL;
    int i = 0;
    int iRet = 0;

    cout<<"Enter number of elements: ";
    cin>>iLength;

    ptr = new int[iLength];

    cout<<"Enter the elements : \n";
    for(i=0; i < iLength; i++)
    {
        cin>>ptr[i];
    }

    iRet = Addition(ptr, iLength);
    cout<<"Addition is: "<<iRet<<"\n";

    delete []ptr;

    return 0;
}