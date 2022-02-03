// Najem Hamo
#include <iostream>
#include <cctype>
#include "xo.h"
using namespace std;


int main()
{
    Game g;
    while(true)
    {
        if (g.meny() == 1)
        {
            if (g.round > 0)
                g.resetBoard();
            else
                g.draw();
            while (true)
            {
                g.inmatning();
                g.draw();
                
                if (g.win() == 'X')
                {
                    g.xVann++;
                    g.round++;
                    break;
                }
                else if (g.win() == 'O')
                {
                    g.oVann++;
                    g.round++;
                    break;
                }
                
                g.växlaSpelare();
                
                if (g.Tie() == true)
                    break;
                else
                    continue;
            }
        }
        
        else
        {
            cout << "\033[2J\033[1;1H";
            cout << "Tack för att du spelar spelet!" << endl << endl;
            return 0;
        }
    }
    
    return 0;
}