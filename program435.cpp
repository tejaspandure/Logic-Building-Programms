#include<iostream>
using namespace std;

float Maximum(float Arr[], int iSize)
{
    float fMax = Arr[0];
    int i = 0;
    for(i = 1; i < iSize; i++)
    {
        if(Arr[i] > fMax)
        {
            fMax = Arr[i];
        }
    }
    return fMax;
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

    fRet = Maximum(ptr, iLength);
    cout<<"Maximum number is: "<<fRet<<"\n";

    delete []ptr;

    return 0;
}