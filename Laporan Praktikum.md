**BAB 1**

**PENDAHULUAN**

**LATAR BELAKANG**

Single Linked List (SLL) adalah struktur data linier yang terdiri dari serangkaian node di mana setiap node berisi data dan satu pointer yang menunjuk ke node berikutnya. Traversal hanya bisa dilakukan searah, dari node pertama (head) ke node terakhir yang menunjuk ke `null`.

Double Linked List (DLL) adalah struktur data linier yang serupa dengan SLL tetapi setiap node memiliki dua pointer: satu menunjuk ke node berikutnya dan satu lagi ke node sebelumnya. Ini memungkinkan traversal dua arah, baik maju maupun mundur.

**RUMUSAN MASALAH**

1. Bagaimana mahasiswa dapat memahami perbedaan konsep antara Single Linked List, Double Linked List, Circular Linked List, dan Non Linked List?
2. Bagaimana mahasiswa dapat menerapkan konsep Single Linked List, Double Linked List, Circular Linked List, dan Non Linked List ke dalam pemrograman?

**TUJUAN PRAKTIKUM**

1.	Mahasiswa memahami perbedaan konsep Single, Double, Circular dan Non Linked List. 
2.	Mahasiswa mampu menerapkan SingleSingle, Double, Circular dan Non Linked List ke dalam pemrograman.

**BAB 2**

**PEMBAHASAN**

**DASAR TEORI**

### a) Single Linked List

Single Linked List adalah struktur data yang terdiri dari kumpulan elemen yang disebut node, di mana setiap node berisi data dan satu pointer yang menunjuk ke node berikutnya. Elemen pertama dalam list disebut head dan elemen terakhir disebut tail, yang pointer-nya berisi `NULL`, menandakan akhir list. Linked List disusun secara sekuensial dan dinamis, memungkinkan penambahan dan penghapusan elemen dengan mudah. Struktur ini efisien untuk operasi traversal satu arah tetapi tidak untuk akses acak.

### Linked List Circular

Linked List Circular adalah varian dari Single Linked List di mana node terakhir tidak menunjuk ke `NULL` tetapi kembali ke node pertama, membentuk lingkaran. Hal ini memungkinkan traversal list tanpa batas. Node dummy atau node pengecoh sering digunakan untuk membantu menghentikan traversal ketika kembali ke node pertama. Struktur ini berguna untuk aplikasi yang memerlukan akses data berulang, seperti daftar putar musik atau antrian siklis.

### b) Double Linked List

Double Linked List adalah struktur data yang mirip dengan Single Linked List tetapi setiap node memiliki dua pointer: satu menunjuk ke node berikutnya (next) dan satu lagi menunjuk ke node sebelumnya (prev). Hal ini memungkinkan traversal dua arah, baik maju maupun mundur, serta operasi penambahan dan penghapusan elemen di mana saja dalam list secara lebih efisien. Meskipun lebih fleksibel, Double Linked List memerlukan lebih banyak memori karena adanya dua pointer di setiap node. Struktur ini bermanfaat untuk aplikasi yang memerlukan akses dua arah dan manipulasi data yang lebih kompleks.

**GUIDED**

**GUIDED 1**

a)	Latihan Single Linked List
```C++
#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node{
    //komponen/member
    int data;
    Node *next;
};
    Node *head;
    Node *tail;
//Inisialisasi Node
void init(){
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty(){
    if (head == NULL)
    return true;
    else
    return false;
}
//Tambah Depan
void insertDepan(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
        baru->next = head;
        head = baru;
    }
}
//Tambah Belakang
void insertBelakang(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
    tail->next = baru;
    tail = baru;
    }
}
//Hitung Jumlah List
int hitungList(){
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while( hitung != NULL ){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
//Tambah Tengah
void insertTengah(int data, int posisi){
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
            bantu = head;
            int nomor = 1;
        while( nomor < posisi - 1 ){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
//Hapus Depan
void hapusDepan() {
    Node *hapus;
    if (isEmpty() == false){
        if (head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Belakang
void hapusBelakang() {
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false){
        if (head != tail){
            hapus = tail;
            bantu = head;
            while (bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Tengah
void hapusTengah(int posisi){
    Node *hapus, *bantu, *bantu2;
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        int nomor = 1;
        bantu = head;
        while( nomor <= posisi ){
            if( nomor == posisi-1 ){
                bantu2 = bantu;
            }
            if( nomor == posisi ){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
    delete hapus;
    }
}
//Ubah Depan
void ubahDepan(int data){
    if (isEmpty() == false){
        head->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Tengah
void ubahTengah(int data, int posisi){
    Node *bantu;
    if (isEmpty() == false){
        if( posisi < 1 || posisi > hitungList() ){
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if( posisi == 1){
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else{
            bantu = head;
            int nomor = 1;
            while (nomor < posisi){
                bantu = bantu->next;nomor++;
            }
            bantu->data = data;
        }
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Belakang
void ubahBelakang(int data){
    if (isEmpty() == false){
        tail->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Hapus List
void clearList(){
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
//Tampilkan List
void tampil(){
    Node *bantu;
    bantu = head;
    if (isEmpty() == false){
        while (bantu != NULL){
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
int main(){
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7,2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();

    insertTengah(7,1);
    tampil();
    return 0;
}
```
**Bagian 1**
```C++
#include <iostream>
using namespace std;
```
Interpretasi : 

