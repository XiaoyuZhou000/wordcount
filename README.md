In this assignment you will create your own version of the unix command wc. You will read in a file and report stats including the number of lines and number of words in the file. Your code should behave as follows:

- Compile with the command gcc -Wall -std=c11 -o wordcount wordcount.c

- Requires one or more input files.

  - If there are no input files, reports an error and exits with a (1) code.

  - Does not need to work with redirected input

  - If a file can not be opened an error message is printed that the file is skipped.

- For each input file calculate the number of lines, words, and characters

  - Can check against wc on any test file.

- Prints a message with the results and the file name, similar to wc

- Additionally prints the total number of lines for all files

- Proccesses a limited number of options - -l, -w, -c

  - If an option is detected the program will output only the number of lines, words, or characters

  - The program will additionally not print the total number of lines in all the files

  - The program shouldn't process more than one option. If more than one option is submitted the first one should be activated.

- Be able to handle input lines containing up to 500 characters (including the terminating \0 byte).
