#include "input_from_keyboard.h"

void enter_from_keyboard(Exam **list_of_exams, Group **list_of_groups)
{
    cout << "\n��ଠ� ����� ��㯯�: �<����� �������><�/� (�筮/���筮)>-<����� ��㯯�><�/�� (���/��������)>-<��� ����㯫���� � �ଠ� ��>. �ਬ��: �10-101�-21\n\n������ �������� ��㯯�, ����� ���ன �� ��� ��������: ";
    auto *new_exam = new Exam;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        new_exam->group[i] = getchar();
        if (new_exam->group[i] == '*') return;
        if (new_exam->group[i] == ' ') new_exam->group[i] = '_';
        if (new_exam->group[i] == '\n')
        {
            new_exam->group[i] = '\0';
            break;
        }
        if (i == ARRAY_SIZE-1)
        {
            char massage[] = "������ ���� �� ����� �ॢ���� 70 ᨬ�����.\n";
            cin.clear(); //���⪠ �����
            system("cls"); //���⪠ ���᮫�
            cout << "������ ���� �� ����� �ॢ���� 70 ᨬ�����.\n";
        }
    }
    if (!check_group(new_exam->group))
    {
        cin.clear(); //���⪠ �����
        system("cls"); //���⪠ ���᮫�
        cout << "�����४�� �ଠ� ����� ��㯯�. ���஡�� �� ࠧ.\n";
        return;
    }
    Group *ptr_to_group = search_group(*list_of_groups, new_exam->group);
    if (!ptr_to_group)
        ptr_to_group = add_group(list_of_groups, new_exam->group);
    if (ptr_to_group->number_of_exams >= 5)
    {
        cout << "� �⮩ ��㯯� 㦥 ���ᨬ��쭮� ������⢮ �������: 5.\n";
        return;
    }
    char message[][150] =
            {
                    "������ �������� ������: ",
                    "������ ��� �९�����⥫� (��� � �ଠ� \"<�������> <�> <�>\"): ",
                    "������ �㤨��� (<�����>-<����� �㤨�ਨ>, ���ਬ��: \"��� �-225\", \"3-111\"): ",
                    "������ ���� �������樨 (� �ଠ� ��.��.����): ",
                    "������ �६� �������樨 (� �ଠ� ��:��): ",
                    "������ ���� ������ (� �ଠ� ��.��.����): ",
                    "������ �६� ������ (� �ଠ� ��:��): ",
            };
    bool (*check_functions[])(char []) = {check_subject, check_lecturer, check_classroom, check_day, check_time, check_day, check_time};
    char *fields[] = {new_exam->subject, new_exam->lecturer, new_exam->classroom, new_exam->consultation_day, new_exam->consultation_time, new_exam->exam_day, new_exam->exam_time};
    for (int i = 0; i < 7; i++)
    {
        if (!enter_field(list_of_exams, new_exam, fields[i], check_functions[i], message[i]))
        {
            delete new_exam;
            return;
        }
    }
    ptr_to_group->number_of_exams = ptr_to_group->number_of_exams + 1;
    add_exam(list_of_exams, new_exam);
}

bool enter_field(Exam **list_of_exams, Exam *new_exam, char *field, bool(*verification)(char *), char *message)
{
    while (true) //������ ���祭�� ����, ���� �� �� �㤥� ������� ���४⭮ ��� ���짮��⥫� �� ����� ���
    {
        cout << message; //�뢮� ᮮ�饭��
        //���� ����
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            field[i] = getchar();
            if (field[i] == '*') return false;
            if (field[i] == ' ') field[i] = '_';
            if (field[i] == '\n')
            {
                field[i] = '\0';
                break;
            }
            if (i == ARRAY_SIZE-1 && field[i] != '\0')
            {
                char massage[] = "������ ���� �� ����� �ॢ���� 70 ᨬ�����.\n";
                cin.clear(); //���⪠ �����
                system("cls"); //���⪠ ���᮫�
                system("pause");
                cout << "���ᨬ���� ࠧ��� ���� -" << ARRAY_SIZE-1 << " ᨬ�����.\n��� ��室� ���⭮ � ���� ������ *.\n";
            }
        }
        if (!verification (field))
        {
            char massage[] = "�����४�� �ଠ�. ���஡�� �� ࠧ.\n";
            cin.clear(); //���⪠ �����
            system("cls"); //���⪠ ���᮫�
            cout << "�����४�� �ଠ�. ���஡�� �� ࠧ.\n";
            continue; //���室 �� ����� ����� 横��
        }
        if (verification == check_subject)
        {
            if (search_exam(list_of_exams, new_exam->group, field))
            {
                cout << "����� ����� 㦥 �������.\n";
                return false;
            }
        }
        break; //��室 �� 横�� while
    }
    return true;
}

