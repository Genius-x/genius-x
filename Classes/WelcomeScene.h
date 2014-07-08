//
//  WelcomeScene.h
//  sg
//
//  Created by Elvis on 3/24/14.
//
//

#ifndef __sg__WelcomeScene__
#define __sg__WelcomeScene__

#include <iostream>
#include "genius-x.h"

USING_NS_CC;

class WelcomeScene : public LayerColor {
public:
    ~WelcomeScene();
    
    static Scene* scene();
    static WelcomeScene* create();
    
private:
    GX::Entity* _welcomeEntity;
};

#endif /* defined(__sg__WelcomeScene__) */
