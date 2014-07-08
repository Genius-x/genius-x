//
//  LevelCom.h
//  sg
//
//  Created by Elvis on 3/24/14.
//
//

#ifndef __sg__LevelCom__
#define __sg__LevelCom__

#include "genius-x.h"

USING_NS_CC;

struct LevelData{
    std::string image;
    std::string title;
    std::string description;
    std::string entity;
};

class LevelCom :public GX::Com
{
public:
    static std::string _TYPE;
    LevelCom();
    
    Size viewSize;
    Size cellSize;
    Point position;
    Point anchorPoint;
    Point anchor;
    
    std::vector<LevelData> data;
    
protected:
    virtual void initWithMap(rapidjson::Value&) override;
    virtual Com* cloneEmpty() const override;
};

#endif /* defined(__sg__LevelCom__) */
