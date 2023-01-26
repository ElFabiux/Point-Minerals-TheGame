#include "Card.h"

const std::string Card::rutasTexturas[MAXCARTAS] = {
    "ResourseFiles/Diamond/LogoDiamond.jpg",
    "ResourseFiles/Ruby/LogoRuby.jpg",
    "ResourseFiles/Fluorite/LogoFluorite.jpg",
    "ResourseFiles/Emerald/LogoEmerald.jpg",
    "ResourseFiles/Gold/LogoGold.jpg",
    "ResourseFiles/Iron/LogoIron.jpg"
};

void Card::loadTexture(const std::string& rutaTextura) {
    if (!texture.loadFromFile(rutaTextura)) {
        std::cout << "Error al cargar la textura" << std::endl;
    }
    texture.setSmooth(true);
    texture.setRepeated(false);
    sprite.setTexture(texture);
}