Simple and thoroughly commented shell written in C, just for educative purposes. Created by Francis Kimani and Peter Njoroge as part of an exercise in ALX SE PROGRAMME . .This is an ALX collaboration project on Shell. We were tasked to create a simple shell that mimics the Bash shell.

Our shell shall be called hsh.

Introduction This repository is a ALX Holberton School Project. The school project consisted in writing a shell like sh (Bourne Shell) by Stephen Bourne , in C, using a limited number of standard library functions, so instead we used our own function that we rewrited over the past three month Here.

The goal in this project is to make us understand how a shell works.

To single out some core topics which includes; What is the environment? The difference between functions and system calls. How to create processes using execve... General Requirements

README file, at the root of the folder of the project is mandatory. Allowed editors: vi, vim, emacs Compiler; Ubuntu 20.04 LTS using gcc. Using the options -Wall -Werror -Wextra -pedantic -std=gnu89 Coding style; Betty Style. Shell should not have any memory leaks. No more than 5 functions per file. All header files should be include guarded. How hsh works Prints a prompt and waits for a command from the user. Creates a child process in which the command is checked. Checks for built-ins, aliases in the PATH, and local executable programs. The child process is replaced by the command, which accepts arguments. When the command is done, the program returns to the parent process and prints the prompt. The program is ready to receive a new command. To exit: press Ctrl-D or enter "exit" (with or without a status). Works also in non interactive mode. Usage In order to run this program includes:
