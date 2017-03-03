//
//  operator_loading.cpp
//  
//
//  Created by garry kevin on 29/09/16.
//
//

#include <iostream>
using namespace std;

class a
{
    int x;
    int y;
    int z;
public:
    a()
    {
        x=1;
        y=1;
        z=1;
    }
    
    void operator--()
    {
        
        x++;
        y++;
        z++;
    }
    void show()
    {
        cout<<x<<" "<<y<<" "<<z<<" \n";
    }

};

int main()
{
    a ob;
    ob.show();
    --ob;
    ob.show();
    return 0;
}