# C - Simple Shell project:
Holberton school Toulouse | C19

## 📝DESCRIPTION:

Write a UNIX command line interpreter.

What is a shell in computing ?
Shell is the command line interpreter, it allows a user to identify himself on a console or terminal. It provides a number of commands to interact with the operating system.

## 📝PROTOTYPE:

![image](https://zupimages.net/up/22/49/5mj8.png)

## 📜Task 0:

| description        |   Write a README, AUTHORS and  MAN.                                                       |
| ----------------- | ------------------------------------------------------------------ |
|README| description of the our project.
|AUTHORS| contributors (view file).
|MAN| shell description.

## 📜Task 1:
| description        |  Write beautiful code that passes with Betty checks.   
| ----------------- | ------------------------------------------------------------------ |
|| check that your code is no problem with Betty.

## 📜Task 2:

|   description     |  Write a UNIX command line interpreter.                                                              |
| ----------------- | ------------------------------------------------------------------ |
| Your Shell should | Display a prompt and wait for the user to type a command. A command line always ends with a new line.  |
|| The prompt is displayed again each time a command has been executed.
|| The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
|| The command lines are made only of one word. No arguments will be passed to programs.
|| If an executable cannot be found, print an error message and display the prompt again.
|| Handle errors.
|| You have to handle the “end of file” condition `(Ctrl+D)`.

## 📜Task 3:
|   description     |  Simple shell 0.1 +                                                                    |
| ----------------- | ------------------------------------------------------------------ |
|| Handle command lines with arguments.

## 📜Task 4:

| description           |  Simple shell 0.2 +                                                           |
| ----------------- | ------------------------------------------------------------------ |
|| Handle the `PATH`
|| `fork` must not be called if the command doesn’t exist

## 📜Task 5:

| description           |  Simple shell 0.3 +                                                               |
| ----------------- | ------------------------------------------------------------------ |
|| Implement the `exit` built-in, that exits the shell
|| Usage: `exit`
|| You don’t have to handle any argument to the built-in `exit`

## 📜Task 6:

| description           |  Simple shell 0.4 +                                                            |
| ----------------- | ------------------------------------------------------------------ |
|| Implement the `env` **built-in**, that prints the current environment


## 📝Files description:

| files names             | description                                                                |
| ----------------- | ------------------------------------------------------------------ |
|token_creator.c| Analyse each commands from the buffer.
|execute_funk.c| Execute the command that are analysed by the token_creator function.
|getpath.c| retrieve the path and it concatenate the command to the path.
|main.c| it's a main.
|shell.h| it's a file containing the prototypes of all the function.

#### 📃EXAMPLES IN INTERACTIVE MODE:
In a script / program:  

`$ ./hsh`  
`($) /bin/ls`  
`hsh main.c shell.c`  
`($)`  
`($) exit`    
`$` 

#### 📃EXAMPLES IN NON INTERACTIVE MODE:
In a script / program:  

`$ echo "/bin/ls" | ./hsh`  
`hsh main.c shell.c test_ls_2`  
`$`  
`$ cat test_ls_2`  
`/bin/ls`  
`/bin/ls`  
`$`  
`$ cat test_ls_2 | ./hsh`  
`hsh main.c shell.c test_ls_2`  
`hsh main.c shell.c test_ls_2`  
`$`  

#### 📃COMPILATION:
compile:
`gcc -Wall -Werror -Wextra -pedantic *.c -o nameofthescript`  
execution: `./nameofthescript`
 
## 📖MAN PAGE:
execution: `man ./man_1_simple_shell`

![image](https://zupimages.net/up/22/49/2auu.png)

## 🗓ORGANISATION:

- TRELLO :  
  https://trello.com/b/bWNX1UKm/shell

- Diagrams link:  
  https://app.diagrams.net/#G1MGgbXYgmWPvQRQCVN_7jR_iI9OMvLKGT

### ✍ AUTHORS: 
🔸Marine Dehaye
[![linkedin](https://img.shields.io/badge/linkedin-white?style=for-the-badge&logo=linkedin&logoColor=black)](https://www.linkedin.com/in/marine-dehaye-9a5b39127/?originalSubdomain=fr)

🔸Mohamad Al Annan 
[![linkedin](https://img.shields.io/badge/linkedin-white?style=for-the-badge&logo=linkedin&logoColor=black)](https://www.linkedin.com/in/mohamad-al-annan-325b0776/?originalSubdomain=lb)

🔸Pauline Parmigiani
[![linkedin](https://img.shields.io/badge/linkedin-white?style=for-the-badge&logo=linkedin&logoColor=black)](https://www.linkedin.com/in/pauline-parmigiani-36384017b/?originalSubdomain=fr)

### 🎓 SCHOOL:
Holberton School - TOULOUSE
C19 cohort
