#include "imagedansdiaporama.h"

ImageDansDiaporama::ImageDansDiaporama(unsigned int pPos, unsigned int pRang):
    pos(pPos),
    rang(pRang)
{}

int ImageDansDiaporama::getPos() {
    return this->pos;
}
int ImageDansDiaporama::getRang() {
    return this->rang;
}
