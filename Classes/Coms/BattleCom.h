//
//  BattleCom.h
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#ifndef __sg__BattleCom__
#define __sg__BattleCom__

#include "genius-x.h"

class BattleCom :public GX::Com
{
public:
    static std::string _TYPE;
    BattleCom();
    
protected:
    virtual void initWithMap(rapidjson::Value&) override;
    virtual Com* cloneEmpty() const override;
};

#endif /* defined(__sg__BattleCom__) */
