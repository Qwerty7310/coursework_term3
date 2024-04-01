#include "selection_according_to_conditions.h"

void selection_according_to_conditions(Exam *list_of_exams)
{
    setlocale(LC_ALL, "C");

    if (list_of_exams->next == nullptr)
    {
        cout << "��� ��ப ��� �롮ન. ���� ������ ����.\n\n";
        return;
    }
    int number;
    cout << "�᫮���:\n"
         << "1 - �� ������ ��㯯�\n"
         << "2 - �� �������� �।���\n"
         << "3 - �� ����� �९�����⥫�\n"
         << "4 - �� ������ �㤨�ਨ\n"
         << "5 - �� ��� �������樨\n"
         << "6 - �� �६��� �������樨\n"
         << "7 - �� ��� ������\n"
         << "8 - �� �६��� ������\n\n";
    cout << "��� �����饭�� � ������� ���� ������ 0.\n\n";
    cout << "������ ���������� �᫮��� (�� 1 �� 8), �� ����� ��� ������� �롮�� ���祭��: ";
    cin >> number;
    //�᫨ �����४�� ����
    if(cin.fail() || number < 0 || number > 8)
    {
        cin.clear(); //���⪠ �����
        system("cls"); //���⪠ ���᮫�
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //㤠���� '\n', ��⠢訩�� ��᫥ �����

        cout << "������ ���४⭮� ������⢮ �᫮���: ����ࠫ쭮� �᫮ �� 1 �� 9.\n\n";
        return;
    }
    cin.clear(); //���⪠ �����
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //㤠���� '\n', ��⠢訩�� ��᫥ �����
    if (number == 0) return;

    int *array_of_conditions = new int [number];
    for (int i = 0; i < number; i++)
        array_of_conditions[i] = -1;
    if (number == 8)
    {
        for (int i = 0; i < number; i++)
            array_of_conditions[i] = i;
    }
    else
    {
        for (int i = 0; i < number; i++)
        {
            while (true)
            {
                system("cls");
                cout << "�᫮���:\n"
                     << "1 - �� ������ ��㯯�\n"
                     << "2 - �� �������� �।���\n"
                     << "3 - �� ����� �९�����⥫�\n"
                     << "4 - �� ������ �㤨�ਨ\n"
                     << "5 - �� ��� �������樨\n"
                     << "6 - �� �६��� �������樨\n"
                     << "7 - �� ��� ������\n"
                     << "8 - �� �६��� ������\n\n";

                cout << "��� �����饭�� � ������� ���� ������ 0.\n\n";
                cout << "������ ����� " << i+1 << " �᫮���: ";

                int number_conditions;
                cin >> number_conditions;
                //�᫨ �����४�� ����
                if(cin.fail() || number_conditions < 0 || number_conditions > 8)
                {
                    cin.clear(); //���⪠ �����
                    system("cls"); //���⪠ ���᮫�
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //㤠���� '\n', ��⠢訩�� ��᫥ �����
                    cout << "\n������ ���४�� ����� �᫮���: ����ࠫ쭮� �᫮ �� 1 �� 8.\n\n";
                    system("pause");
                    continue;
                }
                if (number_conditions == 0)
                {
                    delete [] array_of_conditions;
                    return;
                }
                bool continue_flag = false;
                for (int j = 0; j < number; j++)
                {
                    if (array_of_conditions[j] == number_conditions-1)
                    {
                        cout << "�� 㦥 ����� ��� �������.\n\n";
                        system("pause");
                        continue_flag = true;
                    }
                }
                if (continue_flag) continue;
                array_of_conditions[i] = number_conditions-1;
                break;
            }
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //㤠���� '\n', ��⠢訩�� ��᫥ �����
    }
    //�뤥�塞 ������
    char **fields = new char *[number];
    for (int i = 0; i < number; i++)
        fields[i] = new char [100];
    char message[][150] =
            {
                    "������ ����� ��㯯�: ",
                    "������ �������� ������: ",
                    "������ ��� �९�����⥫� (��� � �ଠ� \"<�������> <�> <�>\"): ",
                    "������ �㤨��� (<�����>-<����� �㤨�ਨ>, ���ਬ��: \"��� �-225\", \"3-111\"): ",
                    "������ ���� �������樨 (� �ଠ� ��.��.����): ",
                    "������ �६� �������樨 (� �ଠ� ��:��): ",
                    "������ ���� ������ (� �ଠ� ��.��.����): ",
                    "������ �६� ������ (� �ଠ� ��:��): ",
            };
    bool (*check_functions[])(char []) = {check_group, check_subject, check_lecturer, check_classroom, check_day, check_time, check_day, check_time};
    system("cls");
    cout << "������ \"*\", �⮡� ��� � ������� ����.\n\n";
    for (int i = 0; i < number; i++)
    {
        if(!enter_condition(fields[i], check_functions[array_of_conditions[i]], message[array_of_conditions[i]]))
            return;
    }

    int (*comparison_functions[])(Exam *, char []) = {compare_groups, compare_subjects, compare_lecturers, compare_classrooms, compare_consultation_days, compare_consultation_times, compare_exam_days, compare_exam_times};
    Exam *ptr_to_exam = list_of_exams;

    auto *new_list = new Exam;
    bool first_iteration = true; //䫠� ��ࢮ�� ��宦����� 横��
    while (ptr_to_exam != list_of_exams || first_iteration)
    {
        bool result = true; //१���� �ࠢ�����
        for (int i = 0; i < number; i++)
        {
            if (comparison_functions[array_of_conditions[i]](ptr_to_exam, fields[i]) != 0)
                result = false;
        }
        if (result)
        {
            auto *ptr_to_new_exam = new Exam;

            copy(std::begin(ptr_to_exam->group), std::end(ptr_to_exam->group), std::begin(ptr_to_new_exam->group));
            copy(std::begin(ptr_to_exam->subject), std::end(ptr_to_exam->subject), std::begin(ptr_to_new_exam->subject));
            copy(std::begin(ptr_to_exam->lecturer), std::end(ptr_to_exam->lecturer), std::begin(ptr_to_new_exam->lecturer));
            copy(std::begin(ptr_to_exam->classroom), std::end(ptr_to_exam->classroom), std::begin(ptr_to_new_exam->classroom));
            copy(std::begin(ptr_to_exam->consultation_day), std::end(ptr_to_exam->consultation_day), std::begin(ptr_to_new_exam->consultation_day));
            copy(std::begin(ptr_to_exam->consultation_time), std::end(ptr_to_exam->consultation_time), std::begin(ptr_to_new_exam->consultation_time));
            copy(std::begin(ptr_to_exam->exam_day), std::end(ptr_to_exam->exam_day), std::begin(ptr_to_new_exam->exam_day));
            copy(std::begin(ptr_to_exam->exam_time), std::end(ptr_to_exam->exam_time), std::begin(ptr_to_new_exam->exam_time));
            add_exam(&new_list, ptr_to_new_exam);
        }
        ptr_to_exam = ptr_to_exam->next;
        first_iteration = false;
    }
    if (new_list->next == nullptr)
    {
        cout << "\n��� ��ப, ᮮ⢥������� ������� �᫮���.\n\n";
        return;
    }
    print_DB(new_list);
    cout << "\n\n���࠭��� � 䠩�?\n\n";
    cout << "������ \"1\", �᫨ ��� ��࠭��� ��� �ࠣ����, ��� �� ��㣮� ᨬ���, �⮡� ��� � ������� ����: ";
    char answer;
    cin >> answer;
    cin.clear(); //���⪠ �����
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //㤠���� '\n', ��⠢訩�� ��᫥ �����

    if (answer == '1')
    {
        enter_to_file(new_list);
    }
    delete_list(&new_list,nullptr);
}

bool enter_condition(char *field, bool(*verification)(char *), char *message)
{
    while (true) //������ ���祭�� ����, ���� �� �� �㤥� ������� ���४⭮ ��� ���짮��⥫� �� ����� ���
    {
        cout << message; //�뢮� ᮮ�饭��
        //���� ����
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            field[i] = getchar();
            if (field[i] == '*')
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //㤠���� '\n', ��⠢訩�� ��᫥ �����
                return false;
            }
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
            cout << "�����४�� �ଠ�. ���஡�� �� ࠧ.\n\n";
            system("pause");
            system("cls"); //���⪠ ���᮫�
            cout << "������ \"*\", �⮡� ��� � ������� ����.\n\n";
            continue; //���室 �� ����� ����� 横��
        }
        break; //��室 �� 横�� while
    }
    return true;
}

