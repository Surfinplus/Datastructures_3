#ifndef ISLEMLER_HPP
#define ISLEMLER_HPP

#include "Populasyon.hpp"
#include <string>
#include <iostream>
using namespace std;

class Islemler {
private:
    Populasyon& populasyon;

public:
    Islemler(Populasyon& populasyon);
    void caprazlama(int satir1, int satir2);
    void mutasyon(int satir, int sutun);
    void otomatikIslemler(const string& dosyaAdi);
    void populasyonuGoruntule(const Populasyon& populasyon);
    void ekranaYaz();
    
};

#endif
