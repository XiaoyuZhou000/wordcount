/* Author: Xiaoyu Zhou
 * Date: 2022/2/4
 * UWNetID: xz081302
 * Homework 3
 * This c program will run a mini version of the unix command wc. 
 * This program will read in a file and report stats including the number of
 * lines and number of words in the file.
 * This program requires one or more input files.
 * This program has three flags, -l for calculating lines, -w for calculating words,
 * -c for calculating characters.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define T 1
#define F 0

// This function will print out the calculation result.
void output(char* flag, int lines, int words, int chars, char* filename) {
  if (strcmp(flag, "-l") == 0) {
    printf("%d\n", lines);
  } else if (strcmp(flag, "-w") == 0) {
    printf("%d\n", words);
  } else if (strcmp(flag, "-c") == 0) {
    printf("%d\n", chars);
  } else {
    printf("%d %d %d %s\n", lines, words, chars, filename);
  }
}

// This function will calculate the number of lines, words,
// and characters in given file.
int count(FILE *file, char *filename, char* flag) {
  int lines = 0, words = 0, chars = 1, spaces = F;
  char c = fgetc(file);
  while ((c = fgetc(file)) != EOF) {
    if (c == '\n' || c == '\0') {
        lines++;
    }
    if (c == '\n' || c == '\0' || c == '\t' || c == ' ') {
      if (spaces) {
        spaces = F;
        words++;
      }
    } else {
      spaces = T;
    }
    chars++;
  }
  output(flag, lines, words, chars, filename);
  return lines;
}

int main(int argc, char* argv[]) {
  int start;
  char *flag = argv[1];
  if (argv[1] == NULL) {
    fprintf(stderr, "Usage: ./wordcount requires an input file.\n");
    return EXIT_FAILURE;
  }
  if ( strcmp(flag, "-l") == 0 || strcmp(flag, "-w") == 0 ||
       strcmp(flag, "-c") == 0) {
    if (argc == 2) {
      fprintf(stderr, "Usage: ./wordcount requires an input file.\n");
      return EXIT_FAILURE;
    }
    start = 2;
  } else {
    if (argc == 1) {
      fprintf(stderr, "Usage: ./wordcount requires an input file.\n");
      return EXIT_FAILURE;
    }
    start = 1;
  }
  int liness = 0;
  for (int i = start; i < argc; i++) {
    FILE *file = fopen(argv[i], "r");
    if (file) {
      liness += count(file, argv[i], flag);
      fclose(file);
    } else {
      fprintf(stderr, "%s will not open.  Skipping  \n", argv[i]);
    }
  }
  if ((strcmp(argv[1], "-l") != 0) && (strcmp(argv[1], "-w") != 0) &&
      (strcmp(argv[1], "-c") != 0)) {
    printf("Total Lines = %d\n", liness);
  }
  return EXIT_SUCCESS;
}






