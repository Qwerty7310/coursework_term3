#ifndef COURSE_WORK_2_INPUT_FROM_KEYBOARD_H
#define COURSE_WORK_2_INPUT_FROM_KEYBOARD_H

#include "struct_exam.h"

/**
 * @brief ����� ����� � ����������
 * @param list_of_exams - ᯨ᮪ �������
 * @param list_of_groups - ᯨ᮪ ��㯯
 */
void enter_from_keyboard(Exam **list_of_exams, Group **list_of_groups);

/**
 * @brief ����� ���ଠ樮���� ���� �������� ������
 * @param list_of_exams - ᯨ᮪ �������
 * @param new_exam - ���� �����
 * @param field - �������� ⥪�⮢�� ����
 * @param verification - �㭪�� �஢�ન
 * @param message - ᮮ�饭�� ��� ���짮��⥫�
 * @return १���� �����
 */
bool enter_field(Exam **list_of_exams, Exam *new_exam, char *field, bool(*verification)(char *), char *message);

/**
 * @brief �������� ����� �� ������
 * @param list_of_exams - ᯨ᮪ �������
 * @param list_of_groups - ᯨ᮪ ��㯯
 */
void change_data(Exam **list_of_exams, Group **list_of_groups);

/**
 * @brief ��९���� ⥪�⮢�� ���� �������� ������
 * @param field - ⥪�⮢�� ����
 * @param message - ᮮ�饭�� ��� ���짮��⥫�
 * @param check_field - �㭪�� �஢�ન ����
 */
void change_field(char *field, char *message, bool(*check_field)(char *));

/**
 * @brief �뢮� ���� ��� ���짮��⥫�
 */
void show_menu();


#endif //COURSE_WORK_2_INPUT_FROM_KEYBOARD_H
