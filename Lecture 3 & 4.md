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
# Lecture 4
***Type conversation/Casting***
- Implicit Casting
	Performed by the Compiler (Automatically)
	Goes from smaller to larger data type 
- Explicit Casting 
	Performed by the Programmer 
	Goes from Larger to smaller data type 

```C
// implicit casting 
int x = 257;
char y; 
y = x;
```
so since the `y` can only hold one byte. it will hold the first byte in `x` 

```C
// Explicit casting 
int x = 257;
char y; 
y = (char) x;
```
this code will have the same output the different is *i have wrote (char) explicitly*

*Hierarchy*
```
Bool --> char --> int (signed) --> int (unsigned) --> long (signed)
--> long (unsigned) --> long long (signed) --> long long (unsigned) 
--> float --> double --> long double 
```
Note : we don't have any kind of promotion from `short (signed)` to `short (unsigned)`

```C
#include <stdio.h>

int main(void){

signed int x = -1;
unsigned int y = 5;

if (x < y)
	printf("ok\n");

else
	printf("Not Ok\n");
}
```
you would think the output will be "ok" since x is smaller than y
but the thing is the compiler will turn the signed int into unsigned int to complete the comparison 
turning the -1 into the largest number possible 
so the value of `x` and `y` in hex would be 
```
x -> FF FF FF FF
y -> 00 00 00 05 
```
so when comparing the compiler will check the MSB and the 'x' would win 
and all of this wouldn't happen if 'x' and 'y' had the same data type *there wouldn't be any kind of promotion*

*hint :* for any operation between integer number and float number the output would be *float*

```C
#include <stdio.h>

int main(void)
{
	int x = 5;
	float y = 2.0;
	if(x/y == 2)  // if the output is float it gonna be 2.5
		printf("int/float --> int\n");
	else
		printf("int/float --> float\n");
}
```


## 2.Assignment Operators 
$= ,+= ,-= ,/= , *= ,$ %= , &= $,|=,>>=,<<=,$ ^=

`x = x+2;` --> `x += 2;`
`x = x & 1;` --> `x &= 1;`

*Hint* 
`x = +2;` it is the same as `x=2;`

## 3.Relational Operators
used in conditions and loops 
$<,<=,>,>=,==,!=$

*for example*
```c
#include <stdio.h>

int main(void)
{
	int x = 2;
	if(x == 2)
		printf("ok\n")
}
```

```c
#include <stdio.h>
#if 0
int main(void)
{
	int x = 2;
	if(x = 2)
		printf("ok\n")
}
#endif 
/* this code will work because the compiler will make it 1 or -1 so it is not a ) aka it is not false so to avoid that you can write your condition backward */

#if 1
int main(void)
{
	int x = 2;
	if(2 == x)
		printf("ok\n")
}
#endif 

/*so if you forget a = it gonna be a syntax error instead of a logical error*/
```


## 4.Logical operators 
And &&
OR $||$
Not $!$
the output of its operations are *True or False*

`int x = 3 && 0;`
 any value other than 0 *(False)* is considered 1 *(True)*

*Tricky code*
```c
#include <stdio.h>

int main(void)
{
int a =1, b=1,c,d;
c = a++ || b++; 
// b++ gonna be neglected  
// because 1 || X (Don't Care) = 1 so the compiler will execute the first part and neglect the part after the or 
d = --b && a--; 
// the same thing goes here because 0 && X = 0 so a won't be decremented 

printf("c = %d\nd = %d\n",c,d); 
/*
The output:
c = 1 
d = 0
*/ 
}
```

## 5. Bitwise Operators 
1. `&` --> bitwise AND 
	used to perform ANDing between each 2 adjacent bit in 2 variables
```C
#include <stdio.h>
int main(void)
{
	int x = 5,y=6,z;
	z= x & y;
	printf("%d",z);
	/*
	x = 00000000 00000000 00000000 00000101
	y = 00000000 00000000 00000000 00000110
	then 
	z = 00000000 00000000 00000000 00000100 = 4 in decimal 
	*/
}
```

2. `|` --> bitwise OR
	used to perform ORing between each 2 adjacent bit in 2 variables 
```C
#include <stdio.h>
int main(void)
{
	int x = 5,y=6,z;
	z= x | y;
	printf("%d",z);
	/*
	x = 00000000 00000000 00000000 00000101
	y = 00000000 00000000 00000000 00000110
	then 
	z = 00000000 00000000 00000000 00000111 = 7 in decimal 
	*/
}
```

3. `^` --> bitwise XOR 
	if the number of ones are odd the output would be 1 
```C
#include <stdio.h>
int main(void)
{
	int x = 5,y=6,z;
	z= x ^ y;
	printf("%d",z);
	/*
	x = 00000000 00000000 00000000 00000101
	y = 00000000 00000000 00000000 00000110
	then 
	z = 00000000 00000000 00000000 00000011 = 3 in decimal 
	*/
}
```

4. `~`  --> NOT (one's complement)
5. `<<` shift left , `>>` shift right
 `<<`  adds $n$ zero from the left :
	  `0001` becomes `0010` so it is like multiplying by $2^n$
  `>>` adds $n$ zeros from the right :
	  `0010` becomes `0001` so it is like diving by $2^n$

Note: we don't insert zeros all the time
if you are using `<<` it adds zeros if you variable is signed or unsigned 
`>>` adds zeros for unsigned variables, BUT for signed variable u may need to insert ones if The *MSB = 1* and insert zeros if The *MSB = 0*
for signed variables *MSB* is also called ***Sign bit***

*Bitwise operators doesn't work with float/double data type "Syntax error"*

*Hint*
AND : 
	$x$ & $1$ $=$ $x$     *used for clear*
	$x$ & $0$ $=$ $0$ 
OR :
	$x$ | $1$ $=$ $1$        *used for set*
	$x$ | $0$ $=$ $x$
XOR :
	$x$ ^ $0$ $=$ $x$
	$x$ ^ $1$ $=$ $x`$     *used for toggle*

***What about registers***
8 bit Reg :   

```
Index : 7654 3210
		1111 0101
```

1) Set bit #3
	you want to set bit #3 without affecting the other bits in register , to do that we will use 
	*bit masking* 
```
Reg: 1111 0101
			  |
	 0000 1000
	 
output: 1111 1101
```
why we use 0 cuz `x | 0 = x`

2) clear bit #2
```
Reg: 1111 0101
			  &
	 1111 1011
	 
output: 1111 0001 
```

3) Toggle bit #4
```
Reg: 1111 0101
			  ^
	 0001 0000
	 
output: 1110 0101
```

As you can notice, you can perform any operation if you know the index `n` you want to use.

*Set :*  `Reg |= (1 << n)` 
	shifting by `n` will set 1 where u need to be
 *Clear :*  `Reg &= (~(1 << n))`
	shifting by `n` will set 1 where u need to be and then toggling to get the zero u need 
*Toggle :* `Reg ^= (1 << n)` 
	shifting by `n` will set 1 where u need to be

*How to read a specific bit, and rotate*