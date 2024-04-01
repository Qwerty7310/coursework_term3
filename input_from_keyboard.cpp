#include "input_from_keyboard.h"

void enter_from_keyboard(Exam **list_of_exams, Group **list_of_groups)
{
    cout << "\nФормат имени группы: М<номер института><О/З (очно/заочно)>-<номер группы><Б/Бк (бюджет/коммерция)>-<год поступления в формате ГГ>. Пример: М10-101Б-21\n\nВведите название группы, экзамен которой вы хотите добавить: ";
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
            char massage[] = "Размер поля не может превышать 70 символов.\n";
            cin.clear(); //очистка ввода
            system("cls"); //очистка консоли
            cout << "Размер поля не может превышать 70 символов.\n";
        }
    }
    if (!check_group(new_exam->group))
    {
        cin.clear(); //очистка ввода
        system("cls"); //очистка консоли
        cout << "Некорректный формат имени группы. Попробуйте еще раз.\n";
        return;
    }
    Group *ptr_to_group = search_group(*list_of_groups, new_exam->group);
    if (!ptr_to_group)
        ptr_to_group = add_group(list_of_groups, new_exam->group);
    if (ptr_to_group->number_of_exams >= 5)
    {
        cout << "У этой группы уже максимальное количество экзаменов: 5.\n";
        return;
    }
    char message[][150] =
            {
                    "Введите название экзамена: ",
                    "Введите имя преподавателя (ФИО в формате \"<Фамилия> <И> <О>\"): ",
                    "Введите аудиторию (<Корпус>-<номер аудитории>, например: \"Орш Б-225\", \"3-111\"): ",
                    "Введите день консультации (в формате ДД.ММ.ГГГГ): ",
                    "Введите время консультации (в формате ЧЧ:ММ): ",
                    "Введите день экзамена (в формате ДД.ММ.ГГГГ): ",
                    "Введите время экзамена (в формате ЧЧ:ММ): ",
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
    while (true) //вводим значение поля, пока он не будет введено корректно или пользователь не захочет выйти
    {
        cout << message; //вывод сообщения
        //ввод поля
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
                char massage[] = "Размер поля не может превышать 70 символов.\n";
                cin.clear(); //очистка ввода
                system("cls"); //очистка консоли
                system("pause");
                cout << "Максимальные размер поля -" << ARRAY_SIZE-1 << " символов.\nДля выхода обратно в меню введите *.\n";
            }
        }
        if (!verification (field))
        {
            char massage[] = "Некорректный формат. Попробуйте еще раз.\n";
            cin.clear(); //очистка ввода
            system("cls"); //очистка консоли
            cout << "Некорректный формат. Попробуйте еще раз.\n";
            continue; //переход на новую итерацию цикла
        }
        if (verification == check_subject)
        {
            if (search_exam(list_of_exams, new_exam->group, field))
            {
                cout << "Такой экзамен уже существует.\n";
                return false;
            }
        }
        break; //выход из цикла while
    }
    return true;
}

