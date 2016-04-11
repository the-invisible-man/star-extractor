//
//  ServiceProvider.hpp
//  startracker
//
//  Created by Carlos on 4/11/16.
//  Copyright © 2016 Carlos Granados. All rights reserved.
//

#ifndef ServiceProvider_hpp
#define ServiceProvider_hpp

#include "header.h"

namespace strtckr{
    
    class ServiceProvider{
    private:
        static CombinationsGenerator *combinationsGeneratorObj;
        static StarVision *starVisionObj;
    public:
        static CombinationsGenerator* makeCombinationsGenerator();
        static StarVision* makeStarVision();
    };
}

#endif /* ServiceProvider_hpp */
