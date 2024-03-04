/* KODE 1 Mengakses Elemen Struktur */

#include <stdio.h>
#include <string.h>
struct date { 
int month;
int day;
int year;
};
struct student{ 
char name[30];
struct date birthday;
};

struct student mhs;
main()
{

strcpy(mhs.name, "MUHAMMAD IHSAN");
mhs.birthday.month = 8;
mhs.birthday.day = 10;
mhs.birthday.year = 1970;
printf("Name : %s\n", mhs.name);
printf("Birthday : %d-%d-%d\n",mhs.birthday.month,
mhs.birthday.day, mhs.birthday.year);
}


/*
----------------------- ANALISIS -----------------
1. Dalam kode diatas terdapat dua struct yaitu: 'date' untuk merepresentasikan tanggal dengan bulan, hari, dan tahun, lalu 'struct student' untuk merepresentasikan seorang siswa dengan nama dan tanggal lahir.
2. Terdapat variabel dengan nama 'mhs' dan tipe data struct 'student'. Variabel ini untuk menyimpan informasi tentang seorang siswa.
3. perintah printf berfungsi untuk menampilkan isi dari struct.
*/


/* KODE 2 Menginisialisasi Struktur */

#include <stdio.h>
main()
{
struct zodiak {
char nama[11];
int tgl_awal;
int bln_awal;
int tgl_akhir;
int bln_akhir;
};
static struct zodiak bintang =
{"Sagitarius", 22, 11, 21, 12};
int tgl_lhr, bln_lhr, thn_lhr;
printf("Masukkan tgl lahir Anda (XX-XX-XXXX): ");
scanf("%d-%d-%d",&tgl_lhr, &bln_lhr, &thn_lhr);
if((tgl_lhr >= bintang.tgl_awal && bln_lhr ==
bintang.bln_awal) || (tgl_lhr <= bintang.tgl_akhir &&
bln_lhr == bintang.bln_akhir))
printf("Bintang Anda adalah %s\n", bintang.nama);
else
printf("Bintang Anda bukan %s\n", bintang.nama);
}

/* ----------------------- ANALISIS -----------------
Program ini bertujuan untuk menentukan zodiak seseorang sagitarius atau bukan berdasarkan tanggal lahir yang dimasukkan.
1. Terdapat 'struct zodiak' untuk menyimpan beberapa field tanggal, bulan, dan tahun.
2. Variabel bintang diinisialisasi ke dalam 'struct zodiak'.
3. Program hanya terdapat 2 kemungkinan yakni, berzodiak sagitarius atau bukan. 
4. User diminta untuk memasukkan tanggal lahir berisi tanggal bulan dan tahun.
*/

/* KODE 3 Array dan Struktur */

#include <stdio.h>
#define MAKS 20
struct date { 
int month;
int day;
int year;
};
struct student { 
char name[30];
struct date birthday;
};
struct student data_mhs[MAKS];
main()
{
int i=0, sudah_benar, jml;
char lagi;
do
{
printf("Name : ");
fgets(data_mhs[i].name,sizeof data_mhs[i].name,stdin);
printf("Birthday (mm-dd-yyyy): ");
scanf("%d-%d-%d",
&data_mhs[i].birthday.month,
&data_mhs[i].birthday.day,
&data_mhs[i].birthday.year);
printf("\n");
i++;
printf("Mau memasukkan data lagi [Y/T] ? ");
do
{
lagi = getchar( ); 
sudah_benar = (lagi == 'Y') || (lagi== 'y')||
(lagi == 'T') || (lagi == 't');
} while(! sudah_benar);
fflush(stdin);
printf("\n");
} while(lagi == 'Y' || lagi == 'y');
jml = i;
printf("DATA SISWA\n");
for (i=0; i<jml; i++)
{
printf("%d. Name : %s", i+1, data_mhs[i].name);
printf(" Birthday : %d-%d-%d\n\n",
data_mhs[i].birthday.month,
data_mhs[i].birthday.day,
data_mhs[i].birthday.year );
};
}

/* ----------------------- ANALISIS -----------------
Kode program diatas berfungsi untuk menyimpan data siswa ke dalam array.
1. Terdapat dua struktur, 'date' dan 'student', didefinisikan untuk menyimpan tanggal dan data siswa.
2. Sebuah array dari tipe data struct 'student' dengan nama 'data_mhs' dideklarasi sebagai variabel. Array ini akan menampung data siswa sebanyak 'MAKS' yang telah ditetapkan sebelumnya, yakni sebanyak 20.
3. Program menggunakan perulangan 'do-while' untuk meminta user memasukkan data siswa yang akan disimpan dalam array 'data_mhs'.
4. Setelah itu data akan ditampilkan dari array 'data_mhs' menggunakan program perulangan for.
*/

/* KODE 4 Melewatkan Elemen Struktur ke dalam Fungsi */

