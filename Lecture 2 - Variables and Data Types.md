-  C language is a structured programming language 
	-  so the code is divided into units / blocks and those units are called functions 
	- the main function is the entry point *but it is not the first thing to be executed all the time thought*
- what calls the main function is called *startup code* 
	- it is a code that execute some processes and then branch into the main function 

```C
int main ()
{
	printf("hello learnplusplus");
	return 0;
}
```
- this code will trigger and error
	- because `printf()` is a function declared in `stdio.h` so without including the  library , the code won't work.

```C

#include <stdio.h>
int main()
{
	printf("hello learnplusplus")
	return 0;
}
```

***Comments*** 
**why**
- it's very important to explain your code 
**How**
1. single line comment 
	- you will use the `//` to comment the line
2. multiple line comment
	- for this one, you'd use this one `/**/`
	- `/**/` is the standard way


***Escape sequences***
it is a `\` + `charcter` and the behavior changes depending on that `character`
`\` is called  escape operator 

***Variables & Assignment***
Assignment operator is `=`
simply it takes the data on the hand side and assign it to the left hand side.

```C
void main()
{
	int x; // declaring x as an int variable and has a garbage value
	int y = 10; // declaration and initialization 
	x = y; // that is called assigning 
}
```

Variable : part of the memory & hold a piece of data.
so we need 3 things to declare a variable 
1. data type *to specify the size needed for the variable in memory*
2. name *to be able to use the variable*
3. data "value" 

***variable naming rules also known as "C-identifiers"***
1. No spaces 
2. No Special characters 
	- except :  __ and $
3. No reserved words 
	- we got 32 keyword in C
4. you must start the name with alphabet character

Hint : make the names of your variables meaningful & short , making your code readable 

***C Data Types***
1. permeative (Basic)
2. Derived
	- function 
	- array
	- pointer
3. User defined
	- structure 
	- union
	- Enum 
	- typedef 

### permeative Data Type
1. void  
	- Special Case
2. Decimal (Integer values)
	- int 
	- char
3. Real Values (Floating)
	- float 
	- double 

| Data type | Size               |
| --------- | ------------------ |
| char      | 1 byte             |
| int       | 4 bytes "Normally" |
| float     | 4 bytes            |
| double    | 8 bytes            |
you can also have signed and unsigned data type affecting the range of values can be stored :
1. Signed
	- you will have positive and negative numbers
	- the range is [-2^ (n-1) : 2 ^ (n -1) -1]
2. UnSigned 
	- all values are positive so the range is $[0:2^n - 1]$ 

***Hints :*** 
1. any number represents a group of bits that is why in Embedded System we use (unsigned)
2. ranges of (float , double) depends on the standard used
3. short , long => are not data types but ***modifiers*** 
	- because they are prepended to change the size of data byte
4. `int x;` that is called declaration / declaration 
	`int x = 10;` definition with initialization 
5. you can use the keyword `extern` i used when the variable is defined in another file 
	- when u use `extern` that is called declaration not definition 'cause you r not reserving any more space 
6. `bool` data type is not a standard data type which means it is not in *C89* but it does exist in newer versions

## Endianness 
it is how data is stored in memory 
there is 2 types of Endianness 
1. big 
	- we store the Most significant bit to Least significant bit
	- so it is storing the bigger value in the lower address
2. little
	- we store the Least significant bit to The Most significant bit
	- so it is storing the smaller value in the lower address 