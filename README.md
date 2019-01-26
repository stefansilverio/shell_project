# 0x15. C - Simple Shell
## Description

In this project, we created a	simple UNIX command line interpreter called "sash". Sash prints a command prompt and waits for the user to type a command and press enter. This intepreter can handle standard commands and user-created executables as well as some builtin functions.

**Entry Functions**

File | Function | Description
-----|-----|----
main_sash.c | main_sash | Tests interactivity of sash shell
enter_sash.c | enter_sash | Enter interactive mode of sash shell
enter_nonsash.c | enter_nonsash.c | Enter noninteractive mode of sash shell

**Essential Functions**

File | Function	| Description
-----|-----|----
read_command.c | read_line | Reads the line entered into standard input and stores it in a buffer
split_line.c | split_line | Splits the line entered into standard input into a 2D array of strings
get_path.c | get_path | gets the PATH from the environment
tokenize.c | tokenize_path | Splits the PATH into individual directories
find_dir.c | find_dir | Finds the directory an executable is in and concatenates the command with the directory
execute.c | _execute | Executes non-builtin commands

**Builtin Functions**

File | Function | Description
-----|-----|----
builtins.c | run_builtin | Looks for the right builtin function and executes it
_env.c | _env | Prints the current environment
exit.c | exit_sash | Exits the Sash shell
chdir.c | _chdir | Changes the working directory 

**String Manipulation/Counting Functions**

File | Function | Description
-----|-----|-----
doubleptr_len | doubleptr_len | Counts the number of strings in a 2D array
str_cmp.c | str_cmp | Compares two strings and returns 0 if they are identical
str_len.c | str_len | Counts the length of a string and returns the length
str_str.c | str_str | Finds a substring in a string and returns that substring
str_cat.c | str_cat | Concatenates two strings together

**Memory Allocation and Free Functions**

File | Function | Description
-----|-----|-----
double_ptr_list.c | double_ptr_list | Stores all allocated double pointers in a linked list
single_ptr_list.c | single_ptr_list | Stores all allocated pointers in a linked list
free_double_list.c | free_double_list | Frees all double pointers stored in linked list
free_single_list.c | free_single_list | Frees all single pointers stored in linked list

**Non-Function Files**

File | Description
-----|-----
sash.h | Header file containing all prototype functions and structs used in this project
man_1_simple_shell | man page for our program
AUTHORS | Lists individuals who contributed to this repository

## Examples
```
$ ls -l file.c
-rw-rw-r-- vagrant vagrant 501 Nov 16 01:06 file.c
```
Entering `ls -l` file.txt will display the permissions and details of file.c

```
$ echo hi
hi
```
Entering `echo hi` will print `hi` to the standard output

```
echo "ls -l" | ./sash
-rw-rw-r-- vagrant vagrant 501 Nov 16 01:06 file.c
````
Piping echo "ls -l" into ./sash (non-interactive mode) will print the same output as entering "ls -l" in interactive mode

## Authors
`Stefan Silverio & Allison Weiner`