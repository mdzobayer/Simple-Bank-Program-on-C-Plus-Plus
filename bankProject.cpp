#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <conio.h>
//#include <zobayer.h>

using namespace std;

void newWindow() {

    cout << "\n\tPress any key to Back" << endl;
    getch();
    system("CLS");
}

int menu() {
    cout << "\n\n\t+++++++++++++++++++++++" << endl;
    cout << "\t Welcome to Basic Bank" << endl;
    cout << "\t+++++++++++++++++++++++" << endl;
    //aboutMe();
    cout << "\n\t    Main Menu" << endl << endl;
    cout << "1. Exit" << endl;
    cout << "2. Client List" << endl;
    cout << "3. Add New Client" << endl;
    cout << "4. Remove Client" << endl;
    int choice;
    cout << endl << "Enter your Choice(1-4): ";
    cin >> choice;
    return choice;
}
int showClientList(vector<string> vt) {
    cout << "\tClient List" << endl << endl;
    for (int i = 0; i < vt.size(); ++i) {
        cout << i + 1 << ". " << vt[i] << endl;
    }
    cout << endl << vt.size() + 1 << ". Back" << endl;
    cout << endl;
    int choice;
    cout << "Enter Client Number(1-" << vt.size() + 1 << "): ";
    cin >> choice;
    return choice;
}
int clientProfile() {
    cout << "\tClient Option" << endl << endl;
    cout << "1. Show Balance" << endl;
    cout << "2. Credit Amount" << endl;
    cout << "3. Debit Amount" << endl;
    cout << endl << "4. Back" << endl;
    int choice;
    cout << endl << "Enter your choice(1-4): ";
    cin >> choice;
    return choice;
}
void displayAmount(int cltNum, vector<string> cltName, vector<int> cltAmount) {
    system("CLS");
    cout << endl << "\t";
    cout << cltName[cltNum] << "\t\t: " << cltAmount[cltNum]
         << " $ " << endl << endl;
    newWindow();

}
void creditAmount(int cltNum, vector<int> &vect) {
    system("CLS");
    int amount;
    cout << "Credit Amount: ";
    cin >> amount;
    vect[cltNum] += amount;
    system("CLS");
    cout << "\tOperation Successful" << endl << endl;
    cout << "  New Balance is " << vect[cltNum] << " $" << endl << endl;
    newWindow();
}
void debitAmount(int cltNum, vector<int> &vect) {
    system("CLS");
    int debitAmount;
        cout << "Debit Amount: ";
        cin >> debitAmount;
    if (debitAmount >= vect[cltNum]) {
        cout << "You can't Debit" << endl << endl;
        newWindow();
    }
    else {

        vect[cltNum] -= debitAmount;
        system("CLS");
        cout << "\tOperation Successful" << endl << endl;
        cout << "  New Balance is " << vect[cltNum] << " $" << endl << endl;
        newWindow();
    }
}
void addNewClient(vector<string> &cltName, vector<int> &cltAmount) {
    string fullName;
    int amount;
    getchar();
    cout << "Enter new Client name: ";
    getline(cin, fullName);
    cout << "Enter Balance: ";
    cin >> amount;
    cltName.push_back(fullName);
    cltAmount.push_back(amount);
}
void removeClient(vector<string> &cltName, vector<int> &cltAmount) {
    vector<string> tempName;
    vector<int> tempAmount;
    int removeClt;
    cout << "\tClient List" << endl << endl;
    for (int i = 0; i < cltName.size(); ++i) {
        cout << i + 1 << ". " << cltName[i] << endl;
    }
    cout << endl << "Which number of client you want to remove(1-" << cltName.size() << "): ";
    cin >> removeClt;
    getchar();
    for (int i = 0; i < cltName.size(); ++i) {
        if ( removeClt == i + 1) {
            continue;
        }
        string tName = cltName[i];
        tempName.push_back(tName);
    }
    for (int i = 0; i < cltAmount.size(); ++i) {
        if ( removeClt == i + 1) {
            continue;
        }
        int tAmount = cltAmount[i];
        tempAmount.push_back(tAmount);
    }
    while (!cltName.empty()) {
        cltName.pop_back();
    }
    while (!cltAmount.empty()) {
        cltAmount.pop_back();
    }
    for (int i = 0; i < tempName.size(); ++i) {
        string teName = tempName[i];
        cltName.push_back(teName);
    }
    for (int i = 0; i < tempName.size(); ++i) {
        int teAmount = tempAmount[i];
        cltAmount.push_back(teAmount);
    }
}

int main() {

    vector<string> clientName;
    vector<int> clientAmount;
    clientName.push_back("Zobayer");
    clientName.push_back("Abeer");
    clientName.push_back("Khalid Hasan");
    clientName.push_back("Pulok");
    clientAmount.push_back(25);
    clientAmount.push_back(50);
    clientAmount.push_back(75);
    clientAmount.push_back(45);

    int profileNum, clientOption, backVal;
    label1:
    system("CLS");
    int option = menu();
    system("CLS");
    switch(option) {
        case 1:
            cout << "\n\n\t\tProgram Exit Successfully" << endl;
            return EXIT_SUCCESS;
        case 2:
            label:
            system("CLS");
            profileNum = showClientList(clientName);
            if (profileNum == clientName.size() + 1) {
                goto label1;
            }
            system ("CLS");
            label2:
            clientOption = clientProfile();
            switch(clientOption) {
                case 1:
                    displayAmount(profileNum - 1, clientName, clientAmount);
                    break;
                case 2:
                    creditAmount(profileNum - 1, clientAmount);
                    break;
                case 3:
                    debitAmount(profileNum - 1, clientAmount);
                    break;
                case 4:
                    goto label;
                default:
                    cout << "\a\tWrong Input!" << endl;
                    break;
            };
            goto label2;

            break;
        case 3:
            addNewClient(clientName, clientAmount);
            goto label1;
            break;
        case 4:
            removeClient(clientName, clientAmount);
            cout << endl << "\t    Successful";
            newWindow();
            goto label1;
            break;
        default:
            cout << "\a\tWrong Input!" << endl;
            break;
    }

    return EXIT_SUCCESS;
}
