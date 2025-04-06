/*
*@file Kromozom.cpp
*@description kromozom lar çift yönlü gendugumlerinden oluşuyor burada gen ekle fonksiyonumuz bulunuyor ve kromozomun uzunluğunu döndüren fonksiyonumuz bulunuyor.
*@course 2. Öğretim C Grubu
*@assignment 1. Ödev
*@date 10.11.2024
*@author Eren Çoban g221210090 eren.coban1@ogr.sakarya.edu.tr
*/


#include "Kromozom.hpp"



Kromozom::Kromozom() : bas(nullptr), son(nullptr) {}

void Kromozom::genEkle(char harf) {
    GenDugumu* yeniGen = new GenDugumu(harf);
    if (!bas) {
        bas = son = yeniGen;
    } else {
        son->ileri = yeniGen;
        yeniGen->geri = son;
        son = yeniGen;
    }
}

int Kromozom::uzunluk() const {
    int uzunluk = 0;
    GenDugumu* simdiki = bas;
    while (simdiki) {
        ++uzunluk;
        simdiki = simdiki->ileri;
    }
    return uzunluk;
}

void Kromozom::temizle() {
    GenDugumu* simdiki = bas;
    while (simdiki) {
        GenDugumu* silinecek = simdiki;
        simdiki = simdiki->ileri;
        delete silinecek;
    }
    bas = son = nullptr;
}



void Kromozom::genEkleBas(char harf) {
    
    GenDugumu* yeniGen = new GenDugumu(harf);
    yeniGen->harf = harf;  // Verilen harfi yeni gene atıyoruz.

    // Yeni genin 'ileri' bağlantısını eski başa yönlendiriyoruz.
    yeniGen->ileri = bas; 

    // Eğer başta zaten bir gen varsa, eski başın 'geri' bağlantısını yeni gene yönlendiriyoruz.
    if (bas != nullptr) {
        bas->geri = yeniGen;
    }

    // Yeni gen şu an baş oldu, o yüzden başa yeni gene işaret ediyoruz.
    bas = yeniGen;

    // Yeni genin 'geri' bağlantısını null yapıyoruz, çünkü baştaki genin gerisi yok.
    yeniGen->geri = nullptr;
}









Kromozom::~Kromozom() {
    temizle();
}
