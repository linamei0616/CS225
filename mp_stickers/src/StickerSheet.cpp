#include "StickerSheet.h"


// //testing 
#include "StickerSheet.h"

StickerSheet::StickerSheet (const Image &picture, unsigned max) {
    picture_ = picture;
    max_ = max;
}
StickerSheet::~StickerSheet () {
    for (auto t: stickers_) {
        delete t;
        t = NULL;
    }
}
StickerSheet::StickerSheet (const StickerSheet &other) {
    picture_ = other.picture_;
    max_ = other.max_;
    for (auto t: other.stickers_) {
        Image* to_add = new Image(*t);
        stickers_.push_back(to_add);
    }
}
const StickerSheet & StickerSheet::operator=(const StickerSheet &other) {
    if (this == &other) {
        return *this;
    }
    picture_ = other.picture_;
    max_ = other.max_;
    for (auto t: stickers_) {
        delete t;
        t = NULL;
    }
    for (auto t: other.stickers_) {
        Image* to_add = new Image(*t);
        stickers_.push_back(to_add);
    }
    return *this; 
}

void StickerSheet::changeMaxStickers (unsigned max) {
    if (stickers_.size() > max) {
        std::vector<Image*> max_stickers;
        for (unsigned int i = 0; i < max; ++i) {
            max_stickers.push_back(stickers_[i]);
        }
        for (unsigned int j = max; j < stickers_.size(); ++j) {
            removeSticker(j);
        }
        stickers_ = max_stickers;
    }
    max_ = max;
}
int StickerSheet::addSticker (Image &sticker, unsigned x, unsigned y) {
    if (stickers_.size() < max_) {
        int size = stickers_.size();
        Image* to_add = new Image(sticker);
        to_add->x_ = x;
        to_add->y_ = y;
        stickers_.push_back(to_add);
        return size;
    }
    return -1;
}
bool StickerSheet::translate (unsigned index, unsigned x, unsigned y) {
    if (index >= stickers_.size()) {
        return false; 
    }
    stickers_[index]->x_ = x;
    stickers_[index]->y_ = y;
    return true;
}
void StickerSheet::removeSticker (unsigned index) {
    Image* to_delete = stickers_[index];
    delete to_delete;
    to_delete = NULL;
    stickers_.erase(stickers_.begin() + index);
}

Image * StickerSheet::getSticker (unsigned index) {
    if (index >= stickers_.size()) {
        return NULL;
    } else if (index < 0) {
        return NULL;
    }
    return stickers_[index];
}
Image StickerSheet::render () const {
    Image rendered_(picture_);
    for (unsigned int a = 0; a < stickers_.size(); a++) {
        unsigned int sticker_y = stickers_.at(a)->height() + stickers_.at(a)->y_;
        unsigned int sticker_x = stickers_.at(a)->width() + stickers_.at(a)->x_;
        if (sticker_y > rendered_.height()) {
            rendered_.resize(rendered_.width(), sticker_y);
        }
        if (sticker_x > rendered_.width()) {
            rendered_.resize(sticker_x, rendered_.height());
        }
        for (unsigned int i = 0; i < stickers_[a]->width(); ++i) {
            for (unsigned int j = 0; j < stickers_[a]->height(); ++j) {
                cs225::HSLAPixel &pixel = stickers_[a]->getPixel(i,j);
                if (pixel.a != 0) {
                    rendered_.getPixel(i + stickers_[a]->x_, j + stickers_[a]->y_) = pixel;
                }
            }
        }
    }
    return rendered_;
}