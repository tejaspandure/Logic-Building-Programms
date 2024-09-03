
#include<iostream>
using namespace std;

void Swap(char &A, char &B)
{
    char Temp;
    
    Temp = A;
    A = B;
    B = Temp;
}

int main()
{
    char Value1 = 'T', Value2 = 'M';

    cout<<"Value of Value1 Variable is: "<<Value1<<"\n";
    cout<<"Value of Value2 Variable is: "<<Value2<<"\n";

    Swap(Value1,Value2);

    cout<<"Value of Value1 variable after swapping is : "<<Value1<<"\n";
    cout<<"Value of Value2 variable after swapping is : "<<Value2<<"\n";

    return 0;
}