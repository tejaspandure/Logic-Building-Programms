#include<iostream>
using namespace std;

int Addition(int iNo1, int iNo2)
{
    int iAns = 0;
    iAns = iNo1 + iNo2;
    return iAns;

}
int main()
{
    int iValue1 = 10;
    int iValue2 = 11;
    int iRet = 0;

    iRet = Addition(iValue1, iValue2);

    cout<<"Addition is : "<<iRet<<"\n";

    return 0;
}