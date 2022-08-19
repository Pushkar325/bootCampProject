
#include <stdio.h>      // for Input/Output functions.
#include <stdlib.h>     // for General utility functions.
#include <conio.h>      // for Console Input/Output functions.
#include <ctype.h>      // for useful for testing and mapping characters.
#include <time.h>       // for using inbuilt srand(time(NULL)).
#include <windows.h>    // use for the changing color or some inbuilt window features.
#include <process.h>    // for all the common macros used by Windows programmers and some other features.
#include<string.h>      // for String functions.



void createMatrix(int arr[][4])
{
    int n = 15;
    int num[n], i, j;
    for (i = 0; i < 15; i++)  // here 1 to 15 matrix show karne k liye.
        num[i] = i + 1;

    srand(time(NULL)); //  random number generate karne k liye.

    int lastIndex = n - 1, index;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
        {
            if (lastIndex >= 0)
            {
                index = rand() % (lastIndex + 1); // idea : performing % operation by (lastIndex+1)
                arr[i][j] = num[index];           // will give index , so put that num[index] number in matrix
                num[index] = num[lastIndex--];    // and replace last number with this indexed positioned number
            }                                     // and finally lastIndex--
        }
    arr[i - 1][j - 1] = 0; // last number zero hai.
}



// show k liye function banaya hu
void showMatrix(int arr[][4])
{
    int i, j;
    printf(" ------------------\n");
    for (i = 0; i < 4; i++)
    {
        printf(" | ");
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] != 0)
                printf("%-2d |", arr[i][j]);
            else
                printf("   |");
        }
        printf("\n");
    }

    printf(" ------------------\n");
}



// check karega winning condition.
int winner(int arr[][4])
{
    int i, j, k = 1;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++, k++)
            if (arr[i][j] != k && k != 16)
                break;
        if (j < 4)
            break;
    }
    if (j < 4)
        return 0;
    return 1;
}



// function banaya hu swap k liye 2 number ka.
void swap(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
    printf("\a\a\a");
}



// Read karega user k input character and return ascii value karega.
int readEnteredKey()
{
    char c;
    c = getch();
    if (c == 27 || c == 91) //  scan karega code ko.
    {
        c = getch();
        if (c == 27 || c == 91) // yeah v scan karega code.
            c = getch();
    }
    return c;
}



// shift upper k liye  function
int shiftUp(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }
    if (i == 3) // shifting possible nai hai.
        return 0;
    swap(&arr[i][j], &arr[i + 1][j]);
    return 1; // shift up success
}



// down shift k liye function.
int shiftDown(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }
    if (i == 0) // shifting possible nai hai.
        return 0;
    swap(&arr[i][j], &arr[i - 1][j]); // swap karo numbers ka.

    return 1; // shift up success.
}



// right shift k liye function.
int shiftRight(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }
    if (j == 0) // shifting possible nai hai.
        return 0;
    swap(&arr[i][j], &arr[i][j - 1]);

    return 1; // shift up success.
}



// left shift k liye function.
int shiftLeft(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }
    if (j == 3) // shifting possible nai hai.
        return 0;
    swap(&arr[i][j], &arr[i][j + 1]);
    return 1; // shift up success.
}



// Game rules k liye function bnaya hua.
void gameRule(int arr[][4])
{
    system("cls");
    int x ;
    int i, j, k = 1;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
    printf("===================== ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 71);
    printf("RULE OF THIS GAME");
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
    printf(" ====================== \n");
    printf("\n\n  1.You can move only 1 step at a time by arrow key. ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("\n       * Move Up   : by Up arrow key.");
    printf("\n       * Move Down : by Down arrow key.");
    printf("\n       * Move Left : by Left arrow key.");
    printf("\n       * Move Right: by Right arrow key.");
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
    printf("\n  2.You can move number at empty position only.");
    printf("\n");
    printf("\n  3.For each valid move : your total number of move will decreased by 1.\n");
    printf("  4.Wining situation : ");
    printf("  number in a 4*4 matrix should be in order from 1 to 15.");
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("\n\n            winning situation:         \n");
    printf("           ====================\n\n");

    printf(" ---------------------\n");
    for (i = 0; i < 4; i++)    // matrix print kraya hu.
    {
        printf(" | ");
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] != 0)
                printf("%-2d | ", 4 * i + j + 1);
            else
                printf("   | ");
        }
        printf("\n");
    }

    printf(" ---------------------\n");
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
    printf("\n  5.You can exit the game at any time by pressing 'E' or 'e' ");

    printf("\n    So Try to win in minimum no of move. \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("\n         Happy gaming , Good Luck\n\n");
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 71);
    printf("Enter any key to start.....   :");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    x = readEnteredKey();
}



