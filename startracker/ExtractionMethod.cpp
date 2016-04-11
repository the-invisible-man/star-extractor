//
//  ExtractionMethods.cpp
//  startracker
//
//  Created by Carlos on 4/4/16.
//  Copyright © 2016 Carlos Granados. All rights reserved.
//

#include "ExtractionMethod.hpp"

class ExtractionMethod {

protected:
    strtckr::StarTriad triad;
    
public:
    ExtractionMethod* setTriad(strtckr::StarTriad triad) {
        this->triad = triad;
        return this;
    }
    
    strtckr::StarTriad getTriad() {
        return this->triad;
    }
    
    std::vector<int> extract();
    
    double norm(cv::Point point) {
        return sqrt( (point.x ^ 2) + (point.y ^ 2));
    }
};