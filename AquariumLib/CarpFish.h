/**
 * @file CarpFish.h
 * @author Rajaditya Shrikishan Bajaj
 *
 * The class that represents the carp fish
 */

#ifndef AQUARIUM_CARPFISH_H
#define AQUARIUM_CARPFISH_H

#include "Item.h"
#include <memory>

/**
 * Class representing Carp Fish
 */
class CarpFish : public Item{
private:
    /// The underlying fish image
    std::unique_ptr<wxImage> mFishImage;

    /// The bitmap we can display for this fish
    std::unique_ptr<wxBitmap> mFishBitmap;

    // Item location in the aquarium
    double  mX = 0;     ///< X location for the center of the item
    double  mY = 0;     ///< Y location for the center of the item

public:
    /// Default constructor (disabled)
    CarpFish() = delete;

    /// Copy constructor (disabled)
    CarpFish(const CarpFish &) = delete;

    /// Assignment operator
    void operator=(const CarpFish &) = delete;

    CarpFish(Aquarium* aquarium);

    void Draw(wxDC* dc) override;

    bool HitTest(int x, int y) override;

   void SetLocation(double x, double y) override;
};

#endif //AQUARIUM_CARPFISH_H
