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

#include "HttpBase.h"

HttpBase::HttpBase()
{
    
}

HttpBase::~HttpBase()
{
    
}

void HttpBase::setTGId(int tgId)
{
    
}

void HttpBase::setToken(const std::string& token)
{
    
}

void HttpBase::setUserId(const int userId)
{
    
}

void HttpBase::setAddressType(const std::string& type)
{
    
}

void HttpBase::init()
{
    
}

std::string HttpBase::MakeCMDRequestURL(const int nCMD,const std::map<std::string,std::string>&)
{
    return nullptr;
}

void HttpBase::MakeGetRequest(const std::string& url, std::function<void(const rapidjson::Value&)> callback)
{

}

void HttpBase::MakePostRequest(const std::string& url, cocos2d::Data* pData, std::function<void(const rapidjson::Value&)> callback)
{
    
}

void HttpBase::registerAddress(int nCMD,const std::string& controller,const std::string& action,const std::string& path)
{
    
}

void HttpBase::onHttpResponse(cocos2d::network::HttpClient *pSender, cocos2d::network::HttpResponse *response)
{
    
}
