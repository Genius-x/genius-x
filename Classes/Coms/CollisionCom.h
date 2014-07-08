//
//  CollisionCom.h
//  sg
//
//  Created by Elvis on 3/26/14.
//
//

#ifndef __sg__CollisionCom__
#define __sg__CollisionCom__

#include "genius-x.h"

class CollisionCom :public GX::Com
{
public:
    static std::string _TYPE;
    CollisionCom();
    
    std::string target;
    
protected:
    virtual Com* cloneEmpty() const override;
};

#endif /* defined(__sg__Collision__) */
