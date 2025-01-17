/**
 * @file StickerSheet.h
 * Contains your declaration of the interface for the StickerSheet class.
 */
#pragma once
#include "Image.h"
#include <vector>
using namespace cs225;

class StickerSheet {
    public:
        StickerSheet(const Image &picture, unsigned max);
        ~StickerSheet();
        StickerSheet (const StickerSheet &other);
        const StickerSheet & operator= (const StickerSheet &other);
        void changeMaxStickers (unsigned max);
        int addSticker (Image &sticker, unsigned x, unsigned y);
        bool translate (unsigned index, unsigned x, unsigned y);
        void removeSticker (unsigned index);
        Image * getSticker (unsigned index);
        Image render () const;

        //for testing
        std::vector<Image*> return_stickers_();
        unsigned return_max_();

    private:
        std::vector<Image*> stickers_; // vector of pointers to images to hold all stickers
        unsigned max_; // max number of stickers
        Image picture_; // base picture
};