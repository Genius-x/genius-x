//
//  ShipCom.h
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#ifndef __sg__ShipCom__
#define __sg__ShipCom__

#include "genius-x.h"

class ShipCom :public GX::Com
{
public:
    static std::string _TYPE;
    ShipCom();
    
protected:
    virtual Com* cloneEmpty() const override;
};

#endif /* defined(__sg__ShipCom__) */
