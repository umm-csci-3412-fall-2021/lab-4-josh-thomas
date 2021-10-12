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
    char *out_buf;
    char *buffer[1024];

    //FILE * stream = fopen(inputFile, "r");
    int count = fread(&buffer, sizeof(char), sizeof(inputFile), inputFile);
    //fclose(stream);
    out_buf = calloc(sizeof(char), count);
    int num = copy_non_vowels(count, buffer, out_buf);
    fwrite(out_buf, sizeof(char), num, outputFile);
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
    if(argc == 2){
        inputFile = argv[1];
        outputFile = argv[2];
    }
    else if(argc == 1){
        inputFile = argv[1];
    }

    // Code that processes the command line arguments
    // and sets up inputFile and outputFile.

    disemvowel(inputFile, outputFile);

    return 0;
}