include iostream : Ini adalah preprocessor directive yang menyertakan pustaka input-output standar C++ ke dalam program. Ini diperlukan untuk menggunakan fungsi-fungsi dasar seperti cout dan cin untuk output dan input data.

include string : Ini adalah preprocessor directive yang menyertakan pustaka string ke dalam program. Pustaka ini memberikan fungsionalitas untuk bekerja dengan tipe data string di C++, seperti deklarasi, manipulasi, dan operasi pada string.

using namespace std;: Ini adalah deklarasi yang mengizinkan penggunaan semua simbol dalam namespace std tanpa menuliskan std:: di depannya setiap kali digunakan. Namespace std berisi semua fungsi, tipe data, dan objek yang didefinisikan dalam pustaka standar C++.

**Bagian 2**
```C++
#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node{
    //komponen/member
    int data;
    Node *next;
};
    Node *head;
    Node *tail;
//Inisialisasi Node
void init(){
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty(){
    if (head == NULL)
    return true;
    else
    return false;
}
//Tambah Depan
void insertDepan(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
        baru->next = head;
        head = baru;
    }
}
//Tambah Belakang
void insertBelakang(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
    tail->next = baru;
    tail = baru;
    }
}
//Hitung Jumlah List
int hitungList(){
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while( hitung != NULL ){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
```
Interpretasi : 

Kode ini mengimplementasikan dasar-dasar operasi pada Single Linked List non-circular, termasuk inisialisasi, pengecekan apakah list kosong, penambahan node di depan dan belakang list, serta penghitungan jumlah node dalam list. Struktur ini memungkinkan penyimpanan dan pengelolaan data secara dinamis dengan penambahan dan penghapusan elemen yang efisien.

**Bagian 3**
```C++
//Tambah Tengah
void insertTengah(int data, int posisi){
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
            bantu = head;
            int nomor = 1;
        while( nomor < posisi - 1 ){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
//Hapus Depan
void hapusDepan() {
    Node *hapus;
    if (isEmpty() == false){
        if (head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Belakang
void hapusBelakang() {
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false){
        if (head != tail){
            hapus = tail;
            bantu = head;
            while (bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Tengah
void hapusTengah(int posisi){
    Node *hapus, *bantu, *bantu2;
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        int nomor = 1;
        bantu = head;
        while( nomor <= posisi ){
            if( nomor == posisi-1 ){
                bantu2 = bantu;
            }
            if( nomor == posisi ){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
    delete hapus;
    }
}
//Ubah Depan
void ubahDepan(int data){
    if (isEmpty() == false){
        head->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Tengah
void ubahTengah(int data, int posisi){
    Node *bantu;
    if (isEmpty() == false){
        if( posisi < 1 || posisi > hitungList() ){
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if( posisi == 1){
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else{
            bantu = head;
            int nomor = 1;
            while (nomor < posisi){
                bantu = bantu->next;nomor++;
            }
            bantu->data = data;
        }
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Belakang
void ubahBelakang(int data){
    if (isEmpty() == false){
        tail->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Hapus List
void clearList(){
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
//Tampilkan List
void tampil(){
    Node *bantu;
    bantu = head;
    if (isEmpty() == false){
        while (bantu != NULL){
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
int main(){
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7,2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();

    insertTengah(7,1);
    tampil();
    return 0;
}
```
Interpretasi : 

Kode ini mengimplementasikan berbagai operasi dasar pada struktur data Single Linked List, termasuk penambahan, penghapusan, dan perubahan elemen di depan, tengah, dan belakang list. Kode ini juga menyediakan fungsi untuk menghapus seluruh list (`clearList`) dan menampilkan semua elemen list (`tampil`). Penambahan dan penghapusan di tengah list memperhatikan validasi posisi agar sesuai dengan jangkauan list dan memastikan posisi bukanlah posisi pertama. Operasi seperti `insertTengah` dan `hapusTengah` memerlukan traversal melalui list untuk mencapai posisi yang diinginkan, yang menunjukkan bahwa operasi ini memiliki kompleksitas O(n) untuk pencarian posisi tertentu. Penggunaan pointer dan traversal satu arah adalah ciri khas dari Single Linked List, membuat operasi relatif sederhana tetapi kurang efisien dibandingkan Double Linked List untuk beberapa operasi. Kode juga memperhatikan edge cases seperti penghapusan dan penambahan pada list kosong, serta penanganan posisi di luar jangkauan, dengan pesan kesalahan yang informatif untuk membantu pengguna. Fungsi-fungsi yang ada cukup modular dan dapat diperluas untuk mendukung operasi tambahan, sementara contoh penggunaan dalam fungsi `main` mempermudah pengujian dan verifikasi. Secara keseluruhan, kode ini memberikan implementasi dasar yang solid untuk mengelola Single Linked List, menunjukkan pemahaman yang baik tentang manipulasi pointer dan traversal list, serta menekankan pentingnya validasi posisi dan penanganan list kosong.

