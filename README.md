# mac
A simple virtual machine for educational purposes. Made following [blog post](https://felixangell.com/blogs/virtual-machine-in-c).

## Instruction set
* PSH	; push to the stack
* ADD	; pop two values on top of the stack, adds them pushes to stack
* POP	; pops the value on the stack, will also print it for debugging
* SET	; set a value into a register
* HLT	; stop the program

## Test program

<p>PSH, 5,</p>
<p>PSH, 6,</p>
<p>ADD,</p>
<p>POP</p>
<p>HLT</p>

<br />

<p>The test program will push 5 and 6 to the stack, then add the two values 
and psuh the result back on the stack. The POP instruction will print the result
value for debugging purposes.</p>

# Running

## Requirements
    * CMAKE

<p>use 'make' to compile and run with './mac'</p>
