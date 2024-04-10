#include "imagedansdiaporama.h"

ImageDansDiaporama::ImageDansDiaporama(unsigned int pPos, unsigned int pRang):
    _pos(pPos),
    _rang(pRang)
{}
int ImageDansDiaporama::getPos() {
    return this->_pos;
}
int ImageDansDiaporama::getRang() {
    return this->_rang;
}
