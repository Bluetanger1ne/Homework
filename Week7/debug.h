#ifndef HOMEWORK_DEBUG_H
#define HOMEWORK_DEBUG_H

#define MAX_AMT 4
#define MAX_LEN 40

void set_debug_level(int debug_level);
int dprintf(int debug_level,const char *fmt,...);
void clear_input_buffer();

#endif //HOMEWORK_DEBUG_H