#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <time.h>

#define TO_STR(x) #x
#define STR(x) TO_STR(x)

#define LOG_PRINT(fmt, ...) \
    do { \
        time_t t = time(NULL); \
        struct tm *m = localtime(&t); \
        printf("[%.2d:%.2d:%.2d] " \
               "[\e[32m" __FILE__ "\e[0m:\e[36m" STR(__LINE__) "\e[0m] " \
               fmt "\n", \
               m->tm_hour, m->tm_min, m->tm_sec, \
               ##__VA_ARGS__); \
    } while (0)

#ifndef NDEBUG
#define LOG_DEBUG(fmt, ...) \
    do { \
        time_t t = time(NULL); \
        struct tm *m = localtime(&t); \
        printf("[%.2d:%.2d:%.2d] " \
               "[\e[32m" __FILE__ "\e[0m:\e[36m" STR(__LINE__) "\e[0m " \
               "\e[35mDEBUG\e[0m] " \
               fmt "\n", \
               m->tm_hour, m->tm_min, m->tm_sec, \
               ##__VA_ARGS__); \
    } while (0)
#else
#define LOG_DEBUG(fmt, ...)
#endif

#define LOG_WARN(fmt, ...) \
    do { \
        time_t t = time(NULL); \
        struct tm *m = localtime(&t); \
        printf("[%.2d:%.2d:%.2d] " \
               "[\e[32m" __FILE__ "\e[0m:\e[36m" STR(__LINE__) "\e[0m " \
               "\e[33mWARN\e[0m] " \
               fmt "\n", \
               m->tm_hour, m->tm_min, m->tm_sec, \
               ##__VA_ARGS__); \
    } while (0)

#define LOG_ERROR(fmt, ...) \
    do { \
        time_t t = time(NULL); \
        struct tm *m = localtime(&t); \
        printf("[%.2d:%.2d:%.2d] " \
               "[\e[32m" __FILE__ "\e[0m:\e[36m" STR(__LINE__) "\e[0m " \
               "\e[31mERROR\e[0m] " \
               fmt "\n", \
               m->tm_hour, m->tm_min, m->tm_sec, \
               ##__VA_ARGS__); \
    } while (0)

#endif // LOG_H
