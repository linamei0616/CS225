#include "Image.h"
#include <cmath>
#include <iostream>

void Image::lighten() {
    for (unsigned int x = 0; x < width(); x++) {
        for (unsigned int y = 0; y < height(); y++) {
            cs225::HSLAPixel& pixel = this->getPixel(x,y);
            pixel.l += 0.1;
            if (pixel.l > 1) {
                pixel.l = 1;
            }
        }
    }
};
void Image::lighten(double amount) {
    for (unsigned int x = 0; x < width(); x++) {
        for (unsigned int y = 0; y < height(); y++) {
            cs225::HSLAPixel& pixel = this->getPixel(x,y);
            pixel.l += amount;
            if (pixel.l > 1) {
                pixel.l = 1;
            }
        }
    }
};
void Image::darken() {
    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            cs225::HSLAPixel& pixel = this->getPixel(x,y);
            pixel.l -= 0.1;
            if (pixel.l < 0) {
                pixel.l = 0;
            }
        }
    }
};
void Image::darken(double amount) {
    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            cs225::HSLAPixel& pixel = this->getPixel(x,y);
            pixel.l -= amount;
            if (pixel.l < 0) {
                pixel.l = 0;
            }
        }
    }
};
void Image::saturate() {
    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            cs225::HSLAPixel& pixel = this->getPixel(x,y);
            pixel.s += 0.1;
            if (pixel.s > 1) {
                pixel.s = 1;
            }
        }
    }
};
void Image::saturate(double amount) {
    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            cs225::HSLAPixel& pixel = this->getPixel(x,y);
            pixel.s += amount;
            if (pixel.s > 1) {
                pixel.s = 1;
            }
        }
    }
};
void Image::desaturate() {
    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            cs225::HSLAPixel& pixel = this->getPixel(x,y);
            pixel.s -= 1;
            if (pixel.s < 0) {
                pixel.s = 0;
            }
        }
    }
};
void Image::desaturate(double amount) {
    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            cs225::HSLAPixel& pixel = this->getPixel(x,y);
            pixel.s -= amount;
            if (pixel.s < 0) {
                pixel.s = 0;
            }
        }
    }
};
void Image::grayscale() {
    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            cs225::HSLAPixel& pixel = this->getPixel(x,y);
            pixel.s = 0;
        }
    }
};

void Image::rotateColor(double degrees) {
    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            cs225::HSLAPixel& pixel = this->getPixel(x,y);
            pixel.h+=degrees;
            if (pixel.h < 0) {
                pixel.h += 360;
            } else if (pixel.h > 360) {
                pixel.h -= 360;
            }
        }
    }
};
void Image::illinfy() {
    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            cs225::HSLAPixel& pixel = this->getPixel(x,y);
            if (360 - pixel.s > pixel.s - 0 ) {
                pixel.s = 216;
            } else {
                pixel.s = 11;
            }        
        }
    }
};
void Image::scale(double factor) {
    PNG* original = new PNG(*this);
    this->resize((factor*this->width()), (factor*this->height()));
    for (unsigned x=0; x < this->width(); x++) {
        for (unsigned y=0; y < this->height(); y++) {
            cs225::HSLAPixel& newPixel = this->getPixel(x,y);
            cs225::HSLAPixel& currPixel = original->getPixel((x/factor), (y/factor));
            newPixel=currPixel;
        }
    }
    delete original;
    original = NULL;
};
void Image::scale(unsigned w, unsigned h) {
    if ((double)h/this->height() < (double)w/this->width()) {
        scale((double)h/this->height());
    } else {
        scale((double)w/this->width());
    }
};