//
//  HealthSystem.h
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#ifndef __sg__HealthSystem__
#define __sg__HealthSystem__

#include "genius-x.h"
#include "ui/UIWidget.h"
#include "../Coms/HealthCom.h"

/**
 * 添加和更新血条
 * 在死亡的时候触发死亡时间（其他组件可能播放死亡特效）
 */
class HealthSystem : public GX::System
{
public:
    HealthSystem();
    
protected:
    virtual System* cloneEmpty() const;
    
    virtual void onAttached() override;
    virtual void update(float dt) override;
    
private:
    cocos2d::ProgressTimer* _timer;
    HealthCom* _health;
    bool _dead;
};

#endif /* defined(__sg__HealthSystem__) */
