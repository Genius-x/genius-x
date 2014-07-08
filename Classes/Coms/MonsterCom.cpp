//
//  MonsterCom.cpp
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#include "MonsterCom.h"

std::string MonsterCom::_TYPE="MonsterCom";
MonsterCom::MonsterCom()
:GX::Com(_TYPE)
,type(MonsterType::Monster)
{
    
}

GX::Com* MonsterCom::cloneEmpty() const
{
    return new  MonsterCom();
}
