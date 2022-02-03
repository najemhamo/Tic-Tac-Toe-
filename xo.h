#ifndef XO_HPP
#define XO_HPP

#include <iostream>
#include <cctype>
using namespace std;

class variabler{
    public:
            char namn[9] = "By Najem Hamo";
            char spelare = 'X';
            int turns = 0;
            int round = 0;
            int xVann = 0;
            int oVann = 0;
            int numTies = 0;
            char board[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
};

class spel : public variabler{
    public:
        int meny()
            {
                // rensar skärmen i terminalen
                cout << "\033[2J\033[1;1H";
                
                int spelarensVal;
                
                cout << "Tic Tac Toe - " << namn << endl << endl;
                cout << "    MENY:    " << endl << "1. Spelare mot Spelare" << endl << "2. Avsluta Spelet"
                << endl;
                
                cout << endl << "X Vann: " << xVann << "   O Vann: " << oVann << "   Ties: "
                << numTies << endl;
                
                cout << endl << "Välj ett alternativ: ";
                cin >> spelarensVal;
                
                if (spelarensVal == 1)
                    return 1;
                else
                    return 0;
            }

            void draw()
            {
                cout << "\033[2J\033[1;1H";
                cout << "Tic Tac Toe - " << namn << endl << endl;
                
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        cout << board[i][j] << " ";
                    }
                    cout << endl;
                }
            }

            void inmatning()
            {
                int spelarensInmatning;
                cout << endl << "Det är " << spelare << " tur.";
                cout << endl << "Tryck på siffran som motsvarar motsvarande fält: ";
                
                while (true)
                {
                    cin >> spelarensInmatning;
                    
                    spelarensInmatning--;
                    
                    /* kontrollerar om vald position är ett nummer - om inte, då
                     det har redan tagits och spelaren måste välja en annan position */
                    if (isdigit(board[spelarensInmatning/3][spelarensInmatning%3]))
                    {
                        board[spelarensInmatning/3][spelarensInmatning%3] = spelare;
                        break;
                    }
                    else
                    {
                        cout << "Prova en annan plats: ";
                        continue;
                    }
                }
            }

            void växlaSpelare()
            {
                if (spelare == 'X')
                    spelare = 'O';
                else
                    spelare = 'X';
                
                turns++;
            }

            char win()
            {
                // kontrollera om det finns horisontella vinster
                if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
                    return 'X';
                if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
                    return 'X';
                if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
                    return 'X';
                
                // kontrollera vertikala vinster
                if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
                    return 'X';
                if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
                    return 'X';
                if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
                    return 'X';
                
                // kolla efter diagonala vinster
                if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
                    return 'X';
                if (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')
                    return 'X';
                
                // kontrollera om det finns horisontella vinster
                if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
                    return 'O';
                if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
                    return 'O';
                if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
                    return 'O';
                
                // kontrollera vertikala vinster
                if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
                    return 'O';
                if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
                    return 'O';
                if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
                    return 'O';
                
                // kolla efter diagonala vinster
                if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
                    return 'O';
                if (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O')
                    return 'O';
                
                return '/';
            }

            bool Tie()
            {
                if (turns == 9 && win() == '/')
                {
                    numTies++;
                    round++;
                    return true;
                }
                else
                    return false;
            }

            void resetBoard()
            {
                cout << "\033[2J\033[1;1H";
                cout << "Tic Tac Toe - " << namn << endl << endl;
                
                // återställer x-antal av varv till 0 för att fixa Tie() funktionen
                turns = 0;
                
                // ascii-kod för nummer ett ("1")
                int resetVal = 49;
                
                /*
                återställer enskilda fläckar till 1-9 med 'resetVal' och
                skriver sedan ut nämnda fläckar som "återställer brädet" för ett nytt spel
                */
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        board[i][j] = resetVal;
                        ++resetVal;
                        cout << board[i][j] << " ";
                    }
                    cout << endl;
                }
            }
};

#endif  // XO_HPP