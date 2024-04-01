#ifndef COURSE_WORK_2_INPUT_FROM_FILE_H
#define COURSE_WORK_2_INPUT_FROM_FILE_H

#include <iostream>
#include <fstream>
#include <string>
#include "struct_exam.h"

/**
 * @brief Ввести данные из файла
 * @param list_of_exams - список экзаменов
 * @param list_of_groups - список групп
 */
void enter_from_file(Exam **list_of_exams, Group **list_of_groups);

/**
 * @brief Сдвинуть курсор и пропустить пробелы
 * @param file - файловая переменная
 */
void move_cursor(ifstream &file);

/**
 * @brief Посчитать количество строк в файле
 * @param file - файловая переменная
 * @return количество строк
 */
int count_lines_in_file(ifstream &file);

#endif //COURSE_WORK_2_INPUT_FROM_FILE_H
