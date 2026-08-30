*This project has been created as part of the 42 curriculum by lnovotny.*

# Description
The goal of this project is to create a get_next_line function (GNL) which is able to return the next line from the given input such as a text file or terminal. The purpose of the project is to learn about static variables.

# Instructions
The prototype of the get_next_line is: `char *get_next_line(int fd);`  
The function takes a file descriptor of the input we want to read from and returns a pointer to a null-terminated string that is a copy of the next line. This implementation of the get_next_line function is able to work with only one file descriptor at a time. The function cannot be used to read from another input if reading all lines from the previous input has not been finished.  

The repository includes `.tests` directory with its own Makefile to run the tests.  
`make` creates and runs the tests  
`make clean` deletes the tests

# Explanation of The Code

### The Basic Principles
`char *line` is a pointer to the next line that is being created and once the process is finished the line is returned.  
`static char *buff` is a pointer to the buffer that is used to store the read text.

The basic principles of how the GNL function works are as follows:  
The function first checks if there is something in the `buff` from a previous GNL function call and if no, the function reads a constant number of characters defined by the BUFFER_SIZE and saves them in the `buff`. 
1. If the `buff` **does not include** the `\n` character, the function adds the content of the `buff` to the end of the `line` and clears the `buff`.
	1. If it **is** the end of the text on the input, the function returns the `line`.  
	2. If it **is not** the end of the text on the input, the process is repeated.  
2. If the `buff` **includes** the `\n` character, the function adds all the content of the `buff`, up to the first `\n` character, to the end of the `line` and returns `line`. The `buff` is also cleared up to the first `\n` character, including the character itself.

### Return Values
`line`: correct behavior
`NULL`: there is nothing else to read, or an error occurred

### Description of The Steps
The following text describes the steps of `char *get_next_line(int fd)`.

Is `buff` `NULL`?  
1. Yes -> allocate memory for `buff` of BUFFER_SIZE and fill it with `\0` characters.  
2. No -> add the `buff` (or everything up to the first `\n` character in `buff`) to the end of `line`. If the `buff` is not empty, return `line`.  

As long as there is not any `\n` character in the `buff`, repeat these steps:
1. Add `buff` to the end of `line`.
2. Read into the `buff`.
3. If the bytes read are 0, we are at the end of the file. Return `line`.
4. If the bytes read are < 0, there was an error and return `NULL`.

Add the `buff` to the end of `line` for the last time.  
Return `line`.  

# Resources
The AI was used mainly for testing purposes and debugging.
