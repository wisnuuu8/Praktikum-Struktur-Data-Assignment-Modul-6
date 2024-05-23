#include <iostream>
using namespace std;

// Node structure
struct Node {
    string namaProduk;
    int harga;
    Node* prev;
    Node* next;
};

// Linked list class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Destructor
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Insert node at the back
    void insertBack(string namaProduk, int harga) {
        Node* newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        newNode->prev = nullptr;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Insert node after a specific node
    void insertAfter(string prevNamaProduk, string namaProduk, int harga) {
        Node* current = head;
        while (current != nullptr) {
            if (current->namaProduk == prevNamaProduk) {
                Node* newNode = new Node;
                newNode->namaProduk = namaProduk;
                newNode->harga = harga;
                newNode->prev = current;
                newNode->next = current->next;
                if (current->next != nullptr) {
                    current->next->prev = newNode;
                } else {
                    tail = newNode;
                }
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        cout << "Node dengan nama produk " << prevNamaProduk << " tidak ditemukan" << endl;
    }

    // Delete node by name
    void deleteNode(string namaProduk) {
        Node* current = head;
        while (current != nullptr) {
            if (current->namaProduk == namaProduk) {
                if (current == head) {
                    head = current->next;
                    if (head != nullptr) {
                        head->prev = nullptr;
                    }
                } else if (current == tail) {
                    tail = current->prev;
                    tail->next = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Node dengan nama produk " << namaProduk << " tidak ditemukan" << endl;
    }

    // Update node data by name
    void updateNode(string namaProduk, string newNamaProduk, int newHarga) {
        Node* current = head;
        while (current != nullptr) {
            if (current->namaProduk == namaProduk) {
                current->namaProduk = newNamaProduk;
                current->harga = newHarga;
                return;
            }
            current = current->next;
        }
        cout << "Node dengan nama produk " << namaProduk << " tidak ditemukan" << endl;
    }

    // Display all nodes
    void display() {
        cout << "Nama Produk\tHarga" << endl;
        Node* current = head;
        while (current != nullptr) {
            cout << current->namaProduk << "\t\t" << current->harga << endl;
            current = current->next;
        }
    }
};

int main() {
    DoublyLinkedList list;

    // Menambahkan data awal
    list.insertBack("Originote", 60000);
    list.insertBack("Somethinc", 150000);
    list.insertBack("Skintific", 100000);
    list.insertBack("Wardah", 50000);
    list.insertBack("Hanasui", 30000);

    int choice;
    string namaProduk, prevNamaProduk, newNamaProduk;
    int harga, newHarga;

    do {
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan Nama Produk: ";
                cin >> namaProduk;
                cout << "Masukkan Harga: ";
                cin >> harga;
                list.insertBack(namaProduk, harga);
                break;
            case 2:
                cout << "Masukkan Nama Produk yang akan dihapus: ";
                cin >> namaProduk;
                list.deleteNode(namaProduk);
                break;
            case 3:
                cout << "Masukkan Nama Produk yang akan diupdate: ";
                cin >> namaProduk;
                cout << "Masukkan Nama Produk Baru: ";
                cin >> newNamaProduk;
                cout << "Masukkan Harga Baru: ";
                cin >> newHarga;
                list.updateNode(namaProduk, newNamaProduk, newHarga);
                break;
            case 4:
                cout << "Masukkan Nama Produk Sebelumnya: ";
                cin >> prevNamaProduk;
                cout << "Masukkan Nama Produk Baru: ";
                cin >> namaProduk;
                cout << "Masukkan Harga: ";
                cin >> harga;
                list.insertAfter(prevNamaProduk, namaProduk, harga);
                break;
            case 5:
                cout << "Masukkan Nama Produk yang akan dihapus: ";
                cin >> namaProduk;
                list.deleteNode(namaProduk);
                break;
            case 6:
                list.~DoublyLinkedList();
                break;
            case 7:
                list.display();
                break;
            case 8:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (choice != 8);

    return 0;
}

