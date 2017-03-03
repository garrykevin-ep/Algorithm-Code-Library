//
//  friend.cpp
//  
//
//  Created by garry kevin on 29/09/16.
//
//


#include <iostream>
using namespace std;
class B;     // forward declaration

class A {
private:
    int data;
public:
    A()
    {
        data =2;
    }
    
    friend int func(A , B);   //friend function Declaration
};

class B {
private:
    int data;
public:
    B() {
        data=1;
    }
    friend int func(A , B);  //friend function Declaration
};

/*Function func() is the friend function of both classes A and B.
 So, the private data of both class can be accessed from this function.*/


int func(A d1,B d2)
{
    return (d1.data+d2.data);
}

int main()
{
    A a;
    B b;
    cout<<"Data: "<<func(a,b);
    return 0;
}
