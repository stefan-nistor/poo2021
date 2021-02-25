//
// Created by Stefan on 2/25/2021.
//

#include "Masina.h"

Masina::Masina() {
    anul_fabricatiei = 2010;
    culoare = "Rosie";
    marca = "Dacia Logan";
}

void Masina::seteazaAnulFabricatiei(unsigned int anul_fabricatiei) {
    this->anul_fabricatiei = anul_fabricatiei;
}

void Masina::vopseste(const char *culoareNoua) {
    this->culoare = culoareNoua;
}

const char *Masina::getMarca() {
    return this->marca;
}

const char *Masina::getCuloare() {
    return this->culoare;
}

unsigned int Masina::getAnulFabricatiei() const {
    return this->anul_fabricatiei;
}

void Masina::setMarca(const char *marca) {
    this->marca = marca;
}


