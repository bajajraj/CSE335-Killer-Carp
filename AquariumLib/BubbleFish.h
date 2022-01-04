/**
 * @file BubbleFish.h
 * @author Rajaditya Shrikishan Bajaj
 *
 * The class that represents the Bubble Fish
 */

#ifndef AQUARIUM_BUBBLEFISH_H
#define AQUARIUM_BUBBLEFISH_H

#include "Item.h"
#include <memory>

/**
 * Class representing Bubble fish
 */
class BubbleFish : public Item {
private:
    /// The underlying fish image
    std::unique_ptr<wxImage> mFishImage;

    /// The bitmap we can display for this fish
    std::unique_ptr<wxBitmap> mFishBitmap;
public:
    /// Default constructor (disabled)
    BubbleFish() = delete;

    /// Copy constructor (disabled)
    BubbleFish(const BubbleFish &) = delete;

/// Assignment operator
    void operator=(const BubbleFish &) = delete;

    BubbleFish(Aquarium* aquarium);

    void Draw(wxDC* dc) override;

    bool HitTest(int x, int y) override;

};

#endif //AQUARIUM_BUBBLEFISH_H
