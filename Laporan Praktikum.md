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

// Node structure
struct Node {
    string nama;
    int usia;
    Node* next;
};

// Linked list class
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // Destructor
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Insert node at the front
    void insertFront(string nama, int usia) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = head;
        head = newNode;
    }

    // Insert node at the back
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

    // Insert node after a specific node
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

    // Delete node by name
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

    // Update node data by name
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

    // Display all nodes
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

    // Menambahkan data awal (nama dan usia Anda)
    list.insertFront("Nama_anda", Usia_anda);

    // Menambahkan data sesuai urutan
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
```
Interpretasi : 

Struktur data tersebut terdiri dari dua elemen utama: sebuah struktur Node yang menyimpan data nama dan usia dalam bentuk string dan integer, serta pointer next yang menunjukkan ke node berikutnya dalam linked list. Selain itu, terdapat kelas LinkedList yang bertanggung jawab atas manajemen linked list tersebut. Kelas ini memiliki fungsi-fungsi seperti insertFront, insertBack, insertAfter, deleteNode, updateNode, dan display, yang memungkinkan penambahan, penghapusan, pembaruan, dan penampilan data dalam linked list. Dengan menggunakan kelas LinkedList, pengguna dapat membuat, mengelola, dan mengoperasikan linked list untuk menyimpan data nama dan usia mahasiswa. Prosesnya dimulai dari inisialisasi linked list, diikuti dengan operasi-operasi seperti penambahan, penghapusan, pembaruan, dan penampilan data, sesuai dengan kebutuhan pengguna.

**Bagian 3**
```C++
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
```
Interpretasi :

Program menginisialisasi objek LinkedList yang digunakan untuk menyimpan dan mengelola data. Data awal dimasukkan ke dalam linked list menggunakan fungsi insertFront() dan insertBack(), yang menempatkan data ke depan dan belakang linked list secara berurutan. Selanjutnya, program melakukan operasi seperti penghapusan data dengan menggunakan fungsi deleteNode() untuk menghapus data "Akechi", dan penambahan data "Futaba" setelah data "John" menggunakan fungsi insertAfter(). Data "Igor" dimasukkan di awal linked list melalui fungsi insertFront(), sedangkan data "Michael" diubah namanya menjadi "Reyn" menggunakan fungsi updateNode(). Akhirnya, program menampilkan seluruh data yang tersimpan dalam linked list menggunakan fungsi display()

## Hasil output
```C++
Nama    Usia
Igor    20
Nama_anda    Usia_anda
John    19
Futaba    18
Jane    20
Reyn    18
Yusuke    19
Hoshino    18
Karin    18
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
    string namaProduk;
    int harga;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

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

    void display() {
        cout << "Nama Produk\tHarga" << endl;
        Node* current = head;
        while (current != nullptr) {
            cout << current->namaProduk << "\t\t" << current->harga << endl;
            current = current->next;
        }
    }
};
```
Interpretasi :

Kode yang diberikan mendefinisikan sebuah struktur `Node` yang menyimpan informasi tentang produk, seperti nama dan harga, serta pointer ke node sebelumnya dan node berikutnya dalam linked list ganda. Selanjutnya, ada kelas `DoublyLinkedList` yang mengelola linked list ganda tersebut. Dengan konstruktor, kelas ini menginisialisasi pointer `head` dan `tail` ke `nullptr`, menunjukkan bahwa linked list awalnya kosong. Metode destruktor bertanggung jawab untuk menghapus semua node dalam linked list dengan melakukan iterasi dari `head` hingga `tail` dan menghapusnya satu per satu. Metode `insertBack` memasukkan node baru ke akhir linked list, sementara `insertAfter` memungkinkan penambahan node baru setelah node tertentu dalam linked list. Metode `deleteNode` menghapus node dengan nama produk yang cocok, sedangkan `updateNode` memperbarui nama dan harga node yang cocok. Akhirnya, `display()` digunakan untuk menampilkan semua produk dalam linked list dengan format yang ditentukan. Dengan demikian, kelas `DoublyLinkedList` memungkinkan pengelolaan data produk dengan cara menambah, menghapus, memperbarui, dan menampilkan data dengan efisien dalam linked list ganda.

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

Program dimulai dengan membuat objek list dari kelas DoublyLinkedList, kemudian menambahkan data awal berupa nama produk dan harganya ke dalam list. Selanjutnya, program menampilkan menu yang berisi operasi-operasi yang dapat dilakukan pada data produk skincare, seperti menambah data baru, menghapus data, dan mengupdate data. Pengguna diminta untuk memilih menu yang sesuai dengan kebutuhan mereka dengan memasukkan angka yang sesuai. Setelah pengguna memilih operasi yang diinginkan, program akan mengeksekusi operasi tersebut dan memberikan umpan balik sesuai dengan hasil operasi. Operasi-operasi tersebut mencakup penambahan data di belakang, penghapusan data berdasarkan nama produk, pembaruan data, penambahan data di urutan tertentu, penghapusan data di urutan tertentu, penghapusan semua data, dan penampilan semua data yang ada. Program akan terus berjalan hingga pengguna memilih menu untuk keluar dari program. Dengan demikian, program ini memberikan antarmuka yang interaktif dan mudah digunakan bagi pengguna untuk mengelola data produk skincare mereka.

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
Pilih menu: 7
Nama Produk	Harga
Originote	60.000
Somethinc	150.000
Skintific	100.000
Wardah	50.000
Hanasui	30.000
```

**DAFTAR PUSTAKA**

Saptadi, A. H., & Sari, D. W. (2012). Analisis Algoritma Insertion Sort, Merge Sort Dan Implementasinya Dalam Bahasa Pemrograman C++. JURNAL INFOTEL - Informatika Telekomunikasi Elektronika, 4(2), 10. https://doi.org/10.20895/infotel.v4i2.103

Wijaya, H., Wardhono, W. S., & Arwani, I. (2018). Implementasi Linked List pada Interaksi Antar Marker Augmented Reality untuk Operand dan Operator Aritmetika. Jurnal Pengembangan Teknologi Informasi Dan Ilmu Komputer (J-PTIIK) Universitas Brawijaya, 2(9), 3328–3332.

Kadir, A. (2014). Teori dan Aplikasi Struktur Data Menggunakan Java. 1(December), 374.


