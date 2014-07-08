//
//  LevelDataSystem.h
//  sg
//
//  Created by Elvis on 3/26/14.
//
//

#ifndef __sg__LevelDataSystem__
#define __sg__LevelDataSystem__

#include "genius-x.h"
#include "ui/UIWidget.h"
#include "../Coms/LevelDataCom.h"

/**
 * 产生资源
 */
class LevelDataSystem : public GX::System
{
public:
    LevelDataSystem();
    
protected:
    virtual System* cloneEmpty() const;
    
    virtual void onAttached() override;
    virtual void update(float dt) override;
    
private:
    LevelDataCom* _levelData;
    
    //在每个阶段，按顺序平均出怪，然后移除数据
    PhaseData _currentPhaseData;    //当前阶段
    float _currentPhaseTime;        //
    float _currentPhaseInterval;    //当前阶段出怪频率
    int _currentCount;
    float _totalTime;
    bool _isOver;
};


#endif /* defined(__sg__LevelDataSystem__) */
