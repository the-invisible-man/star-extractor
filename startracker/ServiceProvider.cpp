//
//  ServiceProvider.cpp
//  startracker
//
//  Created by Carlos on 4/11/16.
//  Copyright © 2016 Carlos Granados. All rights reserved.
//

#include "ServiceProvider.hpp"

using namespace strtckr;

CombinationsGenerator* ServiceProvider::makeCombinationsGenerator(){
    if(!ServiceProvider::combinationsGeneratorObj){
        ServiceProvider::combinationsGeneratorObj = new CombinationsGenerator();
    }
    return ServiceProvider::combinationsGeneratorObj;
}

StarVision* ServiceProvider::makeStarVision(){
    if(!ServiceProvider::starVisionObj){
        ServiceProvider::starVisionObj = new StarVision();
    }
    return ServiceProvider::starVisionObj;
}