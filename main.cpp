#include "struct_exam.h"
#include "input_from_file.h"
#include "print_DB.h"
#include "input_from_keyboard.h"
#include "sort.h"
#include "selection_according_to_conditions.h"
#include "output_to_file.h"


int main() {
    auto *list_of_exams = new Exam;
    auto *list_of_groups = new Group;
    while (true)
    {
        setlocale(LC_ALL, "C");
        system("cls"); //���⪠ ���᮫�
        cout << "���᮪ ������:\n"
             << "1 - �뢥�� ���� ������\n"
             << "2 - ����� ����� � ����������\n"
             << "3 - ����� ����� �� 䠩��\n"
             << "4 - �������� �����\n"
             << "5 - �롮ઠ ���祭�� �� ������� �᫮���\n"
             << "6 - ���஢�� �� ��।�������� ���祭��\n"
             << "7 - ������� ���� ������ � 䠩�\n"
             << "8 - 㤠���� ���� ������\n"
             << "9 - �������� �ணࠬ��\n";
        cout << "\n������ ����� �������: ";
        int comm;
        cin >> comm;
        if(cin.fail() || comm < 1 || comm > 9)
        {
            cin.clear(); //���⪠ �����
            system("cls"); //���⪠ ���᮫�
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //㤠���� '\n', ��⠢訩�� ��᫥ �����
            cout << "������ ���४�� ����� �������: ����ࠫ쭮� �᫮ �� 1 �� 8.\n\n";
            system("pause");
            continue; //���室 �� ����� ����� 横��
        }
        cin.clear(); //���⪠ �����
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //㤠���� '\n', ��⠢訩�� ��᫥ �����
        if (comm == 9) break;
        switch (comm)
        {
            case 1: //����� ���� ������
                system("cls"); //���⪠ ���᮫�
                cout << "1 - ������� ���� ������\n\n";
                print_DB(list_of_exams);
                system("pause");
                break;
            case 2: //���� � ����������
                system("cls");
                cout << "2 - ������ ������ � ����������\n\n";
                cout << "��� ��室� � ������� ���� ������ \"*\".\n���ᨬ���� ࠧ��� ����: " << ARRAY_SIZE-1 << " ᨬ�����.\n";
                enter_from_keyboard(&list_of_exams, &list_of_groups);
                system("pause");
                break;
            case 3: //���� �� 䠩��
                system("cls");
                cout << "3 - ������ ������ �� �����\n\n";
                cout << "��� ��室� � ������� ���� ������ \"*\".\n\n";
                enter_from_file(&list_of_exams, &list_of_groups);
                system("pause");
                break;
            case 4: //��������� ������
                system("cls"); //���⪠ ���᮫�
                cout << "4. �������� ������\n\n";
                cout << "��� ��室� � ������� ���� ������ \"*\".\n���ᨬ���� ࠧ��� ����: " << ARRAY_SIZE-1 << " ᨬ�����.\n\n";
                change_data(&list_of_exams, &list_of_groups);
                system("pause");
                break;
            case 5: //�롮ઠ ���祭�� �� ��������� �᫮���
                system("cls"); //���⪠ ���᮫�
                cout << "5. ������� �������� �� �������� ��������\n\n";
                selection_according_to_conditions(list_of_exams);
                system("pause");
                break;
            case 6: //���஢�� �� ��।�������� ���祭��
                system("cls"); //���⪠ ���᮫�
                cout << "6. ���������� �� ������������� ��������\n\n";
                sorting_menu(&list_of_exams);
                system("pause");
                break;
            case 7: //�뢥�� � 䠩�
                system("cls"); //���⪠ ���᮫�
                cout << "7. �������� ���� ������ � ����\n\n";
                enter_to_file(list_of_exams);
                system("pause");
                break;
            case 8: //㤠����� ���� ������
                system("cls"); //���⪠ ���᮫�
                cout << "8. ������� ���� ������\n\n";
                cout << "\n�� 㢥७�, �� ��� 㤠���� ���� ������?\n";
                cout << "������ \"1\", �᫨ ��� 㤠���� �����, ��� �� ��㣮� ᨬ���, �⮡� ��� � ������� ����: ";
                char answer;
                cin >> answer;
                cin.clear(); //���⪠ �����
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //㤠���� '\n', ��⠢訩�� ��᫥ �����
                if (answer != '1')
                {
                    cout << "\n���� ������ �� 㤠����.\n\n";
                    system("pause");
                    continue;
                }
                delete_list(&list_of_exams, &list_of_groups);
                cout << "\n���� ������ 㤠����.\n\n";
                system("pause");
                break;
            default:
                exit(-1);
        }
    }
    return 0;
}