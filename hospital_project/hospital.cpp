#include <iostream>
using namespace std;
// defination of global varible
struct S_pateint
{
    string name;
    int status;
};
struct S_specialization
{
    S_pateint add[5];
};
S_specialization patients[20];
// defination of functions
int Add_new_patient()
{
    int test = 0, specialization;
    cout << "Enter the spcialization number (1...20)\n";
    cin >> specialization;
    if (specialization - 1 < 0 || specialization - 1 > 19)
    {
        cout << "sorry,choice mistake!!\n";
        return 0;
    }
    for (int i = 0; i < 5; i++)
    {
        if (patients[specialization - 1].add[i].name == "")
        {
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, patients[specialization - 1].add[i].name);
            cout << "Enter the status(regular 0),(urgent 1): ";
            cin >> patients[specialization - 1].add[i].status;

            if (patients[specialization - 1].add[i].status == 1)
            {
                string temp_name;
                int temp_status;
                temp_name = patients[specialization - 1].add[i].name;
                temp_status = patients[specialization - 1].add[i].status;

                for (int k = 0; k < i; k++)
                {
                    patients[specialization - 1].add[i - k].name = patients[specialization - 1].add[i - 1 - k].name;
                    patients[specialization - 1].add[i - k].status = patients[specialization - 1].add[i - 1 - k].status;
                }
                patients[specialization - 1].add[0].name = temp_name;
                patients[specialization - 1].add[0].status = temp_status;
            }
            test = 1;
            return 1;
        }
    }
    if (!test)
        cout << "sorry the list is full. \n";
    return 1;
}
void Print_all_patient()
{
    cout << "****************************\n";
    for (int i = 0; i < 20; i++)
    {
        bool hasPatients = false;
        for (int j = 0; j < 5; j++)
        {
            if (!patients[i].add[j].name.empty())
            {
                if (!hasPatients)
                {
                    cout << "Specialization " << (i + 1) << " Patients:\n";
                    hasPatients = true;
                }
                cout << "- " << patients[i].add[j].name << " (";
                cout << (patients[i].add[j].status == 1 ? "Urgent" : "Regular") << ")\n";
            }
        }
    }
}

int get_next_patient()
{
    int special_num;
    cout << "Enter the Specialization(1...20): ";
    cin >> special_num;
    if (special_num - 1 < 0 || special_num - 1 > 19)
    {
        cout << "sorry,choice mistake!!\n";
        return 0;
    }
    if (patients[special_num - 1].add[0].name == "")
    {
        cout << "No patients at the moment . Have rest,Dr \n";
        return 0;
    }
    cout << patients[special_num - 1].add[0].name << " please go with the Dr\n";
    for (int i = 0; i < 5; i++)
    {
        if (patients[special_num - 1].add[i].name == "")
        {
            for (int j = 0; j < i; j++)
            {
                patients[special_num - 1].add[j].name = patients[special_num - 1].add[j + 1].name;
                patients[special_num - 1].add[j].status = patients[special_num - 1].add[j + 1].status;
            }
            return 1;
        }
    }
}
int main()
{
    int choice;
    char n;
    bool check = true;
    while (check)
    {
        cout << "1)Add new patient" << endl;
        cout << "2)Print all patient" << endl;
        cout << "3)Get next patient" << endl;
        cout << "4)Exit" << endl;
        cout << "Enter your choice :";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Add_new_patient();
            break;
        case 2:
            Print_all_patient();
            break;
        case 3:
            get_next_patient();
            break;
        case 4:
            break;
        default:
            cout << "sorry your choice is not found!!";
        }
        if (choice != 4)
        {
            cout << "Do you want to continue (y/n)? ";
            cin >> n;
            if (n != 'y' && n != 'Y')
                check = false;
        }
    }
}
