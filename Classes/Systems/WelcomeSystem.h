//
//  WelcomeSystem.h
//  sg
//
//  Created by Elvis on 3/20/14.
//
//

#ifndef __sg__WelcomeSystem__
#define __sg__WelcomeSystem__

#include "genius-x.h"
#include "ui/UIWidget.h"

/**
 * 主界面，主要功能：Play和Shop按钮
 */
class WelcomeSystem : public GX::System
{
public:
    WelcomeSystem();
    
protected:
    virtual System* cloneEmpty() const;
    
    virtual void onInit() override;
    virtual void onAttached() override;
    virtual void onDeattached() override;
    
    virtual void update(float dt) override;
    virtual void onComsChanged() override;
    
    void onPlayClicked(cocos2d::Ref *pSender, cocos2d::ui::TouchEventType type);
    void onShopClicked(cocos2d::Ref *pSender, cocos2d::ui::TouchEventType type);
};

#endif /* defined(__sg__WelcomeSystem__) */
