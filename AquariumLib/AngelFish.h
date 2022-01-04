/**
 * @file AngelFish.h
 * @author Rajaditya Shrikishan BAjaj
 *
 * The class that represents the Angel Fish
 */

#ifndef AQUARIUM_ANGELFISH_H
#define AQUARIUM_ANGELFISH_H

#include "Item.h"

/**
 * Class representing angel fish
 */
class AngelFish : public Item {
private:

    /// The underlying fish image
    std::unique_ptr<wxImage> mFishImage;

    /// The bitmap we can display for this fish
    std::unique_ptr<wxBitmap> mFishBitmap;

public:
    /// Default constructor (disabled)
    AngelFish() = delete;

    /// Copy constructor (disabled)
    AngelFish(const AngelFish &) = delete;

    /// Assignment operator
    void operator=(const AngelFish &) = delete;

    AngelFish(Aquarium* aquarium);

    void Draw(wxDC* dc) override;

    bool HitTest(int x, int y) override;
};

#endif //AQUARIUM_ANGELFISH_H
