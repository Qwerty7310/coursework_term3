#include "struct_exam.h"
#include "print_DB.h"

//���������� ������ ������
void add_exam(Exam **list_of_exams, Exam *new_exam)
{
    if ((*list_of_exams)->next == nullptr) //�᫨ ᯨ᮪ ������� ����
    {
        *list_of_exams = new_exam;
        (*list_of_exams)->next = *list_of_exams; //㪠��⥫� �� ᫥���騩 㧥� 㪠�뢠�� �� ᠬ �����
        return; //��� �� �㭪樨
    }
    //���樠����஢��� 㪠��⥫� ��� ��室� �� ᯨ�� � ���᪠� ����
    Exam *ptr_to_exam = (*list_of_exams)->next;
    //���� �� ��諨 �� ��᫥����� �����
    while(ptr_to_exam->next != *list_of_exams)
        ptr_to_exam = ptr_to_exam->next; //��६����� 㪠��⥫� �� ᫥���騩 �����
    //������塞 ���� �����
    ptr_to_exam->next = new_exam;
    new_exam->next = *list_of_exams;
}

//㤠���� �����
void delete_exam(Exam **list_of_exams, Exam **exam, Group **list_of_groups, bool question)
{
    if (question)
    {
        cout << "\n�� 㢥७�, �� ��� 㤠���� �����?\n";
        cout << "������ \"1\", �᫨ ��� 㤠���� �����, ��� �� ��㣮� ᨬ���, �⮡� ��� � ������� ����: ";
        char answer;
        cin >> answer;
        cin.clear(); //���⪠ �����
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //㤠���� '\n', ��⠢訩�� ��᫥ �����
        if (answer != '1')
        {
            cout << "\n������� �� 㤠���.";
            return;
        }
    }


    if (list_of_groups)
    {
        //㬥��蠥� ������⢮ ������� � ��㯯� �� 1
        Group *ptr_to_group = search_group(*list_of_groups, (*exam)->group);
        ptr_to_group->number_of_exams = ptr_to_group->number_of_exams - 1;
        //�᫨ ����� �� ⮫쪮 1, 㤠�塞 ��㯯�
        if (ptr_to_group->number_of_exams == 0) delete_group(list_of_groups, &ptr_to_group);
    }


    if (*exam == *list_of_exams) //�᫨ 㤠�塞 ���� � ᯨ᪥ �����
    {
        //�᫨ � ᯨ᪥ ⮫쪮 ���� �����
        if ((*exam)->next == *list_of_exams)
        {
            (*list_of_exams)->next = nullptr;
            int i = 0;
            while ((*list_of_exams)->group[i] != '\0')
            {
                (*list_of_exams)->group[i] = '\0';
                i++;
            }
            if (question) cout << "\n������� 㤠���.\n";
            return;
        }
        //�᫨ � ᯨ᪥ ��᪮�쪮 �������
        *list_of_exams = (*exam)->next; //������ ������� ᯨ᪠ ᫥���騩 �����
        //���樠�����㥬 㪠��⥫� ��� ��室� ᯨ᪠
        Exam *ptr_to_exam = (*list_of_exams)->next;
        //���� �� ��諨 �� ���� ᯨ᪠, ��।������ 㪠��⥫�
        while (ptr_to_exam->next != *exam) ptr_to_exam = ptr_to_exam->next;
        ptr_to_exam->next = *list_of_exams; //���塞 㪠��⥫� ��᫥����� ����� �� 㪠��⥫� �� ����� ������ ᯨ᪠
        delete *exam; //㤠�塞 �����
        if (question) cout << "\n������� 㤠���.\n";
        return;
    }
    //�᫨ 㤠�塞 �� ���� �����
    Exam *ptr_to_exam = *list_of_exams;
    //���� �� ᯨ��, ���� �� ��諨 �� 㤠�塞��� �����
    while (ptr_to_exam->next != *exam) ptr_to_exam = ptr_to_exam->next;
    ptr_to_exam->next = (*exam)->next; //���塞 㪠��⥫� �।��饣� �����
    delete *exam; //㤠�塞 �����
    if (question) cout << "\n������� 㤠���.\n";
}

//�������� ����� ��㯯� � ᯨ᮪ ��㯯
Group* add_group(Group **list_of_groups, char new_group[])
{
    //�᫨ ᯨ᮪ ����
    if ((*list_of_groups)->next == nullptr)
    {
        int i = 0;
        //�����뢠�� �������� ��㯯� � �������� ����� ᯨ᪠
        while (new_group[i] != '\0')
        {
            (*list_of_groups)->name_of_group[i] = new_group[i];
            i++;
        }
        (*list_of_groups)->next = *list_of_groups; //������殢뢠�� ᯨ᮪
        return *list_of_groups; //��室�� �� �㭪樨
    }
    //���樠�����㥬 㪠��⥫� ��� ��室� ᯨ᪠
    Group *ptr_to_group = *list_of_groups;
    //��室�� �� ���� ᯨ᪠ � ��⠭���������� �� ��᫥���� �����
    while (ptr_to_group->next != *list_of_groups) ptr_to_group = ptr_to_group->next;
    auto *group = new Group; //ᮧ���� ���� ����� ᯨ᪠
    //�����뢠�� �������� ��㯯�
    int i = 0;
    while (new_group[i] != '\0')
    {
        group->name_of_group[i] = new_group[i];
        i++;
    }
    //���塞 㪠��⥫�
    ptr_to_group->next = group;
    group->next = *list_of_groups;
    return group;
}

