#include <iostream>
#include <string>

using namespace std;

struct Movie {
    string title;
    string director;
    int releaseYear;
    float rating;

    Movie *next;
};

Movie *head, *cur, *tail, *newNode;

void createSingleLinkedList(string title, string director, int releaseYear, float rating){
    head = new Movie();
    head->title = title;
    head->director = director;
    head->releaseYear = releaseYear;
    head->rating = rating;
    head->next = NULL;
    tail = head;
}

void addBeginning(string title, string director, int releaseYear, float rating) {
    newNode = new Movie();
    newNode->title = title;
    newNode->director = director;
    newNode->releaseYear = releaseYear;
    newNode->rating = rating;
    newNode->next = head;
    head = newNode;
}

// void addMiddle(string title, string director, int releaseYear, float rating) {
//     newNode = new Movie();
//     newNode->title = title;
//     newNode->director = director;
//     newNode->releaseYear = releaseYear;
//     newNode->rating = rating;
//     head->next = newNode;
// }

void addLast(string title, string director, int releaseYear, float rating) {
    newNode = new Movie();
    newNode->title = title;
    newNode->director = director;
    newNode->releaseYear = releaseYear;
    newNode->rating = rating;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}
void deleteBeginning() {
    cur = head;
    head = head->next;
    delete cur;
}

void deleteLast() {
    
}

void printList() {
    cur = head;
    while(cur != NULL) {
        cout << cur->title << endl;
        cout << cur->director << endl;
        cout << cur->releaseYear << endl;
        cout << cur->rating << endl << endl;

        cur = cur->next;
    }
}

int main(int argc, char const *argv[])
{
    createSingleLinkedList("A", "Udin", 1998, 5.5);

    addBeginning("B", "Joko", 2003, 7.4);

    addLast("C", "Budi", 2001, 7.8);

    deleteBeginning();

    printList();

    return 0;
}
