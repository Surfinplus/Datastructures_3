/*
*@file Populasyon.cpp
*@description Bu dosyada populasyona ait kromozom dugumlerini oluşturan fonksiyon ve populasyonu temizleyen fonksiyon yıkıcı için bulunmaktadır.
*@course 2. Öğretim C Grubu
*@assignment 1. Ödev
*@date 10.11.2024
*@author Eren Çoban g221210090 eren.coban1@ogr.sakarya.edu.tr
*/

#include "Populasyon.hpp"

Populasyon::KromozomDugumu::KromozomDugumu(Kromozom* kromozom) 
    : kromozom(kromozom), ileri(nullptr), geri(nullptr) {}

Populasyon::Populasyon() : bas(nullptr), son(nullptr) {}

void Populasyon::kromozomEkle(Kromozom* yeniKromozom) {
    KromozomDugumu* yeniDugum = new KromozomDugumu(yeniKromozom);
    if (!bas) {
        bas = son = yeniDugum;
    } else {
        son->ileri = yeniDugum;
        yeniDugum->geri = son;
        son = yeniDugum;
    }
}

void Populasyon::temizle() {
    KromozomDugumu* simdiki = bas;
    while (simdiki) {
        KromozomDugumu* silinecek = simdiki;
        simdiki = simdiki->ileri;
        delete silinecek->kromozom;
        delete silinecek;
    }
    bas = son = nullptr;
}

Populasyon::~Populasyon() {
    temizle();
}
