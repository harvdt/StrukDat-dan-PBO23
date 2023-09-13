#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    string NIM;
    int umur;
    double IPK;
};

void displayData(Mahasiswa mhs[], int size) {
    for (int i = 0; i < size; i++) {
        cout << endl << "Nama: " << mhs[i].nama << endl;
        cout << "NIM: " << mhs[i].NIM << endl;
        cout << "Umur: " << mhs[i].umur << endl;
        cout << "IPK: " << mhs[i].IPK << endl;
    }
}

void addData(Mahasiswa mhs[], int &size) {
    if(size < 0 || size > 10) {
        cout << "Array sudah penuh" << endl;
    } else {
        cout << "Nama : ";
        cin >> mhs[size].nama;
        cout << "NIM : ";
        cin >> mhs[size].NIM;
        cout << "Umur : ";
        cin >> mhs[size].umur;
        cout << "IPK : ";
        cin >> mhs[size].IPK;
        cout << endl;
        size++;
    }
}

void deleteData(Mahasiswa mhs[], int &size) {
    int pos;
    cout << "Masukkan posisi data yang akan dihapus : ";
    cin >> pos;

    if(pos > size || pos < 0) {
        cout << "Posisi tidak ditemukan" << endl;
    } else {
        for(int i = 0; i < size - 1; i++) {
            mhs[i].nama = mhs[i+1].nama;
            mhs[i].NIM = mhs[i+1].NIM;
            mhs[i].umur = mhs[i+1].umur;
            mhs[i].IPK = mhs[i+1].IPK;
        }
        size--;
    }
}

void editData(Mahasiswa mhs[], int size) {
    int pos;
    cout << "Masukkan posisi yang akan diedit : ";
    cin >> pos;
    cout << endl;

    if(pos > size || pos < 0) {
        cout << "Posisi tidak ditemukan" << endl;
    } else {
        cout << "Nama : ";
        cin >> mhs[pos].nama;
        cout << "NIM : ";
        cin >> mhs[pos].NIM;
        cout << "Umur : ";
        cin >> mhs[pos].umur;
        cout << "IPK : ";
        cin >> mhs[pos].IPK;
        cout << endl;
    }
}

int main(int argc, char const *argv[]) {
    Mahasiswa mhs[10];

    int size = 0;
    int choice;
    
    while (true) {
        cout 
        << "Pilih mode :\n" 
        << "1. Menampilkan data\n" 
        << "2. Menambah data baru\n" 
        << "3. Menghapus data\n" 
        << "4. Mengubah data\n"
        << "5. Keluar\n" 
        << "Silahkan pilih mode : ";
        
        cin >> choice;

        switch (choice)
        {
        case 1:
            displayData(mhs, size);
            break;
        case 2:
            addData(mhs, size);
            break;
        case 3:
            deleteData(mhs, size);
            break;
        case 4:
            editData(mhs, size);
            break;
        case 5:
            cout << "Keluar dari program";
            return 0;
            break;
        default:
            cout << "Opsi yang anda masukkan tidak valid" << endl; 
            break;
        }
    }

    return 0;
}
