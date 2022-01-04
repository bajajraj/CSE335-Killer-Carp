/**
 * @file Aquarium.h
 * @author Rajaditya Shrikishan Bajaj
 *
 * The class that is responsible for the background
 */

#ifndef AQUARIUM_AQUARIUM_H
#define AQUARIUM_AQUARIUM_H

#include <memory>
#include <algorithm>

class Item;
/**
 * Class responsible for the background.
 */
class Aquarium {
private:

    std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use

    /// All of the items to populate our aquarium
    std::vector<std::shared_ptr<Item>> mItems;
public:

    void OnDraw(wxDC* dc);

    Aquarium();

    void Add(std::shared_ptr<Item> item);

    std::shared_ptr<Item> HitTest(int x, int y);

    void PutAtEnd(const std::shared_ptr<Item>& item);

    bool FishKill(Item* killer);
};

#endif //AQUARIUM_AQUARIUM_H