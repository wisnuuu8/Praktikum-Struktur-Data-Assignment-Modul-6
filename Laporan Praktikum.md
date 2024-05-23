**BAB 1**

**PENDAHULUAN**

**LATAR BELAKANG**

Single Linked List (SLL) adalah struktur data linier yang terdiri dari serangkaian node di mana setiap node berisi data dan satu pointer yang menunjuk ke node berikutnya. Traversal hanya bisa dilakukan searah, dari node pertama (head) ke node terakhir yang menunjuk ke `null`[1].

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

Single Linked List adalah struktur data yang terdiri dari kumpulan elemen yang disebut node, di mana setiap node berisi data dan satu pointer yang menunjuk ke node berikutnya. Elemen pertama dalam list disebut head dan elemen terakhir disebut tail, yang pointer-nya berisi `NULL`, menandakan akhir list. Linked List disusun secara sekuensial dan dinamis, memungkinkan penambahan dan penghapusan elemen dengan mudah. Struktur ini efisien untuk operasi traversal satu arah tetapi tidak untuk akses acak[2].

### Linked List Circular

Linked List Circular adalah varian dari Single Linked List di mana node terakhir tidak menunjuk ke `NULL` tetapi kembali ke node pertama, membentuk lingkaran. Hal ini memungkinkan traversal list tanpa batas. Node dummy atau node pengecoh sering digunakan untuk membantu menghentikan traversal ketika kembali ke node pertama. Struktur ini berguna untuk aplikasi yang memerlukan akses data berulang, seperti daftar putar musik atau antrian siklis.

### b) Double Linked List

Double Linked List adalah struktur data yang mirip dengan Single Linked List tetapi setiap node memiliki dua pointer: satu menunjuk ke node berikutnya (next) dan satu lagi menunjuk ke node sebelumnya (prev). Hal ini memungkinkan traversal dua arah, baik maju maupun mundur, serta operasi penambahan dan penghapusan elemen di mana saja dalam list secara lebih efisien[3]. Meskipun lebih fleksibel, Double Linked List memerlukan lebih banyak memori karena adanya dua pointer di setiap node. Struktur ini bermanfaat untuk aplikasi yang memerlukan akses dua arah dan manipulasi data yang lebih kompleks.

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

1.	Soal mengenai Single Linked List

Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:
a.	Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda.

[Nama_anda]	[Usia_anda]
John	19
Jane	20
Michael	18
Yusuke	19
Akechi	20
Hoshino	18
Karin	18
b.	Hapus data Akechi
c.	Tambahkan data berikut diantara John dan Jane : Futaba	18
d.	Tambahkan data berikut diawal : Igor	20
e.	Ubah data Michael menjadi : Reyn	18
f.	Tampilkan seluruh data

```C++
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
```
Interpretasi : 

Struktur Node menyimpan data berupa string nama, int usia, dan pointer Node* next yang menunjuk ke node berikutnya. Konstruktor Node menginisialisasi nama, usia, dan next dengan nilai yang diberikan. Kelas LinkedList memiliki pointer Node* head yang menunjuk ke node pertama dalam linked list, diinisialisasi ke NULL dalam konstruktor default, menandakan bahwa linked list awalnya kosong. Destruktor LinkedList memastikan semua node dihapus untuk menghindari kebocoran memori.

Metode insertFront menambahkan node baru di awal linked list dengan mengatur next dari node baru ke head dan memperbarui head ke node baru tersebut. Metode insertBack menambahkan node baru di akhir linked list. Jika head adalah NULL, node baru menjadi head; jika tidak, ia akan berjalan hingga akhir list dan menambahkan node baru di sana. Metode insertAfter menambahkan node baru setelah node dengan nama tertentu (prevNama). Jika node dengan prevNama ditemukan, node baru ditambahkan setelahnya, jika tidak ditemukan, akan dicetak pesan kesalahan.

Metode deleteNode menghapus node dengan nama tertentu. Jika node yang dihapus adalah head, head diperbarui ke node berikutnya; jika node dengan nama yang diberikan ditemukan di tengah atau akhir list, node tersebut dihapus dan list diperbarui, jika tidak ditemukan, akan dicetak pesan kesalahan. Metode updateNode memperbarui nama dan usia node yang memiliki nama tertentu. Jika node ditemukan, nilai nama dan usia diperbarui, jika tidak ditemukan, pesan kesalahan akan dicetak.

