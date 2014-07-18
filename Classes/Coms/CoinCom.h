//
//  CoinCom.h
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#ifndef __sg__CoinCom__
#define __sg__CoinCom__

/** 产生金币 */
#include "genius-x.h"

class CoinCom :public GX::Com
{
public:
    static std::string _TYPE;
    CoinCom();
    
    int coin;        //每次产生多少金币
    int coin_rate;   //隔多久产生一次
    
protected:
    virtual Com* cloneEmpty() const override;
};

#endif /* defined(__sg__CoinCom__) */
