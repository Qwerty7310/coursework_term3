#ifndef COURSE_WORK_2_STRUCT_EXAM_H
#define COURSE_WORK_2_STRUCT_EXAM_H

#include <iostream>
#include <fstream>
#include <limits>
#include <Windows.h>
#include <cstring>
#include <iomanip>
#include "regex.h"

//��ਠ�� 2: ����楢� �����吝� ᯨ᪨
//��ᯨᠭ�� ������樮���� ��ᨨ � �᫮� ������� �� ����� 5, ��㯯�, �।���, �㤨���, �६� �஢������ �������樨, �६� �஢������ ������, �९�����⥫�

/*
 * 1. ����஫� ����� ����������� ����� �� 䠩�� � �뢮� ᮮ�饭�� �� �⮬
 * 2. ��������/���� system("pause")
 * 3. ������� ���� ����� ��ᨢ�
 * 4. ���� ��� 䠩�� �१ cin
 * 5. �������� �������ਨ
 * 6. ��������� functions �� ��᪮�쪮 䠩���
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
 * @brief ���������� ������ ������ � ᯨ᮪
 * @param list_of_exams - ᯨ᮪ �������
 * @param new_exam - ������塞� �����
 */
void add_exam(Exam **list_of_exams, Exam *new_exam);

/**
 * @brief �������� ������ �� ᯨ᪠
 * @param list_of_exams - ᯨ᮪ �������
 * @param exam - 㤠�塞� �����
 * @param list_of_group - ᯨ᮪ ��㯯
 * @param question - ᯨ᮪ ��㯯
 */
void delete_exam(Exam **list_of_exams, Exam **exam, Group **list_of_group, bool question = true);

/**
 * @brief ���������� ����� ��㯯� � ᯨ᮪
 * @param list_of_groups - ᯨ᮪ ��㯯
 * @param new_group - �������� ������塞�� ��㯯�
 * @return ���� 㧫� ����������� ��㯯�
 */
Group* add_group(Group **list_of_groups, char new_group[]);

/**
 * @brief ������� ��㯯� �� ᯨ᪠ ��㯯
 * @param list_of_groups  - ᯨ᮪ ��㯯
 * @param group - 㤠�塞�� ��㯯�
 */
void delete_group(Group **list_of_groups, Group **group);

/**
 * @brief ���� �����
 * @param list_of_exams - ᯨ᮪ �������
 * @param group - �������� ��㯯�
 * @param subject - �������� �।���
 * @return ���� �㦭��� 㧫�
 */
Exam* search_exam(Exam **list_of_exams, char group[], char subject[]);

/**
 * @brief ���� ��㯯�
 * @param list_of_groups - ᯨ᮪ ��㯯
 * @param group -�᪮��� ��㯯�
 * @return ���� �㦭��� 㧫�
 */
Group* search_group(Group *list_of_groups, char group[]);

/**
 * @brief �������� ���� ������
 * @param list_of_exams - ᯨ᮪ �������
 * @param list_of_groups - ᯨ᮪ ��㯯
 */
void delete_list(Exam **list_of_exams, Group **list_of_groups);

/**
 * @brief ������� ����� ��ப�
 * @param str - ��ப�
 * @return ����� ��ப�
 */
int get_length(char *str);

#endif //COURSE_WORK_2_STRUCT_EXAM_H