## Hasil output 
```C++
3
3 5
2 3 5
1 2 3 5
2 3 5
2 3
2 7 3
2 3
1 3
1 8
1 11
Posisi bukan posisi tengah
1 11

--------------------------------
Process exited after 0.09238 seconds with return value 0
Press any key to continue . . .
```

**GUIDED 2**

b)	Latihan Double Linked List
```C++
#include <iostream>
using namespace std;

class Node {
    public:int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } 
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
**Bagian 1**
```C++
#include <iostream>
using namespace std;
```
Interpretasi : 

include iostream : Ini adalah preprocessor directive yang menyertakan pustaka input-output standar C++ ke dalam program. Ini diperlukan untuk menggunakan fungsi-fungsi dasar seperti cout dan cin untuk output dan input data.

include string : Ini adalah preprocessor directive yang menyertakan pustaka string ke dalam program. Pustaka ini memberikan fungsionalitas untuk bekerja dengan tipe data string di C++, seperti deklarasi, manipulasi, dan operasi pada string.

using namespace std;: Ini adalah deklarasi yang mengizinkan penggunaan semua simbol dalam namespace std tanpa menuliskan std:: di depannya setiap kali digunakan. Namespace std berisi semua fungsi, tipe data, dan objek yang didefinisikan dalam pustaka standar C++.

**Bagian 2**
```C++
class Node {
    public:int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } 
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
```
Interpretasi : 

Kelas `Node` mendefinisikan setiap simpul dalam list dengan atribut `data`, `prev`, dan `next` yang mewakili nilai data, pointer ke simpul sebelumnya, dan pointer ke simpul berikutnya.

Kelas `DoublyLinkedList` mengelola seluruh list dengan atribut `head` dan `tail` yang menunjukkan simpul pertama dan terakhir dalam list. 

Fungsi `push` menambahkan simpul baru di awal list, `pop` menghapus simpul pertama, `update` memperbarui nilai data simpul tertentu, `deleteAll` menghapus seluruh list, dan `display` menampilkan isi list.

Contoh penggunaan menunjukkan bagaimana kelas `DoublyLinkedList` dapat digunakan untuk memanipulasi dan menampilkan data dalam list.

**Bagian 3**
```C++


int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
Interpretasi : 

Program ini merupakan implementasi operasi-operasi dasar pada Doubly Linked List menggunakan C++. Berikut adalah penjelasan ringkas langkah-langkah program:

**Deklarasi Objek Doubly Linked List**: Objek `list` dari kelas `DoublyLinkedList` dideklarasikan untuk menyimpan data menggunakan Doubly Linked List.

**Loop Utama**: Program berada dalam loop utama yang berjalan terus menerus sampai pengguna memilih untuk keluar.

**Menu Pilihan Operasi**: Program menampilkan menu yang berisi pilihan operasi yang dapat dilakukan oleh pengguna.

**Input Pilihan Pengguna**: Pengguna diminta untuk memasukkan pilihan operasi yang diinginkan.

**Switch Statement untuk Memproses Pilihan Pengguna**: Program menggunakan statement switch untuk mengeksekusi kode yang sesuai berdasarkan pilihan pengguna.

**Implementasi Setiap Pilihan Operasi**:
   - **Add data**: Pengguna diminta untuk memasukkan data yang akan ditambahkan, kemudian data tersebut dimasukkan ke dalam Doubly Linked List menggunakan metode `push`.
   - **Delete data**: Data terakhir dalam Doubly Linked List dihapus menggunakan metode `pop`.
   - **Update data**: Pengguna diminta untuk memasukkan data lama dan data baru. Metode `update` digunakan untuk mencari data lama dan menggantinya dengan data baru.
   - **Clear data**: Semua data dalam Doubly Linked List dihapus menggunakan metode `deleteAll`.
   - **Display data**: Semua data dalam Doubly Linked List ditampilkan menggunakan metode `display`.
   - **Exit**: Program keluar dari loop utama dan berakhir.

**Default Case**: Jika pengguna memasukkan pilihan yang tidak valid, program akan mencetak pesan kesalahan.

Program ini memungkinkan pengguna untuk melakukan operasi-operasi dasar seperti menambah, menghapus, memperbarui, membersihkan, dan menampilkan data dalam Doubly Linked List.

## Hasil output
```C++
1. Add data
2. Delete data
3. Update data
4. Clear data
5. Display data
6. Exit
Enter your choice: 1
Enter data to add: 10
Enter your choice: 1
Enter data to add: 20
Enter your choice: 1
Enter data to add: 30
Enter your choice: 5
30 20 10 
Enter your choice: 3
Enter old data: 20
Enter new data: 25
Enter your choice: 5
30 25 10 
Enter your choice: 4
Enter your choice: 5

Enter your choice: 6
```

**UNGUIDED**

**UNGUIDED 1**

**UNGUIDED 2**

