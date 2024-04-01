#include "selection_according_to_conditions.h"

void selection_according_to_conditions(Exam *list_of_exams)
{
    setlocale(LC_ALL, "C");

    if (list_of_exams->next == nullptr)
    {
        cout << "Нет строк для выборки. База данных пуста.\n\n";
        return;
    }
    int number;
    cout << "Условия:\n"
         << "1 - по номеру группы\n"
         << "2 - по названию предмета\n"
         << "3 - по имени преподавателя\n"
         << "4 - по номеру аудитории\n"
         << "5 - по дню консультации\n"
         << "6 - по времени консультации\n"
         << "7 - по дню экзамена\n"
         << "8 - по времени экзамена\n\n";
    cout << "Для возвращения в главное меню введите 0.\n\n";
    cout << "Введите КОЛИЧЕСТВО условий (от 1 до 8), по которым хотите получить выборку значений: ";
    cin >> number;
    //если некорректный ввод
    if(cin.fail() || number < 0 || number > 8)
    {
        cin.clear(); //очистка ввода
        system("cls"); //очистка консоли
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //удалить '\n', оставшийся после ввода

        cout << "Введите корректное количество условий: натуральное число от 1 до 9.\n\n";
        return;
    }
    cin.clear(); //очистка ввода
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //удалить '\n', оставшийся после ввода
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
                cout << "Условия:\n"
                     << "1 - по номеру группы\n"
                     << "2 - по названию предмета\n"
                     << "3 - по имени преподавателя\n"
                     << "4 - по номеру аудитории\n"
                     << "5 - по дню консультации\n"
                     << "6 - по времени консультации\n"
                     << "7 - по дню экзамена\n"
                     << "8 - по времени экзамена\n\n";

                cout << "Для возвращения в главное меню введите 0.\n\n";
                cout << "Введите номер " << i+1 << " условия: ";

                int number_conditions;
                cin >> number_conditions;
                //если некорректный ввод
                if(cin.fail() || number_conditions < 0 || number_conditions > 8)
                {
                    cin.clear(); //очистка ввода
                    system("cls"); //очистка консоли
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //удалить '\n', оставшийся после ввода
                    cout << "\nВведите корректный номер условия: натуральное число от 1 до 8.\n\n";
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
                        cout << "Вы уже ввели эту команду.\n\n";
                        system("pause");
                        continue_flag = true;
                    }
                }
                if (continue_flag) continue;
                array_of_conditions[i] = number_conditions-1;
                break;
            }
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //удалить '\n', оставшийся после ввода
    }
    //Выделяем память
    char **fields = new char *[number];
    for (int i = 0; i < number; i++)
        fields[i] = new char [100];
    char message[][150] =
            {
                    "Введите номер группы: ",
                    "Введите название экзамена: ",
                    "Введите имя преподавателя (ФИО в формате \"<Фамилия> <И> <О>\"): ",
                    "Введите аудиторию (<Корпус>-<номер аудитории>, например: \"Орш Б-225\", \"3-111\"): ",
                    "Введите день консультации (в формате ДД.ММ.ГГГГ): ",
                    "Введите время консультации (в формате ЧЧ:ММ): ",
                    "Введите день экзамена (в формате ДД.ММ.ГГГГ): ",
                    "Введите время экзамена (в формате ЧЧ:ММ): ",
            };
    bool (*check_functions[])(char []) = {check_group, check_subject, check_lecturer, check_classroom, check_day, check_time, check_day, check_time};
    system("cls");
    cout << "Введите \"*\", чтобы выйти в главное меню.\n\n";
    for (int i = 0; i < number; i++)
    {
        if(!enter_condition(fields[i], check_functions[array_of_conditions[i]], message[array_of_conditions[i]]))
            return;
    }

    int (*comparison_functions[])(Exam *, char []) = {compare_groups, compare_subjects, compare_lecturers, compare_classrooms, compare_consultation_days, compare_consultation_times, compare_exam_days, compare_exam_times};
    Exam *ptr_to_exam = list_of_exams;

    auto *new_list = new Exam;
    bool first_iteration = true; //флаг первого прохождения цикла
    while (ptr_to_exam != list_of_exams || first_iteration)
    {
        bool result = true; //результат сравнения
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
        cout << "\nНет строк, соответствующих заданным условиям.\n\n";
        return;
    }
    print_DB(new_list);
    cout << "\n\nСохранить в файл?\n\n";
    cout << "Введите \"1\", если хотите сохранить этот фрагмент, или любой другой символ, чтобы выйти в главное меню: ";
    char answer;
    cin >> answer;
    cin.clear(); //очистка ввода
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //удалить '\n', оставшийся после ввода

    if (answer == '1')
    {
        enter_to_file(new_list);
    }
    delete_list(&new_list,nullptr);
}

bool enter_condition(char *field, bool(*verification)(char *), char *message)
{
    while (true) //вводим значение поля, пока он не будет введено корректно или пользователь не захочет выйти
    {
        cout << message; //вывод сообщения
        //ввод поля
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            field[i] = getchar();
            if (field[i] == '*')
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //удалить '\n', оставшийся после ввода
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
            cout << "Некорректный формат. Попробуйте еще раз.\n\n";
            system("pause");
            system("cls"); //очистка консоли
            cout << "Введите \"*\", чтобы выйти в главное меню.\n\n";
            continue; //переход на новую итерацию цикла
        }
        break; //выход из цикла while
    }
    return true;
}

//сравнить номера групп
int compare_groups(Exam *ptr_to_exam, char field[])
{
    return strcmp(ptr_to_exam->group, field);
}

//сравнить названия предметов
int compare_subjects(Exam *ptr_to_exam, char field[])
{
    return strcmp(ptr_to_exam->subject, field);
}

//сравнить имена преподавателей
int compare_lecturers(Exam *ptr_to_exam, char field[])
{
    return strcmp(ptr_to_exam->lecturer, field);
}

//сравнить номера аудиторий
int compare_classrooms(Exam *ptr_to_exam, char field[])
{
    return strcmp(ptr_to_exam->classroom, field);
}

//сравнить день консультации
int compare_consultation_days(Exam *ptr_to_exam, char field[])
{
    return strcmp(ptr_to_exam->consultation_day, field);
}

//сравнить время консультации
int compare_consultation_times(Exam *ptr_to_exam, char field[])
{
    return strcmp(ptr_to_exam->consultation_time, field);
}

//сравнить день экзамена
int compare_exam_days(Exam *ptr_to_exam, char field[])
{
    return strcmp(ptr_to_exam->exam_day, field);
}

//сравнить время экзамена
int compare_exam_times(Exam *ptr_to_exam, char field[])
{
    return strcmp(ptr_to_exam->exam_time, field);
}