//㤠���� ��㯯� �� ᯨ᪠ ��㯯
void delete_group(Group **list_of_groups, Group **group)
{
    if (*group == *list_of_groups) //�᫨ 㤠�塞�� ��㯯� ��ࢠ� � ᯨ᪥
    {
        if ((*list_of_groups)->next == *list_of_groups) //�᫨ 㤠�塞�� ��㯯� ���� � ᯨ᪥
        {
            //��頥� ���� ��������
            int i = 0;
            while ((*list_of_groups)->name_of_group[i] != '\0')
            {
                (*list_of_groups)->name_of_group[i] = '\0';
                i++;
            }
            (*list_of_groups)->number_of_exams = 0; //����塞 �᫮ �������
            (*list_of_groups)->next = nullptr; //����塞 㪠��⥫� �� ᫥���騩 㧥�
            return; //��室�� �� �㭪樨
        }
        //�᫨ �� ���� � ᯨ᪥
        *list_of_groups = (*group)->next; //���塞 㪠��⥫� �� ᫥���騩 㧥�
        //���樠�����㥬 㪠��⥫� ��� ��室� ᯨ᪠
        Group *ptr_to_group = *list_of_groups;
        //��室�� �� ���� ᯨ᪠
        while (ptr_to_group->next != *group) ptr_to_group = ptr_to_group->next;
        ptr_to_group->next = *list_of_groups; //㪠��⥫� ��᫥����� ����� �� ������ ᯨ᪠
        delete *group; //㤠�塞 ��㯯�
        group = nullptr;
        return; //��室 �� �㭪樨
    }
    //���樠�����㥬 㪠��⥫� ��� ��室� ᯨ᪠
    Group *ptr_to_group = *list_of_groups;
    //��室�� �� ���� ᯨ᮪
    while (ptr_to_group->next != *group) ptr_to_group = ptr_to_group->next;
    ptr_to_group->next = (*group)->next; //���塞 㪠��⥫�
    delete *group; //㤠�塞 ��㯯�
    group = nullptr;
}

//���� �����
Exam* search_exam(Exam **list_of_exams, char group[], char subject[])
{
    //�᫨ ᯨ᮪ ������� ����
    if ((*list_of_exams)->next == nullptr)
    {
        return nullptr; //������ ���⮩ 㪠��⥫�
    }
    //���樠�����㥬 㪠��⥫� ��� ��宦����� ᯨ᪠
    Exam *ptr_to_exam = *list_of_exams;
    bool first_iteration = true; //䫠� ��ࢮ�� ��宦����� 横��
    //���� �� ��諨 �� ���� ᯨ᪠
    while (ptr_to_exam != *list_of_exams || first_iteration)
    {
        first_iteration = false;
        //�᫨ ��諨 �।��� � �������� ��㯯�
        if (strcmp(group, ptr_to_exam->group) == 0 && strcmp(subject, ptr_to_exam->subject) == 0)
        {
            return ptr_to_exam; //�����頥� ���� ���������� ������
        }
        ptr_to_exam = ptr_to_exam->next; //��।������ 㪠��⥫� �� ᫥���騩 㧥�
    }
    return nullptr; //�᫨ ��祣� �� ��諨, �����頥� �㫥��� 㪠��⥫�
}

//���� ��㯯�
Group* search_group(Group *list_of_groups, char group[])
{
    //�஢�ઠ ᯨ᪠ �� ������
    if (list_of_groups->next == nullptr)
        return nullptr; //�����頥� ���⮩ 㪠��⥫�
    //���樠�����㥬 㪠��⥫� ��� ��宦����� ᯨ᪠
    Group *ptr_to_group = list_of_groups;
    bool first_iteration = true; //䫠� ��ࢮ�� ��宦����� 横��
    //���� �� ��諨 �� ���� ᯨ᪠
    while (ptr_to_group != list_of_groups || first_iteration)
    {
        first_iteration = false;
        if (strcmp(group, ptr_to_group->name_of_group) == 0)
        {
            return ptr_to_group; //�᫨ ��諨, �����頥� true
        }
        ptr_to_group = ptr_to_group->next; //��।������ 㪠��⥫� �� ᫥���騩 㧥�
    }
    return nullptr; //�᫨ ��祣� �� ��諨, �����頥� �㫥��� 㪠��⥫�
}


void delete_list(Exam **list_of_exams, Group **list_of_groups)
{
    if ((*list_of_exams)->next == nullptr)
    {
        cout << "��� ��ப ��� ���஢��. ���� ������ ����.\n\n";
        return;
    }
    Exam *ptr_to_exam = *list_of_exams;
    while (ptr_to_exam->next != *list_of_exams)
    {
        Exam *temp = ptr_to_exam;
        ptr_to_exam = ptr_to_exam->next;
        delete_exam(list_of_exams, &temp, list_of_groups, false);
    }
    delete_exam(list_of_exams, list_of_exams,list_of_groups, false);
}

//������� ����� ��ப�
int get_length(char *str)
{
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}