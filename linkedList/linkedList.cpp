#include <iostream>
#include <string>

using namespace std;

struct Movie {
    string title;
    int releaseYear;
    float rating;
    Movie *next;
};

Movie *head, *current, *tail, *newNode, *temp;

void addMovie() {
    Movie *newMovie = new Movie;
    cout << "Masukkan judul film: ";
    cin.ignore();
    getline(cin, newMovie->title);
    cout << "Masukkan tahun rilis: ";
    cin >> newMovie->releaseYear;
    cout << "Masukkan rating: ";
    cin >> newMovie->rating;
    newMovie->next = NULL;

    int position;
    cout << "Masukkan posisi film (1: Awal, 2: Akhir, 3: Tengah): ";
    cin >> position;

    if (position == 1) {
        newMovie->next = head;
        head = newMovie;
        cout << "Film berhasil ditambahkan di awal daftar" << endl;
    } else if (position == 2) {
        if (head == NULL) {
            head = tail = newMovie;
        } else {
            tail->next = newMovie;
            tail = newMovie;
        }
        cout << "Film berhasil ditambahkan di akhir daftar" << endl;
    } else if (position == 3) {
        if (head == NULL) {
            head = tail = newMovie;
        } else {
            int pos;
            cout << "Masukkan posisi tengah film (setelah film ke-berapa): ";
            cin >> pos;
            Movie *current = head;
            int currentPos = 1;
            while (current != NULL && currentPos < pos) {
                current = current->next;
                currentPos++;
            }
            if (current == NULL) {
                cout << "Posisi tengah tidak valid" << endl;
                delete newMovie;
                return;
            }
            newMovie->next = current->next;
            current->next = newMovie;
        }
        cout << "Film berhasil ditambahkan di tengah daftar" << endl;
    } else {
        cout << "Pilihan tidak valid" << endl;
        delete newMovie;
        return;
    }
}

void deleteMovie() {
    if (head == NULL) {
        cout << "Daftar film kosong" << endl;
        return;
    }

    int position;
    cout << "Masukkan posisi film yang ingin dihapus (1: Awal, 2: Akhir, 3: Tengah): ";
    cin >> position;

    if (position == 1) {
        Movie *temp = head;
        head = head->next;
        delete temp;
        cout << "Film di awal daftar berhasil dihapus" << endl;
    } else if (position == 2) {
        if (head == tail) {
            delete head;
            head = tail = NULL;
        } else {
            Movie *current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = NULL;
        }
        cout << "Film di akhir daftar berhasil dihapus" << endl;
    } else if (position == 3) {
        int pos;
        cout << "Masukkan posisi tengah film (setelah film ke-berapa): ";
        cin >> pos;
        Movie *current = head;
        int currentPos = 1;
        while (current != NULL && currentPos < pos) {
            current = current->next;
            currentPos++;
        }
        if (current == NULL || current->next == NULL) {
            cout << "Posisi tengah tidak valid" << endl;
            return;
        }
        Movie *temp = current->next;
        current->next = current->next->next;
        delete temp;
        cout << "Film di tengah daftar berhasil dihapus" << endl;
    } else {
        cout << "Pilihan tidak valid" << endl;
        return;
    }
}

void editMovie() {
    if (head == NULL) {
        cout << "Daftar film kosong" << endl;
        return;
    }

    string title;
    int releaseYear;
    float rating;

    cout << "Masukkan judul film: ";
    cin.ignore();
    getline(cin, title);
    cout << "Masukkan tahun rilis: ";
    cin >> releaseYear;
    cout << "Masukkan rating: ";
    cin >> rating;

    int position;
    cout << "Masukkan posisi film yang ingin diedit (1: Awal, 2: Akhir, 3: Tengah): ";
    cin >> position;

    if (position == 1) {
        head->title = title;
        head->releaseYear = releaseYear;
        head->rating = rating;
    } else if (position == 2) {
        tail->title = title;
        tail->releaseYear = releaseYear;
        tail->rating = rating;
    } else if (position == 3) {
        int pos;
        cout << "Masukkan posisi tengah film (setelah film ke-berapa): ";
        cin >> pos;
        Movie *current = head;
        int currentPos = 1;
        while (current != NULL && currentPos < pos) {
            current = current->next;
            currentPos++;
        }
        if (current == NULL || current->next == NULL) {
            cout << "Posisi tengah tidak valid" << endl;
            return;
        }
        current->next->title = title;
        current->next->releaseYear = releaseYear;
        current->next->rating = rating;
    } else {
        cout << "Pilihan tidak valid" << endl;
        return;
    }
}

void printMovie() {
    if (head == NULL) {
        cout << "Daftar film kosong" << endl;
        return;
    }

    Movie *current = head;
    while (current != NULL) {
        cout << "Judul: " << current->title << endl;
        cout << "Tahun Rilis: " << current->releaseYear << endl;
        cout << "Rating: " << current->rating << endl << endl;

        current = current->next;
    }
}

int main(int argc, char const *argv[])
{
    int choice;

    while (true) {
        cout 
        << "Pilih menu: \n"
        << "1. Tambahkan data\n"
        << "2. Hapus data\n"
        << "3. Edit data\n"
        << "4. Print seluruh data\n"
        << "5. Keluar\n"
        << "Menu: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addMovie();
            break;
        case 2:
            deleteMovie();
            break;
        case 3:
            editMovie();
            break;
        case 4:
            printMovie();
            break;
        case 5:
            cout << "Keluar dari program";
            return 0;
            break;
        default:
            cout << "Input tidak valid"; 
            break;
        }
    }

    return 0;
}
