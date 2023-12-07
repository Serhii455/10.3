#include <iostream>
#include <fstream>

using namespace std;

struct Friend {
    string name, surname;
    int phone;
    int birthday[3];
};

bool IfFileOpen(const string& filename) 
{
    int test_variable;

    ifstream F(filename);
    if (!F.is_open()) {
        cout << "Can't open the file" << endl;
        test_variable = 0;
        return false;
    }
    return true;
    test_variable = 1;
}

void ReadTheFile(const string& filename, Friend list[], int& n) {
    ifstream F(filename);
    if (!F.is_open()) {
        cout << "Can't open the file" << endl;
        return;
    }
    F >> n;
    for (int i = 0; i < n; i++) {
        if (F >> list[i].surname >> list[i].name >> list[i].phone >> list[i].birthday[0] >> list[i].birthday[1] >> list[i].birthday[2]) {
            // Вивід, якщо зчитано успішно
        }
        else {
            cout << "Invalid data in the file." << endl;
            return;
        }
    }
    F.close();
}

void CoutInfo(Friend list[], int n) {
    cout << "-------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Surname: " << list[i].surname << endl;
        cout << "Name: " << list[i].name << endl;
        cout << "Number: " << list[i].phone << endl;
        cout << "Date of birth: " << list[i].birthday[0] << "." << list[i].birthday[1] << "." << list[i].birthday[2] << endl;
        cout << "------------------------" << endl;
    }
}

void AddFriend(const string& filename, Friend list[], int& n) {
    // Перевірка на обмеження кількості друзів
    if (n >= 100) {
        cout << "Cannot add more friends. The limit is reached." << endl;
        return;
    }

    ofstream outFile(filename, ios::app); // Відкриття файлу для додавання даних в кінець

    if (!outFile.is_open()) {
        cout << "Can't open the file" << endl;
        return;
    }

    cout << "Enter the surname: ";
    cin >> list[n].surname;

    cout << "Enter the name: ";
    cin >> list[n].name;

    cout << "Enter the phone number: ";
    cin >> list[n].phone;

    cout << "Enter the date of birth (day month year): ";
    cin >> list[n].birthday[0] >> list[n].birthday[1] >> list[n].birthday[2];

    outFile << list[n].surname << " " << list[n].name << " " << list[n].phone << " "
        << list[n].birthday[0] << " " << list[n].birthday[1] << " " << list[n].birthday[2] << endl;

    n++;

    outFile.close();
}

void FindByMonth(Friend list[], int n) {
    int month;
    cout << "Enter the month to find: ";
    cin >> month;

    cout << "Friends born in month " << month << ":" << endl;
    cout << "-------------------------" << endl;
    for (int i = 0; i < n; i++) {
        if (list[i].birthday[1] == month) {
            cout << "Surname: " << list[i].surname << endl;
            cout << "Name: " << list[i].name << endl;
            cout << "Number: " << list[i].phone << endl;
            cout << "Date of birth: " << list[i].birthday[0] << "." << list[i].birthday[1] << "." << list[i].birthday[2] << endl;
            cout << "------------------------" << endl;
        }
    }
}

int main() {
    string filename;
    cout << "Enter the file name: ";
    cin >> filename;

    if (!IfFileOpen(filename)) {
        return 1;
    }

    ifstream F(filename);
    Friend list[100];
    int n = 0;

    ReadTheFile(filename, list, n);

    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. View list" << endl;
        cout << "2. Add to list" << endl;
        cout << "3. Find by month" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            CoutInfo(list, n);
            break;
        case 2:
            AddFriend(filename, list, n);
            break;
        case 3:
            FindByMonth(list, n);
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (true);

    F.close();
    return 0;
}