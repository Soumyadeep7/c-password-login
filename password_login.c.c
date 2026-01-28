#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
    char ch;
    char pass[20];
    char saved_pass[20];
    int i;

start:
    i = 0;
    printf("Enter your password: ");

    while (1)
    {
        ch = getch();

        if (ch == 13)   // Enter key
        {
            pass[i] = '\0';
            break;
        }
        else
        {
            pass[i++] = ch;
            printf("*");
        }
    }

    printf("\n");

    FILE *ptr;
    ptr = fopen("password.txt", "r");

    if (ptr == NULL)
    {
        printf("Error opening password file\n");
        return 1;
    }

    fscanf(ptr, "%s", saved_pass);
    fclose(ptr);

    if (strcmp(pass, saved_pass) == 0)
    {
        printf("LOGIN Successful\n");
    }
    else
    {
        printf("Incorrect Password. Try again.\n\n");
        goto start;
    }

    return 0;
}
