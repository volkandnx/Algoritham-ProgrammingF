# Algoritham-ProgrammingF
This repo inludes Algoritham&amp;Programming Class Project
# Otel Rezervasyon Sistemi

Bu proje, Algoritma ve Programlama dersi kapsamında C Programlama Dili kullanılarak geliştirilmiş, dosya tabanlı bir otel otomasyon sistemidir.

## Ozellikler

Proje asagidaki temel islevleri yerine getirmektedir:

* Yeni Musteri Kaydi (Check-in): Musteri bilgilerini (Ad, Soyad, Gun) alarak sisteme kaydeder.
* Oda Kontrol Algoritmasi: Secilen odanin dolu olup olmadigini kontrol eder. Eger oda doluysa, kullaniciyi uyarir ve yeni bir oda secmesini ister.
* Kayit Silme (Check-out): Otelden ayrilan musterinin kaydini siler ve odayi tekrar musait hale getirir. (Dosya yeniden yazma mantigi kullanilmistir).
* Listeleme: Mevcut musterileri ve borc bilgilerini duzenli bir liste halinde gosterir.
* Veri Kaliciligi (File Handling): Tum veriler .txt dosyasi uzerinde tutulur, program kapatilsa bile veriler kaybolmaz.

## Kurulum ve Calistirma (ONEMLI)

Projenin hatasiz calisabilmesi icin dosya yolunun olusturulmasi gerekmektedir.

1. Bilgisayarinizin C: surucusu icerisine girin.
2. AlgorithamProject adinda yeni bir klasor olusturun.
   Tam Yol: C:\AlgorithamProject
3. Kodu derleyip calistirin. Program, veritabani dosyasini (otel_kayitlari.txt) bu klasor icerisine otomatik olarak olusturacaktir.

## Kullanilan Teknolojiler

* Dil: C
* Kutuphaneler: stdio.h, stdlib.h
* Veri Yapilari: struct
* Dosya Islemleri: fopen, fprintf, fscanf, remove, rename

## Hazirlayan

Ad Soyad: VOLKAN DENIZ
Bolum: Bilisim Sistemleri Muhendisligi
Ders: Algoritma ve Programlama
