#ifndef COURSE_WORK_2_INPUT_FROM_KEYBOARD_H
#define COURSE_WORK_2_INPUT_FROM_KEYBOARD_H

#include "struct_exam.h"

/**
 * @brief Ввести данные с клавиатуры
 * @param list_of_exams - список экзаменов
 * @param list_of_groups - список групп
 */
void enter_from_keyboard(Exam **list_of_exams, Group **list_of_groups);

/**
 * @brief Ввести информационное поле структуры экзамена
 * @param list_of_exams - список экзаменов
 * @param new_exam - новый экзамен
 * @param field - вводимое текстовое поле
 * @param verification - функция проверки
 * @param message - сообщение для пользователя
 * @return результат ввода
 */
bool enter_field(Exam **list_of_exams, Exam *new_exam, char *field, bool(*verification)(char *), char *message);

/**
 * @brief Изменить данные об экзамене
 * @param list_of_exams - список экзаменов
 * @param list_of_groups - список групп
 */
void change_data(Exam **list_of_exams, Group **list_of_groups);

/**
 * @brief Переписать текстовое поле структуры экзамена
 * @param field - текстовое поле
 * @param message - сообщение для пользователя
 * @param check_field - функция проверки поля
 */
void change_field(char *field, char *message, bool(*check_field)(char *));

/**
 * @brief Вывод меню для пользователя
 */
void show_menu();


#endif //COURSE_WORK_2_INPUT_FROM_KEYBOARD_H
