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

#include "Localization.h"
#include "../Utility/DataBase.h"
#include "json/document.h"

USING_NS_GX;

static Localization* _localInstance=nullptr;

Localization* Localization::getInstance()
{
    if (_localInstance==nullptr) {
        _localInstance=new Localization();
        _localInstance->loadStringsFrom(Application::getInstance()->getCurrentLanguageCode());
    }
    
    return _localInstance;
}

void Localization::destroyInstance()
{
    delete _localInstance;
    _localInstance=nullptr;
}

std::string Localization::getStr(const std::string& key)
{
    if (_dataLua.find(key.c_str())!=_dataLua.end()) {
        return _dataLua.at(key).asString();
    }
    //else if (_data.HasMember(key.c_str())) {
    //    return _data[key.c_str()].GetString();
    //}
    
    return key;
}

Localization::Localization()
{

}

Localization::~Localization()
{
    
}

void Localization::updateFromDataBase()
{
    
}

void Localization::setData(const cocos2d::ValueMap& data)
{
    _dataLua=data;
}

void Localization::resetData()
{
    
}


void Localization::loadStringsFrom(const std::string& lan)
{
    std::string filePath = "localizable";
    std::string strData="";
    
    if (!lan.empty()) {
        const std::string filename=StringUtils::format("%s.%s.json",filePath.c_str(),lan.c_str());
        if (FileUtils::getInstance()->isFileExist(filename)){
            std::string jsonpath = cocos2d::FileUtils::getInstance()->fullPathForFilename(filename);
            strData=cocos2d::FileUtils::getInstance()->getStringFromFile(jsonpath);
        }
    }
    
    if (strData.empty()) {
        const std::string filename=StringUtils::format("%s.json",filePath.c_str());
        if (FileUtils::getInstance()->isFileExist(filename)){
            std::string jsonpath = cocos2d::FileUtils::getInstance()->fullPathForFilename(filename);
            strData=cocos2d::FileUtils::getInstance()->getStringFromFile(jsonpath);
        }
    }
    
    if (!strData.empty()) {
        _data.Parse<0>(strData.c_str());
        if(!_data.HasParseError()) {
            
        }
    }
}

//将多个字符串按，拼在一起
std::string Localization::getMultiStr(int n,...)
{
    std::string str;
        
    va_list arguments;
    const char* type1=NULL;
    va_start(arguments, n);
    for (int i=0; i<n; i++) {
        type1=va_arg(arguments, const char*);
        if (i==0) {
            str=StringUtils::format("%s",type1);
        }
        else {
            str=StringUtils::format("%s,%s",str.c_str(),type1);
        }
    }
    va_end(arguments);
    
    return str;
}

