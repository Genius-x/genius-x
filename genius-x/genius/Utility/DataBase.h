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

#ifndef __GX__DataBase__
#define __GX__DataBase__

#include "../GXMacros.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
#include <sqlite3.h>
#else
#include "sqlite3/include/sqlite3.h"
#endif

NS_GX_BEGIN

USING_NS_CC;

class DataBase:public cocos2d::Ref
{
public:
    static DataBase *getInstance();
	static void destroyInstance();
    int openDataScoure();
    
    /**
     * 执行一个SQL语句
     */
    void executeSql(const std::string& sql);
    
    /**
     * 从表查东西 返回int型数据
     */
    int selectDataWithInteger(const std::string& sql);
    
    /**
     * 从表查东西 返回数组
     */
    Value selectDataWithArray(const std::string& sql);
    
    /**
     * 从表查东西 返回字符串
     */
    std::string selectDataWithString(const std::string& sql);
    
private:
    DataBase();
    ~DataBase();
    
    inline void checkOpenDatabase(){
        if (!_opended) {
            openDataScoure();
            _opended=true;
        }
    }
    
    sqlite3* _db;
    bool _opended;
};

NS_GX_END

#endif /* defined(__GX__DataBase__) */
