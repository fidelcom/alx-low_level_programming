n.o school.o
gcc    -c -o main.o main.c
gcc    -c -o school.o school.c
gcc main.o school.o -o school
julien@ubuntu:~/0x1C. Makefiles$ 
Repo:

GitHub repository: alx-low_level_programming
Directory: 0x1C-makefiles
File: 3-Makefile
   
4. A complete Makefile
mandatory
Requirements:

name of the executable: school
rules: all, clean, fclean, oclean, re
all: builds your executable
cleanAME: the name of the executable
RM: the program to delete files
CFLAGS: your favorite compiler flags: -Wall -Werror -Wextra -pedantic
The all rule should recompile only the updated source files
The clean, oclean, fclean, re rules should never fail
You are not allowed to have a list of all the .o files
You have to use $(RM) for the cleaning up rules, 
