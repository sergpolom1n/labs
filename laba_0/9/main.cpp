#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



  

  

int convertTo10(char num[], int baseN, int* num10)
{
    //long numN = strtol(num, NULL, baseN);
    
    
    *num10 = 0;
    int empty = 0;
    int flag = 1;
    int count = 0;
    int countBack = 1;
    
    for (int i = 0; num[i] == ' ' || num[i] == '0'; i++)
    {
        count++;
    }
    for (int i = 0; i < strlen(num); i++) {
        if (num[i] != ' ' && num[i] != '\n') {
            empty = 1;
        }
    }
    if (empty == 0) {
        return 0;
    }
    if (num[count] == '-')
    {
        count++;
        flag = 0;
    }
    
    while (num[(int)strlen(num) - countBack] == ' ' || num[(int)strlen(num) - countBack] == '\n')
    {
        countBack++;
    }
    countBack = (int)strlen(num) - countBack;
    
    char numX[countBack - count + 1];
    
    for (int i = 0; i <= countBack - count; i++) {
        numX[i] = num[i + count];
        if (baseN <= 10 && ((int)numX[i] < 48 || (int)numX[i] > 48 + baseN - 1))
        {
            return 0;
        }
        else if (baseN > 10 && (((int)numX[i] < 48) || ((int)numX[i] > 57 && ((int)numX[i] < 65)) || ((int)numX[i] > 65 + baseN - 10 - 1)))
        {
            return 0;
        }
    }
    
//    if ((int)strlen(numX) > ) {
//        <#statements#>
//    }
    
    for (int i = 0; i < (int)strlen(numX); i++)
    {
        if (baseN <= 10 && (int)numX[i] >= 48 && (int)numX[i] <= 48 + baseN - 1)
        {
            *num10 = *num10 + (((int)numX[i] - 48) * pow((double)baseN, (double)((int)strlen(numX) - i - 1)));
        }
        else if (baseN > 10 && (((int)numX[i] >= 48 && (int)numX[i] <= 57)))
        {
            *num10 = *num10 + (((int)numX[i] - 48) * pow((double)baseN, (double)((int)strlen(numX) - i - 1)));
        }
        else if (baseN > 10 && (((int)numX[i] >= 65 && (int)numX[i] <= 65 + baseN - 10 - 1)))
        {
            *num10 = *num10 + (((int)numX[i] - 55) * pow((double)baseN, (double)((int)strlen(numX) - i - 1)));
        }
        else
        {
            *num10 = 0;
            return 0;
        }
    }
    return 1;
}

void convertToN(int number10, int baseN)
{
    int count = 0;
    int n = number10;
    
    while (n != 0) {
        n = n / baseN;
        count++;
    }
    char numberN[count + 1];
    
    for (int i = count - 1; i >= 0; i--)
    {
        if (number10 % baseN >= 0 && number10 % baseN <= 9)
        {
            numberN[i] = (char)(number10 % baseN + 48);
        }
        else if (number10 % baseN >= 10 && number10 % baseN <= baseN - 1)
        {
            numberN[i] = (char)(number10 % baseN + 55);
        }
        number10 = number10 / baseN;
        
    }
    printf("number in %d base: ", baseN);
    for (int i = 0; i < count; i++) {
        printf("%c", numberN[i]);
    }
    printf("\n");
}


int main(void)
{
    char num[1000] = "";
    char stop[1000] = "Stop";
    char numStop[1000] = "";
    int max10 = 0;
    int baseN;
    printf("Input base: ");
    scanf("%d", &baseN);
    if (baseN <= 1 || baseN > 36)
    {
        printf("repeat input base\n");
        return 1;
    }
    fflush(stdin);
    printf("Input num in %d base: ", baseN);
    fgets(num, 1000, stdin);
    sscanf(num, "%s", numStop);
    fflush(stdin);
    while (strcmp(numStop, stop)) {
        
        int num10 = 0;
        int a = convertTo10(num, baseN, &num10);
        if (a == 1)
        {
            if (num10 > max10) {
                max10 = num10;
            }
            
        }
        else
        {
            printf("Input repeat\n");
        }
        printf("Input num in %d base: ", baseN);
        fgets(num, 1000, stdin);
        sscanf(num, "%s", numStop);
        fflush(stdin);
    }
    printf("\nnumber in 10 base: %d\n", max10);
    convertToN(max10, 9);
    convertToN(max10, 18);
    convertToN(max10, 27);
    convertToN(max10, 36);
    
}
    








