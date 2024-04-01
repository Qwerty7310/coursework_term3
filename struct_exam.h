#ifndef COURSE_WORK_2_STRUCT_EXAM_H
#define COURSE_WORK_2_STRUCT_EXAM_H

#include <iostream>
#include <fstream>
#include <limits>
#include <Windows.h>
#include <cstring>
#include <iomanip>
#include "regex.h"

//Вариант 2: Кольцевые односвязные списки
//Расписание экзаменационной сессии с числом экзаменов не более 5, группа, предмет, аудитория, время проведения консультации, время проведения экзамена, преподаватель

/*
 * 1. Контроль ввода повторяющихся полей из файла и вывод сообщения об этом
 * 2. Добавить/убрать system("pause")
 * 3. Сделать меню более красивым
 * 4. Ввод пути файла через cin
 * 5. Добавить комментарии
 * 6. Разделить functions на несколько файлов
 */

using namespace std;

const int ARRAY_SIZE = 71;

struct Exam
{
    char group[ARRAY_SIZE] = {};
    char subject[ARRAY_SIZE] = {};
    char lecturer[ARRAY_SIZE] = {};
    char classroom[ARRAY_SIZE] = {};
    char consultation_day[ARRAY_SIZE] = {};
    char consultation_time[ARRAY_SIZE] = {};
    char exam_day[ARRAY_SIZE] = {};
    char exam_time[ARRAY_SIZE] = {};
    Exam *next = nullptr;
};

struct Group
{
    char name_of_group[ARRAY_SIZE] = {};
    int number_of_exams = 0;
    Group *next = nullptr;
};

/**
 * @brief Добавление нового экзамена в список
 * @param list_of_exams - список экзаменов
 * @param new_exam - добавляемый экзамен
 */
void add_exam(Exam **list_of_exams, Exam *new_exam);

/**
 * @brief Удаление экзамена из списка
 * @param list_of_exams - список экзаменов
 * @param exam - удаляемый экзамен
 * @param list_of_group - список групп
 * @param question - список групп
 */
void delete_exam(Exam **list_of_exams, Exam **exam, Group **list_of_group, bool question = true);

/**
 * @brief Добавление новой группы в список
 * @param list_of_groups - список групп
 * @param new_group - название добавляемой группы
 * @return адрес узла добавленной группы
 */
Group* add_group(Group **list_of_groups, char new_group[]);

/**
 * @brief Удалить группу из списка групп
 * @param list_of_groups  - список групп
 * @param group - удаляемая группа
 */
void delete_group(Group **list_of_groups, Group **group);

/**
 * @brief Найти экзамен
 * @param list_of_exams - список экзаменов
 * @param group - название группы
 * @param subject - название предмета
 * @return адрес нужного узла
 */
Exam* search_exam(Exam **list_of_exams, char group[], char subject[]);

/**
 * @brief Найти группу
 * @param list_of_groups - список групп
 * @param group -искомая группа
 * @return адрес нужного узла
 */
Group* search_group(Group *list_of_groups, char group[]);

/**
 * @brief Удаление Базы данных
 * @param list_of_exams - список экзаменов
 * @param list_of_groups - список групп
 */
void delete_list(Exam **list_of_exams, Group **list_of_groups);

/**
 * @brief Получить длину строки
 * @param str - строка
 * @return Длина строки
 */
int get_length(char *str);

#endif //COURSE_WORK_2_STRUCT_EXAM_H
