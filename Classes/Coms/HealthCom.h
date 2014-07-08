//
//  HealthCom.h
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#ifndef __sg__HealthCom__
#define __sg__HealthCom__

#include "genius-x.h"

class HealthCom :public GX::Com
{
public:
    static std::string _TYPE;
    HealthCom();
    
    static HealthCom* create(const std::string& json);
    
    int hp;
    int total;
    
protected:
    virtual void initWithMap(rapidjson::Value&) override;
    virtual Com* cloneEmpty() const override;
};

#endif /* defined(__sg__HealthCom__) */
