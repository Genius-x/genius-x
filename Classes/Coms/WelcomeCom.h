//
//  WelcomeCom.h
//  sg
//
//  Created by Elvis on 3/20/14.
//
//

#ifndef __sg__WelcomeCom__
#define __sg__WelcomeCom__

#include "genius-x.h"

class WelcomeCom :public GX::Com
{
public:
    static std::string _TYPE;
    WelcomeCom();

protected:
    virtual void initWithMap(rapidjson::Value&) override;
    virtual Com* cloneEmpty() const override;
};


#endif /* defined(__sg__WelcomeCom__) */
