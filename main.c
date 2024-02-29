#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    #if SHOW_USER == 1
    printf("\e[31muser%s\e[0m   %s\n", SPACER, getenv("USER"));
    #endif

    #if SHOW_OS == 1
    FILE* osRelease = fopen("/etc/os-release", "r");
    char osName[64];
    char currentLine[64];
    while(fgets(currentLine, sizeof(currentLine), osRelease) != NULL) {
        if (!strncmp(currentLine, "ID=", 3)) {
            for (unsigned short i = 4; i < sizeof(currentLine); i++) {
                if (currentLine[i] == '"') {
                    osName[i - 4] = '\0';
                    break;
                }
                osName[i - 4] = currentLine[i];
            }
            break;
        }
    }

    printf("\e[32mos%s\e[0m     %s\n", SPACER, osName);
    #endif

    #if SHOW_WM == 1
    printf("\e[33mwm%s\e[0m     %s\n", SPACER, getenv("XDG_CURRENT_DESKTOP"));
    #endif

    #if SHOW_SHELL == 1
    const char* shell = getenv("SHELL");
    unsigned short shellName = 0;
    unsigned short shellLength = strlen(shell);
    for (unsigned short i = 0; i < shellLength; i++) {
        if (shell[i] == '/') shellName = i + 1;
    }
    printf("\e[34mshell%s\e[0m  %s\n", SPACER, shell + shellName);
    #endif

    #if SHOW_TERM == 1
    printf("\e[35mterm%s\e[0m   %s\n", SPACER, getenv("TERM"));
    #endif

    #if SHOW_COLOURS == 1
    printf("\e[36mcolours%s\e[41m%s\e[42m%s\e[43m%s\e[44m%s\e[45m%s\e[46m%s\e[0m\n", SPACER, COLOUR_BLOCK, COLOUR_BLOCK, COLOUR_BLOCK, COLOUR_BLOCK, COLOUR_BLOCK, COLOUR_BLOCK);
    #endif

    return 0;
}