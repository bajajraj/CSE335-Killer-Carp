/**
 * @file AquariumView.h
 * @author Rajaditya Shrikishan Bajaj
 *
 * View class for our aquarium
 */

#ifndef AQUARIUM_AQUARIUMVIEW_H
#define AQUARIUM_AQUARIUMVIEW_H

#include <memory>
#include "Aquarium.h"

/**
 * View class for our aquarium
 */
class AquariumView : public wxWindow{
private:
    /// An object that describes our aquarium
    Aquarium  mAquarium;

    void OnPaint(wxPaintEvent& event);

    /// Any item we are currently dragging
    std::shared_ptr<Item> mGrabbedItem;

public:

    void Initialize(wxFrame* parent);

    void OnAddFishBetaFish(wxCommandEvent& event);

    void OnLeftDown(wxMouseEvent& event);

    void OnLeftUp(wxMouseEvent& event);

    void OnMouseMove(wxMouseEvent& event);

    void OnAddFishAngelFish(wxCommandEvent& event);

    void OnAddBubbleFish(wxCommandEvent& event);

    void OnAddCarpFish(wxCommandEvent& event);
};

#endif //AQUARIUM_AQUARIUMVIEW_H
