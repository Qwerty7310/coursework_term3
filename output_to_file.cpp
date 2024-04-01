#include <filesystem>
#include "output_to_file.h"

void enter_to_file(Exam *list_of_exams)
{
//    setlocale(LC_ALL, "Russian");

    if (list_of_exams->next == nullptr)
    {
        cout << "���������� ������� ���� ������ � 䠩�. ���� ������ ����.\n\n";
        return;
    }
    //���樠������ ��� � 䠩��
    char path[ARRAY_SIZE] = {};
    while (true)
    {
        //���� ��� � 䠩��
        system("cls");
        cout << "\n��� ��室� � ������� ���� ������ 0.\n\n";
        cout << "������ ��� 䠩��: ";
        int i = 0;
        //���� ����� 䠩��
        while (true)
        {
            path[i] = getchar();
            if (path[i] == '\n' || path[i] == '\r')
            {
                path[i] = '\0';
                break;
            }
            i++;
        }
        if (strcmp(path, "0") == 0) return;
        //�஢�ઠ ����� 䠩��
        if (!check_file(path)) {
            cout << "\n��� 䠩�� \"" << path << "\" �����४⭮.\n\n";
            system("pause");
            continue;
        }
        break;
    }
    //���樠������ 䠩����� ��६�����
    ofstream file( path, ios_base::binary | ios_base::out );
    bool first_iteration = true; //䫠� ��ࢮ�� ��室� 横��
    Exam *ptr_to_exam = list_of_exams;
    ptr_to_exam = list_of_exams;
    while (ptr_to_exam != list_of_exams || first_iteration)
    {
        file << ptr_to_exam->group << '\t'
        << ptr_to_exam->subject << '\t'
        << ptr_to_exam->lecturer << '\t'
        << ptr_to_exam->classroom << '\t'
        << ptr_to_exam->consultation_day << '\t'
        << ptr_to_exam->consultation_time << '\t'
        << ptr_to_exam->exam_day << '\t'
        << ptr_to_exam->exam_time << endl;
        ptr_to_exam = ptr_to_exam->next;
        first_iteration = false;
    }
    cout << "\n����� �ᯥ譮 ����㦥�� � 䠩� \"" << path << "\".\n\n";
}
