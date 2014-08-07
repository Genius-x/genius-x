/****************************************************************************
 Copyright (c) 2014 Elvis Qin
 Copyright (c) 2014 Soulgame Inc.
 
 http://www.genius-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __GX__GameSystem__
#define __GX__GameSystem__

#include "../GXMacros.h"
#include "FTUE.h"
#include "Notification.h"
#include "../ECS/ECSManager.h"

NS_GX_BEGIN


/**
 * 类似于Application的设计，有Current的概念，全局只有一个实例，它是项目在GameSystem上面的自定义，项目应该在初始化的时候指定
 * 
 * 游戏系统对外全部展现为全局方法，例如GX::showFTUE();
 */
class GameSystem:public cocos2d::Ref,public NotificationDelegate,public FTUEUIDalegate
{
public:
    GameSystem();
    virtual ~GameSystem();
    static GameSystem* getInstance();
    
    inline GX::ECSManager* getECS(){return _ecs;}
    
    virtual void init();
    void update(float dt);
    
    //FTUE
    virtual void saveFTUEToServer(FTUEData* data){};
    virtual bool willDoFTUE(FTUEData* data){return true;}
    virtual void parserFTUEData(FTUEData*){};
    
    //断言失败
    virtual void assertionFailed(std::string& expr,std::string& function,std::string& file,long line){};
    
    virtual bool showFTUEUI(FTUEData* data){return false;}
    
protected:
    static GameSystem * sm_pSharedGameSystem;
    
    bool _haveInit;
    GX::ECSManager* _ecs;
};

NS_GX_END
#endif /* defined(__GX__GameSystem__) */
