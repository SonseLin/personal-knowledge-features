//
// Created by Sonse on 24.12.2023.
//

// used as benchmark for grep processing

#include "timer_checker.h"

void time_checker(void (*func)(char *, char *, char *), char* file, char* flag, char* pattern) {
    clock_t start = clock();
    func(file, flag, pattern);
    printf("%lu ms for flag '%s' with file '%s'\n", clock() - start, flag, file);
}