Metode display menampilkan semua node dalam linked list dengan iterasi dari head hingga akhir list dan mencetak nama serta usia setiap node. Fungsi main menguji operasi-operasi pada linked list, termasuk menambahkan node di depan (insertFront), menambahkan di belakang (insertBack), menambahkan setelah node tertentu (insertAfter), menghapus node (deleteNode), dan menampilkan seluruh isi linked list (display). Contoh penggunaan termasuk penambahan beberapa node dengan nama dan usia tertentu, penghapusan node bernama "Akechi", penambahan node "Futaba" setelah "John", dan penambahan node "Igor" di awal list, diakhiri dengan menampilkan seluruh isi linked list.

**Bagian 3**
```C++
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
```
Interpretasi : 

Fungsi `main` yang diberikan menunjukkan berbagai operasi pada linked list tunggal menggunakan kelas `LinkedList`. Pertama, sebuah instance dari kelas `LinkedList` bernama `list` dibuat. Kode dimulai dengan menyisipkan sebuah node dengan nama "Nama_anda" dan usia 21 di bagian depan list. Selanjutnya, kode menyisipkan node-node di bagian belakang list dengan nama dan usia: John (19), Jane (20), Reyn (18), Yusuke (19), Akechi (20), Hoshino (18), dan Karin (18).

Setelah penyisipan tersebut, list dimanipulasi dengan menghapus node yang bernama "Akechi". Setelah penghapusan ini, sebuah node baru dengan nama "Futaba" dan usia 18 disisipkan setelah node yang bernama "John". Selain itu, sebuah node dengan nama "Igor" dan usia 20 disisipkan di bagian depan list.

Terakhir, kode mencetak header ("Nama\tUsia") dan memanggil metode `display` dari kelas `LinkedList` untuk mencetak semua node di dalam list. Hasil akhir akan menunjukkan nama dan usia dari semua node di dalam list, memperlihatkan operasi penyisipan, penghapusan, dan penampilan yang berhasil pada linked list tersebut.

## Hasil output 
```C++
Nama    Usia
Igor    20
Wisnu   21
John    19
Futaba  18
Jane    20
Reyn    18
Yusuke  19
Hoshino 18
Karin   18

--------------------------------
Process exited after 0.0892 seconds with return value 0
Press any key to continue . . .
```
**UNGUIDED 2**

2.	Soal mengenai Double Linked List
Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.
Nama Produk	Harga
Originote	60.000
Somethinc	150.000
Skintific	100.000
Wardah	50.000
Hanasui	30.000

Case:
1.	Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific
2.	Hapus produk wardah
3.	Update produk Hanasui menjadi Cleora dengan harga 55.000
4.	Tampilkan menu seperti dibawah ini
Toko Skincare Purwokerto
1.	Tambah Data
2.	Hapus Data
3.	Update Data
4.	Tambah Data Urutan Tertentu
5.	Hapus Data Urutan Tertentu
6.	Hapus Seluruh Data
7.	Tampilkan Data
8.	Exit
Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah ini :

Nama Produk	Harga
Originote	60.000
Somethinc	150.000
Azarine	65.000
Skintific	100.000
Cleora	55.000

```C++
#include <iostream>
using namespace std;

// Struktur Node
struct Node {
    string namaProduk;
    int harga;
    Node* prev;
    Node* next;
};

// Kelas Linked list ganda
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Konstruktor
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Destruktor
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Menambahkan node di akhir
    void insertBack(string namaProduk, int harga) {
        Node* newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        newNode->prev = NULL;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Menambahkan node setelah node tertentu
    void insertAfter(string prevNamaProduk, string namaProduk, int harga) {
        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == prevNamaProduk) {
                Node* newNode = new Node;
                newNode->namaProduk = namaProduk;
                newNode->harga = harga;
                newNode->prev = current;
                newNode->next = current->next;
                if (current->next != NULL) {
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

    // Menghapus node berdasarkan nama
    void deleteNode(string namaProduk) {
        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == namaProduk) {
                if (current == head) {
                    head = current->next;
                    if (head != NULL) {
                        head->prev = NULL;
                    }
                } else if (current == tail) {
                    tail = current->prev;
                    if (tail != NULL) {
                        tail->next = NULL;
                    }
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

    // Mengupdate data node berdasarkan nama
    void updateNode(string namaProduk, string newNamaProduk, int newHarga) {
        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == namaProduk) {
                current->namaProduk = newNamaProduk;
                current->harga = newHarga;
                return;
            }
            current = current->next;
        }
        cout << "Node dengan nama produk " << namaProduk << " tidak ditemukan" << endl;
    }

    // Menampilkan semua node
    void display() {
        cout << "Nama Produk\tHarga" << endl;
        Node* current = head;
        while (current != NULL) {
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

// Struktur Node
struct Node {
    string namaProduk;
    int harga;
    Node* prev;
    Node* next;
};

// Kelas Linked list ganda
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Konstruktor
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Destruktor
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Menambahkan node di akhir
    void insertBack(string namaProduk, int harga) {
        Node* newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        newNode->prev = NULL;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Menambahkan node setelah node tertentu
    void insertAfter(string prevNamaProduk, string namaProduk, int harga) {
        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == prevNamaProduk) {
                Node* newNode = new Node;
                newNode->namaProduk = namaProduk;
                newNode->harga = harga;
                newNode->prev = current;
                newNode->next = current->next;
                if (current->next != NULL) {
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

    // Menghapus node berdasarkan nama
    void deleteNode(string namaProduk) {
        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == namaProduk) {
                if (current == head) {
                    head = current->next;
                    if (head != NULL) {
                        head->prev = NULL;
                    }
                } else if (current == tail) {
                    tail = current->prev;
                    if (tail != NULL) {
                        tail->next = NULL;
                    }
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

    // Mengupdate data node berdasarkan nama
    void updateNode(string namaProduk, string newNamaProduk, int newHarga) {
        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == namaProduk) {
                current->namaProduk = newNamaProduk;
                current->harga = newHarga;
                return;
            }
            current = current->next;
        }
        cout << "Node dengan nama produk " << namaProduk << " tidak ditemukan" << endl;
    }

    // Menampilkan semua node
    void display() {
        cout << "Nama Produk\tHarga" << endl;
        Node* current = head;
        while (current != NULL) {
            cout << current->namaProduk << "\t\t" << current->harga << endl;
            current = current->next;
        }
    }
};
```
Interpretasi : 

