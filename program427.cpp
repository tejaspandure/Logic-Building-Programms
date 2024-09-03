#include<iostream>
using namespace std;

template <class T>
T Addition(T dNo1, T dNo2)
{
    T Ans;
    Ans = No1 + No2;
    return Ans;
}

int main()
{
    int iValue1 = 10.0;
    int iValue2 = 11.0;
    int iRet = 0.0;

    double dValue1 = 10.0;
    double dValue2 = 11.0;
    double dRet = 0.0;

    float fValue1 = 10.0f;
    float fValue2 = 11.0f;
    float fRet = 0.0f;

    iRet = Addition(iValue1, iValue2);
    cout<<"Addition of Integers : "<<iRet<<"\n";

    fRet = Addition(fValue1, fValue2);
    cout<<"Addition of Float : "<<fRet<<"\n";

    dRet = Addition(dValue1, dValue2);
    cout<<"Addition of Double: "<<dRet<<"\n";

    return 0;
}