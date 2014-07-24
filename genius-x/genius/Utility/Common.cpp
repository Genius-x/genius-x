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

#include "Common.h"
#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
// #include "strptime.c"
// 
// char *strptime(const char * __restrict, const char * __restrict, struct tm * __restrict);

#endif

using namespace std;

NS_GX_BEGIN

typedef std::vector<std::string> strArray;

// string toolkit
static inline void split(const std::string& src, const std::string& token, strArray& vect)
{
    size_t nend = 0;
    size_t nbegin = 0;
    size_t tokenSize = token.size();
    while(nend != std::string::npos)
    {
        nend = src.find(token, nbegin);
        if(nend == std::string::npos)
            vect.push_back(src.substr(nbegin, src.length()-nbegin));
        else
            vect.push_back(src.substr(nbegin, nend-nbegin));
        nbegin = nend + tokenSize;
    }
}

// first, judge whether the form of the string like this: {x,y}
// if the form is right,the string will be split into the parameter strs;
// or the parameter strs will be empty.
// if the form is right return true,else return false.
static bool splitWithForm(const std::string& content, strArray& strs)
{
    bool bRet = false;
    
    do
    {
        CC_BREAK_IF(content.empty());
        
        size_t nPosLeft  = content.find('{');
        size_t nPosRight = content.find('}');
        
        // don't have '{' and '}'
        CC_BREAK_IF(nPosLeft == std::string::npos || nPosRight == std::string::npos);
        // '}' is before '{'
        CC_BREAK_IF(nPosLeft > nPosRight);
        
        const std::string pointStr = content.substr(nPosLeft + 1, nPosRight - nPosLeft - 1);
        // nothing between '{' and '}'
        CC_BREAK_IF(pointStr.length() == 0);
        
        size_t nPos1 = pointStr.find('{');
        size_t nPos2 = pointStr.find('}');
        // contain '{' or '}'
        CC_BREAK_IF(nPos1 != std::string::npos || nPos2 != std::string::npos);
        
        split(pointStr, ",", strs);
        if (strs.size() < 2 || strs[0].length() == 0 || strs[1].length() == 0)
        {
            strs.clear();
            break;
        }
        
        bRet = true;
    } while (0);
    
    return bRet;
}

Time4f Time4fFromSeconds(int seconds)
{
    Time4f t;
    
    t.d=seconds/(60*60*24);
    t.h=seconds%(60*60*24)/(60*60);
    t.m=seconds%(60*60*24)%(60*60)/60;
    t.s=seconds%(60*60*24)%(60*60)%60;

    return t;
}

Color3B Color3BFromString(const std::string& str)
{
    cocos2d::Color3B ret = cocos2d::Color3B::BLACK;
    
    do
    {
        strArray strs;
        CC_BREAK_IF(!splitWithForm(str, strs));
        
        GLubyte r = (GLubyte) atoi(strs[0].c_str());
        GLubyte g = (GLubyte) atoi(strs[1].c_str());
        GLubyte b = (GLubyte) atoi(strs[2].c_str());
        ret = cocos2d::Color3B(r, g,b);
    } while (0);
    
    return ret;
}

Color4B Color4BFromString(const std::string& str)
{
    cocos2d::Color4B ret = cocos2d::Color4B::BLACK;
    
    do
    {
        strArray strs;
        CC_BREAK_IF(!splitWithForm(str, strs));
        
        GLubyte r = (GLubyte) atoi(strs[0].c_str());
        GLubyte g = (GLubyte) atoi(strs[1].c_str());
        GLubyte b = (GLubyte) atoi(strs[2].c_str());
        GLubyte a = (GLubyte) atoi(strs[3].c_str());
        ret = cocos2d::Color4B(r,g,b,a);
    } while (0);
    
    return ret;
}

std::string convertTimeToString(time_t t)
{
    struct tm *time_str=gmtime(&t);
    char buf[20];
    
    strftime(buf, 20, "%a, %d.%m.%Y %H:%M:%S", time_str);
    
    return std::string(buf);
}

time_t convertStringToTime(const std::string& str)
{
    struct tm time_str;
//     strptime(str.c_str(), "%a, %d.%m.%Y %H:%M:%S", &time_str);
    return mktime(&time_str);
}

std::string convertSecondsToHours(int seconds)
{
    int d=seconds/(60*60*24);
    int h=seconds%(60*60*24)/(60*60);
    int m=seconds%(60*60*24)%(60*60)/60;
    int s=seconds%(60*60*24)%(60*60)%60;
    
    if (d>0)
        return StringUtils::format("%dd%dh",d,h);
    else if (h>0)
        return StringUtils::format("%dh%dm",h,m);
    else if (m>0)
        return StringUtils::format("%dm%ds",m,s);
    else
        return StringUtils::format("%ds",s);
}

NS_GX_END