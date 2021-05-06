/*
 *  ofxShelfPack.h
 *
 * \brief This addon wraps shelf-pack.ccp by mapbox (https://github.com/mapbox/shelf-pack-cpp)
 * It allows 2D rectangle bin packing by passing OpenFrameworks rectangle objects.
 *
 * Internal:
 * Bin vector managed by shelf-pack.hpp is kept at same size as rectangle reference vector of this
 * class, allowing bin dimensions to be applied to rectangles with passed refs.
 */


#pragma once
#include "ofMain.h"
#include "shelf-pack.hpp"
#include <iostream>

using namespace mapbox;


class ofxShelfPack {
public:
    /// \brief Set up packer
    /// \param container the container to pack into
    void setup(ofRectangle* container);
    /// \brief Set up packer, optionally as a resizable container
    /// \param container the container to pack into
    /// \param resizable true will allow the container to resize
    void setup(ofRectangle* container, bool resize);
    /// \brief Pack a single rectangle into the container
    /// \param item reference to the rectangle to pack into container, x and y will be modified on update
    bool pack(ofRectangle* item);
    /// \brief Pack many rectangles into the container
    /// \param items reference to the rectangles to pack into container, will be updated automatically
    /// \return whether or not packing ws successful.
    unsigned long packMany(vector<ofRectangle>* items);
    /// \brief Update previously packed rectangles (this changes x and y on the passed rectangle references)
    /// \return Number of successfully packed items
    void update();
    /// \brief Update previously packed rectangles, optionally shrinking the container
    /// \param shrink if true the container will shrink to the smallest possible dimensions
    void update(bool shrink);
    /// \brief clear packed items and container
    void clear();
    
private:
    // container to pack into
    std::unique_ptr<ShelfPack> sprite = nullptr;
    ofRectangle* container;
    // packed rectangle refs
    vector<ofRectangle*> rectangles;
};
