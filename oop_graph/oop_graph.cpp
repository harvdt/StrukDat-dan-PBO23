#include <iostream>
#include <stack>
#include <list>
#include <stdio.h>
using namespace std;

class Titik
{
public:
    int id;
    string nama_tempat;
    int x;
    int y;

    Titik(int id, string nama_tempat, int x, int y)
    {
        this->id = id;
        this->nama_tempat = nama_tempat;
        this->x = x;
        this->y = y;
    }
};

class Peta
{
private:
    int jumlah_titik;
    list<int> *adjacency_list;
    list<Titik> *adjacency_list_titik;
    int **adjacency_matrix;

public:
    Peta(int jumlah_titik)
    {
        this->jumlah_titik = jumlah_titik;
        this->inisialisasiAdjList(jumlah_titik);
        this->inisialisasiAdjListTitik(jumlah_titik);
        this->inisialisasiAdjMatrix(jumlah_titik);
    }

    ~Peta()
    {
        delete[] adjacency_list;
        delete[] adjacency_list_titik;
    }

    void inisialisasiAdjList(int jumlah_titik)
    {
        adjacency_list = new list<int>[jumlah_titik];
    }

    void inisialisasiAdjListTitik(int jumlah_titik)
    {
        adjacency_list_titik = new list<Titik>[jumlah_titik];
        adjacency_list_titik[0].push_back(Titik(0, "Kos", 50, 350));
        adjacency_list_titik[1].push_back(Titik(1, "Sakinah", 150, 375));
        adjacency_list_titik[2].push_back(Titik(2, "Tower 2 ITS", 150, 325));
        adjacency_list_titik[3].push_back(Titik(3, "Perumdos Blok U", 125, 300));
        adjacency_list_titik[4].push_back(Titik(4, "Tower 1 ITS", 200, 300));
        adjacency_list_titik[5].push_back(Titik(5, "Perpustakaan ITS", 150, 275));
        adjacency_list_titik[6].push_back(Titik(6, "Gedung Robotika", 150, 200));
        adjacency_list_titik[7].push_back(Titik(7, "Bundaran ITS", 200, 100));
        adjacency_list_titik[8].push_back(Titik(8, "Bundaran Mulyosari", 100, 100));
        adjacency_list_titik[9].push_back(Titik(9, "BME", 0, 400));
    }

    void inisialisasiAdjMatrix(int jumlah_titik)
    {
        adjacency_matrix = new int *[jumlah_titik];
        for (int i = 0; i < jumlah_titik; i++)
        {
            adjacency_matrix[i] = new int[jumlah_titik];
            for (int j = 0; j < jumlah_titik; j++)
            {
                adjacency_matrix[i][j] = 0;
            }
        }
    }

    void tambahLintasan(int titik_awal, int titik_tujuan)
    {
        adjacency_matrix[titik_awal][titik_tujuan] += 1;
        adjacency_matrix[titik_tujuan][titik_awal] += 1;

        adjacency_list[titik_awal].push_back(titik_tujuan);

        adjacency_list_titik[titik_awal].push_back(adjacency_list_titik[titik_tujuan].front());
    }

    void tampilkanAdjList()
    {
        list<int>::iterator i;

        for (int v = 0; v < jumlah_titik; v++)
        {
            cout << v << " -> ";
            for (i = adjacency_list[v].begin(); i != adjacency_list[v].end(); ++i)
            {
                cout << (*i);
                if (next(i, 1) != adjacency_list[v].end())
                {
                    cout << " -> ";
                }
            }
            cout << endl;
        }
    }

    void tampilkanAdjListTitik()
    {
        for (int v = 0; v < jumlah_titik; v++)
        {
            list<Titik> places = adjacency_list_titik[v];
            for (const Titik &titik : places)
            {
                cout << titik.nama_tempat;
                if (&titik != &places.back())
                {
                    cout << " -> ";
                }
            }
            cout << endl;
        }
    }

    void tampilkanAdjMatrix()
    {
        for (int i = 0; i < jumlah_titik; i++)
        {
            for (int j = 0; j < jumlah_titik; j++)
            {
                cout << adjacency_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int jumlah_titik = 10;
    Peta petaKu(jumlah_titik);

    petaKu.tambahLintasan(0, 1);
    petaKu.tambahLintasan(0, 8);
    petaKu.tambahLintasan(0, 9);
    petaKu.tambahLintasan(1, 0);
    petaKu.tambahLintasan(1, 2);
    petaKu.tambahLintasan(1, 4);
    petaKu.tambahLintasan(1, 9);
    petaKu.tambahLintasan(2, 1);
    petaKu.tambahLintasan(2, 3);
    petaKu.tambahLintasan(2, 4);
    petaKu.tambahLintasan(3, 2);
    petaKu.tambahLintasan(3, 5);
    petaKu.tambahLintasan(4, 1);
    petaKu.tambahLintasan(4, 2);
    petaKu.tambahLintasan(4, 7);
    petaKu.tambahLintasan(5, 3);
    petaKu.tambahLintasan(5, 6);
    petaKu.tambahLintasan(6, 5);
    petaKu.tambahLintasan(6, 7);
    petaKu.tambahLintasan(6, 8);
    petaKu.tambahLintasan(7, 4);
    petaKu.tambahLintasan(7, 6);
    petaKu.tambahLintasan(7, 8);
    petaKu.tambahLintasan(8, 0);
    petaKu.tambahLintasan(8, 6);
    petaKu.tambahLintasan(8, 7);
    petaKu.tambahLintasan(9, 0);
    petaKu.tambahLintasan(9, 1);

    cout << endl;
    cout << "Adjacency List" << endl;
    petaKu.tampilkanAdjList();

    cout << endl;
    cout << "Adjacency List Titik" << endl;
    petaKu.tampilkanAdjListTitik();

    cout << endl;
    cout << "Adjacency Matrix" << endl;
    petaKu.tampilkanAdjMatrix();

    return 0;
}
