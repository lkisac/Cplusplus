/* Len Isac                      
   Bits and Binary Operators Program
   Date: November 20th, 2013 
   Status: insertBitPattern in UNSIGNED version is being worked on.
*/


#include <cstdio>
#include <string.h>

#define MAXHEX   256

#define SIGNED   1  
#define UNSIGNED 2
//#define VERSION SIGNED // SIGNED version
#define VERSION UNSIGNED // UNSIGNED version (comment this line out to enable signed version)

static char bitstr[MAXHEX]; 
using namespace std;



/****************************************/
/*            SIGNED VERSION            */
/****************************************/

#if VERSION == SIGNED
const char* bits(int val)
{
    int i;
    int j = 0;

    for (i = sizeof(int) * 8; i >= 0; i--, j++)
    {
        (val & (1 << (i - 1))) ? bitstr[j] = 1 + '0' : bitstr[j] = 0 + '0';
    }

    bitstr[--j] = 0;

    return bitstr;
}

const char* bitrep(int hex)
{
    char* binary;
    int i, j;

    binary = new char[strlen(bits(hex)) + 1];
    binary[strlen(binary)] = 0;
    strcpy(binary, bits(hex));
    for(i = 0, j = 0; i < (signed)strlen(binary); i++, j++)
    {
        (i % 4) == 0  && j > 0 ? printf(" %c", binary[i]) : printf("%c", binary[i]);
    }

    return binary;
}

char leftShift(int val)
{

    int shiftno = 0;
    int lsHex;

    printf("Left Shift by how many bits: ");
    scanf("%d", &shiftno);
    fflush(stdin);

    lsHex = val << shiftno;
    printf("Left Shift result is: %X\n", lsHex);
    printf("Bit Representation is:  ");
    bitrep(lsHex);
    printf("\n");

    return lsHex;
}

char rightShift(int val)
{
    int shiftno = 0;
    int rsHex;

    printf("Right Shift by how many bits: ");
    scanf("%d", &shiftno);
    fflush(stdin);

    rsHex = val >> shiftno;
    printf("Right Shift result is: %X\n", rsHex);
    printf("Bit Representation is:  ");
    bitrep(rsHex);
    printf("\n");

    return rsHex;
}

int reverse(int orghex)
{
    int revHex;

    revHex = ~orghex;
    printf("Reverse result is: %X\n", revHex);
    printf("Bit Representation is:  ");
    bitrep(revHex);
    printf("\n");

    return revHex;
}

int compare(int orghex)
{
    int choice = 0;
    int hexComp;
    int C;

    printf("Enter hex value to compare: ");
    scanf("%X", &hexComp);
    fflush(stdin);
    printf("Bit Representation is:  ");
    bitrep(hexComp);

    printf("\n\nSelect comparison operator\n");
    printf("1) &, AND\n2) |, OR\n3) ^, Exclusive OR\n");
    scanf("%d", &choice);
    fflush(stdin);

    switch(choice)
    {
    case 1:
        C = orghex & hexComp;
        printf("%X & %X \n", orghex, hexComp, C);
        break;
    case 2:
        C = orghex | hexComp;
        printf("%X | %X \n", orghex, hexComp, C);
        break;
    case 3:
        C = orghex ^ hexComp;
        printf("%X ^ %X \n", orghex, hexComp, C);
        break;
    }
    printf("Bit Representation is:  ");
    bitrep(C);
 
    return C;
}


int set3(int val, int n, bool setToOne)
{
   int mask = setToOne ? 1 << (n-1) : ~(1 << (n-1));

   printf("\nMask created for %s", (setToOne) ? "true:  " : "false: ");
   bitrep(mask);
   printf("\n");

   mask = setToOne ? 1 << (n-1) : ~(1 << (n-1));

   if(setToOne)
   {
       printf("using | (OR)\n");
       val = val | mask;
   }
   else
   {
      printf("using & (AND)\n");
      val = val & mask;      
   }
   
   printf("After set, \n");   
   printf("Bit Representation is:  ");

   return val;
}


/*create a function that copies the bit pattern of a character, into an integer, starting from "n"th bit,
  so the first bit of the character is copied on "n"th bit of the integer and the 8th bit of the character is copied onto "n + 8"th bit of integer*/
