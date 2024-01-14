#include <bits/stdc++.h>
using namespace std;
#include "System.h"
int main()
{
    System s;
    s.display_main_menu();
    int choice;
    bool flag =1;
    while (flag)
    {
        cin >> choice;
        switch (choice)
        {
            case 1:
                s.display_sign_in_menu();
                break;
            case 2:
                s.display_sign_up_menu();
                break;
            case 3:
                flag =0;
            default:
                cout << "Please enter a valid option [1-3]\n";
        }
    }


    return 0;
}
