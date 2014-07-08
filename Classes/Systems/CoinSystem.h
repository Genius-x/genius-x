//
//  CoinSystem.h
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#ifndef __sg__CoinSystem__
#define __sg__CoinSystem__

#include "genius-x.h"
#include "ui/UIWidget.h"
#include "../Coms/CoinCom.h"

/**
 * 产生资源
 */
class CoinSystem : public GX::System
{
public:
    CoinSystem();
    
protected:
    virtual System* cloneEmpty() const;
    
    virtual void onAttached() override;
    virtual void update(float dt) override;
    
private:
    CoinCom* _coin;
    float _currentTime;
};

#endif /* defined(__sg__CoinSystem__) */
