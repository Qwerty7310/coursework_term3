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
        system("cls"); //очистка консоли
        cout << "Список команд:\n"
             << "1 - вывести Базу данных\n"
             << "2 - ввести данные с клавиатуры\n"
             << "3 - ввести данные из файла\n"
             << "4 - изменить данные\n"
             << "5 - выборка значений по заданным условиям\n"
             << "6 - сортировка по определенному значению\n"
             << "7 - записать Базу данных в файл\n"
             << "8 - удалить Базу данных\n"
             << "9 - завершить программу\n";
        cout << "\nВведите номер команды: ";
        int comm;
        cin >> comm;
        if(cin.fail() || comm < 1 || comm > 9)
        {
            cin.clear(); //очистка ввода
            system("cls"); //очистка консоли
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //удалить '\n', оставшийся после ввода
            cout << "Введите корректный номер команды: натуральное число от 1 до 8.\n\n";
            system("pause");
            continue; //переход на новую итерацию цикла
        }
        cin.clear(); //очистка ввода
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //удалить '\n', оставшийся после ввода
        if (comm == 9) break;
        switch (comm)
        {
            case 1: //печать базы данных
                system("cls"); //очистка консоли
                cout << "1 - ВЫВЕСТИ БАЗУ ДАННЫХ\n\n";
                print_DB(list_of_exams);
                system("pause");
                break;
            case 2: //ввод с клавиатуры
                system("cls");
                cout << "2 - ВВЕСТИ ДАННЫЕ С КЛАВИАТУРЫ\n\n";
                cout << "Для выхода в главное меню введите \"*\".\nМаксимальный размер поля: " << ARRAY_SIZE-1 << " символов.\n";
                enter_from_keyboard(&list_of_exams, &list_of_groups);
                system("pause");
                break;
            case 3: //ввод из файла
                system("cls");
                cout << "3 - ВВЕСТИ ДАННЫЕ ИЗ ФАЙЛА\n\n";
                cout << "Для выхода в главное меню введите \"*\".\n\n";
                enter_from_file(&list_of_exams, &list_of_groups);
                system("pause");
                break;
            case 4: //изменение данных
                system("cls"); //очистка консоли
                cout << "4. ИЗМЕНИТЬ ДАННЫЕ\n\n";
                cout << "Для выхода в главное меню введите \"*\".\nМаксимальный размер поля: " << ARRAY_SIZE-1 << " символов.\n\n";
                change_data(&list_of_exams, &list_of_groups);
                system("pause");
                break;
            case 5: //выборка значений по заданному условию
                system("cls"); //очистка консоли
                cout << "5. ВЫБОРКА ЗНАЧЕНИЙ ПО ЗАДАННЫМ УСЛОВИЯМ\n\n";
                selection_according_to_conditions(list_of_exams);
                system("pause");
                break;
            case 6: //сортировка по определенному значению
                system("cls"); //очистка консоли
                cout << "6. СОРТИРОВКА ПО ОПРЕДЕЛЕННОМУ ЗНАЧЕНИЮ\n\n";
                sorting_menu(&list_of_exams);
                system("pause");
                break;
            case 7: //вывести в файл
                system("cls"); //очистка консоли
                cout << "7. ЗАПИСАТЬ БАЗУ ДАННЫХ В ФАЙЛ\n\n";
                enter_to_file(list_of_exams);
                system("pause");
                break;
            case 8: //удаление базы данных
                system("cls"); //очистка консоли
                cout << "8. УДАЛИТЬ БАЗУ ДАННЫХ\n\n";
                cout << "\nВы уверены, что хотите удалить Базу данных?\n";
                cout << "Введите \"1\", если хотите удалить экзамен, или любой другой символ, чтобы выйти в главное меню: ";
                char answer;
                cin >> answer;
                cin.clear(); //очистка ввода
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //удалить '\n', оставшийся после ввода
                if (answer != '1')
                {
                    cout << "\nБаза данных не удалена.\n\n";
                    system("pause");
                    continue;
                }
                delete_list(&list_of_exams, &list_of_groups);
                cout << "\nБаза данных удалена.\n\n";
                system("pause");
                break;
            default:
                exit(-1);
        }
    }
    return 0;
}