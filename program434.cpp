#include<iostream>
using namespace std;

template <class T>
T Addition(T Arr[], int iSize)
{
    int i = 0;
    T iSum = 0;
    for(i = 0; i < iSize; i++)
    {   
        iSum = iSum + Arr[i];
    }
    return iSum;
}

int main()
{
    int iLength = 0;
    float *ptr = NULL;
    int i = 0;
    float fRet = 0.0f;

    cout<<"Enter number of elements: ";
    cin>>iLength;

    ptr = new float[iLength];

    cout<<"Enter the elements : \n";
    for(i=0; i < iLength; i++)
    {
        cin>>ptr[i];
    }

    fRet = Addition(ptr, iLength);
    cout<<"Addition is: "<<fRet<<"\n";

    delete []ptr;

    return 0;
}