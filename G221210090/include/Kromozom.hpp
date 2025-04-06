#ifndef KROMOZOM_HPP
#define KROMOZOM_HPP

#include "GenDugumu.hpp"

class Kromozom {
public:
    GenDugumu* bas;
    GenDugumu* son; 

    Kromozom();
    void genEkle(char harf); 
    int uzunluk() const;      
    void temizle();           
    void genEkleBas(char harf); 
    ~Kromozom();
};

#endif
