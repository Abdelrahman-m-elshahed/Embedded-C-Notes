***Unary operators*** 
they are the kind of operators that needs only one operand :
$++,--,-,~,!,$ sizeof , & , *  

## sizeof Operator 
`sizeof()` it accepts variables and data-types as an input to return its size *in bytes*.
***Hint***
sizeof operator doesn't evaluate any operation inside of it.
```C
#include <stdio.h> 

int main(void)
{
    int i = 5,j = 10, k = 15;
	sizeof(k /= i+j); 
	// the operation inside of sizeof won't be evaluated so K value would stay the same
    printf("%d",k); // 15

}
```
## Comma operator 
it's used as a separator , so u can use it to create more than one variable in the same line *if all of them are of the same type*.
`int a = 3,b = 4, c = 5;`

***Hint***
`int x = (5,6,7);` which value would be stored in `x`? 
it will be 7 or in other words the most right value.

`int x = 5,6,,7;` // syntax error
so if i don't wanna use brackets as in `int x = (5,6,7);`
you would need to do it this way 
```C
int x;
x = 5,6,7;
```
but in this case the value that is gonna eb stored is 5 🤡
and that is because of something called ***Precedence***
so assignment operator (=) has higher precedence than the comma operator(,), so the assignment operator is evaluated first , and then the comma expression is evaluated.
[operators precedence](https://en.cppreference.com/w/c/language/operator_precedence.html)

```C
#include <stdio.h>

int main(void)
{
    int x = (printf("hello\n"),8); // prinf() will return the number of char

    printf("%d\n",x); // 8
    x = printf("hello\n"); 
    printf("number of charcters pritned is %d",x); // 6 
}
```


a trick with `printf()` : print "hello world" without using (;) in your code
one way to do is to add the `printf()` statement inside and if condition with an empty body 

```C
#include <stdio.h>

int main(void)
{
	if(printf("hello world")) {}
	// the prinf will return the number of characters which doesn't equal to zero
}
```

***Task***
1. indiabix MCQs
2. write a code that figures out if the variable is in little or big endianness
3. Swap  in (3 different ways)

***Solution***
1. [[swap.c|Swap Problem]]	
2. [[endianness.c|Endianness Problem]]

---
## Controlling Program Flow 
the program will execute in 3 different ways
1. sequential "without using loops or conditions"
2. Decision "use conditions"
3. Loop

Which means any statement will be:
1. Selection or Condition
	1. if condition
	2. Switch Case 
	3. Ternary operator 
2. iteration 
	1. While Loop
	2. For Loop
	3. Do While loop
3. Jump 
	1. Break
	2. Continue 
	3. goto 
4. other C statements 

## 1. Selection Statement 

### If Statement 
```C
// Syntax
if(condition)
{
	// body
}

// Example
int x = 10;
if(x == 10)
{
	X++;
}
printf("X = %d\n",x); // X = 11

if(x = 10) // bug , the condition will always be True
{
	X++;
}

if(x = 0) // bug , the condition will always be False "unreacahble code"
{
	X++;
}
```

***Cascaded if :***
```C
//Syntax
if(conditon)
{
	// body
}
elseif(conditon)
{
	// body
}
else
{
	// body
}

//Example
if(grade > 50) 
	printf("passed");
else if(grade > 40)
	printf("passed with mercy");
else
	printf("failed");
```

***if....else :***
```C
//Syntax
if(condition)
{
	// body
}
else
{
	// body
}
```

***Nested if....else :***
```c
//Syntax
if(condition)
{
	// body
}
else
{
	if(condition)
	{
		// body
	}
	else
	{
		// body
	}
}
```

***Rules***
1. elseif, else are *Optional*
2. else should be appended to the if condition 
3. it is recommended not to use more than 3 stages when using nested if
4. { } is used for the readability 
	1. when using one statement in the body 
	2. but it is mandatory when having more than one statement 
5. use ( ) when u use more than on condition *cuz of Precedence*

***Dangling else problem :*** 
```c
if()
	if()
		printf();
else
	printf();
```
so the program doesn't know the else is connected to which if 
it is solution is using curly bracket 

***Tricky Codes***
```c
int x =5;
if(x == 4); // there is no statement to be executed 
x = x+2;
// x = 7

if(x = /*anynumber*/) 
// if the number != 0 then "true" else "false"

// compilation error
if(x==10)
{
	printf("lol\n");
}
x = 30;
else 
{
	printf("lmao\n");
}


int x = 10, y =0,z =30;
if(x && y && z++)
	printf("ok\n");
printf("Z = %d",z);
/*
Z = 30
*/
// but if Y != 0 Z would be 31
```