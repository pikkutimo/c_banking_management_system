#include "bms_utils.h"

time_t create_timestamp(int year, int month, int weekday, int hour, int min, int sec, int isdst) {
    struct tm str_time;
    str_time.tm_year = year - 1900;
    str_time.tm_mon = month; // Starts from 0 ?
    str_time.tm_mday = weekday;
    str_time.tm_hour = hour;
    str_time.tm_min = min;
    str_time.tm_sec = sec;
    str_time.tm_isdst = isdst;

    return mktime(&str_time);
}

void write_to_file(char * filename, ...) {
    // variadic function
    // 1. parameter is the filename
    // 2. parameter is the pointer to a struct pointer
    //

    printf("Not implemented yet.\n");
}