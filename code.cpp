#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

//Blackjack
//Simple and it works
//made by lordduck for fun

int random_numb;
int chance;

int drawCard() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    random_numb = std::rand() % 10 + 1;
    return random_numb;
}

bool randomchance() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    chance = std::rand() % 12 + 1;
    if (chance < 4)
    {
        return true;
    } else
    {
        return false;
    }
}

int main() 
{
    char a;
    bool isRunning = true;
    int dealerHand = 0;
    int playerHand = 0;
    char choice;

    std::cout << "Press anything to start the game" << std::endl;
    std::cin.ignore();

    while (isRunning) 
    {
        std::cout << "|=========" << std::endl;
        std::cout << "|Blackjack" << std::endl;
        std::cout << "|Dealer's hand: " << dealerHand << std::endl;
        std::cout << "|Your hand: " << playerHand << std::endl;
        std::cout << "|Would you like to hit or stand? [H/S]" << std::endl;
        std::cin >> choice;

        if (choice == 'H') 
        {
            randomchance();
            playerHand += drawCard();
            system("cls");
        } else if (choice == 'S') 
        {
            dealerHand += drawCard();
            system("cls");
        } else 
        { 
            system("cls");
            std::cout << "Invalid choice. Please enter 'H' or 'S'." << std::endl;
            continue;
        }

        if (playerHand > 21) 
        {
            std::cout << "Dealer's hand: " << dealerHand << std::endl;
            std::cout << "Your hand: " << playerHand << std::endl;
            std::cout << "Game over, you lost!" << std::endl;

            isRunning = false;
        } else if (dealerHand > 21)
        {
            std::cout << "Dealer's hand: " << dealerHand << std::endl;
            std::cout << "Your hand: " << playerHand << std::endl;
            std::cout << "Game over, you win!" << std::endl;
            isRunning = false;
        }
    }
    std::cin >> a;
    return 0;
}