//�ࠢ���� ����� ��㯯
int compare_groups(Exam *ptr_to_exam, char field[])
{
    return strcmp(ptr_to_exam->group, field);
}

//�ࠢ���� �������� �।��⮢
int compare_subjects(Exam *ptr_to_exam, char field[])
{
    return strcmp(ptr_to_exam->subject, field);
}

//�ࠢ���� ����� �९�����⥫��
int compare_lecturers(Exam *ptr_to_exam, char field[])
{
    return strcmp(ptr_to_exam->lecturer, field);
}

//�ࠢ���� ����� �㤨�਩
int compare_classrooms(Exam *ptr_to_exam, char field[])
{
    return strcmp(ptr_to_exam->classroom, field);
}

//�ࠢ���� ���� �������樨
int compare_consultation_days(Exam *ptr_to_exam, char field[])
{
    return strcmp(ptr_to_exam->consultation_day, field);
}

//�ࠢ���� �६� �������樨
int compare_consultation_times(Exam *ptr_to_exam, char field[])
{
    return strcmp(ptr_to_exam->consultation_time, field);
}

//�ࠢ���� ���� ������
int compare_exam_days(Exam *ptr_to_exam, char field[])
{
    return strcmp(ptr_to_exam->exam_day, field);
}

//�ࠢ���� �६� ������
int compare_exam_times(Exam *ptr_to_exam, char field[])
{
    return strcmp(ptr_to_exam->exam_time, field);
}
