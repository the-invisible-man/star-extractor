//
//  Permutator.cpp
//  startracker
//
//  Created by Carlos on 4/10/16.
//  Copyright © 2016 Carlos Granados. All rights reserved.
//

#include "header.h"

using namespace strtckr;

std::vector<std::vector<int>> CombinationsGenerator::generate(int n, int r){
    std::vector<int> current;
    std::vector<std::vector<int>> output;
    
    std::vector<bool> v(n);
    std::fill(v.begin() + n - r, v.end(), true);
    
    do{
        for(int i = 0; i < n; ++i){
            if(v[i]){
                current.push_back(i+1);
            }
        }
        output.push_back(current);
    }while(std::next_permutation(v.begin(), v.end()));
    
    return output;
}