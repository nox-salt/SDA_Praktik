#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void createList(Kota daftarKota[]) {
    int i = 0;
    while (i < MAX_KOTA) {
        daftarKota[i].kt[0] = '\0';
        daftarKota[i].p = NULL;
        i++;
    }
}

void tambahKota(Kota daftarKota[], int *jumlahKota, char namaKota[]) {
    if (*jumlahKota < MAX_KOTA) {
        strcpy(daftarKota[*jumlahKota].kt, namaKota);
        daftarKota[*jumlahKota].p = NULL;
        (*jumlahKota)++;
    } else {
        printf("Daftar kota penuh!\n");
    }
}


void hapusKota(Kota daftarKota[], int *jumlahKota) {
    if (*jumlahKota > 0) {
        (*jumlahKota)--;
        daftarKota[*jumlahKota].kt[0] = '\0';
        daftarKota[*jumlahKota].p = NULL;
    } else {
        printf("Tidak ada kota untuk dihapus!\n");
    }
}


void tambahNama(Kota *kota, char nama[]) {
    dataNama *newNode = (dataNama *)malloc(sizeof(dataNama));
    if (newNode) {
        strcpy(newNode->nama, nama);
        newNode->next = kota->p;
        kota->p = newNode;
    } else {
        printf("Gagal menambahkan nama!\n");
    }
}


void hapusNama(Kota *kota, char nama[]) {
    dataNama *current = kota->p, *prev = NULL;
    while (current != NULL && strcmp(current->nama, nama) != 0) {
        prev = current;
        current = current->next;
    }
    if (current != NULL) {
        if (prev == NULL) {
            kota->p = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
        printf("Nama %s berhasil dihapus!\n", nama);
    } else {
        printf("Nama tidak ditemukan!\n");
    }
}

void tampilkanDaftar(Kota daftarKota[], int jumlahKota) {
    int i = 0;
    while (i < jumlahKota) {
        printf("Kota: %s\n", daftarKota[i].kt);
        dataNama *current = daftarKota[i].p;
        while (current) {
            printf(" - %s\n", current->nama);
            current = current->next;
        }
        i++;
    }
}

