# Programming Exercises - August 11, 2025

## Exercise 1 : String Operations

**Qestion:** Write a single program in c with menu facility to perform the following string operations :

                1. String Length
                
                2. String Reverse
                
                3. String Concatenation
                
                4. String Compare
                
                5. Search A Character Within A String

**Sollution:** [View Code](StringOperations.cpp)

```cpp
#include <stdio.h>

// Loop With Counter
int stringLength(char *str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

// Loop And Swap The Values Using Temp
void stringReverse(char *str)
{
    int len = stringLength(str);
    int i, j;
    char temp;

    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Run Two Loops And Check
void stringConcatenate(char *dest, char *src)
{
    int i = 0, j = 0;

    while (dest[i] != '\0')
    {
        i++;
    }

    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }

    dest[i] = '\0';
}

// Search Each With A loop
int stringCompare(char *str1, char *str2)
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return 0;
        }
        i++;
    }

    return (str1[i] == '\0' && str2[i] == '\0');
}

// Linear Search Loop
int searchCharacter(char *str, char ch)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == ch)
        {
            return i;
        }
        i++;
    }
    return -1;
}

int main()
{
    int choice;
    char str1[100], str2[100];
    char ch;
    int index;

    do
    {
        printf("\n\n*** String Operations Menu ***\n");
        printf("1. String Length\n");
        printf("2. String Reverse\n");
        printf("3. String Concatenation\n");
        printf("4. String Compare\n");
        printf("5. Character Search\n");
        printf("6. Exit\n");
        printf("Enter Your Choice (1 - 6): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter A String : ");
            scanf("%s", str1);

            printf("The Length Of String : %d\n", stringLength(str1));
            break;

        case 2:
            printf("Enter String To Reverse : ");
            scanf("%s", str1);

            stringReverse(str1);

            printf("Reversed String : %s\n", str1);
            break;

        case 3:
            printf("Enter First String : ");
            scanf("%s", str1);

            printf("Enter Second String : ");
            scanf("%s", str2);

            stringConcatenate(str1, str2);

            printf("Concatenated String : %s\n", str1);
            break;

        case 4:
            printf("Enter First String : ");
            scanf("%s", str1);

            printf("Enter Second String : ");
            scanf("%s", str2);

            if (stringCompare(str1, str2))
            {
                printf("The Stings Not Equal.\n");
            }
            else
            {
                printf("The Strings Are Not Euqal\n");
            }
            break;

        case 5:
            printf("Enter A String : ");
            scanf("%s", str1);

            printf("Enter A Character To Search : ");
            scanf(" %c", &ch);

            index = searchCharacter(str1, ch);

            if (index != -1)
            {
                printf("Character '%c' Found At %d\n", ch, index);
            }
            else
            {
                printf("Character '%c' Not Found\n", ch);
            }
            break;

        case 6:
            printf("Exiting Program\n");
            break;

        default:
            printf("Invalid Choise\n");
        }

    } while (choice != 6);

    return 0;
}

```

### OUTPUT 1

```bash
*** String Operations Menu ***
1. String Length
2. String Reverse
3. String Concatenation
4. String Compare
5. Character Search
6. Exit
Enter Your Choice (1 - 6): 1
Enter A String : SOHAM
The Length Of String : 5


*** String Operations Menu ***
1. String Length
2. String Reverse
3. String Concatenation
4. String Compare
5. Character Search
6. Exit
Enter Your Choice (1 - 6): 2
Enter String To Reverse : SOHAM
Reversed String : MAHOS


*** String Operations Menu ***
1. String Length
2. String Reverse
3. String Concatenation
4. String Compare
5. Character Search
6. Exit
Enter Your Choice (1 - 6): 3
Enter First String : SO
Enter Second String : HAM
Concatenated String : SOHAM


*** String Operations Menu ***
1. String Length
2. String Reverse
3. String Concatenation
4. String Compare
5. Character Search
6. Exit
Enter Your Choice (1 - 6): 4
Enter First String : SOHAM
Enter Second String : Soham
The Strings Are Not Euqal


*** String Operations Menu ***
1. String Length
2. String Reverse
3. String Concatenation
4. String Compare
5. Character Search
6. Exit
Enter Your Choice (1 - 6): 5
Enter A String : SOHAM
Enter A Character To Search : H
Character 'H' Found At 2


*** String Operations Menu ***
1. String Length
2. String Reverse
3. String Concatenation
4. String Compare
5. Character Search
6. Exit
Enter Your Choice (1 - 6): 6
Exiting Program

```
