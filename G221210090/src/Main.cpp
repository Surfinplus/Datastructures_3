/*
*@file Main.cpp
*@description Bu dosya ihtiyacımız olan nesneleri oluşturup menuyu çağırır.
*@course 2. Öğretim C Grubu
*@assignment 1. Ödev
*@date 10.11.2024
*@author Eren Çoban g221210090 eren.coban1@ogr.sakarya.edu.tr
*/
#include "Populasyon.hpp"
#include "DnaOku.hpp"
#include "Islemler.hpp"
#include "AnaMenu.hpp"
using namespace std;

int main() {
    DnaOku dnaOku;
    Populasyon populasyon;
    dnaOku.dosyaOkuVeOlustur(populasyon, "Dna.txt");

    system("CLS");
    Islemler islemler(populasyon);

    AnaMenu menu;
    menu.goster(islemler, populasyon);

    populasyon.~Populasyon();
    return 0;
}
