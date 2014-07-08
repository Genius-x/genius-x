//
//  LevelScene.h
//  sg
//
//  Created by Elvis on 3/24/14.
//
//

#ifndef __sg__LevelScene__
#define __sg__LevelScene__

#include "cocos2d.h"
#include "genius-x.h"

USING_NS_CC;

class LevelScene : public LayerColor {
public:
    static Scene* scene();
    ~LevelScene();
    
private:
    GX::Entity* _entity;
};
#endif /* defined(__sg__LevelScene__) */
