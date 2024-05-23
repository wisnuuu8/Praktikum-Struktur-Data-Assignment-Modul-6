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
