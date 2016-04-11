//
//  StarVision.cpp
//  startracker
//
//  Created by Carlos on 4/10/16.
//  Copyright © 2016 Carlos Granados. All rights reserved.
//

#include "StarVision.h"

using namespace strtckr;
using namespace std;
using namespace cv;

StarVision* StarVision::loadFile(std::string FileLocation){
    this->FileLocation = FileLocation;
    this->currentImage = imgread(this->FileLocation);
    
    return this;
}

vector <StarTriad> StarVision::getTriads(){
    vector<KeyPoint> stars = this->findStars();
    return this->buildTriads(stars);
}

vector <StarTriad>StarVision::buildTriads(std::vector<KeyPoint> keypoints){
    // Here well get all possible unordered permutations
    int totalPoints = keypoints.size();
    vector <StarTriad> output;
    std::vector<std::vector<int>> triads = ServiceProvider::makeCombinationsGenerator()->generate(totalPoints, 3);
    
    for(int i = 0; i < triads.size(); i++){
        StarTriad triad;
        triad.a = triads[i][0];
        triad.b = triads[i][1];
        triad.c = triads[i][2];
        output.push_back(triad);
    }
    
    return output;
}

vector<cv::KeyPoint> StarVision::findStars(){
    
    // Some stuff we need
    vector<StarTriad> triadsFound;
    Mat img_gray;
    Mat img_keypoints;
    SimpleBlobDetector::Params params;
    vector<cv::KeyPoint> keypoints;
    vector<strtckr::StarTriad> triads;
    
    // Necesasry parameters for blob analisys
    params.filterByArea = true;
    params.minArea = 0.01;
    params.maxArea = 1000;
    params.filterByColor = true;
    params.blobColor = 255;
    
    // Instantiate detector
    Ptr<cv::SimpleBlobDetector> detector = cv::SimpleBlobDetector::create(params);
    
    cvtColor(this->currentImage, img_gray, CV_RGB2GRAY);
    
    // Fix matrix size and type to allocate final image
    Mat img_bw(img_gray.size(), img_gray.type());
    
    // Apply threshhold to convert into binary image and save to new matrix
    threshold(img_gray, img_bw, 100, 255, THRESH_BINARY);
    
    // Extract cordinates of blobs at their centroids, save to keypoints variable.
    detector->detect(img_bw, keypoints);
    
    return keypoints;
}