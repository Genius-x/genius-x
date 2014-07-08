//
//  PlayerCom.h
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#ifndef __sg__PlayerCom__
#define __sg__PlayerCom__

#include "genius-x.h"

/**
 * 记录玩家的数值信息
 * 使用Entity使数据可配置，方便调试
 * 真实运行则根据玩家数据动态构造
 */
class PlayerCom :public GX::Com
{
public:
    static std::string _TYPE;
    PlayerCom();
    
    int coins;
    int lockLevel;
    int winCount;
    int lostCount;
    
    //当前选择的关卡，真实中是一个关卡Id
    std::string currentLevel;
    
    void saveData();
    
protected:
    virtual void initWithMap(rapidjson::Value&) override;
    virtual Com* cloneEmpty() const override;
};


#endif /* defined(__sg__PlayerCom__) */
