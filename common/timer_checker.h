//
// Created by Sonse on 24.12.2023.
//

#ifndef C3_SIMPLEBASHUTILS_1_TIMER_CHECKER_H
#define C3_SIMPLEBASHUTILS_1_TIMER_CHECKER_H

#include "stdio.h"
#include "time.h"

void time_checker(void (*func)(char *, char *, char *), char* file, char* flag, char* pattern);

#endif //C3_SIMPLEBASHUTILS_1_TIMER_CHECKER_H
