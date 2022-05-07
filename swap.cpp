/*
The original swap_cr won't compile as you can't modify a constant.
Solution: create two temp values.
*/


#include "std_lib_facilities.h"

void print (int a, int b)
{
    cout << "After Swap: " << a << '\t' << b << endl;
}

void swap_v (int a, int b)
{
    int temp;
    temp = a, a = b;
    b = temp;
    print(a,b);
}

void swap_r (int& a, int& b)
{
    int temp;
    temp = a, a = b;
    b = temp;
    print(a,b);
}

void swap_cr (const int& a, const int& b)
{
    int temp, temp2;
    temp = a;
    temp2 = b;
    swap_r(temp, temp2);
}

int main()
{
    int x = 7;
    int y = 9;

    cout << "Before Swap: " << x << '\t' << y << endl;
    swap_v(x,y);
    cout << "Before Swap: " << '7' << '\t' << '9' << endl;
    swap_v(7,9); 
    //can't be passed to swap_r as it uses reference.
    
    const int cx = 7;
    const int cy = 9;

    cout << "Before Swap: " << cx << '\t' << cy << endl;

    swap_cr(cx, cy);

    cout << "Before Swap: " << "7.7" << '\t' << "9.9" << endl;
    swap_v(7.7,9.9);

    double dx = 7.7;
    double dy = 9.9;
    cout << "Before Swap: " << dx << '\t' << dy << endl;

    swap_v(dx, dy);
    /*can't be passed to swap_r as it only accepts reference to ints
    thus passing to swap_v will truncate the values. */

    cout << "Before Swap: " << "7.7" << '\t' << "9.9" << endl;
    swap_cr(7.7, 9.9);
}
