# Lecture 3
## Input & Output Values 
`Scanf` : it scans the input from the user.
```
// Syntax
scanf("Format_Specifier",&variable); // & is called address operator 


```
We give `scanf` the address of the variable, so it can insert the value read from the user. 
and the size of the variable is specified by the Format_Specifier 

`printf` : it display the output for the user 
```
// Syntax
printf("Format_Specifier",variable); 

// ex
printf("%i",x);
```

the format specifier : specifies the datatype 
there is lots of format specifiers : https://www.freecodecamp.org/news/format-specifiers-in-c/ 
you will find them all in this link.

*Hint*  
`scanf` & `printf` are not used in Embedded System

| symbol | type   |
| ------ | ------ |
| 0x     | hex    |
| 0      | octa   |
| 0b     | binary |

```c
#include <stdio.h>

int main(void){

   unsigned char x = 0;

   signed char y = 0;

   x--;

   y--;

   printf("x=%i\ny=%i",x,y); 

   return 0;

}
```
Output:
x=255
y=-1

this happened because `x` is unsigned so when we decrement the 0 , we get -1
but our range is in between 0 and 255, so we use two's complement to get the value 
1 in binary is 

| 0   | 0   | 0   | 0   | 0   | 0   | 0   | 1   |
| --- | --- | --- | --- | --- | --- | --- | --- |
it's two's complement

| 1   | 1   | 1   | 1   | 1   | 1   | 1   | 1   |
| --- | --- | --- | --- | --- | --- | --- | --- |
which is 255 in decimal 

*hint*
when microprocessor encounter `scanf` it stops till the user enter the input.
BUT how does it know the user input!
each letter on the keyboard has an ASCII code 

```C
#include <stdio.h>
int main(void){
char ch = '97';
printf("%c\n",ch);
}
```
this code will show a *warning* because 97 is not a characters it is composite of 2 characters
but it still will work.
`ch` will store one of the 2 variables 

```C
#include <stdio.h>
int main(void){
char ch = 97; // decimial value 
printf("%c\n",ch); // will print the ASCII value
printf("%i\n",ch); // will print the decimal value
}
```

```C
#include <stdio.h>

int main(void){

char x,y;
printf("Enter X : ");
scanf("%c",&x); // will save the input in the address of x 

printf("Enter Y : ");
scanf("%c",&y); // will save the input in the address of x 

printf ("\nX=%c Y=%c\n",x,y);
printf ("X=%i Y=%i\n",x,y);
}
```
this code will take the input into `x` and takes the `\n` as the input for the `y` 
this problem happened because the buffer stored the input of `x` and the new line caused by the Enter key.
so to overcome this problem, you can use this 
`fflush(stdin);`  to flush the input buffer 
`fflush(stdout);` to flush the output buffer 

```C
#include <stdio.h>

int main(void){

char x,y;
printf("Enter X : ");
scanf("%c",&x); // will save the input in the address of x 

fflush(stdin); 
fflush(stdout);

printf("Enter Y : ");
scanf("%c",&y); // will save the input in the address of x 

printf ("\nX=%c Y=%c\n",x,y);
printf ("X=%i Y=%i\n",x,y);
}
```

another solution is to add space before the `%c` 
this format will discard all the whitespaces.
```C
#include <stdio.h>

int main(void){

char x,y;
printf("Enter X : ");
scanf("%c",&x); // will save the input in the address of x 

printf("Enter Y : ");
scanf(" %c",&y); // will save the input in the address of x 

printf ("\nX=%c Y=%c\n",x,y);
printf ("X=%i Y=%i\n",x,y);
}
```

---
and to avoid this problem you can use *get* and *put* 
Search about :
get char , put char 
get string and put string 

---

## operators 
- Arithmetic Operator
- Bitwise Operator
- Assignment Operator 
- Relational Operator
- Logical Operator

## 1. Arithmetic Operator
- binary --> it needs 2 operands 
	$(+ , - , / , *$ and %$)$ 
	N % k = the output would be in between $[0 : k-1]$

Note : $dec(A/B)*B + (A mod B) = A$  *This Theorem called : division algorithm*
so you can use this rule to calculate the mod of any numbers you want

- Unary  --> it only needs 1 operands 
	Operators like $(++,--)$ 
	Postfix : `X--` , `X++`
	Prefix : `--X` , `++X`
```C
#include <stdio.h>

int main(void)
{
int x = 20;
printf("%d",x++); 
// will print and then increment x value 
// Output: 20 , x = 21

printf("%d",++x);
// will increment x value and then print 
// Output: 22 , x = 22 
}
```

``` C
unsigned char x = 6,y = 7,z=8,w;
w = x++ + y++ + --z;
printf("W = %d\n",w); // W = 20 
printf("X = %d\n",x); // X = 6
printf("Y = %d\n",y); // Y = 8
printf("Z = %d\n",z); // Z = 7
```

```C
int x = 10, y = 20 , z;
z = x+++y; // it's equvilient to (x++ + y)

z = x++++y; // error and the solution is Space
z = x++ + +y; // (+y) positive value, + addition , ++ increment 
```

***Hierarchy of operations***
1.  $*,/$ and %
2. $+,-$
3. $=$