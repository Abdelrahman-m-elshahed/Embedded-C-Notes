***Computing system***
- processor
- memory 
- I/O
for all three components to communicate they use *Buses* ; data bus, address bus, Control bus 
so we have instructions stored in memory and used by microprocessor 
             
and here comes an important concept ***Languages of Microprocessor***
1. machine language  (0 , 1) stored on the memory
it is written in memory as a set of instructions 
each instruction has a specific format 

| 011 | 110 | 01  |
| --- | --- | --- |

so for the microprocessor to understand those instruction "Decode it" :
	instruction set 
	instruction format 

2. Assembly language
the assembler is what converts the assembly code into machine language 

but we faced 3 problems :
1. opcode depends on the microprocessor 
2. the assembly instruction defer from microprocessor to another 
3. some instructors are not understood by some microprocessor 

beside all of those problems, Writing a code in assembly is difficult 

it has some ***Advantages :***
1. Optimized --> size and execution time
2. no need for a compiler *you would just need the assembler*

all of those problems we faced with Assembly has been solved by *Programming languages*

***History of Programming Languages***
- "1960" with the First of all programming languages "ALGOL"
- "1967" --> BCPL started which stands for "Basic Combined Programming Language" and was made by "Martin Richards"
- "1970" was when "B" showed up and was made by "Ken Thompson"
	- B was based on BCPL + some features 
	- Disadvantage of "B" was that it's based on UNIX *it only works on UNIX operating systems*
- "1972" C language was made by Dennis Ritchie 
	- C is a combination of ALGOL + BCPL + B + features 
	- at first it only worked on "UNIX" but after it got popular many compilers were released for cross platform
- and after lots of developers started to use "C" as the base programming language and create a new language which made it necessary to establish some standards for programming languages 
- So ANSI *stands for American national standard institute* created (C89) at "1989"
	- (C89) was the standard and it was ratified by ISO at "1990" as ANSIC
	- and then other extensions was released "i need to search about it more" 

***why do we use C instead of assembly***
- C is easier 
- fast to develop
- simpler than assembly
- Portable "in case we change the platform"

***Why do we use C in ES***
- memory allocation 
	- you can access memory address directly *Thanks to pointers*
	- so you can access **Registers**
- portable code
- performance
- layout

***Building Process/Compilation process***
- `.c` file goes through *Tool Chain* so we can get `.exe` file
- Tool chain we deal with is "GCC" which stands to "GNU C Compiler''

***Tool Chain***
1. Native : it is the tool chain that runs on the same architecture 
	- Tool Chain installed on a microprocessor
	- and the output of the Tool Chain works on the same microprocessor 
2. Cross : runs on another architecture
	- Tool Chain installed on a microprocessor
	- and the output of the Tool Chain works on a different microprocessor 

Source file gets into "pre-processor" for pre-processing stage 
	it is a text replacement process and u will get a .i file 
.i file will get into the "compiler" producing the assembly file `.s` file
.s file goes into the "Assembler" so u get the object file `.o` file
object files + static libraries + linker script goes to linker so u can get .exe file
