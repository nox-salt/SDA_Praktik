#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tampilkanMenu() {
    printf("\n======================  Menu: ======================\n");
    printf("1. Tambah Kota\n");
    printf("2. Hapus Kota\n");
    printf("3. Tambah Nama ke Kota\n");
    printf("4. Hapus Nama dari Kota\n");
    printf("5. Tampilkan Data\n");
    printf("6. Keluar\n");
    printf("=======================================================\n");
    printf("Pilih opsi: ");
}

int main() {
    Kota daftarKota[MAX_KOTA];
    int jumlahKota = 0;
    int pilihan;
    char namaKota[NAMA], nama[NAMA];
    
    createList(daftarKota);
    
    do {
        tampilkanMenu();
        scanf("%d", &pilihan);
        getchar();
        
        switch (pilihan) {
            case 1:
                printf("Masukkan nama kota: ");
                fgets(namaKota, NAMA, stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                tambahKota(daftarKota, &jumlahKota, namaKota);
                break;
            case 2:
                hapusKota(daftarKota, &jumlahKota);
                break;
            case 3:
                printf("Masukkan nama kota yang akan ditambahkan nama: ");
                fgets(namaKota, NAMA, stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                printf("Masukkan nama: ");
                fgets(nama, NAMA, stdin);
                nama[strcspn(nama, "\n")] = 0;
                int i = 0;
                while (i < jumlahKota) {
                    if (strcmp(daftarKota[i].kt, namaKota) == 0) {
                        tambahNama(&daftarKota[i], nama);
                        break;
                    }
                    i++;
                }
                break;
            case 4:
                printf("Masukkan nama kota yang akan dihapus namanya: ");
                fgets(namaKota, NAMA, stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                printf("Masukkan nama yang akan dihapus: ");
                fgets(nama, NAMA, stdin);
                nama[strcspn(nama, "\n")] = 0;
                i = 0;
                while (i < jumlahKota) {
                    if (strcmp(daftarKota[i].kt, namaKota) == 0) {
                        hapusNama(&daftarKota[i], nama);
                        break;
                    }
                    i++;
                }
                break;
            case 5:
                tampilkanDaftar(daftarKota, jumlahKota);
                break;
            case 6:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 6);
    
    return 0;
}