void insertBitPattern(int val)
{    
    // forloop variables.
    int i;
    int j = 0;
    // nth bit, mask and user's bit pattern variables.
    int nth_bit;
    int mask;
    char bit[MAXHEX];
    
    printf("Enter bit pattern (set of 0's & 1's): ");
    scanf("%s", &bit);

    //printf("%s length is %d\n", bit, strlen(bit));

    printf("Enter nth position to enter bit pattern: ");
    scanf("%d", &nth_bit);

    // getmask for integer
    mask = 1 << (nth_bit -1);
    for (i = strlen(bit)-1; i >= 0; i--, mask = mask << 1)
    {
        //printf("mask representation:    ");
        if (bit[i] == '1')
        {
            val = val | mask;
            //bitrep(mask);
        }
        else 
        {
            val = val & ~mask;
            //bitrep(~mask);
        }
       /*printf("\n");        
       printf("val representation is:  ");
       bitrep(val);
       printf("\n");*/
    }
    printf("val representation is:  ");
    bitrep(val);
    printf("\n");   
}


int main ()
{
    int hex = 0;
    int choice = 0;
    int nth_bit = 0;
    bool setToTrue = 0;


    printf("Hexadecimal Converter\n");
    printf("=====================\n");

    do{
        printf("\nEnter a series of numbers(0-9) and letters(A-F) followed by 0x\n(e.g. 0x3A, 0x95, 0x5C001, 0x78DEF, etc.)\n(0 to quit)\n==> ");

        scanf("%X", &hex);
        fflush(stdin);
        if (hex == 0) break; // Hex values: 51 is q, 71 is Q
        else
        {
            printf("Bit Representation is:  ");
            bitrep(hex);
    
            printf("\nSelect an option\n");
            printf("1) Left Shift\n2) Right Shift\n3) Reverse\n4) Compare with another hexadecimal value\n5) Set bit\n6) Insert Bit Pattern\n");
            scanf("%d", &choice);
            fflush(stdin);

            switch(choice)
            {
            case 1:
                leftShift(hex);
                break;
            case 2:
                rightShift(hex);
                break;
            case 3:
                reverse(hex);
                break;
            case 4:
                printf("\nCompare result is: %X\n", compare(hex));
                break;
            case 5:
                printf("Which bit to set: ");
                scanf("%u", &nth_bit);
                fflush(stdin);
                printf("Set to 0) false, 1) true: ");
                scanf("%u", &setToTrue);                
                fflush(stdin);
                bitrep(set3(hex, nth_bit, setToTrue));
                printf("\n");
                break;
            case 6:
                insertBitPattern(hex);
                break;
            }
        }
    }while(hex != 0);    

    return 0;
}
#endif





/****************************************/
/*          UNSIGNED VERSION            */
/****************************************/

#if VERSION == UNSIGNED
const char* bits(int val)
{
    int i;
    int j = 0;

    for (i = sizeof(int) * 8; i >= 0; i--, j++)
    {
        (val & (1 << (i - 1))) ? bitstr[j] = 1 + '0' : bitstr[j] = 0 + '0';
    }

    bitstr[--j] = 0;

    return bitstr;
}

const char* bitrep(int hex)
{
    char* binary;
    int i, j;

    binary = new char[strlen(bits(hex)) + 1];
    binary[strlen(binary)] = 0;
    strcpy(binary, bits(hex));
    for(i = 0, j = 0; i < strlen(binary); i++, j++)
    {
        (i % 4) == 0  && j > 0 ? printf(" %c", binary[i]) : printf("%c", binary[i]);
    }

    return binary;
}

char leftShift(int val)
{

    int shiftno = 0;
    int lsHex;

    printf("Left Shift by how many bits: ");
    scanf("%d", &shiftno);
    fflush(stdin);

    lsHex = val << shiftno;
    printf("Left Shift result is: %X\n", lsHex);
    printf("Bit Representation is:  ");
    bitrep(lsHex);
    printf("\n");

    return lsHex;
}

char rightShift(int val)
{
    int shiftno = 0;
    int rsHex;

    printf("Right Shift by how many bits: ");
    scanf("%d", &shiftno);
    fflush(stdin);

    rsHex = val >> shiftno;
    printf("Right Shift result is: %X\n", rsHex);
    printf("Bit Representation is:  ");
    bitrep(rsHex);
    printf("\n");

    return rsHex;
}

int reverse(int orghex)
{
    int revHex;

    revHex = ~orghex;
    printf("Reverse result is: %X\n", revHex);
    printf("Bit Representation is:  ");
    bitrep(revHex);
    printf("\n");

    return revHex;
}

