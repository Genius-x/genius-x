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

#include "DataBase.h"
#include "GameConfig.h"
USING_NS_GX;

static DataBase* _databaseInstance=nullptr;

DataBase::DataBase()
:_db(nullptr)
,_opended(false)
{
    
}

DataBase::~DataBase()
{
    
}

DataBase* DataBase::getInstance()
{
    if(_databaseInstance == nullptr) {
        _databaseInstance = new DataBase();
    }
    
    return _databaseInstance;
}

void DataBase::destroyInstance()
{
    if (_databaseInstance!=nullptr) {
        delete _databaseInstance;
    }
    
    _databaseInstance=nullptr;
}

int loadDataWithInteger( void * para, int n_column, char ** column_value, char ** column_name )
{
    int *exp= (int *)para;
    
    if(n_column!=0){
        *exp=CCString::createWithFormat("%s",column_value[0])->intValue();
    }
    
    return 0;
}

int executeSqlNoReturn(void * para, int n_column, char ** column_value, char ** column_name )
{
    return 0;
}


void DataBase::executeSql(const std::string& sql)
{
    checkOpenDatabase();
    
    char * errMsg = NULL;
    
    int result = sqlite3_exec(_db, sql.c_str(), loadDataWithInteger, nullptr, &errMsg);
    if(result != SQLITE_OK || errMsg != NULL)
	{
		CCLOG( "[sqlite]%d, %s" , result, errMsg );
		sqlite3_free(errMsg);
    }
}


int DataBase::selectDataWithInteger(const std::string& sql)
{
    checkOpenDatabase();
    
    char * errMsg = NULL;
    int data=0;
    
    int result = sqlite3_exec(_db, sql.c_str(), loadDataWithInteger, &data, &errMsg);
    if(result != SQLITE_OK || errMsg != NULL)
	{
		CCLOG( "[sqlite]%d, %s" , result, errMsg );
		sqlite3_free(errMsg);
    }
    
    return data;
}

int loadDataWithArray( void * para, int n_column, char ** column_value, char ** column_name )
{
    std::vector<Value>*array= static_cast<std::vector<Value>*>(para);
    
	if(n_column==1){
		for(int i=0;i<n_column;i++){
            Value v(column_value[i]);
            array->push_back(v);
		}
	}
	else if(n_column > 1){
        std::vector<Value> colsValue;
		for(int i=0;i<n_column;i++){
            Value v(column_value[i]);
            colsValue.push_back(v);
		}
        
        array->push_back(Value(colsValue));
	}
    
    return 0;
}

Value DataBase::selectDataWithArray(const std::string& sql)
{
    checkOpenDatabase();
    
    std::vector<Value> data;
    
    char * errMsg = NULL;
	int result = sqlite3_exec(_db, sql.c_str() , loadDataWithArray, &data, &errMsg );
	if(result != SQLITE_OK || errMsg != NULL)
	{
		CCLOG( "[sqlite]%d, %s" , result, errMsg );
		sqlite3_free(errMsg);
	}
    
    return Value(data);
}

int loadDataWithString(void* para, int n_column, char** column_value, char ** column_name )
{
    Value* str= (Value*)para;
    std::string result=column_value[0];
    *str=result.c_str();
    return 0;
}

std::string DataBase::selectDataWithString(const std::string& sql)
{
    checkOpenDatabase();
    
    Value str;

    char * errMsg = NULL;
	int result = sqlite3_exec(_db,sql.c_str(),loadDataWithString,&str,&errMsg);
	if(result != SQLITE_OK || errMsg != NULL)
	{
		CCLOG( "[sqlite]%d, %s" , result, errMsg );
		sqlite3_free(errMsg);
	}
    
    return str.asString();
}

int DataBase::openDataScoure()
{
    std::string filename=GameConfig::getInstance()->getConfig("dbname").GetString();
    
    int result = SQLITE_OK;
    
	if(!_db)
	{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
        
#ifdef WOC_ENABLE_REMOTE_DB
        result = sqlite3_open((CCFileUtils::sharedFileUtils()->getWritablePath()+"woc.db").c_str(), &_db);
        CCLOG((FileUtils::sharedFileUtils()->getWritablePath()+"woc.db").c_str());
#else
		result = sqlite3_open(FileUtils::getInstance()->fullPathForFilename(filename).c_str(), &_db);
        CCLOG("%s",FileUtils::getInstance()->fullPathForFilename(filename).c_str());
#endif
        
#else
       	std::string canWriteString=CCFileUtils::sharedFileUtils()->getWritablePath() + "woc.db";
        
        ssize_t len = 0;
        unsigned char *data = CCFileUtils::sharedFileUtils()->getFileData(canWriteString.c_str(),"rw",&len);
        
        CCLOG("[sqlite]canWriteString %s, length %ld",canWriteString.c_str(),len);
        
        if(len==0)
        {
            FILE *file = fopen(canWriteString.c_str(), "wb");
            std::string path = CCFileUtils::sharedFileUtils()->fullPathForFilename("woc.db");
            
            ssize_t filelen = 0;
            unsigned char *filedata = CCFileUtils::sharedFileUtils()->getFileData(path.c_str(),"r",&filelen);
            
            CCLOG("[sqlite]buffer size %ld",filelen);
            
            fwrite(filedata,sizeof(char),filelen,file);
            fclose(file);
        }
        
        result = sqlite3_open(canWriteString.c_str(), &_db);
        CC_SAFE_DELETE_ARRAY(data);
#endif
	}
    
    if( result != SQLITE_OK )
    {
        CCLOG( "[sqlite]open fail %d" , result);
    }
    
	return result;
}

