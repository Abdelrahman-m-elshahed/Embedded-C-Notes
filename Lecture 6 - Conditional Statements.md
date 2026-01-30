### 2. Switch 
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
### 3. Ternary Operator

```c
// syntax
ID = (test_expression) ? (true_expression) : (false_expression);

// example
z = (y > x) ? 5 : 10; // if (y > x) then z = 5, if y =< x then z = 10
```