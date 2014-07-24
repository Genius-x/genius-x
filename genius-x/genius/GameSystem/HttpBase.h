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

#ifndef __GX__HttpBase__
#define __GX__HttpBase__

#include "../GXMacros.h"
#include "network/HttpClient.h"

USING_NS_CC;
using namespace network;

/**
 * 网络接口基类
 * 1,根据配置选择服务器地址
 * 2,
 */
class HttpBase : public Ref
{
public:
    struct Address
    {
        std::string strController;
        std::string strAction;
        std::string strPath;
    };
    
    void setTGId(int tgId);
    void setToken(const std::string& token);
    void setUserId(const int userId);
    void setAddressType(const std::string& type);
  
protected:
    virtual void init();
    
    //常用变量
	int          _tgID;
	int          _userId;
    std::string  _token;
    
    std::string MakeCMDRequestURL(const int nCMD,const std::map<std::string,std::string>&);
    
	void MakeGetRequest(const std::string& url, std::function<void(const rapidjson::Value&)> callback);
	void MakePostRequest(const std::string& url, cocos2d::Data* pData, std::function<void(const rapidjson::Value&)> callback);
    
private:
    void registerAddress(int nCMD,const std::string& controller,const std::string& action,const std::string& path);
    
    
    //用来保存每一个请求的request
	int		    domainId;
    
	void onHttpResponse(HttpClient *pSender,HttpResponse *response);
    
    HttpBase();
    virtual ~HttpBase();
    
    //存储所有的接口地址
    std::unordered_map<int,Address> _address;
};


#endif /* defined(__GX__HttpBase__) */
