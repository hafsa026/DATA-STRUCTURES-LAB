// DoublyTask3_Inventory.cpp
#include <iostream>
#include <string>
using namespace std;

struct Item {
    string name;
    int qty;
    Item* next;
    Item(string n, int q) : name(n), qty(q), next(NULL) {}
};

struct Section {
    string name;
    Item* items;
    Section* next;
    Section(string n) : name(n), items(NULL), next(NULL) {}
};

struct Store {
    string name;
    Section* sections;
    Store* next;
    Store(string n) : name(n), sections(NULL), next(NULL) {}
};

Store* storeHead = NULL;

Store* findStore(string name) {
    Store* s = storeHead;
    while (s != NULL) {
        if (s->name == name) return s;
        s = s->next;
    }
    return NULL;
}

Section* findSection(Store* store, string name) {
    Section* sec = store->sections;
    while (sec != NULL) {
        if (sec->name == name) return sec;
        sec = sec->next;
    }
    return NULL;
}

void addStore(string name) {
    Store* newStore = new Store(name);
    if (storeHead == NULL) { storeHead = newStore; return; }
    Store* temp = storeHead;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newStore;
}

void addSection(string storeName, string secName) {
    Store* store = findStore(storeName);
    if (store == NULL) { cout << "Store not found\n"; return; }

    Section* newSec = new Section(secName);
    if (store->sections == NULL) {
        store->sections = newSec;
        return;
    }
    Section* temp = store->sections;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newSec;
}

void addItem(string storeName, string secName, string itemName, int qty) {
    Store* store = findStore(storeName);
    if (store == NULL) { cout << "Store not found\n"; return; }

    Section* sec = findSection(store, secName);
    if (sec == NULL) { cout << "Section not found\n"; return; }

    Item* newItem = new Item(itemName, qty);
    if (sec->items == NULL) {
        sec->items = newItem;
        return;
    }
    Item* temp = sec->items;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newItem;
}

void removeItem(string storeName, string secName, string itemName) {
    Store* store = findStore(storeName);
    if (store == NULL) { cout << "Store not found\n"; return; }

    Section* sec = findSection(store, secName);
    if (sec == NULL) { cout << "Section not found\n"; return; }

    Item* curr = sec->items;
    Item* prev = NULL;

    while (curr != NULL) {
        if (curr->name == itemName) {
            if (prev == NULL) sec->items = curr->next;
            else prev->next = curr->next;
            delete curr;
            cout << "Item removed\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    cout << "Item not found\n";
}

void displaySection(string storeName, string secName) {
    Store* store = findStore(storeName);
    if (store == NULL) { cout << "Store not found\n"; return; }

    Section* sec = findSection(store, secName);
    if (sec == NULL) { cout << "Section not found\n"; return; }

    cout << "Items in " << storeName << " -> " << secName << ":\n";
    Item* temp = sec->items;
    while (temp != NULL) {
        cout << "  " << temp->name << " (Qty: " << temp->qty << ")\n";
        temp = temp->next;
    }
}

void displayStore(string storeName) {
    Store* store = findStore(storeName);
    if (store == NULL) { cout << "Store not found\n"; return; }

    cout << "Store: " << storeName << endl;
    Section* sec = store->sections;
    while (sec != NULL) {
        cout << "  Section: " << sec->name << endl;
        Item* temp = sec->items;
        while (temp != NULL) {
            cout << "    - " << temp->name << " (Qty: " << temp->qty << ")\n";
            temp = temp->next;
        }
        sec = sec->next;
    }
}

int main() {
    addStore("Walmart NYC");
    addStore("Walmart LA");

    addSection("Walmart NYC", "Toys");
    addSection("Walmart NYC", "Fruits");
    addSection("Walmart LA", "Electronics");

    addItem("Walmart NYC", "Toys", "Lego", 50);
    addItem("Walmart NYC", "Toys", "Barbie", 30);
    addItem("Walmart NYC", "Fruits", "Apple", 200);
    addItem("Walmart NYC", "Fruits", "Banana", 150);
    addItem("Walmart LA", "Electronics", "TV", 25);

    displayStore("Walmart NYC");

    cout << "\n--- Removing Apple ---\n";
    removeItem("Walmart NYC", "Fruits", "Apple");
    displaySection("Walmart NYC", "Fruits");

    return 0;
}