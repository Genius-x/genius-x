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

#include "GameConfig.h"

USING_NS_GX;

static GameConfig* _configInstance=nullptr;

GameConfig::GameConfig()
{
    
}

GameConfig::~GameConfig()
{
    
}

GameConfig* GameConfig::getInstance()
{
    if (_configInstance==nullptr) {
        _configInstance=new GameConfig();
        _configInstance->loadLocalConfigData();
    }
    
    return _configInstance;
}
void GameConfig::destroyInstance()
{
    if (_configInstance!=nullptr) {
        delete _configInstance;
    }
    
    _configInstance=nullptr;
}

void GameConfig::loadLocalConfigData()
{
    std::string jsonpath = cocos2d::FileUtils::getInstance()->fullPathForFilename("res/ecs/config.json");
    std::string strData=cocos2d::FileUtils::getInstance()->getStringFromFile(jsonpath);
    
    _data.Parse<0>(strData.c_str());
    if(!_data.HasParseError()) {
        
    }
}

void GameConfig::setConfig(const std::string& key,rapidjson::Value& newValue)
{
    if (_data.HasMember(key.c_str())) {
        _data.RemoveMember(key.c_str());
    }
    
    _data[key.c_str()]=newValue;
}

const rapidjson::Value& GameConfig::getConfig(const std::string& key)
{
    return _data[key.c_str()];
}