void change_data(Exam **list_of_exams, Group **list_of_groups)
{
    if ((*list_of_exams)->next == nullptr)
    {
        cout << "��� ����� ��� ���������. ���� ������ ����.\n\n";
        return;
    }
    char group[ARRAY_SIZE] = {};
    cout << "\n��ଠ� ����� ��㯯�: �<����� �������><�/� (�筮/���筮)>-<����� ��㯯�><�/�� (���/��������)>-<��� ����㯫����>\n�ਬ��: �1�-101�-21\n\n������ �������� ��㯯�, ����� � ���ன �� ��� ��������: ";
    //���� �������� ��㯯�
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        group[i] = getchar();
        if (group[i] == '*') return;
        if (group[i] == ' ') group[i] = '_';
        if (group[i] == '\n')
        {
            group[i] = '\0';
            break;
        }
        if (i == ARRAY_SIZE-1 && group[i] != '\0')
        {
            cin.clear(); //���⪠ �����
            system("cls"); //���⪠ ���᮫�
            cout << "������ ���� �� ����� �ॢ���� 70 ᨬ�����.\n";
            return;
        }
    }
    if (!check_group(group))
    {
        cin.clear(); //���⪠ �����
        system("cls"); //���⪠ ���᮫�
        cout << "�����४�� �ଠ� ����� ��㯯�. ���஡�� �� ࠧ.\n";
        return;
    }
    Group *ptr_to_group = search_group(*list_of_groups, group);
    if (!ptr_to_group)
    {
        cin.clear(); //���⪠ �����
        system("cls"); //���⪠ ���᮫�
        cout << "����� ��㯯� �� �������.\n";
        return;
    }
    char subject[ARRAY_SIZE] = {};
    cout << "������ �������� �।���, ����� �� ������ �� ���஬� �� ��� ��������: ";
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        subject[i] = getchar();
        if (subject[i] == '*') return;
        if (subject[i] == ' ') subject[i] = '_';
        if (subject[i] == '\n')
        {
            subject[i] = '\0';
            break;
        }
        if (i == ARRAY_SIZE-1)
        {
            cout << "������ ���� �� ����� �ॢ���� 70 ᨬ�����.\n";
            cin.clear(); //���⪠ �����
            system("cls"); //���⪠ ���᮫�
            system("pause");
            return;
        }
    }
    if (!check_subject(subject))
    {
        cin.clear(); //���⪠ �����
        system("cls"); //���⪠ ���᮫�
        cout << "�����४�� �ଠ� �������� �।���. ���஡�� �� ࠧ.\n";
        delete ptr_to_group;
        return;
    }
    Exam *ptr_to_exam = search_exam(list_of_exams, group, subject);
    if (!ptr_to_exam)
    {
        cin.clear(); //���⪠ �����
        system("cls"); //���⪠ ���᮫�
        cout << "� ������ ��㯯� ��������� ⠪�� �����.���஡�� �� ࠧ.\n";
        return;
    }
    show_menu(); //�뢮� ����
    int comm;
    cout << "\n������ ����� �������: ";
    cin >> comm;
    //�᫨ �����४�� ����
    if(cin.fail() || comm < 1 || comm > 9)
    {
        cin.clear(); //���⪠ �����
        system("cls"); //���⪠ ���᮫�
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //㤠���� '\n', ��⠢訩�� ��᫥ �����
        cout << "������ ���४�� ����� �������: ����ࠫ쭮� �᫮ �� 1 �� 9.\n";
        system("pause");
        return;
    }
    cin.clear(); //���⪠ �����
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //㤠���� '\n', ��⠢訩�� ��᫥ �����
    if (comm == 8) return;
    switch (comm)
    {
        case 1:
        {
            char message[] = "������ ��� ������ �९�����⥫� (��� � �ଠ� \"<�������> <�> <�>\"): ";
            change_field(ptr_to_exam->lecturer, message, check_lecturer);
            break;
        }
        case 2:
        {
            char message[] = "������ ���� ����� �㤨�ਨ (<�����>-<����� �㤨�ਨ>, ���ਬ��: \"��� �-225\", \"3-111\"): ";
            change_field(ptr_to_exam->classroom, message, check_classroom);
            break;
        }
        case 3:
        {
            char message[] = "������ ���� ���� �������樨 (� �ଠ� ��.��.����): ";
            change_field(ptr_to_exam->consultation_day, message, check_day);
            break;
        }
        case 4:
        {
            char message[] = "������ ����� �६� �������樨 (� �ଠ� ��:��): ";
            change_field(ptr_to_exam->consultation_time, message, check_time);
            break;
        }
        case 5:
        {
            char message[] = "������ ���� ���� ������ (� �ଠ� ��.��.����): ";
            change_field(ptr_to_exam->exam_day, message, check_day);
            break;
        }
        case 6:
        {
            char message[] = "������ ����� �६� ������ (� �ଠ� ��:��): ";
            change_field(ptr_to_exam->exam_time, message, check_time);
            break;
        }
        case 7:
        {
            delete_exam(list_of_exams, &ptr_to_exam, list_of_groups);
            break;
        }
        default:
            cout << "Unexpected error.\n";
            exit(-1);
    }
}

