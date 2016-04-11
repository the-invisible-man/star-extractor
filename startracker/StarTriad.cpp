//
//  StarPattern.cpp
//  startracker
//
//  Created by Carlos on 4/4/16.
//  Copyright © 2016 Carlos Granados. All rights reserved.
//

#include "header.h"

#ifndef STARTRIAD
#define STARTRIAD

namespace strtckr {
    typedef struct StarTriad {
    
        cv::Point a;
        cv::Point b;
        cv::Point c;
    
    }StarTriad;
}

#endif