//
//  ProgressSystem.h
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#ifndef __sg__ProgressSystem__
#define __sg__ProgressSystem__

#include "genius-x.h"
#include "ui/UIWidget.h"
#include "../Coms/ProgressCom.h"

class ProgressSystem : public GX::System
{
public:
    ProgressSystem();
    
protected:
    virtual System* cloneEmpty() const;
    
    virtual void onInit() override;
    virtual void onAttached() override;
    virtual void onDeattached() override;
    
    virtual void update(float dt) override;
    virtual void onComsChanged() override;
    
    void onBegin(cocos2d::EventCustom*);
    
private:
    ProgressCom* _progress;
    cocos2d::ProgressTimer* _progressTimer;
    cocos2d::Label* _labelTimer;
    bool _begin;
};

#endif /* defined(__sg__ProgressSystem__) */
