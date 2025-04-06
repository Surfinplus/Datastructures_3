#ifndef POPULASYON_HPP
#define POPULASYON_HPP

#include "Kromozom.hpp"

class Populasyon {
public:
    struct KromozomDugumu {
        Kromozom* kromozom;
        KromozomDugumu* ileri;
        KromozomDugumu* geri;

        KromozomDugumu(Kromozom* kromozom);
    };

    KromozomDugumu* bas;
    KromozomDugumu* son;

    Populasyon();
    void kromozomEkle(Kromozom* yeniKromozom);
    void temizle(); 
    ~Populasyon();
};

#endif
