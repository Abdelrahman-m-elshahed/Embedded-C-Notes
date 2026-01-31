### Switch 
```C
// Syntax
switch(expression) // expression is what i am checking
{
	case conmt_expresssion:
		// body
		break; 
		
	default : // it executes when there is no match to the expression
		// body
		break; // optional 
}
```

***Rules***
1. const_ecpression 
	- must be unique 
	- it can't be a variable *bruh, it's called const*
	- must be integral value *Not float* or enumerated type
2. default
	- only one default is allowed 
	- it is optional 
	- can be placed anywhere in the switch
3. Break statement 
	- it is what ends the switch so the code would run till it encounter the break statement 
4. Nesting is allowed 

***Hint***
1. if two cases have the same body? 
	1. you can make them one
```C
case 'A': // the code doesn't encounter a break so it would execute the other case
case 'B':
	// body
	berak;
```

2. what if it was a Range? 
```C
// example if you wanna check if the letter are lower or uppaer case
switch (x)
{
	case 'a'...'z': // char works because we check its ASCII value
		// body
		break;
	case 'A'...'Z':
		// body
		break;
}
```


|                    | if              | switch               | Cause                                                                                                                                                                                      |
| ------------------ | --------------- | -------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Speed              | slowwe          | faster               | when using if condition you would need go through it all till  u find a match, but switch is more like a lookup table and each case points to its body so it has fixed time for all cases. |
| memory             | less consumtion | consumes more memory | lookup table created by the switch case consumes memory                                                                                                                                    |
| complex conditions | supports it     | doesn't support it   | switch case only support constant expressions                                                                                                                                              |
### Ternary Operator

```c
// syntax
ID = (test_expression) ? (true_expression) : (false_expression);

// example
z = (y > x) ? 5 : 10; // if (y > x) then z = 5, if y =< x then z = 10
```

## 2. Loops
### for loop
it is used for specific iterations *so it is the bets choice if the loop is counting up or down*

```c
// syntax
for(/*initialization*/ ; /*condition*/ ; /*increment/decrement*/)
{
	// body
}

```


- Optional 
	1. Initialization
	2. C condition 
		- C assume it as True *Infinite Loop*
	3. Increment expression
		- it can be coded in the body
- Mandatory
	1. semicolon 
![[Stage diagram (for loop).png]]

```c
for(); // then there is no body

// Example
unsigned char i = 0;
for(; i <=5;++i); // will break out of it when i = 6
printf("Coutner = %d",i); // Counter = 6
```

***Hint***
1. avoid using floating numbers as a terminator 
2. we may use for loop with multiple of variables *using comma operator*
```c
for(int i = 0, j =1 ; i < j ;++i,++j)
```
3. Nested for loop is allowed  
### while loop
```c
// Syntax
while(condition)
{
	//body 
}
```
***Rules***
1. Condition should reach *False*
	- if not then it is *infinite loop*
	- Or the body should contain a break statement to terminate the loop
2. Nested while loops are allowed
### do-while loop
```c
// syntax
do {
	// body
}while(condition);

// Examples

int counter = 1;
do{
	printf("%d\n",counter);
	counter++;
}while(counter <= 10);
```

## Jump Statement 
***Break :*** it terminates the switch case or break out of the loops
```c
for(int i = 0; i <= 5;++i) // or any other types of loops
{
	if(condition)
		break; 
}
```
***Continue :*** it skips the current iteration 
```c
for(int i = 0 i <= 5;++i)
{
	if(condiiton)
		continue; // it skips this iteration 
}
```
***goto :*** you would need to add a label that points to that line 
and then use it like this `goto label;`
