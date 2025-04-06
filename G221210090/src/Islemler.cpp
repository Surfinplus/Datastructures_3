/*
*@file Islemler.cpp
*@description Bu dosyada kromozomlar üzerinde yaptığımız işlemlerin fonksiyonları bulunuyor -> caprazlama mutasyon otomatik islemler ekrana yaz populasyonu goruntule
populasyonu buradan görüntülemek istedim çünkü menuye isteğe bağlı böyle bir seçenek ekleyeceğim bu populasyon üzerinde yapılsada bir işlem diye düşündüm.
*@course 2. Öğretim C Grubu
*@assignment 1. Ödev
*@date 10.11.2024
*@author Eren Çoban g221210090 eren.coban1@ogr.sakarya.edu.tr
*/
#include "Islemler.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Islemler::Islemler(Populasyon& populasyon) : populasyon(populasyon) {}


void Islemler::caprazlama(int satir1, int satir2) {
    
    Populasyon::KromozomDugumu* dugum1 = populasyon.bas;
    Populasyon::KromozomDugumu* dugum2 = populasyon.bas;

    for (int i = 0; i < satir1 && dugum1; ++i) dugum1 = dugum1->ileri;
    for (int i = 0; i < satir2 && dugum2; ++i) dugum2 = dugum2->ileri;

    if (!dugum1 || !dugum2) {
        cerr << "Geçersiz satir numaralari." << endl;
        return;
    }

    Kromozom* kromozom1 = dugum1->kromozom;
    Kromozom* kromozom2 = dugum2->kromozom;

    int uzunluk1 = kromozom1->uzunluk();
    int uzunluk2 = kromozom2->uzunluk();

    Kromozom* yeniKromozom1 = new Kromozom();
    Kromozom* yeniKromozom2 = new Kromozom();

    if (uzunluk1 == 2 && uzunluk2 % 2 == 0) {
        
        yeniKromozom1->genEkle(kromozom1->bas->harf); // 1. Kromozomdan ilk gen
        GenDugumu* iter2 = kromozom2->bas;
        for (int i = 0; i < uzunluk2 / 2; ++i) iter2 = iter2->ileri;
        while (iter2) {
            yeniKromozom1->genEkle(iter2->harf);
            iter2 = iter2->ileri;
        }

        yeniKromozom2->genEkle(kromozom1->bas->ileri->harf); // 1. Kromozomdan ikinci gen
        iter2 = kromozom2->bas;
        for (int i = 0; i < uzunluk2 / 2; ++i) {
            yeniKromozom2->genEkle(iter2->harf);
            iter2 = iter2->ileri;
        }

    } else if (uzunluk1 == 2 && uzunluk2 == 2) {
        
        yeniKromozom1->genEkle(kromozom1->bas->harf); // 1. Kromozomdan ilk gen
        yeniKromozom1->genEkle(kromozom2->bas->ileri->harf); // 2. Kromozomdan ikinci gen

        yeniKromozom2->genEkle(kromozom1->bas->ileri->harf); // 1. Kromozomdan ikinci gen
        yeniKromozom2->genEkle(kromozom2->bas->harf); // 2. Kromozomdan ilk gen
    } else if (uzunluk1 == 2 && uzunluk2 % 2 == 1) {
        
        yeniKromozom1->genEkle(kromozom1->bas->harf); // 1. Kromozomdan ilk gen
        yeniKromozom1->genEkle(kromozom2->bas->ileri->ileri->harf); // 2. Kromozomdan son gen

        yeniKromozom2->genEkle(kromozom1->bas->ileri->harf); // 1. Kromozomdan ikinci gen
        yeniKromozom2->genEkle(kromozom2->bas->harf); // 2. Kromozomdan ilk gen
    } else {
       
        GenDugumu* orta1 = kromozom1->bas;
        GenDugumu* orta2 = kromozom2->bas;

        for (int i = 0; i < uzunluk1 / 2; ++i) orta1 = orta1->ileri;
        for (int i = 0; i < uzunluk2 / 2; ++i) orta2 = orta2->ileri;

        GenDugumu* iter1 = kromozom1->bas;
        while (iter1 != orta1) {
            yeniKromozom1->genEkle(iter1->harf);
            iter1 = iter1->ileri;
        }

        if (uzunluk2 % 2 == 0) {
            yeniKromozom1->genEkle(orta2->harf);
        }

        GenDugumu* iter2 = orta2->ileri;
        while (iter2) {
            yeniKromozom1->genEkle(iter2->harf);
            iter2 = iter2->ileri;
        }

        iter1 = orta1->ileri;
        while (iter1) {
            yeniKromozom2->genEkle(iter1->harf);
            iter1 = iter1->ileri;
        }

        if (uzunluk1 % 2 == 0) {
            yeniKromozom2->genEkleBas(orta1->harf);
        }

        iter2 = kromozom2->bas;
        while (iter2 != orta2) {
            yeniKromozom2->genEkle(iter2->harf);
            iter2 = iter2->ileri;
        }
    }

    populasyon.kromozomEkle(yeniKromozom1);
    populasyon.kromozomEkle(yeniKromozom2);
}




