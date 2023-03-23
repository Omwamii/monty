**Monty Language**

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). 
It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

	.monty.h - Contains global variables, structs and the prototypes of all functions

	.main.c - Main function for the monty interpreter

** Usage **

The program using gcc with the flags -Wall -Werror -Wextra -pedantic -std=c89 

	gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
	
To run the interpreter run the executable *monty* with the bytecode file to be interpreted

	./monty bytecodes/0.m
	
Sample file : bytecodes/0.m

	push 0
	push 1
	push 2
  		push 3
        	           pall    
	push 4
    		 push 5    
    	  	push    6        
	pall

Output:
	
	3
	2
	1
	0
	6
	5
	4
	3
	2
	1
	0