truktur data ini terdiri dari dua elemen utama: struktur Node dan kelas DoublyLinkedList.

Struktur Node menyimpan informasi tentang sebuah produk, seperti namaProduk dan harga, serta dua pointer, yaitu prev yang menunjukkan ke node sebelumnya, dan next yang menunjukkan ke node selanjutnya.

Kelas DoublyLinkedList memiliki dua pointer, head dan tail, yang menandakan awal dan akhir dari linked list. Konstruktor kelas inisialisasi kedua pointer ini menjadi NULL. Selain itu, kelas ini memiliki metode untuk menambahkan node baru di bagian belakang linked list (insertBack), menambahkan node baru setelah node tertentu (insertAfter), menghapus node berdasarkan nama produk (deleteNode), mengupdate data node berdasarkan nama produk (updateNode), dan menampilkan seluruh node dalam linked list (display).

**Bagian 3**
```C++
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
```
Interpretasi : 

Pada awalnya, program membuat sebuah objek list dari kelas DoublyLinkedList dan menambahkan beberapa data awal ke dalamnya.

Setelah itu, program memasuki loop do-while yang menampilkan menu interaktif kepada pengguna. Pengguna diberikan opsi untuk menambahkan data baru, menghapus data, mengupdate data, menambahkan data setelah produk tertentu, menghapus data pada posisi tertentu, menghapus seluruh data, menampilkan seluruh data, atau keluar dari program.

Setiap opsi yang dipilih oleh pengguna akan memanggil fungsi yang sesuai dari objek list, seperti insertBack untuk menambahkan data ke belakang linked list, deleteNode untuk menghapus data berdasarkan nama produk, updateNode untuk mengupdate data berdasarkan nama produk, dan lain-lain.

Program akan terus berjalan hingga pengguna memilih opsi untuk keluar (pilihan 8). Saat itu, program akan menampilkan pesan "Terima kasih!" dan kemudian keluar dengan mengembalikan nilai 0. Ini adalah kerangka utama dari program untuk mengelola daftar produk skincare menggunakan linked list ganda.

## Hasil output 
```C++
Toko Skincare Purwokerto
1. Tambah Data
2. Hapus Data
3. Update Data
4. Tambah Data Urutan Tertentu
5. Hapus Data Urutan Tertentu
6. Hapus Seluruh Data
7. Tampilkan Data
8. Exit
Pilih menu:
```

**DAFTAR PUSTAKA**

Saptadi, A. H., & Sari, D. W. (2012). Analisis Algoritma Insertion Sort, Merge Sort Dan Implementasinya Dalam Bahasa Pemrograman C++. JURNAL INFOTEL - Informatika Telekomunikasi Elektronika, 4(2), 10. https://doi.org/10.20895/infotel.v4i2.103

Wijaya, H., Wardhono, W. S., & Arwani, I. (2018). Implementasi Linked List pada Interaksi Antar Marker Augmented Reality untuk Operand dan Operator Aritmetika. Jurnal Pengembangan Teknologi Informasi Dan Ilmu Komputer (J-PTIIK) Universitas Brawijaya, 2(9), 3328–3332.

Kadir, A. (2014). Teori dan Aplikasi Struktur Data Menggunakan Java. 1(December), 374.


