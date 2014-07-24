//
//  GunSystem.h
//  sg
//
//  Created by Elvis on 3/27/14.
//
//

#ifndef __sg__GunSystem__
#define __sg__GunSystem__

#include "genius-x.h"
#include "ui/UIWidget.h"
#include "../Coms/GunCom.h"

/**
 * 根据场上的情况发射子弹
 * 选择最近的目标发射
 */
class GunSystem : public GX::System
{
public:
    GunSystem();
    
protected:
    virtual System* cloneEmpty() const;
    
    virtual void onAttached() override;
    virtual void update(float dt) override;
    
private:
    GunCom* _gun;
    float _currentTime;
};

#endif /* defined(__sg__GunSystem__) */
