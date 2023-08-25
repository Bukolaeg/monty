Monty 0.98 represents a scripting language that undergoes an initial compilation phase into Monty byte codes, a concept akin to Python. It operates with a distinctive stack structure, featuring explicit instructions for stack manipulation. The primary objective of this project revolves around crafting an interpreter tailored to Monty ByteCodes files.

Monty Byte Code Files
Typically denoted with a .m extension, Monty byte code files conform to an industry-wide standard, although adherence to this convention isn't mandated by the language specification. Each line contains a solitary instruction. Flexibility is granted regarding the number of spaces preceding or following the opcode and its accompanying argument:
 push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
Within Monty byte code files, inclusion of empty lines or lines composed solely of spaces is permissible. Additional text following the opcode or its requisite argument holds no significance:
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
Utilization
Compilation of all files adheres to the structure below:
 gcc -Wall -Werror -Wextra -pedantic *.c -o monty.
To execute the program:
 ./monty bytecode_file
Operation codes at your disposal:

Opcode	Description
push	Appends an element to the stack. For instance, (push 1 # adds 1 to the stack)
pall	Displays all stack values, starting from the top.
pint	Prints the value at the stack's top.
pop	Eliminates the top stack element.
swap	Exchanges the top two stack elements.
add	Adds the top two stack elements; outcome replaces second node, and first node is removed.
nop	No operation; opcode has no effect.
sub	Subtracts second top element from top two elements; result replaces second node, and first node is removed.
div	Divides second top element by top two elements; result replaces second node, and first node is removed.
mul	Multiplies second top element by top two elements; result replaces second node, and first node is removed.
mod	Calculates remainder of second top element divided by top two elements; result replaces second node, and first node is removed.
#	Lines starting with a # are treated as comments.
pchar	Prints integer atop stack as ASCII character.
pstr	Prints integers stored in stack as ASCII characters until 0, end of stack, or non-ASCII value is encountered.
rotl	Rotates stack top element to bottom.
rotr	Rotates stack bottom element to top.
stack	Default behavior; maintains data as stack (LIFO).
queue	Alters data format to queue (FIFO).
