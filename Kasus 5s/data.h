#ifndef DATA_H
#define DATA_H

#include "linkedlist.h"

#define MAX_KOTA 10
#define NAMA 20


typedef struct dataNama{
    char nama[NAMA];
    struct dataNama *next;
}dataNama;

typedef struct{
    char kt[NAMA];
    dataNama *p;
}Kota;


void createList(Kota daftarKota[]);
void tambahKota(Kota daftarKota[], int *jumlahKota, char namaKota[]);
void hapusKota(Kota daftarKota[], int *jumlahKota);
void tambahNama(Kota *kota, char nama[]);
void hapusNama(Kota *kota, char nama[]);
void tampilkanDaftar(Kota daftarKota[], int jumlahKota);

#endif


