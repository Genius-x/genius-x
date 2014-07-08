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

#ifndef __GX__FTUE__
#define __GX__FTUE__

#include "../GXMacros.h"
#include <functional>
#include <map>

NS_GX_BEGIN

class FTUEData
{
public:
    int ftueId;
    int rootId;            //FTUE分支
    int parentId;          //上一个FTUE，用来计算顺序
    int groupId;           //代表一个分组
    int islocal;           //是否只需要记录在本地
};

//定义每个FTUE的UI
class FTUEUIDalegate
{
public:
    virtual ~FTUEUIDalegate(){};
    
    virtual bool showFTUEUI(FTUEData* data)=0;
};


class FTUEManager
{
public:
    static const int kFTUENone=0;
    static FTUEManager* getInstance();
    
    /** 是否当前需要执行的FTUE,一般用于退出应用程序之后判断是否要跳到某个界面执行该FTUE */
    bool willDoFTUE(int num,...);
    
    bool isDoingFTUE(int ftueId) const;
    bool isDoingFTUE() const;
    
    bool showFTUE(int ftueId,std::function<void(FTUEData*)> callback=nullptr);
    bool showFTUE(std::function<void(FTUEData*)> callback,int num,...);
    
    /* @param needKeepInFTUE 两个FTUE之间有间隔(如动画)需要锁定交互时设置此属性,
     * 判断规则: 1,此属性只会影响canHandle方法的判定
     *          2,m_bInFTUE只在当前没有FTUE时发生作用，即不会对FTUE状态中的任何事情发生影响
     *          3，只有finishFTUE的时候才能设置m_bInFTUE属性，因为该属性就是用来表示一个FTUE之后需要维持一种"假FTUE"的状态
     *          4，处于保持FTUE状态,只有新的FTUE才会改写此状态
     */
    void finishFTUE(int ftueId,bool needKeepInFTUE=false);
    
    //交互控制
    bool canHandle(int num,...);
    
    void setStillInFTUE(bool);
    void setCurrentGroupIndex(int index,int root, bool force=false);

    void talkCompleted();
    void talkStepCompleted(){};
    
    /*注册新用户的时候重置所有FTUE本地数据*/
    void resetAllLocalProgress();
    
    friend class FTUEData;
    
    FTUEData* getFTUEData(int id);
    
private:
    FTUEManager();
    ~FTUEManager();
    
    bool willDoFTUEInside(int ftueId);
    
    //解析FTUE数据
    void parserFTUEData();
    //加载本地的FTUE数据
    void loadLocalFTUEData();
    //void onUpdateFTUECompleted(CCDictionary*);
    
    bool isftueFinished(int ftueId);
    
    std::map<int, FTUEData*>* _FTUEData;
    std::map<int, int> _progress;
    std::map<int, int> _lastProgress;
    FTUEData* _currentData;
    
    bool _stillInFTUE;
    
    std::function<void(FTUEData*)> _callback;
    FTUEUIDalegate* _delegate;
};
        
        
void showFTUE();

NS_GX_END

#endif /* defined(__GX__FTUE__) */