#include <stdio.h>
void cetak_tanggal(int, int, int);
main()
{
struct date { 
int month;
int day;
int year;
} today;
printf("Enter the current date (mm-dd-yyyy): ");
scanf("%d-%d-%d", &today.month, &today.day, &today.year);
cetak_tanggal(today.month, today.day, today.year);
}
void cetak_tanggal(int mm, int dd, int yy)
{
static char *nama_bulan[] = {
"Wrong month", "January", "February", "March",
"April", "May", "June", "July", "August",
"September", "October", "November", "December"
};
printf("Todays date is %s %d, %d\n\n",
nama_bulan[mm],dd,yy);
}

/* ----------------------- ANALISIS -----------------
Kode program diatas bertujuan untuk meminta user memasukkan tanggal dan kemudian di convert ke tanggal tersebut dalam format yang lebih bersahabat dengan menggunakan nama bulan. 
1. User diminta untuk memasukkan tanggal saat ini melalui input yang dibaca oleh 'scanf' dan disimpan dalam variabel 'today'.
2. 'cetak_tanggal' berfungsi untuk  mengirimkan argumen bulan '(today.month)', hari '(today.day)', dan tahun '(today.year)' lalu mencetak tanggal dengan array statis 'nama_bulan'.
*/

/* KODE 5 Melewatkan Struktur ke dalam Fungsi */

struct date { 
int month;
int day;
int year;
};
void cetak_tanggal(struct date);
main()
{
struct date today;
printf("Enter the current date (mm-dd-yyyy): ");
scanf("%d-%d-%d", &today.month, &today.day, &today.year);
cetak_tanggal(today);
}
void cetak_tanggal(struct date now)
{
static char *nama_bulan[] = {
"Wrong month", "January", "February", "March",
"April", "May", "June", "July", "August",
"September", "October", "November", "December"
};
printf("Todays date is %s %d, %d\n\n",
nama_bulan[now.month], now.day, now.year);
}

/* ----------------------- ANALISIS -----------------
Kode program ini sama dengan kode program sebelumnya, namun parameter fungsi diubah menjadi bentuk struktur, sehingga parameter fungsi tidak lagi sebanyak tiga buah, melainkan hanya satu.
1. 'struct date' digunakan untuk menyimpan data tanggal, bulan, dan tahun.
2. 'cetak_tanggal()' menerima argumen berupa struktur 'date' dengan nama 'now'. Fungsi ini mencetak tanggal dengan menggunakan array statis 'nama_bulan' untuk mendapatkan nama bulan yang sesuai dengan nilai 'now.month'.
*/

/* KODE 6 Struktur dan Pointer (Pointer ke Struktur) */

#include <stdio.h>
struct koordinat
{ int x;
int y;
};
void tukar_xy(struct koordinat *);
main()
{
struct koordinat posisi;
printf("Masukkan koordinat posisi (x, y) : ");
scanf("%d, %d", &posisi.x, &posisi.y);
printf("x, y semula = %d, %d\n", posisi.x, posisi.y);
tukar_xy(&posisi);
printf("x, y sekarang = %d, %d\n", posisi.x, posisi.y);
}
void tukar_xy(struct koordinat *pos_xy)
{
int z;
z = (*pos_xy).x;
(*pos_xy).x = (*pos_xy).y;
(*pos_xy).y = z;
}

/* ----------------------- ANALISIS -----------------
1. Sebuah struktur bernama koordinat didefinisikan untuk menyimpan dua nilai bertipe integer, yaitu x dan y.
2. void tukar_xy(struct koordinat *); Kode ini dideklarasikan untuk menukar nilai x dan y dari suatu struct koordinat. Fungsi ini menggunakan pointer ke struktur koordinat sebagai argumen.
3. 'printf("Masukkan koordinat posisi (x, y) : ");
scanf("%d, %d", &posisi.x, &posisi.y);'
Pada kode ini user diminta untuk memasukkan nilai x dan y untuk koordinat posisi.
4. Lalu nilai x dan y ditukar menggunakan kode:
'tukar_xy(&posisi);'.
5. Setelah itu nilai x dan y ditampilkan dengan kode 'printf("x, y sekarang = %d, %d\n", posisi.x, posisi.y);'.
*/

/* KODE 7 */

#include <stdio.h>
void tukar_xy(int *, int *);
main()
{
struct koordinat {
int x;
int y;
} posisi;
printf("Masukkan koordinat posisi (x, y) : ");
scanf("%d, %d", &posisi.x, &posisi.y);
printf("x, y semula = %d, %d\n", posisi.x, posisi.y);
tukar_xy(&posisi.x, &posisi.y);
printf("x, y sekarang = %d, %d\n", posisi.x, posisi.y);
}
void tukar_xy(int *a, int *b)
{
int z;
z = *a;
*a = *b;
*b = z;
}

/* ----------------------- ANALISIS -----------------
Sebenarnya kode tersebut dengan kokde sebelumnya memiliki tujuan yang sama, yaitu menukar nilai x dan y dari suatu struktur atau variabel.
*/