#include "imagedansdiaporama.h"


/*** Constructeurs ***/
ImageDansDiaporama::ImageDansDiaporama():
    _position(0),
    _rang(0)
{
}

ImageDansDiaporama::ImageDansDiaporama(unsigned int pRang, unsigned int pPos):
    _position(pPos),
    _rang(pRang)
{
}

ImageDansDiaporama::ImageDansDiaporama(const ImageDansDiaporama& origin):
    _position(origin.getPos()),
    _rang(origin.getRang())
{
}



/*** Getters ***/
unsigned int ImageDansDiaporama::getPos() const
{
    return _position;
}

unsigned int ImageDansDiaporama::getRang() const
{
    return _rang;
}

/*** Setters ***/
void ImageDansDiaporama::setPos(unsigned int pPos)
{
    _position = pPos;
}
void ImageDansDiaporama::setRang(unsigned int pRang)
{
    _rang = pRang;
}
