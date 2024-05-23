#include <iostream>
using namespace std;

struct Node {
    string nama;
    int usia;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void insertFront(string nama, int usia) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = head;
        head = newNode;
    }

    void insertBack(string nama, int usia) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    void insertAfter(string prevNama, string nama, int usia) {
        Node* current = head;
        while (current != nullptr) {
            if (current->nama == prevNama) {
                Node* newNode = new Node;
                newNode->nama = nama;
                newNode->usia = usia;
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        cout << "Node dengan nama " << prevNama << " tidak ditemukan" << endl;
    }

    void deleteNode(string nama) {
        if (head == nullptr) {
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
        while (current->next != nullptr) {
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
        while (current != nullptr) {
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
        while (current != nullptr) {
            cout << current->nama << "\t" << current->usia << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList list;

    list.insertFront("Nama_anda", Usia_anda);

    list.insertBack("John", 19);
    list.insertBack("Jane", 20);
    list.insertBack("Michael", 18);
    list.insertBack("Yusuke", 19);
    list.insertBack("Akechi", 20);
    list.insertBack("Hoshino", 18);
    list.insertBack("Karin", 18);

    // Hapus data Akechi
    list.deleteNode("Akechi");

    // Tambahkan data Futaba setelah John dan Jane
    list.insertAfter("John", "Futaba", 18);

    // Tambahkan data Igor di awal
    list.insertFront("Igor", 20);

    // Ubah data Michael menjadi Reyn
    list.updateNode("Michael", "Reyn", 18);

    // Tampilkan seluruh data
    cout << "Nama\tUsia" << endl;
    list.display();

    return 0;
}

