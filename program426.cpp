#include<iostream>
using namespace std;

template <class T>
T Addition(T dNo1, T dNo2)
{
    T dAns = 0.0;
    dAns = dNo1 + dNo2;
    return dAns;

}
int main()
{
    double dValue1 = 10.0;
    double dValue2 = 11.0;
    double dRet = 0.0;

    dRet = Addition(dValue1, dValue2);

    cout<<"Addition is : "<<dRet<<"\n";

    return 0;
}