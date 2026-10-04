// DoublyTask2_MusicPlayer.cpp
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node* next;
    Node* prev;
    Node(string s) : song(s), next(NULL), prev(NULL) {}
};

Node* head = NULL;
Node* tail = NULL;
Node* current = NULL;

void addSong(string name) {
    Node* newNode = new Node(name);
    if (head == NULL) {
        head = tail = current = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void playNext() {
    if (current->next != NULL) {
        current = current->next;
        cout << "Now Playing: " << current->song << endl;
    } else {
        cout << "End of playlist." << endl;
    }
}

void playPrev() {
    if (current->prev != NULL) {
        current = current->prev;
        cout << "Now Playing: " << current->song << endl;
    } else {
        cout << "Start of playlist." << endl;
    }
}

void display() {
    Node* temp = head;
    cout << "Playlist: ";
    while (temp != NULL) {
        cout << temp->song << " | ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    addSong("Song1");
    addSong("Song2");
    addSong("Song3");

    display();

    cout << "\nNow Playing: " << current->song << endl;
    playNext();
    playNext();
    playPrev();

    return 0;
}