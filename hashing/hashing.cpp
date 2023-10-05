#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct Account {
    string username;
    string passwordHash;
};

unordered_map<string, Account> acc;

int hashingFunction(string password) {
    int hash = 0;

    for (char c : password) {
        hash += c * static_cast<int>(c);
    }    

    return hash;
}

void addAccount(string username, string password) {
    if (acc.find(username) != acc.end()) {
        cout << "Username sudah terdaftar. Silakan pilih username lain." << endl;
    } else {
        Account newAccount;
        newAccount.username = username;
        newAccount.passwordHash = to_string(hashingFunction(password));

        acc[username] = newAccount;

        cout << "Akun berhasil didaftarkan!" << endl;
    }
}

bool login(string username, string password) {
    if (acc.find(username) != acc.end()) {
        int enteredPasswordHash = hashingFunction(password);

        if (acc[username].passwordHash == to_string(enteredPasswordHash)) {
            cout << "Password Hash anda adalah: " << acc[username].passwordHash << endl;
            return true;
        } else {
            cout << "Kata sandi salah." << endl;
        }
    } else {
        cout << "Akun tidak ditemukan." << endl;
    }
    return false;
}

int main() {
    int choice;
    string username;
    string password;

    while (true) {
        cout 
        << "Pilih menu" << endl
        << "1. Register" << endl
        << "2. Login" << endl
        << "3. Keluar" << endl
        << "Menu : ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout 
                << "Enter username and password" << endl
                << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;

                addAccount(username, password);
                break;

            case 2:
                cout 
                << "Enter username and password" << endl
                << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;

                login(username, password);
                break;

            case 3:
                cout << "Keluar dari program";
                return 0;
                break;

            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    }

    return 0;
}
