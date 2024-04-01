#ifndef COURSE_WORK_2_REGEX_H
#define COURSE_WORK_2_REGEX_H

#include <regex>
using namespace std;

const char regex_group[] = "å([1-9]|1[0-4])[éá]-[1-6][0-9][0-9](Å™|Å)-[2-9][0-9]";
const char regex_subject[] = "([†-ÔÄ-ü _-]+)";
const char regex_lecturer[] = "[Ä-ü][†-Ô]+( |_)[Ä-ü]( |_)[Ä-ü]";
const char regex_classroom[] = "[0-9†-ÔÄ-ü_ ]+-[0-9†-ÔÄ-ü_ ]+";
const char regex_day[] = "((0[1-9]|[12][0-9]|3[01]).(0[13-9]|1[0-2]).20[0-9][0-9])|((0[1-9]|1[0-9]|2[0-8]).02.20([02468][1235679]|[13579][01345789]))|((0[1-9]|1[0-9]|2[0-9]).02.20([02468][048]|[1357][26]))";
const char regex_time[] = "([01][0-9]|2[0-3]):[0-5][0-9]";
const char regex_file[] = "[A-Za-z0-9_]+.txt";

bool check_group(char []);
bool check_subject(char []);
bool check_lecturer(char []);
bool check_classroom(char []);
bool check_day(char []);
bool check_time(char []);
bool check_file(char []);

#endif //COURSE_WORK_2_REGEX_H
