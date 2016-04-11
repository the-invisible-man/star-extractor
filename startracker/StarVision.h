//
//  StarVision.cpp
//  startracker
//
//  Created by Carlos on 4/10/16.
//  Copyright © 2016 Carlos Granados. All rights reserved.
//

#ifndef STARVISION
#define STARVISION

#include "header.h"

using namespace std;
using namespace cv;

namespace strtckr{
    
    class StarVision {
    
    public:
        StarVision();
        StarVision * loadFile(string FileLocation);
        std::vector<StarTriad> getTriads();

    private:
        Mat currentImage;
        string FileLocation;
        vector<cv::KeyPoint> findStars();
        SimpleBlobDetector::Params params;
        vector<StarTriad> buildTriads(vector<KeyPoint> keypoints);
    };
}

#endif