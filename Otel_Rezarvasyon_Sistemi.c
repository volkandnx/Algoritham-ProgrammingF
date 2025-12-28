#include <stdio.h>
#include <stdlib.h>

struct Musteri {
    int odaNo;
    char ad[50];
    char soyad[50];
    int gunSayisi;
    float toplamUcret;
};

const char* DOSYA_YOLU = "C:\\AlgorithamProject\\otel_kayitlari.txt";
const char* GECICI_DOSYA = "C:\\AlgorithamProject\\gecici.txt";

int odaDoluMu(int istenenOda) {
    FILE *dosya = fopen(DOSYA_YOLU, "r");
    if (dosya == NULL) return 0; 

    int oda, gun;
    char ad[50], soyad[50];
    float ucret;

    while (fscanf(dosya, "%d %s %s %d %f", &oda, ad, soyad, &gun, &ucret) != EOF) {
        if (oda == istenenOda) {
            fclose(dosya);
            return 1; 
        }
    }
    fclose(dosya);
    return 0; 
}

void yeniKayit() {
    int oda;
    printf("\n--- Yeni Kayit Ekrani ---");

    while(1) {
        printf("\nOda No Gir: "); 
        scanf("%d", &oda);

        if (odaDoluMu(oda) == 1) {
            printf(" %d numarali oda DOLU! Baska oda seciniz.\n", oda);
        } else {
            printf("Oda %d musait, isleme devam...\n", oda);
            break; 
        }
    }

    FILE *dosya = fopen(DOSYA_YOLU, "a");    
    if (dosya == NULL) {
        printf("Dosya acilamadi! Klasor yolunu kontrol et!\n");
        return;
    }

    struct Musteri m;
    m.odaNo = oda;

    printf("Ad: "); scanf("%s", m.ad);
    printf("Soyad: "); scanf("%s", m.soyad);
    printf("Gun: "); scanf("%d", &m.gunSayisi);

    m.toplamUcret = m.gunSayisi * 1500.0;

    fprintf(dosya, "%d %s %s %d %.2f\n", m.odaNo, m.ad, m.soyad, m.gunSayisi, m.toplamUcret);
    fclose(dosya);
    printf("\nKayit tamamdir! Borc: %.2f TL\n", m.toplamUcret);
}

void kayitSil() {
    int silinecekOda;
    int bulundu = 0;

    printf("\n--- Cikis Islemi  ---");
    printf("\nCikis yapilacak Oda No: ");
    scanf("%d", &silinecekOda);

    FILE *dosya = fopen(DOSYA_YOLU, "r");
    FILE *gecici = fopen(GECICI_DOSYA, "w");

    if (dosya == NULL || gecici == NULL) {
        printf("Dosyalar acilamadi aga, sistemde bi ariza var.\n");
        return;
    }

    struct Musteri m;

    while (fscanf(dosya, "%d %s %s %d %f", &m.odaNo, m.ad, m.soyad, &m.gunSayisi, &m.toplamUcret) != EOF) {
        if (m.odaNo != silinecekOda) {
            fprintf(gecici, "%d %s %s %d %.2f\n", m.odaNo, m.ad, m.soyad, m.gunSayisi, m.toplamUcret);
        } else {
            bulundu = 1; 
        }
    }

    fclose(dosya);
    fclose(gecici);

    if (bulundu) {
        remove(DOSYA_YOLU);
        rename(GECICI_DOSYA, DOSYA_YOLU);
        printf("\n>>> %d numarali oda bosaltildi. Gule gule kardesim!\n", silinecekOda);
    } else {
        remove(GECICI_DOSYA);
        printf("\n>>> boyle bir oda zaten yok veya bos!\n");
    }
}

void listele() {
    FILE *dosya = fopen(DOSYA_YOLU, "r");
    if (dosya == NULL) {
        printf("Kayit YOk!\n");
        return;
    }

    struct Musteri m; 

    printf("\n--- OTELDE KALANLAR ---\n");
    printf("%-10s %-15s %-15s %-10s %-10s\n", "ODA", "AD", "SOYAD", "GUN", "UCRET");
    printf("----------------------------------------------------------\n");

    while (fscanf(dosya, "%d %s %s %d %f", &m.odaNo, m.ad, m.soyad, &m.gunSayisi, &m.toplamUcret) != EOF) {
        printf("%-10d %-15s %-15s %-10d %.2f TL\n", m.odaNo, m.ad, m.soyad, m.gunSayisi, m.toplamUcret);
    }
    fclose(dosya);
}

int main() {
    int secim;
    while(1) {
        printf("\n==========================");
        printf("\n1- Yeni Kayit (Rezervasyon)");
        printf("\n2- Kayit Sil (Cikis)");
        printf("\n3- Listele");
        printf("\n4- Cikis");
        printf("\nSecim: ");
        scanf("%d", &secim);
        
        switch(secim) {
            case 1: yeniKayit();
                break;
            case 2: 
                listele(); 
                kayitSil();
                break;
            case 3: listele(); 
                break;
            case 4: 
                printf("Kapatiliyor...\n");
                exit(0);
            default: printf("Hatali tuslama yaptiniz!\n");
        }
    }
    return 0;
}