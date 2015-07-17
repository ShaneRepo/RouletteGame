// A Program that mimics a roulette game, betting , winning, etc
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Function prototypes
void showInstructions();
float getBetAmount();
int makeBet();
int spinWheel();
float figureWinnings(int, int, float);

int main()
{
    float betAmount, money;
    int value, random, action;
        // do while loop so user can keep playing
do {
    showInstructions();
    betAmount = getBetAmount();
    value = makeBet();
    random = spinWheel();
    money = figureWinnings(value, random, betAmount);
    printf("\nYou won $%.2f", money);
    printf("\nDo you want to play another game?\nPress o to quit or 1 to continue. ");
    scanf("%d",&action);
}while (action != 0);

    return 0;
}
// showInstructions function
void showInstructions()
{
    printf("\n\tYou can place a bet in one of three ways:");
    printf("\n\n\tBet on a number [payout is 36 times the bet amount]");
    printf("\n\n\tBet on an odd or even [payout is 2 times the bet amount]");
    printf("\n\n\tBet on a dozen ~ [first 1-12], [second 13-24], [third 25-36], \n\n\t[payout is 3 times the bet]");
    printf("\n\n\tThe number zero does not count for odd or even or dozen, \n\n\tbut zero can count as a number bet.");
}
// getBetAmount function
float getBetAmount()
{
float bet;
printf("\n\nEnter amount you would like to bet please: ");
    scanf("%f",&bet);
printf("\n\nBet amount is $%.2f",bet);
return bet;
}
// makeBet function
int makeBet()
{
    int menuChoice, numBet, odd100even200, value, dozenChoice, valid = 1;

printf("\n\nWhat type of bet would you like to place?");
printf("\n\n\tPlease choose from the following menu:");
printf("\n\nEnter 1 if you'd like to bet on a NUMBER:");
printf("\n\nEnter 2 if you'd like to bet on a ODD or EVEN:");
printf("\n\nEnter 3 if you'd like to bet on a DOZEN: ");
    scanf("%d",&menuChoice);

    switch (menuChoice)
    {
    case 1:
        printf("\nEnter a number between 0-36: ");
            scanf("%d", &numBet);
            // Do while loop for data validation
            do {
            if (numBet < 0 || numBet > 36)
            {
                printf("\nInvalid entry. Enter a number between 0-36 please. ");
                scanf("%d", &numBet);
                if (numBet >= 0 && numBet < 37)
                {
                    valid = 0;
                }
                else
                    valid = 1;
            }
                }while (valid != 0);
        printf("\nYour selection is %d", numBet);
        value = numBet;
        break;
    case 2:
        printf("\nEnter 1 for ODD or 2 for EVEN: ");
            scanf("%d", &odd100even200);
            // Do while for data validation
            do {
                if (odd100even200 != 1 || odd100even200 != 2)
                {
                    printf("\nInvalid entry. Enter 1 or 2 please. ");
                    scanf("%d", &odd100even200);
                }
                    if (odd100even200 == 1 || odd100even200 == 2)
                    {
                        valid = 0;
                    }
            }while (valid != 0);

            if (odd100even200 == 1)
            {
                printf("\nYou choose ODD. ");
                value = 100;
                break;
            }
            else if (odd100even200 == 2)
            {
                printf("\nYou choose EVEN. ");
                value = 200;
                break;
            }
            else
                break;
    case 3:
        printf("\nEnter 1 for 1-12\nEnter 2 for 13-24\nEnter 3 for 25-36. ");
        scanf("%d", &dozenChoice);
        // Do while for data validation
        do {
            if (dozenChoice < 1 || dozenChoice > 3)
            {
                printf("\nInvalid entry. Please enter 1 or 2 or 3. ");
                scanf("%d", &dozenChoice);
                if (dozenChoice >= 1 && dozenChoice < 4)
                {
                    valid = 0;
                }
            }

                }while (valid != 0);
                if (dozenChoice == 1)
                {
                    printf("\nSelection is 1-12. ");
                    value = 0112;
                    break;
                }
                else if (dozenChoice == 2)
                {
                    printf("\nSelection is 13-24. ");
                    value = 1324;
                    break;
                }
                else if (dozenChoice == 3)
                {
                    printf("\nSelection is 25-36. ");
                    value = 2536;
                    break;
                }
                else
                    break;

    }

    return value;

}
// spinWheel function
int spinWheel()
{
int random;
     srand(time(NULL));
     random = rand() % 37;
    return random;
}
// figureWinnings function
float figureWinnings(int value, int random, float betAmount)
{
float payout, money;
int dozen;
printf("\n random is %d", random);

        if (value >= 0 || value < 37)
        {
                if (value == random)
                {
                    payout = betAmount * 36;
                    money = payout;
                    printf("\nYou won $%.2f",money);
                }


                else if (value == 100)
                {
                    if (random % 2 != 0)
                    {
                        payout = betAmount * 2;
                        money = payout;
                        printf("\nYou won $%.2f",money);

                    }


                }
                else if (value == 200)
                {
                    if (random % 2 == 0)
                    {
                        payout = betAmount * 2;
                        money = payout;
                        printf("\nYou won $%.2f",money);

                    }


                }
                else if (value == 0112)
                {
                    if (random > 0 && random < 13)
                    {
                        payout = betAmount * 3;
                        money = payout;
                        printf("\nYou won $%.2f",money);
                        dozen = 0112;
                    }


                }
                else if (value == 1324)
                {
                    if (random > 12 && random < 25)
                    {
                        payout = betAmount * 3;
                        money = payout;
                        printf("\nYou won $%.2f",money);
                        dozen = 1324;
                    }


                }
                else if (value == 2536)
                {
                    if (random > 24 && random < 37)
                    {
                        payout = betAmount * 3;
                        money = payout;
                        printf("\nYou won $%.2f",money);
                        dozen = 2536;
                    }


                }
                else
                {
                    printf("\nYou lost $%.2f", betAmount);
                }

        }

return money;

}











