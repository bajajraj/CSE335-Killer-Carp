/**
 * @file Aquarium.cpp
 * @author Rajaditya Shrikishan Bajaj
 */

#include "pch.h"

#include <memory>
#include "Aquarium.h"
#include "FishBeta.h"
#include "AngelFish.h"
#include "BubbleFish.h"

using namespace std;

/// Initial fish X location
const int InitialX = 200;

/// Initial fish Y location
const int InitialY = 200;

/**
 * Draw the aquarium
 * @param dc The device context to draw on
 */
void Aquarium::OnDraw(wxDC *dc)
{
    dc->DrawBitmap(*mBackground, 0, 0);

    wxFont font(wxSize(0, 20),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);
    dc->SetFont(font);
    dc->SetTextForeground(wxColour(0, 64, 0));
    dc->DrawText(L"Under the Sea!", 10, 10);

    for (const auto& item : mItems)
    {
        item->Draw(dc);
    }
}

/**
 * Add an item to the aquarium
 * @param item New item to add
 */
void Aquarium::Add(std::shared_ptr<Item> item)
{
    mItems.push_back(item);
}

/**
 * Aquarium Constructor
 */
Aquarium::Aquarium()
{
    mBackground = make_unique<wxBitmap>(
            L"images/background1.png", wxBITMAP_TYPE_ANY);
}

/**
 * Test an x,y click location to see if it clicked
 * on some item in the aquarium.
 * @param x X location in pixels
 * @param y Y location in pixels
 * @returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<Item> Aquarium::HitTest(int x, int y)
{
    for (auto i = mItems.rbegin(); i != mItems.rend();  i++)
    {
        if ((*i)->HitTest(x, y))
        {
            return *i;
        }
    }

    return  nullptr;
}

/**
 * Function that puts the given item at the end of the list
 * @param item object of vector Item
 */
void Aquarium::PutAtEnd(const shared_ptr<Item>& item)
{
    auto loc = find(begin(mItems), end(mItems), item);
    if (loc != end(mItems))
    {
        mItems.erase(loc);
    }
    mItems.push_back(item);
}

/**
 * Function that kills the other fish
 * @param killer the class of the fish killing.
 * @return boolean telling if the fish is to be killed or not.
 */
bool Aquarium::FishKill(Item * killer)
{
    bool fishKill = false;

    for (const auto& item : mItems)
    {
        if (item.get() == killer)
        {
            continue;
        }
        if (item->HitTest(killer->GetX(), killer->GetY())) {
            auto loc = find(begin(mItems), end(mItems), item);
            if (loc!=end(mItems)) {
                mItems.erase(loc);
                fishKill = true;
                return fishKill;
            }
        }
    }
    return fishKill;
}