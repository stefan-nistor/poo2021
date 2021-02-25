//
// Created by Stefan on 2/25/2021.
//

#ifndef LAB1_MASINA_H
#define LAB1_MASINA_H


class Masina {
private:
    unsigned int anul_fabricatiei;
    const char* culoare;
    const char* marca;
public:
    Masina();

    void seteazaAnulFabricatiei(unsigned int anul_fabricatiei);

    const char* getMarca();
    const char* getCuloare();
    unsigned int getAnulFabricatiei() const;

    void vopseste(const char* culoareNoua);
    void setMarca(const char* marca);
};


#endif //LAB1_MASINA_H
