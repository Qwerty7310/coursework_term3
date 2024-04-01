#include "regex.h"

bool check_group(char group[])
{
    return regex_match(group, regex(regex_group));
}

bool check_subject(char subject[])
{
    return regex_match(subject, regex(regex_subject));
}

bool check_lecturer(char lectures[])
{
    return regex_match(lectures, regex(regex_lecturer));
}

bool check_classroom(char classroom[])
{
    return regex_match(classroom, regex(regex_classroom));
}

bool check_day(char day[])
{
    return regex_match(day, regex(regex_day));
}

bool check_time(char time[])
{
    return regex_match(time, regex(regex_time));
}

bool check_file(char file[])
{
    return regex_match(file, regex(regex_file));
}