void change_field(char *field, char *message, bool(*check_field)(char *))
{
    cout << message; //�뢮� ᮮ�饭��
    char new_field[ARRAY_SIZE] = {}; //���樠������ ��६����� ��� ������ ����
    //���� ������ ���祭��
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        new_field[i] = getchar();
        if (new_field[i] == '*') return;
        if (new_field[i] == ' ') new_field[i] = '_';
        if (new_field[i] == '\n')
        {
            new_field[i] = '\0';
            break;
        }
        if (i == ARRAY_SIZE-1 && new_field[i] != '\0')
        {
            cout << "������ ���� �� ����� �ॢ���� 70 ᨬ�����.\n";
            system("pause");
            cin.clear(); //���⪠ �����
            system("cls"); //���⪠ ���᮫�
            cout << "���ᨬ���� ࠧ��� ���� - " << ARRAY_SIZE-1 << " ᨬ�����.\n��� ��室� ���⭮ � ���� ������ \"*\".\n\n";
        }
    }
    if (!check_field(new_field))
    {
        cin.clear(); //���⪠ �����
        system("cls"); //���⪠ ���᮫�
        cout << "�����४�� �ଠ�. ���஡�� �� ࠧ.\n";
        system("pause");
        return;
    }
    int i = 0;
    while (field[i] != '\0')
    {
        field[i] = '\0';
        i++;
    }
    i = 0;
    while (new_field[i] != '\0')
    {
        field[i] = new_field[i];
        i++;
    }
}

void show_menu()
{
    cout
            << "\n�롥�� �������:\n"
            << "1 - �������� �९�����⥫�\n"
            << "2 - �������� ����� �㤨�ਨ\n"
            << "3 - �������� ���� �������樨\n"
            << "4 - �������� �६� �������樨\n"
            << "5 - �������� ���� ������\n"
            << "6 - �������� �६� ������\n"
            << "7 - 㤠���� �����\n"
            << "8 - ��� � ������� ����\n";
}