// Hamara programm yeha se start hoga (main part of the program)

int main()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    while (1)
    {
        int arr[4][4];   // matrix bnaya hu.
        int maxTry = 8;  // maximum move 400 according to question.
        char name[30];
        system("cls");  // it is inbuilt function, screen clear karne k liye with the help of "window.h".

        SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY); // green color k liye
        printf("Enter Player Name: ");  // name dalo bhai.
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // for white color.
        // fgets(name,30,stdin); // mai yeah v use kar skta tha.
        //gets(name); // yeah v.9
        scanf("%s", name);  // here scanf  mai use kar raha hu only for "FIRST NAME" k liye.
        createMatrix(arr); // function ko call kiya hu "MATRIX CREATE" karne k liye.
        gameRule(arr);     // function ko call kiya hu "GAME RULES" k liye.

        while (!winner(arr)) // checking kar raha hu win k liye.
        {
            system("cls");
            if (!maxTry) // for remaing zero move k liye.
                break;
            SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            printf("\n\n  Hello  %s , ", name);
            printf(" Move remaining : %d\n\n",maxTry);
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 259);

            showMatrix(arr); // matrix show k liye.

            int key = readEnteredKey(); // yeah return karega ascii code jaise user key enter kargea.

            switch (key) // maping k liye.
            {
            case 69: // ascii value captial " E " ka hai.

            case 101: // ascii value small " e "  ka hai.
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                printf("\a\a\a\a\a\a\n     Thanks for Playing !! \n\a");
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
                printf("\n  Press ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 71);
                printf(" Enter ");
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
                printf(" to exit the game \n"); // game se exit honne k liye.
                printf("\n\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                key = readEnteredKey();
                exit(0);


            case 72: // arrow up(Upper) k liye.
                if (shiftUp(arr))
                    maxTry--;
                break;
            case 80: // arrow down(niche) k liye.
                if (shiftDown(arr))
                    maxTry--;
                break;
            case 77: // arrow  " right " k liye
                if (shiftRight(arr))
                    maxTry--;
                break;
            case 75: // arrow " left " k liye.
                if (shiftLeft(arr))
                    maxTry--;
                break;

                // mai default use nai kar raha hu kyuki maine phele hi mention kar diya hu ki aapko arrow key use karna hai.

            default:
                printf("\n You pressed "); // jab v mai key press karung to yeah show karega.
                break;
            }
        }
        //SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);

        if (!maxTry)
        {
            printf("\n\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            printf("\n\a          ");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 71);
            printf(" YOU LOSE !!");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            printf("          \a\a\n\n"); // aagar ham game " LOSE " kar jaye to.
        }
        else
        {
            SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            printf("\n\a!!!!!!!!!!!!!Congratualization !!!!!!!!!!!!!\n\a");
            printf("\a               You have Won      \a\a\a ");   // aagar ham game " WIN " kar jaye to.
        }

        char check[1];

        SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("\n  want to play again ? \n");

        SetConsoleTextAttribute(h, FOREGROUND_GREEN);
        printf("\n  Enter any key to play again\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        printf("\n             OR");
        SetConsoleTextAttribute(h, FOREGROUND_RED);
        printf("\n\n  Press 'e' or 'E' key to exit:\n ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

        scanf("%s", &check);

        if (check[0] == 'e' || check[0] == 'E')   // check karega game again play karna hai ya nai.
        {
            //printf(" \n\n'THANK YOU' FOR PLAYING THE GAME\n");
            exit(1);
        }
        else
            continue;
    }

     //getch();
    return 0;

}

