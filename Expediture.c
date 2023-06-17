#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void catat_pengeluaran();
void Inputan1();
void Inputan2();
void Inputan3();
void menu();

int main() {
    int pilih;
    printf("\t||===============================================================||\n");
    printf("\t||***************************************************************||\n");
    printf("\t||                        PROYEK DASPRO 2022                     ||\n");
    printf("\t||                           EXPENDITURE                         ||\n");
    printf("\t|| *     *     *     *     *     *     *     *     *     *     * ||\n");
    printf("\t||***************************************************************||\n");
    printf("\t||===============================================================||\n");
    printf("\t\t||============================================||\n");
    printf("\t\t||           MENGHITUNG PENGELUARAN           ||\n");
    printf("\t\t||           1. catat pengeluaran             ||\n");
    printf("\t\t||           2. Hitung Pengeluaran/Bulan      ||\n");
    printf("\t\t||           3. Hitung Pengeluaran/Hari       ||\n");
    printf("\t\t||           4. Hitung Pengeluaran/Tahun      ||\n");
    printf("\t\t||           0. keluar                        ||\n");
    printf("\t\t||============================================||\n");

    printf("Masukkan pilihan anda: ");
    scanf("%d", &pilih);
    switch (pilih) {
    case 1 :catat_pengeluaran();break;
    case 2 :Inputan1();break;
    case 3 :Inputan2();break;
    case 4 :Inputan3();break;
    case 0 :printf("\n\n\t||====================================||\n\t||             MAULIATE              ||\n\t||====================================||\n\n");
    }
}

void menu() {
    int pilih;

    printf("\t||===============================================================||\n");
    printf("\t||***************************************************************||\n");
    printf("\t||                        PROYEK DASPRO 2022                     ||\n");
    printf("\t||                           EXPENDITURE                         ||\n");
    printf("\t|| *     *     *     *     *     *     *     *     *     *     * ||\n");
    printf("\t||***************************************************************||\n");
    printf("\t||===============================================================||\n");
    printf("\t\t||============================================||\n");
    printf("\t\t||           MENGHITUNG PENGELUARAN           ||\n");
    printf("\t\t||           1. catat pengeluaran             ||\n");
    printf("\t\t||           2. Hitung Pengeluaran/Bulan      ||\n");
    printf("\t\t||           3. Hitung Pengeluaran/Hari       ||\n");
    printf("\t\t||           4. Hitung Pengeluaran/Tahun      ||\n");
    printf("\t\t||           0. keluar                        ||\n");
    printf("\t\t||============================================||\n");

    printf("Masukkan pilihan anda: ");
    scanf("%d", &pilih);
    switch (pilih){
    case 1 :catat_pengeluaran();break;
    case 2 :Inputan1();break;
    case 3 :Inputan2();break;
    case 4 :Inputan3();break;
    case 0 :printf("\n\n\t||====================================||\n\t||             MAULIATE               ||\n\t||====================================||\n\n");
    }
}    

void kondisi() {
 char y;
  printf("\nKembali ke menu?(enter Y/y)\n");
  printf("Keluar?(enter N/n)\n");
  scanf("%s", &y);
  if(y == 'Y' || 'y') {
    menu();
  }else if(y == 'N' || 'n') {
    menu();
  }else {
    system("cls");
  }
}

void catat_pengeluaran() {
    FILE *fp;
    char *filename = "proyek.txt";
    if((fp = fopen(filename, "a+")) == NULL) {
        printf("file cannot be opened!\n");
        exit(1);
    }
    char nama[255];
    int tanggal, bulan, tahun;
    int pengeluaran;
        printf("Nama        : "); scanf("%s", &nama);
        printf("Tanggal     : "); scanf("%d", &tanggal);
        printf("bulan       : "); scanf("%d", &bulan);
        printf("Tahun       : "); scanf("%d", &tahun);
        printf("Pengeluaran : "); scanf("%d", &pengeluaran);

        fprintf(fp, "%s|%d|%d|%d|%d\n", nama, tanggal, bulan, tahun, pengeluaran);
        fclose(fp);
        menu();
}

void Inputan1() {
    FILE *fp;
    fp = fopen("proyek.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
    }
     
    char nama[255];
    int tanggal, bulan, tahun;
    int pengeluaran;
    int counter = 0;
    int total = 0;
    int cari;
    int cari2;

    printf("inputan 1 : \n");
    printf("Cari Tahun : ");    scanf("%d", &cari);
    printf("Cari Bulan : ");    scanf("%d", &cari2);
    while (fscanf(fp, "%[^|]|%d|%d|%d|%d\n", &nama, &tanggal, &bulan, &tahun, &pengeluaran) != EOF) {
        if(cari == tahun && cari2 == bulan) {
            total += pengeluaran;
            counter++;
        } 
    }
    printf("\npengeluaran = %d\n", total);
    kondisi();
}

void Inputan2() {
  FILE *fp;
    fp = fopen("proyek.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
    }
    
    char nama[255];
    int tanggal, bulan, tahun, pengeluaran;
    int counter = 0;
    int total = 0;
    int cari;
    int cari2;
    int cari3;
    printf("Inputan 2 : \n");   
    printf("Cari Tanggal : ");  scanf("%d", &cari);         
    printf("Cari Bulan : ");    scanf("%d", &cari2);        
    printf("Cari Tahun : ");    scanf("%d", &cari3);
    while (fscanf(fp, "%[^|]|%d|%d|%d|%d\n", &nama, &tanggal, &bulan, &tahun, &pengeluaran) != EOF) {
        if(cari == tanggal && cari2 == bulan && cari3 == tahun) {
            total += pengeluaran;
            counter++;
        } 
    }
    printf("\npengeluaran = %d\n", total);
    kondisi();
}

void Inputan3() {
  FILE *fp;
    fp = fopen("proyek.txt", "r");
    if (fp == NULL) { 
        printf("Error opening file\n");
    }
    
    char nama[255];
    int tanggal, bulan, tahun, pengeluaran;
    int counter = 0;
    int total = 0;
    int cari;
    printf("Inputan 3 : \n");
    printf("Cari Tahun : ");   scanf("%d", &cari);
    while (fscanf(fp, "%[^|]|%d|%d|%d|%d\n", &nama, &tanggal, &bulan, &tahun, &pengeluaran) != EOF) {
        if(cari == tahun) {
            total += pengeluaran;
            counter++;
        } 
    }
    printf("\npengeluaran = %d\n", total);
    kondisi();
}