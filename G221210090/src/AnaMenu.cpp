/*
*@file AnaMenu.cpp
*@description Bu dosyada menumuz ve yapabileceğimiz işlemler bulunuyor.
*@course 2. Öğretim C Grubu
*@assignment 1. Ödev
*@date 10.11.2024
*@author Eren Çoban g221210090 eren.coban1@ogr.sakarya.edu.tr
*/
#include "AnaMenu.hpp"
#include <iostream> 
using namespace std;
void AnaMenu::goster(Islemler& islemler, Populasyon& populasyon) {
    int secim;
    do {
        
            cout << "AnaMenu\n1- Caprazlama\n2- Mutasyon\n3- Otomatik Islemler\n4- Ekrana Yaz\n5-Populasyonu Goruntule\n6-Cikis\nSeciminiz: ";
            cin >> secim;

        switch (secim) {
            case 1: {
                caprazlama(islemler);
                break;
            }
            case 2: {
                mutasyon(islemler);
                break;
            }
            case 3: {
                otomatikIslemler(islemler);
                break;
            }
            case 4: {
                ekranaYaz(islemler);
                break;
            }
            case 5: {
                populasyonuGoruntule(islemler, populasyon);
                break;
            }
            case 6:
                    cout << "Cikis yapiliyor..." << endl;
                break;
            default:
                    cout << "Gecersiz secim! Lutfen tekrar deneyin." << endl;
        }
    } while (secim != 6);
}

void AnaMenu::caprazlama(Islemler& islemler) {
    int satir1, satir2;
        cout << "Caprazlama icin secilen kromozom1: "<<endl;
        cin >> satir1;
        cout << "Caprazlama icin secilen kromozom2: "<<endl;
        cin >> satir2;
    system("CLS");
    islemler.caprazlama(satir1, satir2);
        cout << "Caprazlama tamamlandi!" << endl;
}

void AnaMenu::mutasyon(Islemler& islemler) {
    int satir, sutun;
        cout << "Mutasyon icin kromozom (satir)"<<endl;
        cin >> satir;
        cout << "Mutasyon icin gen (sutun)"<<endl;
        cin >> sutun;
    system("CLS");
    islemler.mutasyon(satir, sutun);
        cout << "Mutasyon tamamlandi!" << endl;
}

void AnaMenu::otomatikIslemler(Islemler& islemler) {
    system("CLS");
    islemler.otomatikIslemler("Islemler.txt");
    cout << "Otomatik islemler tamamlandi!" << endl;
}

void AnaMenu::ekranaYaz(Islemler& islemler) {
    islemler.ekranaYaz();
}

void AnaMenu::populasyonuGoruntule(Islemler& islemler, Populasyon& populasyon) {
    islemler.populasyonuGoruntule(populasyon);
}
