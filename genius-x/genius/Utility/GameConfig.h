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

#ifndef __GX__GameConfig__
#define __GX__GameConfig__

#include "../GXMacros.h"

NS_GX_BEGIN

USING_NS_CC;

/**
 * 运行时所有的配置信息都可以从这里获取
 * 
 * 1,游戏全局配置(如网络地址)
 * 2,玩家个人信息(如背包大小)
 *
 * 首先读配置文件:config.json
 * 登录时后端接口覆盖
 */
class GameConfig
{
public:
    static GameConfig *getInstance();
	static void destroyInstance();
    
	void setConfig(const std::string& key,rapidjson::Value&);
    const rapidjson::Value& getConfig(const std::string& key);
    
private:
    GameConfig();
	~GameConfig();
    
    void loadLocalConfigData();
    
    rapidjson::Document _data;
};

NS_GX_END

#endif /* defined(__GX__GameConfig__) */