void Islemler::mutasyon(int satir, int sutun) {
    Populasyon::KromozomDugumu* dugum = populasyon.bas;

    for (int i = 0; i < satir && dugum; ++i) dugum = dugum->ileri;

    if (!dugum) {
        cerr << "Gecersiz satir numarasi." << endl;
        return;
    }

    Kromozom* kromozom = dugum->kromozom;
    GenDugumu* gen = kromozom->bas;

    for (int i = 0; i < sutun && gen; ++i) gen = gen->ileri;

    if (!gen) {
        cerr << "Gecersiz sutun numarasi." << endl;
        return;
    }

    gen->harf = 'X';
    
}



void Islemler::otomatikIslemler(const string& dosyaAdi) {
    ifstream dosya(dosyaAdi);
    if (!dosya.is_open()) {
        cerr << "Dosya acilamadi: " << dosyaAdi << endl;
        return;
    }

        string satir;
    while (getline(dosya, satir)) {
        if (satir.empty()) continue;

        istringstream ss(satir);
        string komut;
        ss >> komut;

        // Geçici nesneler
        Kromozom* kromozom1 = nullptr;
        Kromozom* kromozom2 = nullptr;

        
        if (komut == "C") {
            int kromozomIndex1, kromozomIndex2;
            if (!(ss >> kromozomIndex1 >> kromozomIndex2) || kromozomIndex1 < 0 || kromozomIndex2 < 0) {
                cerr << "Gecersiz caprazlama satir numaralari: " << kromozomIndex1 << ", " << kromozomIndex2 << endl;
                continue;
            }
            
            caprazlama(kromozomIndex1, kromozomIndex2);
        }
        
        else if (komut == "M") {
            int kromozomIndex, sutun;
            if (!(ss >> kromozomIndex >> sutun) || kromozomIndex < 0 || sutun < 0) {
                cerr << "Gecersiz mutasyon satir veya sutun numaralari: " << kromozomIndex << ", " << sutun << endl;
                continue;
            }
            
            mutasyon(kromozomIndex, sutun);
        }
        
        else if (komut == "E") {
            ekranaYaz();
        } else {
            cerr << "Gecersiz islem komutu: " << komut << endl;
        }

        // Geçici nesneleri serbest bırak
        if (kromozom1 != nullptr) {
            delete kromozom1;  
        }
        if (kromozom2 != nullptr) {
            delete kromozom2;  
        }

        
        
    }

    dosya.close();
   
}





// Ekrana yazma işlemi
void Islemler::ekranaYaz() {
    Populasyon::KromozomDugumu* dugum = populasyon.bas;

    while (dugum) {
        GenDugumu* gen = dugum->kromozom->bas;
        if (!gen) {
            dugum = dugum->ileri;
            continue;
        }

        char minHarf = gen->harf;
        GenDugumu* gezGen = gen;
        bool dahaKucukBulundu = false;

        while (gezGen->ileri) {
            gezGen = gezGen->ileri;
        }

        while (gezGen != gen) {
            if (gezGen->harf < minHarf) {
                minHarf = gezGen->harf;
                dahaKucukBulundu = true;
                break;
            }
            gezGen = gezGen->geri;
        }

        cout << minHarf << " ";
        dugum = dugum->ileri;
    }

        cout << endl;
}


void Islemler::populasyonuGoruntule(const Populasyon& populasyon){
    system("CLS");
    Populasyon::KromozomDugumu* simdiki = populasyon.bas;
    int kromozomNo = 0;
    while(simdiki){
        cout << "Kromozom " << kromozomNo << ": ";
        GenDugumu* gen = simdiki->kromozom->bas;
        while(gen){
            cout << gen->harf << " ";
            gen = gen->ileri;
        }
        cout <<endl;
        simdiki = simdiki->ileri;
        ++kromozomNo;
    }

    
}
