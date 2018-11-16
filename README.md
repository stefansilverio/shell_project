# 0x15. C - Simple Shell
## Description

In this project, we created a	simple UNIX command line interpreter called "sash". Sash prints a command prompt and waits for the user to type a command and press enter. This intepreter can handle standard commands and user-created executables as well as some builtin functions.

File | Function | Purpose
-----|-----|----
sash.h | No function | Header file containing all prototype functions and structs used in this project
sash.c | main | The main/driver function of our program that prints our command prompt and waits for a command to be entered
builtins.c | run_builtin | Looks for the right builtin function and executes it
chdir.c | _chdir | Changes the working directory 
doubleptr_len | doubleptr_len | Counts the number of strings in a 2D array
_env.c | _env | Prints the current environment
execute.c | _execute | Executes non-builtin commands
exit.c | exit_sash | Exits the Sash shell
find_dir.c | find_dir | Finds the directory an executable is in and concatenates the command with the directory
get_path.c | get_path | gets the PATH from the environment
read_command.c | read_line | Reads the line entered into standard input and stores it in a buffer
split_line.c | split_line | Splits the line entered into standard input into a 2D array of strings
str_cmp.c | str_cmp | Compares two strings and returns 0 if they are identical
str_len.c | str_len | Counts the length of a string and returns the length
tokenize.c | tokenize_path | Splits the PATH into individual directories
man_shell | none | man page for our program

Builtin Command | Description | Prototype Function
-----|-----|-----
exit | Exits the shell | exit_sash
env | Prints the current environment | _env
cd | Changes the working directory | _chdir

##Examples
```
$ ls -l file.c
-rw-rw-r-- vagrant vagrant 501 Nov 16 01:06 file.c`
```
Entering `ls -l` file.txt will display the permissions and details of file.c

```
$ echo hi
hi
```
Entering `echo hi` will print `hi` to the standard output

**Authors/Collaborators**
: Stefan Silverio & Allison Weiner
