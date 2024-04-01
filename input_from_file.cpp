#include "input_from_file.h"

void enter_from_file(Exam **list_of_exams, Group **list_of_groups)
{
    //���樠������ ��६����� ��� 䠩��
    char path[ARRAY_SIZE] = {};
    cout << "������ ��� 䠩�� � ���७���: ";
    int i = 0;
    //���� ��� 䠩��
    while (true)
    {
        path[i] = getchar();
        if (path[i] == '*') return;
        if (path[i] == '\n')
        {
            path[i] = '\0';
            break;
        }
        i++;
    }
    //���樠������ 䠩����� ��६�����
    ifstream file;
    file.open(path);
    //�᫨ 䠩�� �� �������
    if (!file) {
        cout << "\n���� \"" << path << "\" �� ������.\n\n";
        return;
    }
    else
        //�᫨ 䠩� ����
        if (file.peek() == EOF)
        {
            cout << "\n���� \"" << path << "\" ����.\n\n"; // �᫨ ���� ᨬ��� ����� 䠩��
            return;
        }
        else cout << "\n���� \"" << path << "\" �����.\n\n";
    int number_of_lines = count_lines_in_file(file); //������ ������⢮ ��ப � 䠩��
    bool error_flag; //�������� ������ �訡��
    for (int j = 0; j < number_of_lines; j++)
    {
        error_flag = false; //����砫쭮 �訡�� ���
        auto *exam = new Exam;
        // �⥭�� ����� ��㯯�
        move_cursor(file);
        if (file.eof())
            break;
        file >> exam->group;
        if (!check_group(exam->group))
        {
            cout << "� ����� " << j+1 << " �����४�� ����� ��㯯�.\n";
            error_flag = true;
        }
        // �⥭�� �������� �।���
        move_cursor(file); //�ய�� �஡����
        if (file.peek() != '\n' && file.peek() != '\r' && file.peek() != ' ') //�᫨ ���।� �� ����� ��ப�
            file >> exam->subject;
        if (!check_subject(exam->subject))
        {
            cout << "� ����� " << j+1 << " �����४⭮� �������� �।���.\n";
            error_flag = true;
        }
        // �⥭�� ����� �९�����⥫�
        move_cursor(file);
        if (file.peek() != '\n' && file.peek() != '\r' && file.peek() != ' ')
            file >> exam->lecturer;
        if (!check_lecturer(exam->lecturer))
        {
            cout << "� ����� " << j+1 << " �����४⭮� ��� �९�����⥫�.\n";
            error_flag = true;
        }
        // �⥭�� ����� �㤨�ਨ
        move_cursor(file);
        if (file.peek() != '\n' && file.peek() != '\r' && file.peek() != ' ')
            file >> exam->classroom;
        if (!check_classroom(exam->classroom))
        {
            cout << "� ����� " << j+1 << " �����४�� ����� �㤨�ਨ.\n";
            error_flag = true;
        }
        // �⥭�� ��� �������樨
        move_cursor(file);
        if (file.peek() != '\n' && file.peek() != '\r' && file.peek() != ' ')
            file >> exam->consultation_day;
        if (!check_day(exam->consultation_day))
        {
            cout << "� ����� " << j+1 << " �����४�� ���� �������樨.\n";
            error_flag = true;
        }
        // �⥭�� �६��� �������樨
        move_cursor(file);
        if (file.peek() != '\n' && file.peek() != '\r' && file.peek() != ' ')
            file >> exam->consultation_time;
        if (!check_time(exam->consultation_time))
        {
            cout << "� ����� " << j+1 << " �����४⭮� �६� �������樨.\n";
            error_flag = true;
        }
        // �⥭�� ��� ������
        move_cursor(file);
        if (file.peek() != '\n' && file.peek() != '\r' && file.peek() != ' ')
            file >> exam->exam_day;
        if (!check_day(exam->exam_day))
        {
            cout << "� ����� " << j+1 << " �����४�� ���� ������.\n";
            error_flag = true;
        }
        // �⥭�� �६��� ������
        move_cursor(file);
        if (file.peek() != '\n' && file.peek() != '\r' && file.peek() != ' ')
            file >> exam->exam_time;
        if (!check_time(exam->exam_time))
        {
            cout << "� ����� " << j+1 << " �����४⭮� �६� ������.\n";
            error_flag = true;
        }
        file.seekg(1, ios::cur);
        while (file.peek() == '\n' || file.peek() == '\r')
        {
            number_of_lines -= 1;
            file.seekg(1, ios::cur);
        }
        if (error_flag)
        {
            delete exam;
            continue;
        }
        Group *ptr_to_group = search_group(*list_of_groups, exam->group);
        if (!ptr_to_group)
        {
            ptr_to_group = add_group(list_of_groups, exam->group);
        }
        if (ptr_to_group->number_of_exams >= 5)
        {
            cout << "� ��㯯� " << exam->group << " 㦥 ������� ���ᨬ��쭮� ������⢮ �������. ������ " << j + 1 << " �ந����஢���.\n";
            delete exam;
            continue;
        }
        Exam *ptr_to_exam = search_exam(list_of_exams, exam->group, exam->subject);
        if (ptr_to_exam)
        {
            cout << "������� \"" << exam->subject << "\" (������ " << j+1 << ") 㦥 ���ᥭ � ���� ������ ��� ��㯯� " << exam->group << ".\n";
            delete exam;
            continue;
        }
        add_exam(list_of_exams, exam);
        ptr_to_group->number_of_exams++;
    }
    cout << "�뫨 ������� �� ���४�� ��ப�.\n\n";
    file.close();
}

//ᤢ����� ����� � �ய����� �஡���
void move_cursor(ifstream &file) {
    while (file.peek() == ' ' || file.peek() == '\t') {
        file.seekg(1, ios::cur);
    }
}

//������� ������⢮ ��ப � 䠩��
int count_lines_in_file(ifstream &file) {
    int count = 1;
    char c;
    for (int i = 0; !file.eof(); i++) {
        c = file.get();
        if (c == '\n' || c == '\r') count++;
    }
    file.clear();
    file.seekg(0, ios::beg);
    return count;
}