int compare(int orghex)
{
    int choice = 0;
    int hexComp;
    int C;

    printf("Enter hex value to compare: ");
    scanf("%X", &hexComp);
    fflush(stdin);
    printf("Bit Representation is:  ");
    bitrep(hexComp);

    printf("\n\nSelect comparison operator\n");
    printf("1) &, AND\n2) |, OR\n3) ^, Exclusive OR\n");
    scanf("%d", &choice);
    fflush(stdin);

    switch(choice)
    {
    case 1:
        C = orghex & hexComp;
        printf("%X & %X \n", orghex, hexComp, C);
        break;
    case 2:
        C = orghex | hexComp;
        printf("%X | %X \n", orghex, hexComp, C);
        break;
    case 3:
        C = orghex ^ hexComp;
        printf("%X ^ %X \n", orghex, hexComp, C);
        break;
    }
    printf("Bit Representation is:  ");
    bitrep(C);
 
    return C;
}


int set3(int val, int n, bool setToOne)
{
   int mask = setToOne ? 1 << (n-1) : ~(1 << (n-1));

   printf("\nMask created for %s", (setToOne) ? "true:  " : "false: ");
   bitrep(mask);
   printf("\n");

   mask = setToOne ? 1 << (n-1) : ~(1 << (n-1));

   if(setToOne)
   {
       printf("using | (OR)\n");
       val = val | mask;
   }
   else
   {
      printf("using & (AND)\n");
      val = val & mask;      
   }
   
   printf("After set, \n");   
   printf("Bit Representation is:  ");

   return val;
}


/*create a function that copies the bit pattern of a character, into an integer, starting from "n"th bit,
  so the first bit of the character is copied on "n"th bit of the integer and the 8th bit of the character is copied onto "n + 8"th bit of integer*/
void insertBitPattern(int val)
{    
    // forloop variables.
    int i;
    int j = 0;
    // nth bit, mask and user's bit pattern variables.
    int nth_bit;
    int mask;
    char bit[MAXHEX];
    
    printf("Enter bit pattern (set of 0's & 1's): ");
    scanf("%s", &bit);

    //printf("%s length is %d\n", bit, strlen(bit));

    printf("Enter nth position to enter bit pattern: ");
    scanf("%d", &nth_bit);

    // getmask for integer
    mask = 1 << (nth_bit -1);
    for (i = strlen(bit)-1; i >= 0; i--, mask = mask << 1)
    {
        //printf("mask representation:    ");
        if (bit[i] == '1')
        {
            val = val | mask;
            //bitrep(mask);
        }
        else 
        {
            val = val & ~mask;
            //bitrep(~mask);
        }
       /*printf("\n");        
       printf("val representation is:  ");
       bitrep(val);
       printf("\n");*/
    }
    printf("val representation is:  ");
    bitrep(val);
    printf("\n");   
}


int main ()
{
    int hex = 0;
    int choice = 0;
    int nth_bit = 0;
    bool setToTrue = 0;


    printf("Hexadecimal Converter\n");
    printf("=====================\n");

    do{
        printf("\nEnter a series of numbers(0-9) and letters(A-F) followed by 0x\n(e.g. 0x3A, 0x95, 0x5C001, 0x78DEF, etc.)\n(0 to quit)\n==> ");

        scanf("%X", &hex);
        fflush(stdin);
        if (hex == 0) break; // Hex values: 51 is q, 71 is Q
        else
        {
            printf("Bit Representation is:  ");
            bitrep(hex);
    
            printf("\nSelect an option\n");
            printf("1) Left Shift\n2) Right Shift\n3) Reverse\n4) Compare with another hexadecimal value\n5) Set bit\n6) Insert Bit Pattern\n");
            scanf("%d", &choice);
            fflush(stdin);

            switch(choice)
            {
            case 1:
                leftShift(hex);
                break;
            case 2:
                rightShift(hex);
                break;
            case 3:
                reverse(hex);
                break;
            case 4:
                printf("\nCompare result is: %X\n", compare(hex));
                break;
            case 5:
                printf("Which bit to set: ");
                scanf("%u", &nth_bit);
                fflush(stdin);
                printf("Set to 0) false, 1) true: ");
                scanf("%u", &setToTrue);                
                fflush(stdin);
                bitrep(set3(hex, nth_bit, setToTrue));
                printf("\n");
                break;
            case 6:
                insertBitPattern(hex);
                break;
            }
        }
    }while(hex != 0);    

    return 0;
}
#endif