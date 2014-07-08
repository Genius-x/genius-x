//
//  GameSystemDelegate.h
//  SG
//
//  Created by Elvis on 14-1-27.
//
//

#ifndef __SG__GameSystemDelegate__
#define __SG__GameSystemDelegate__

#include "genius-x.h"
#include "Coms/PlayerCom.h"

USING_NS_GX;

class GameSystemDelegate : public GameSystem
{
public:
    GameSystemDelegate();
    ~GameSystemDelegate();
    
    bool showFTUEUI(FTUEData* data);
    
    virtual void init() override;
    
private:
    void initPlayerInfo();
    
    Entity* _player;
};

#endif /* defined(__SG__GameSystemDelegate__) */
