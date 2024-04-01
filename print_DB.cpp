#include "print_DB.h"

void print_DB(Exam *list_of_exams)
{
    setlocale(LC_ALL, "rus");
    if (list_of_exams->next == nullptr)
    {
        cout << "���� ������ �����.\n\n";
        return;
    }
    cout << "\t\t���� ������\n";
    //������������� ����������� �������� �����
    int max_length_group = 15;
    int max_length_subject = 20;
    int max_length_lecturer = 15;
    int max_length_classroom = 10;
    int length_day = 12;
    int length_time = 7;
    //������������� ��������� ��� ����������� �� ������
    Exam *ptr_to_exam = list_of_exams;
    //���������� ����� ����� ������� ����� ��� ����������� ���������� �������
    bool first_iteration = true; //���� ������� ����������� �����
    //���� �� ����� �� ����� ��� ������ ��� ������� � ����
    while (ptr_to_exam != list_of_exams || first_iteration)
    {
        //���������� � ��� ������������� �������� ����� ���������������� ����
        if (get_length(ptr_to_exam->group) > max_length_group) max_length_group = get_length(ptr_to_exam->group);
        if (get_length(ptr_to_exam->subject) > max_length_subject) max_length_subject = get_length(ptr_to_exam->subject);
        if (get_length(ptr_to_exam->lecturer) > max_length_lecturer) max_length_lecturer = get_length(ptr_to_exam->lecturer);
        if (get_length(ptr_to_exam->classroom) > max_length_classroom) max_length_classroom = get_length(ptr_to_exam->classroom);
        ptr_to_exam = ptr_to_exam->next;
        first_iteration = false;
    }
    //����������� ������ ��� ���������� ��������
    max_length_group = max_length_group + 5;
    max_length_subject = max_length_subject + 5;
    max_length_lecturer = max_length_lecturer + 5;
    max_length_classroom = max_length_classroom + 5;
    setlocale(LC_ALL, "C"); //������������� �� ������
    //������� ����� �������
    cout << char(218) << setfill(char(196)) << setw(max_length_group)
         << char(194) << setfill(char(196)) << setw(max_length_subject)
         << char(194) << setfill(char(196)) << setw(max_length_lecturer)
         << char(194) << setfill(char(196)) << setw(max_length_classroom)
         << char(194) << setfill(char(196)) << setw(length_day + length_time)
         << char(194) << setfill(char(196)) << setw(length_day + length_time)
         << char(191) << endl;
    cout << char(179) << setfill(' ') << setw(max_length_group)
         << char(179) << setfill(' ') << setw(max_length_subject)
         << char(179) << setfill(' ') << setw(max_length_lecturer)
         << char(179) << setfill(' ') << setw(max_length_classroom)
         << char(179);
    setlocale(LC_ALL, "rus"); //������������� �� ������� ����
    cout << "   ������������   ";
    setlocale(LC_ALL, "C"); //������������� �� ������
    cout << char(179);
    setlocale(LC_ALL, "rus"); //������������� �� ������� ����
    cout << "     �������      ";
    setlocale(LC_ALL, "C"); //������������� �� ������
    cout << char(179) << endl << char(179);
    setlocale(LC_ALL, "rus"); //������������� �� ������� ����
    cout << "   ������" << setfill(' ') << setw(max_length_group - 9);
    setlocale(LC_ALL, "C"); //������������� �� ������
    cout << char(179);
    setlocale(LC_ALL, "rus"); //������������� �� ������� ����
    cout << "   �������" << setfill(' ') << setw(max_length_subject - 10);
    setlocale(LC_ALL, "C"); //������������� �� ������
    cout << char(179);
    setlocale(LC_ALL, "rus"); //������������� �� ������� ����
    cout << "   �������������" << setfill(' ') << setw(max_length_lecturer - 16);
    setlocale(LC_ALL, "C"); //������������� �� ������
    cout << char(179);
    setlocale(LC_ALL, "rus"); //������������� �� ������� ����
    cout << "   ���������" << setfill(' ') << setw(max_length_classroom - 12);
    setlocale(LC_ALL, "C"); //������������� �� ������
    cout << char(195) << setfill(char(196)) << setw(length_day)
         << char(194) << setfill(char(196)) << setw(length_time)
         << char(197) << setfill(char(196)) << setw(length_day)
         << char(194) << setfill(char(196)) << setw(length_time)
         << char(180) << endl
         << char(179) << setfill(' ') << setw(max_length_group)
         << char(179) << setfill(' ') << setw(max_length_subject)
         << char(179) << setfill(' ') << setw(max_length_lecturer)
         << char(179) << setfill(' ') << setw(max_length_classroom)
         << char(179);
    setlocale(LC_ALL, "rus"); //������������� �� ������� ����
    cout << "   ����" << setfill(' ') << setw(length_day - 7);
    setlocale(LC_ALL, "C"); //������������� �� ������
    cout << char(179);
    setlocale(LC_ALL, "rus"); //������������� �� ������� ����
    cout << "�����" << setfill(' ') << setw(length_time - 5);
    setlocale(LC_ALL, "C"); //������������� �� ������
    cout << char(179);
    setlocale(LC_ALL, "rus"); //������������� �� ������� ����
    cout << "   ����" << setfill(' ') << setw(length_day - 7);
    setlocale(LC_ALL, "C"); //������������� �� ������
    cout << char(179);
    setlocale(LC_ALL, "rus"); //������������� �� ������� ����
    cout << "�����" << setfill(' ') << setw(length_time - 5);
    setlocale(LC_ALL, "C"); //������������� �� ������
    cout << char(179) << endl;
    first_iteration = true;
    ptr_to_exam = list_of_exams;
    while (ptr_to_exam != list_of_exams || first_iteration)
    {
        //�������������� �����
//        if (combine_by_groups && !first_iteration && strcmp(ptr_to_exam->group, ptr_to_exam->next->group) == 0) cout << char(179) << setfill(' ') << setw(max_length_group);
//        else cout << char(195) << setfill(char(196)) << setw(max_length_group);
        cout << char(195) << setfill(char(196)) << setw(max_length_group);
        cout << char(197) << setfill(char(196)) << setw(max_length_subject)
             << char(197) << setfill(char(196)) << setw(max_length_lecturer)
             << char(197) << setfill(char(196)) << setw(max_length_classroom)
             << char(197) << setfill(char(196)) << setw(length_day)
             << char(197) << setfill(char(196)) << setw(length_time)
             << char(197) << setfill(char(196)) << setw(length_day)
             << char(197) << setfill(char(196)) << setw(length_time)
             << char(180) << endl << char(179);
        //������ �������
//        if (combine_by_groups && !first_iteration && strcmp(ptr_to_exam->group, ptr_to_exam->next->group) == 0) cout << setfill(' ') << setw(max_length_group) << char(179) ;
//        else cout << "   " << ptr_to_exam->group << setfill(' ') << setw(max_length_group - get_length(ptr_to_exam->group) - 3) << char(179);
        cout << "   " << ptr_to_exam->group << setfill(' ') << setw(max_length_group - get_length(ptr_to_exam->group) - 3) << char(179);
        cout << "   " << ptr_to_exam->subject << setfill(' ') << setw(max_length_subject - get_length(ptr_to_exam->subject) - 3) << char(179)
             << "   " << ptr_to_exam->lecturer << setfill(' ') << setw(max_length_lecturer - get_length(ptr_to_exam->lecturer) - 3) << char(179)
             << "   " << ptr_to_exam->classroom << setfill(' ') << setw(max_length_classroom - get_length(ptr_to_exam->classroom) - 3) << char(179)
             << " " << ptr_to_exam->consultation_day << setfill(' ')  << setw(length_day - get_length(ptr_to_exam->consultation_day) - 1) << char(179)
             << " " << ptr_to_exam->consultation_time << setfill(' ')  << setw(length_time - get_length(ptr_to_exam->consultation_time) - 1) << char(179)
             << " " << ptr_to_exam->exam_day << setfill(' ')  << setw(length_day - get_length(ptr_to_exam->exam_day) - 1) << char(179)
             << " " << ptr_to_exam->exam_time << setfill(' ')  << setw(length_time - get_length(ptr_to_exam->exam_time) - 1) << char(179) << endl;
        ptr_to_exam = ptr_to_exam->next;
        first_iteration = false;
    }
    //��������� ������
    cout << char(192) << setfill(char(196)) << setw(max_length_group)
         << char(193) << setfill(char(196)) << setw(max_length_subject)
         << char(193) << setfill(char(196)) << setw(max_length_lecturer)
         << char(193) << setfill(char(196)) << setw(max_length_classroom)
         << char(193) << setfill(char(196)) << setw(length_day)
         << char(193) << setfill(char(196)) << setw(length_time)
         << char(193) << setfill(char(196)) << setw(length_day)
         << char(193) << setfill(char(196)) << setw(length_time)
         << char(217) << endl;
}