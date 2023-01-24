#include "Carta.h"

const std::string Carta::rutasTexturas[MAXCARTAS] = {
    "ResourseFiles/Diamond/LogoDiamond.jpg",
    "ResourseFiles/Ruby/LogoRuby.jpg",
    "ResourseFiles/Fluorite/LogoFluorite.jpg",
    "ResourseFiles/Emerald/LogoEmerald.jpg",
    "ResourseFiles/Gold/LogoGold.jpg",
    "ResourseFiles/Iron/LogoIron.jpg"
};

void Carta::loadTexture(const std::string& rutaTextura) {
    if (!m_texture.loadFromFile(rutaTextura)) {
        std::cout << "Error al cargar la textura" << std::endl;
    }
    m_texture.setSmooth(true);
    m_texture.setRepeated(false);
    m_sprite.setTexture(m_texture);
}