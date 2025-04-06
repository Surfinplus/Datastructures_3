#ifndef ANAMENU_HPP
#define ANAMENU_HPP

#include "Populasyon.hpp"  
#include "Islemler.hpp"    

class AnaMenu {
public:
    
    void goster(Islemler& islemler, Populasyon& populasyon);
    
private:
    void caprazlama(Islemler& islemler);  
    void mutasyon(Islemler& islemler);    
    void otomatikIslemler(Islemler& islemler); 
    void ekranaYaz(Islemler& islemler);  
    void populasyonuGoruntule(Islemler& islemler, Populasyon& populasyon); 
};

#endif 
