#include <iostream>
using namespace std;

struct Node {
    string nama;
    int usia;
    Node* next;
    Node(string n, int u) : nama(n), usia(u), next(NULL) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(NULL) {}

    ~LinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void insertFront(string nama, int usia) {
        Node* newNode = new Node(nama, usia);
        newNode->next = head;
        head = newNode;
    }

    void insertBack(string nama, int usia) {
        Node* newNode = new Node(nama, usia);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    void insertAfter(string prevNama, string nama, int usia) {
        Node* current = head;
        while (current != NULL) {
            if (current->nama == prevNama) {
                Node* newNode = new Node(nama, usia);
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        cout << "Node dengan nama " << prevNama << " tidak ditemukan" << endl;
    }

    void deleteNode(string nama) {
        if (head == NULL) {
            cout << "Linked list kosong" << endl;
            return;
        }
        if (head->nama == nama) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next != NULL) {
            if (current->next->nama == nama) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
        cout << "Node dengan nama " << nama << " tidak ditemukan" << endl;
    }

    void updateNode(string nama, string newNama, int newUsia) {
        Node* current = head;
        while (current != NULL) {
            if (current->nama == nama) {
                current->nama = newNama;
                current->usia = newUsia;
                return;
            }
            current = current->next;
        }
        cout << "Node dengan nama " << nama << " tidak ditemukan" << endl;
    }

    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->nama << "\t" << current->usia << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList list;

    list.insertFront("Wisnu", 21); // Adjusted to provide actual age for the placeholder

    list.insertBack("John", 19);
    list.insertBack("Jane", 20);
    list.insertBack("Reyn", 18); // Changed from Michael to Reyn
    list.insertBack("Yusuke", 19);
    list.insertBack("Akechi", 20);
    list.insertBack("Hoshino", 18);
    list.insertBack("Karin", 18);

    // Hapus data Akechi
    list.deleteNode("Akechi");

    // Tambahkan data Futaba setelah John
    list.insertAfter("John", "Futaba", 18);

    // Tambahkan data Igor di awal
    list.insertFront("Igor", 20);

    // Tampilkan seluruh data
    cout << "Nama\tUsia" << endl;
    list.display();

    return 0;
}

