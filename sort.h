#ifndef COURSE_WORK_2_SORT_H
#define COURSE_WORK_2_SORT_H

#include "struct_exam.h"
#include "print_DB.h"

/**
 * @brief Меню сортировки
 * @param list_of_exams
 */
void sorting_menu(Exam **list_of_exams);

/**
 * @brief Сортировка списка
 * @param list_of_exams - список экзаменов
 * @param comparison_function - функция сравнения
 */
void selection_sort(Exam **list_of_exams, int(*comparison_function)(Exam *, Exam *));

void shell_sort(Exam **list_of_exams, int(*comparison_function)(Exam *, Exam *));

/*
 * 0 - равны
 * 1 - str1 > str 2
 * -1 - str1 < str2
 */

/**
 * @brief Сравнить номера групп
 * @param ptr_to_exam1 - указатель на первый экзамен
 * @param ptr_to_exam2 - указатель на второй экзамен
 * @return 0 - равны, 1 - ptr_to_exam1 > ptr_to_exam2, -1 - ptr_to_exam1 < ptr_to_exam2
 */
int compare_groups(Exam *ptr_to_exam1, Exam *ptr_to_exam2);

/**
 * @brief Сравнить названия предметов
 * @param ptr_to_exam1 - указатель на первый экзамен
 * @param ptr_to_exam2 - указатель на второй экзамен
 * @return 0 - равны, 1 - ptr_to_exam1 > ptr_to_exam2, -1 - ptr_to_exam1 < ptr_to_exam2
 */
int compare_subjects(Exam *ptr_to_exam1, Exam *ptr_to_exam2);

/**
 * @brief сравнить имена преподавателей
 * @param ptr_to_exam1 - указатель на первый экзамен
 * @param ptr_to_exam2 - указатель на второй экзамен
 * @return 0 - равны, 1 - ptr_to_exam1 > ptr_to_exam2, -1 - ptr_to_exam1 < ptr_to_exam2
 */
int compare_lecturers(Exam *ptr_to_exam1, Exam *ptr_to_exam2);

/**
 * @brief сравнить номера аудиторий
 * @param ptr_to_exam1 - указатель на первый экзамен
 * @param ptr_to_exam2 - указатель на второй экзамен
 * @return 0 - равны, 1 - ptr_to_exam1 > ptr_to_exam2, -1 - ptr_to_exam1 < ptr_to_exam2
 */
int compare_classrooms(Exam *ptr_to_exam1, Exam *ptr_to_exam2);

/**
 * @brief Сравнить день консультации
 * @param ptr_to_exam1 - указатель на первый экзамен
 * @param ptr_to_exam2 - указатель на второй экзамен
 * @return 0 - равны, 1 - ptr_to_exam1 > ptr_to_exam2, -1 - ptr_to_exam1 < ptr_to_exam2
 */
int compare_consultation_days(Exam *ptr_to_exam1, Exam *ptr_to_exam2);

/**
 * @brief Сравнить время консультации
 * @param ptr_to_exam1 - указатель на первый экзамен
 * @param ptr_to_exam2 - указатель на второй экзамен
 * @return 0 - равны, 1 - ptr_to_exam1 > ptr_to_exam2, -1 - ptr_to_exam1 < ptr_to_exam2
 */
int compare_consultation_times(Exam *ptr_to_exam1, Exam *ptr_to_exam2);

/**
 * @brief Сравнить день экзамена
 * @param ptr_to_exam1 - указатель на первый экзамен
 * @param ptr_to_exam2 - указатель на второй экзамен
 * @return 0 - равны, 1 - ptr_to_exam1 > ptr_to_exam2, -1 - ptr_to_exam1 < ptr_to_exam2
 */
int compare_exam_days(Exam *ptr_to_exam1, Exam *ptr_to_exam2);

/**
 * @brief Сравнить время экзамена
 * @param ptr_to_exam1 - указатель на первый экзамен
 * @param ptr_to_exam2 - указатель на второй экзамен
 * @return 0 - равны, 1 - ptr_to_exam1 > ptr_to_exam2, -1 - ptr_to_exam1 < ptr_to_exam2
 */
int compare_exam_times(Exam *ptr_to_exam1, Exam *ptr_to_exam2);

/**
 * @brief Получить количество элементов списка
 * @param list_of_exams
 * @return
 */
int get_number_of_elements(Exam *list_of_exams);

/**
 * @brief Получить указатель на элемент с указанным номер в списке
 * @param list_of_exams - список экзаменов
 * @param number - номер искомого элемента (начиная с 0)
 * @return - указатель на искомый элемент
 */
Exam* get_ptr_to_element(Exam *list_of_exams, int number);

#endif //COURSE_WORK_2_SORT_H
