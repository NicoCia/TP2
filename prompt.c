#include "prompt.h"
#include "echo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ANSI_NORMAL     "\x1b[0m"
#define ANSI_NEGRITA     "\x1b[1m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_GREEN_E   "\x1b[92m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_CYAN_H    "\x1b[96m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define HOME getenv("HOME")

void printPrompt(void) {
    //TODO ver reemplazar /home/USERNAME por ~
    char prompt[100]="\0";
    char hostname[100]="\0";

    char dir[100]="\0";

    getcwd(dir, sizeof(dir));
    cortar(dir,HOME);

    strcpy(prompt,getenv("USER"));
    strcat(prompt, "@");
    FILE *fp;
    size_t bytes_read;
    fp=fopen("/proc/sys/kernel/hostname","r");
    bytes_read=fread(hostname, 1, sizeof(hostname), fp);
    fclose(fp);
    hostname[bytes_read - 1]='\0';
    strcat(prompt, hostname);

    printf(ANSI_COLOR_GREEN_E ANSI_NEGRITA  "%s" ANSI_NORMAL   ANSI_COLOR_RESET ":",prompt);
    printf(ANSI_COLOR_CYAN_H ANSI_NEGRITA  "%s" ANSI_NORMAL   ANSI_COLOR_RESET "$ ",dir);
    return;
}