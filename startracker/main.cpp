//
//  main.cpp
//  startracker
//
//  Created by Carlos on 4/2/16.
//  Copyright © 2016 Carlos Granados. All rights reserved.
//

#include "header.h"

int main() {
    
    using namespace strtckr;
    
    StarVision * visionProcessor = ServiceProvider::makeStarVision();
    vector <StarTriad> triads;
    
    // Set location of image
    triads = visionProcessor->loadFile("/Users/cgranados/Code/startracker/media/summertriangle.jpg")->getTriads();
    
    cout << "Found " << triads.size() << " triads in current view";
    
    return 0;
}