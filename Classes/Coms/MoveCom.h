//
//  MoveCom.h
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#ifndef __sg__MoveCom__
#define __sg__MoveCom__

#include "genius-x.h"

/** 移动到指定的地方并删除元素 */
class MoveCom :public GX::Com
{
public:
    static std::string _TYPE;
    MoveCom();
    
    cocos2d::Point to;
    float speed;
    
protected:
    virtual Com* cloneEmpty() const override;
};

#endif /* defined(__sg__MoveCom__) */
