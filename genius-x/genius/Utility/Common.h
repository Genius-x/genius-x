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

#ifndef __GX__Common__
#define __GX__Common__

#include "../GXMacros.h"

NS_GX_BEGIN
USING_NS_CC;

struct Time4f
{
    Time4f()
    :d(0)
    ,h(0)
    ,m(0)
    ,s(0)
    {};
    
    int d;
    int h;
    int m;
    int s;
};


Color4B Color4BFromString(const std::string& str);
Color3B Color3BFromString(const std::string& str);
Time4f Time4fFromSeconds(int seconds);

std::string convertSecondsToHours(int seconds);

std::string convertTimeToString(time_t t);
time_t convertStringToTime(const std::string&);

NS_GX_END

#endif /* defined(__GX__Common__) */
