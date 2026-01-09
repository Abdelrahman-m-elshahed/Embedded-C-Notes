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
