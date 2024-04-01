#ifndef COURSE_WORK_2_SELECTION_ACCORDING_TO_CONDITIONS_H
#define COURSE_WORK_2_SELECTION_ACCORDING_TO_CONDITIONS_H

#include "struct_exam.h"
#include "print_DB.h"
#include "regex.h"
#include "output_to_file.h"

void selection_according_to_conditions(Exam *list_of_exams);

bool enter_condition(char *field, bool(*verification)(char *), char *message);

int compare_groups(Exam *ptr_to_exam, char field[]);

int compare_subjects(Exam *ptr_to_exam, char field[]);

int compare_lecturers(Exam *ptr_to_exam, char field[]);

int compare_classrooms(Exam *ptr_to_exam, char field[]);

int compare_consultation_days(Exam *ptr_to_exam, char field[]);

int compare_consultation_times(Exam *ptr_to_exam, char field[]);

int compare_exam_days(Exam *ptr_to_exam, char field[]);

int compare_exam_times(Exam *ptr_to_exam, char field[]);

#endif //COURSE_WORK_2_SELECTION_ACCORDING_TO_CONDITIONS_H
