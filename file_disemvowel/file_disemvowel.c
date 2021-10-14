#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 1024

bool is_vowel(char c) {
    char *vowel = "aeiouAEIOU";
    int result = 0;
    for(int i=0; i<10; i++){
        if(c == vowel[i]){
            result = 1;
        }
    }
    return result;
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
    /*
     * Copy all the non-vowels from in_buf to out_buf.
     * num_chars indicates how many characters are in in_buf,
     * and this function should return the number of non-vowels that
     * that were copied over.
     */
    int counter = 0;
    for(int i = 0; i<num_chars; i++){
        if(is_vowel(in_buf[i]) == 0){
            out_buf[counter] = in_buf[i];
            counter++;
        }
    }
    return counter;
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
    /*
     * Copy all the non-vowels from inputFile to outputFile.
     * Create input and output buffers, and use fread() to repeatedly read
     * in a buffer of data, copy the nonstrlen(out_buf)-vowels to the output buffer, and
     * use fwrite to write that out.
     */

    char in_buf[BUF_SIZE];
    char out_buf[BUF_SIZE];
    while(!feof(inputFile)){
        int count = fread(in_buf, sizeof(char), BUF_SIZE, inputFile);
        int num = copy_non_vowels(count, in_buf, out_buf);
        fwrite(out_buf, sizeof(char), num, outputFile);
    }
}

int main(int argc, char *argv[]) {
    // This sets these to `stdin` and `stdout` by default.
    // You then need to set them to user specified files when the user
    // provides files names as command line arguments.
    FILE *inputFile = stdin;
    FILE *outputFile = stdout;

    // checks how many command line arguments there are,
    // if user gives two arguments takes input from file and
    // outputs to given file; if only one argument, reads from
    // that file and writes to stdout.
    if(argc == 3){
        inputFile = fopen(argv[1], "r");
        outputFile = fopen(argv[2], "w");
    }
    else if(argc == 2){
        inputFile = fopen(argv[1], "r");
    }

    // Code that processes the command line arguments
    // and sets up inputFile and outputFile.

    disemvowel(inputFile, outputFile);

    return 0;
}
