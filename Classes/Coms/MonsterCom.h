//
//  MonsterCom.h
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#ifndef __sg__MonsterCom__
#define __sg__MonsterCom__

#include "genius-x.h"
#include "LevelDataCom.h"

enum class MonsterType
{
    Monster,
    Coin
};

class MonsterCom :public GX::Com
{
public:
    static std::string _TYPE;
    MonsterCom();
    
    MonsterData data;
    MonsterType type;
protected:
    virtual Com* cloneEmpty() const override;
};

#endif /* defined(__sg__MonsterCom__) */
