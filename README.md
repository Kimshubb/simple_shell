Simple and thoroughly commented shell written in C, just for educative purposes. Created by Francis Kimani and Peter Njoroge as part of an exercise in ALX SE PROGRAMME . .This is an ALX collaboration project on Shell. We were tasked to create a simple shell that mimics the Bash shell.

Our shell shall be called hsh.

Introduction This repository is a ALX Holberton School Project. The school project consisted in writing a shell like sh (Bourne Shell) by Stephen Bourne , in C, using a limited number of standard library functions, so instead we used our own function that we rewrited over the past three month Here.

The goal in this project is to make us understand how a shell works.

To single out some core topics which includes; What is the environment? The difference between functions and system calls. How to create processes using execve... General Requirements

README file, at the root of the folder of the project is mandatory. Allowed editors: vi, vim, emacs Compiler; Ubuntu 20.04 LTS using gcc. Using the options -Wall -Werror -Wextra -pedantic -std=gnu89 Coding style; Betty Style. Shell should not have any memory leaks. No more than 5 functions per file. All header files should be include guarded. How hsh works Prints a prompt and waits for a command from the user. Creates a child process in which the command is checked. Checks for built-ins, aliases in the PATH, and local executable programs. The child process is replaced by the command, which accepts arguments. When the command is done, the program returns to the parent process and prints the prompt. The program is ready to receive a new command. To exit: press Ctrl-D or enter "exit" (with or without a status). Works also in non interactive mode. Usage In order to run this program includes:
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
Your shell should not have any memory leaks
No more than 5 functions per file
All your header files should be include guarded
Use system calls only when you need to (why?)
Write a README with the description of your project
You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Dockerless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below)
Example of error with sh:

$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
Same error with your program hsh:

$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$

List of allowed functions and system calls
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)
Compilation
Your shell will be compiled this way:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
Testing
Your shell should work like this in interactive mode:

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
But also in non-interactive mode:

$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
