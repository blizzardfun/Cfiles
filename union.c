
#include <stdio.h>
#include <stdlib.h>

int unionexample();
int unionexercise() ;

int main () 
// Use a UNION if you wanted to be able to read a variable's memory in different ways treating the same memory location as different types
{
    unionexample();
    unionexercise();
}

int unionexample()
// look at the same memory location as either integer (4 bytes) or as the individual char bytes
{
    union intParts {
        int theInt;
        char bytes[sizeof(int)];
    };
    union intParts parts;
    parts.theInt = 1234567; // arbitrary number > 255 (1 byte)

// UNION makes the access cean and clear
printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n",
parts.theInt, parts.bytes[0], parts.bytes[1], parts.bytes[2], parts.bytes[3]);

//pointer arithmetic to access the same intger as 4 char
printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n",
parts.theInt, *((char*)&parts.theInt+0), *((char*)&parts.theInt+1), *((char*)&parts.theInt+2), *((char*)&parts.theInt+3));

//arrays used to access the same integer as 4 char
printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n",
parts.theInt, ((char*)&parts.theInt)[0], ((char*)&parts.theInt)[1], ((char*)&parts.theInt)[2], ((char*)&parts.theInt)[3]);
}


  
union intchar {
    int integers[6];
    char chars[21];

};
  
int unionexercise() 
{
    
        // initializer lists like this are assigned to the first member of the union/struct (alt intcharcters.integers)
        // There are 6 ints here 
        union intchar intCharacters = {{1853169737, 1936876900, 1684955508, 1768838432, 561213039, 0}};
      
        /* testing access the 6 integers as 20 characters plus string terminator*/
        printf("[");
        // only go to 18 because 1 byte is for the terminating 0 and we print the last after the loop
        for(int i = 0; i < 19; ++i)
            printf("%c, ", intCharacters.chars[i]);
        printf("%c]\n", intCharacters.chars[19]);
    
        printf("%s\n", intCharacters.chars);
}