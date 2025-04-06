/*
*@file Main.cpp
*@description Bu dosyada Dna.txt yi okuyan ve populasyonu oluşturan dosyaOkuVeOlustur fonksiyonu bulunuyor.
*@course 2. Öğretim C Grubu
*@assignment 1. Ödev
*@date 10.11.2024
*@author Eren Çoban g221210090 eren.coban1@ogr.sakarya.edu.tr
*/


#include "DNAoku.hpp"
#include "Populasyon.hpp"
#include "Kromozom.hpp"
#include "GenDugumu.hpp"
#include <iostream>
#include <fstream>
#include <sstream>



void DnaOku::dosyaOkuVeOlustur(Populasyon& populasyon, const string& dosyaAdi) {
    ifstream dosya(dosyaAdi);
    if (!dosya.is_open()) {
        cerr << "Dosya acilamadi: " << dosyaAdi << endl;
        return;
    }

        string satir;
    while (getline(dosya, satir)) {
        // Satırı kontrol et, boşsa atla
        if (satir.empty()) continue;

        istringstream ss(satir);
        string genHarf;
        Kromozom* yeniKromozom = new Kromozom();

        // Her gen harfini al ve kromozoma ekle
        while (ss >> genHarf) {
            if (!genHarf.empty() && genHarf.length() == 1) { // Gen sadece bir harf olmalı
                yeniKromozom->genEkle(genHarf[0]);
            }
        }

        
        populasyon.kromozomEkle(yeniKromozom);
        
    }
}
