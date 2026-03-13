#include "debug.h"
#include <stdio.h>
#include <stdarg.h>
// Static debug_level accessible to only these two functions
static int current_debug_level = 0;


void set_debug_level(int debug_level) { // Set the current debug level based on input
    current_debug_level = debug_level;
}

int dprintf(int debug_level,const char *fmt,...) { // print statements according to criteria
    if (debug_level <= current_debug_level) {
        fprintf(stderr, "[DBG%d] ", debug_level);
        va_list args;
        va_start(args, fmt);
        vfprintf(stderr, fmt, args);
        va_end(args);
    }
    return 0;
}