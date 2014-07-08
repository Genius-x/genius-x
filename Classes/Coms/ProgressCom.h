//
//  ProgressCom.h
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#ifndef __sg__ProgressCom__
#define __sg__ProgressCom__

/**
 * 计时，计算游戏结束，进度现实，暂停，UI
 */
#include "genius-x.h"

class ProgressCom :public GX::Com
{
public:
    static std::string _TYPE;
    ProgressCom();
    
    float durence;
    float currentProgress;
    bool paused;
    
protected:
    virtual void initWithMap(rapidjson::Value&) override;
    virtual Com* cloneEmpty() const override;
};

#endif /* defined(__sg__ProgressCom__) */
