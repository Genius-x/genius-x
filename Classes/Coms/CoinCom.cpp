//
//  CoinCom.cpp
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#include "CoinCom.h"

std::string CoinCom::_TYPE="CoinCom";
CoinCom::CoinCom():GX::Com(_TYPE)
{
    
}

GX::Com* CoinCom::cloneEmpty() const
{
    return new CoinCom();
}