void change_data(Exam **list_of_exams, Group **list_of_groups)
{
    if ((*list_of_exams)->next == nullptr)
    {
        cout << "Нет полей для изменения. База данных пуста.\n\n";
        return;
    }
    char group[ARRAY_SIZE] = {};
    cout << "\nФормат имени группы: М<номер института><О/З (очно/заочно)>-<номер группы><Б/Бк (бюджет/коммерция)>-<год поступления>\nПример: М1О-101Б-21\n\nВведите название группы, данные о которой вы хотите изменить: ";
    //Ввод названия группы
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
            cin.clear(); //очистка ввода
            system("cls"); //очистка консоли
            cout << "Размер поля не может превышать 70 символов.\n";
            return;
        }
    }
    if (!check_group(group))
    {
        cin.clear(); //очистка ввода
        system("cls"); //очистка консоли
        cout << "Некорректный формат имени группы. Попробуйте еще раз.\n";
        return;
    }
    Group *ptr_to_group = search_group(*list_of_groups, group);
    if (!ptr_to_group)
    {
        cin.clear(); //очистка ввода
        system("cls"); //очистка консоли
        cout << "Такой группы не существует.\n";
        return;
    }
    char subject[ARRAY_SIZE] = {};
    cout << "Введите название предмета, данные об экзамене по которому вы хотите изменить: ";
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
            cout << "Размер поля не может превышать 70 символов.\n";
            cin.clear(); //очистка ввода
            system("cls"); //очистка консоли
            system("pause");
            return;
        }
    }
    if (!check_subject(subject))
    {
        cin.clear(); //очистка ввода
        system("cls"); //очистка консоли
        cout << "Некорректный формат названия предмета. Попробуйте еще раз.\n";
        delete ptr_to_group;
        return;
    }
    Exam *ptr_to_exam = search_exam(list_of_exams, group, subject);
    if (!ptr_to_exam)
    {
        cin.clear(); //очистка ввода
        system("cls"); //очистка консоли
        cout << "У данной группы отсутствует такой экзамен.Попробуйте еще раз.\n";
        return;
    }
    show_menu(); //вывод меню
    int comm;
    cout << "\nВведите номер команды: ";
    cin >> comm;
    //если некорректный ввод
    if(cin.fail() || comm < 1 || comm > 9)
    {
        cin.clear(); //очистка ввода
        system("cls"); //очистка консоли
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //удалить '\n', оставшийся после ввода
        cout << "Введите корректный номер команды: натуральное число от 1 до 9.\n";
        system("pause");
        return;
    }
    cin.clear(); //очистка ввода
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //удалить '\n', оставшийся после ввода
    if (comm == 8) return;
    switch (comm)
    {
        case 1:
        {
            char message[] = "Введите имя нового преподавателя (ФИО в формате \"<Фамилия> <И> <О>\"): ";
            change_field(ptr_to_exam->lecturer, message, check_lecturer);
            break;
        }
        case 2:
        {
            char message[] = "Введите новый номер аудитории (<Корпус>-<номер аудитории>, например: \"Орш Б-225\", \"3-111\"): ";
            change_field(ptr_to_exam->classroom, message, check_classroom);
            break;
        }
        case 3:
        {
            char message[] = "Введите новый день консультации (в формате ДД.ММ.ГГГГ): ";
            change_field(ptr_to_exam->consultation_day, message, check_day);
            break;
        }
        case 4:
        {
            char message[] = "Введите новое время консультации (в формате ЧЧ:ММ): ";
            change_field(ptr_to_exam->consultation_time, message, check_time);
            break;
        }
        case 5:
        {
            char message[] = "Введите новый день экзамена (в формате ДД.ММ.ГГГГ): ";
            change_field(ptr_to_exam->exam_day, message, check_day);
            break;
        }
        case 6:
        {
            char message[] = "Введите новое время экзамена (в формате ЧЧ:ММ): ";
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
    cout << message; //вывод сообщения
    char new_field[ARRAY_SIZE] = {}; //инициализация переменной для нового поля
    //Ввод нового значения
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
            cout << "Размер поля не может превышать 70 символов.\n";
            system("pause");
            cin.clear(); //очистка ввода
            system("cls"); //очистка консоли
            cout << "Максимальные размер поля - " << ARRAY_SIZE-1 << " символов.\nДля выхода обратно в меню введите \"*\".\n\n";
        }
    }
    if (!check_field(new_field))
    {
        cin.clear(); //очистка ввода
        system("cls"); //очистка консоли
        cout << "Некорректный формат. Попробуйте еще раз.\n";
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
            << "\nВыберите команду:\n"
            << "1 - изменить преподавателя\n"
            << "2 - изменить номер аудитории\n"
            << "3 - изменить день консультации\n"
            << "4 - изменить время консультации\n"
            << "5 - изменить день экзамена\n"
            << "6 - изменить время экзамена\n"
            << "7 - удалить экзамен\n"
            << "8 - выйти в главное меню\n";
}