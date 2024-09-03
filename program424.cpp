#include<iostream>
using namespace std;

float Addition(float fNo1, float fNo2)
{
    float fAns = 0.0f;
    fAns = fNo1 + fNo2;
    return fAns;

}
int main()
{
    float fValue1 = 10.0f;
    float fValue2 = 11.0f;
    float fRet = 0.0f;

    fRet = Addition(fValue1, fValue2);

    cout<<"Addition is : "<<fRet<<"\n";

    return 0;
}