//
//  MoveSystem.h
//  sg
//
//  Created by Elvis on 3/26/14.
//
//

#ifndef __sg__MoveSystem__
#define __sg__MoveSystem__

#include "genius-x.h"
#include "ui/UIWidget.h"
#include "../Coms/MoveCom.h"

/**
 * 产生资源
 */
class MoveSystem : public GX::System
{
public:
    MoveSystem();
    
protected:
    virtual System* cloneEmpty() const;
    
    virtual void onAttached() override;
private:
    void onMoveCompleted();
    MoveCom* _move;
};

#endif /* defined(__sg__MoveSystem__) */
