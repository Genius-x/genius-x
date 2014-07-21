//
//  lua_geniusx_manual.cpp
//  cocos2d_lua_bindings
//
//  Created by Elvis on 14-5-26.
//
//

#include "lua_geniusx_manual.hpp"
#include "ECS/Com.h"
#include "ECS/System.h"
#include "Resource/Resource.h"

#include "cocos2d.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"
#include "CCLuaValue.h"

USING_NS_GX;
USING_NS_GX;

static int tolua_geniusx_Component_registerScriptHandler(lua_State* tolua_S)
{
    if (NULL == tolua_S)
        return 0;
    
    int argc = 0;
    GX::Com* self = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
	if (!tolua_isusertype(tolua_S,1,"gx.Com",0,&tolua_err)) goto tolua_lerror;
#endif
    
    self = static_cast<GX::Com*>(tolua_tousertype(tolua_S,1,0));
    
#if COCOS2D_DEBUG >= 1
	if (nullptr == self) {
		tolua_error(tolua_S,"invalid 'self' in function 'tolua_geniusx_Component_registerScriptHandler'\n", NULL);
		return 0;
	}
#endif
    
    argc = lua_gettop(tolua_S) - 1;
    
    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err))
        {
            goto tolua_lerror;
        }
#endif
        LUA_FUNCTION handler = (  toluafix_ref_function(tolua_S,2,0));
        self->registerScriptHandler(handler);
        return 0;
    }
    
    CCLOG("'registerScriptHandler' function of Component  has wrong number of arguments: %d, was expecting %d\n", argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'registerScriptHandler'.",&tolua_err);
    return 0;
#endif
    
}

static int tolua_geniusx_Component_unregisterScriptHandler(lua_State* tolua_S)
{
    
    if (NULL == tolua_S)
        return 0;
    
    int argc = 0;
    GX::Com* self = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
	if (!tolua_isusertype(tolua_S,1,"gx.Com",0,&tolua_err)) goto tolua_lerror;
#endif
    
    self = static_cast<GX::Com*>(tolua_tousertype(tolua_S,1,0));
    
#if COCOS2D_DEBUG >= 1
	if (nullptr == self) {
		tolua_error(tolua_S,"invalid 'self' in function 'tolua_geniusx_Component_unregisterScriptHandler'\n", NULL);
		return 0;
	}
#endif
    
    argc = lua_gettop(tolua_S) - 1;
    
    if (0 == argc)
    {
        self->unregisterScriptHandler();
        return 0;
    }
    
    CCLOG("'unregisterScriptHandler' function of Component  has wrong number of arguments: %d, was expecting %d\n", argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'unregisterScriptHandler'.",&tolua_err);
    return 0;
#endif
}

static int tolua_geniusx_System_registerScriptHandler(lua_State* tolua_S)
{
    if (NULL == tolua_S)
        return 0;
    
    int argc = 0;
    System* self = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
	if (!tolua_isusertype(tolua_S,1,"gx.System",0,&tolua_err)) goto tolua_lerror;
#endif
    
    self = static_cast<System*>(tolua_tousertype(tolua_S,1,0));
    
#if COCOS2D_DEBUG >= 1
	if (nullptr == self) {
		tolua_error(tolua_S,"invalid 'self' in function 'tolua_geniusx_System_registerScriptHandler'\n", NULL);
		return 0;
	}
#endif
    
    argc = lua_gettop(tolua_S) - 1;
    
    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err))
        {
            goto tolua_lerror;
        }
#endif
        LUA_FUNCTION handler = (  toluafix_ref_function(tolua_S,2,0));
        self->registerScriptHandler(handler);
        return 0;
    }
    
    CCLOG("'registerScriptHandler' function of System  has wrong number of arguments: %d, was expecting %d\n", argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'registerScriptHandler'.",&tolua_err);
    return 0;
#endif
    
}

static int tolua_geniusx_System_unregisterScriptHandler(lua_State* tolua_S)
{
    
    if (NULL == tolua_S)
        return 0;
    
    int argc = 0;
    System* self = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
	if (!tolua_isusertype(tolua_S,1,"gx.System",0,&tolua_err)) goto tolua_lerror;
#endif
    
    self = static_cast<System*>(tolua_tousertype(tolua_S,1,0));
    
#if COCOS2D_DEBUG >= 1
	if (nullptr == self) {
		tolua_error(tolua_S,"invalid 'self' in function 'tolua_geniusx_System_unregisterScriptHandler'\n", NULL);
		return 0;
	}
#endif
    
    argc = lua_gettop(tolua_S) - 1;
    
    if (0 == argc)
    {
        self->unregisterScriptHandler();
        return 0;
    }
    
    CCLOG("'unregisterScriptEditBoxHandler' function of System  has wrong number of arguments: %d, was expecting %d\n", argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'unregisterScriptHandler'.",&tolua_err);
    return 0;
#endif
}


static int tolua_cocos2d_Resource_updateResourceReferenceAsyncHandler(lua_State* tolua_S)
{
    if (nullptr==tolua_S)
        return 0;
    
    int argc = 0;
    Resource* self =nullptr;
    
#if COCOS2D_DEBUG>=1
    tolua_Error tolua_err;
	if (!tolua_isusertype(tolua_S,1,"gx.Resource",0,&tolua_err)) goto tolua_lerror;
#endif
    
    self=static_cast<Resource*>(tolua_tousertype(tolua_S, 1, 0));
    
#if COCOS2D_DEBUG>=1
    if (nullptr==self) {
        tolua_error(tolua_S,"invalid 'self' in function 'tolua_cocos2d_Resource_updateResourceReferenceAsyncHandler'\n", NULL);
        return 0;
    }
#endif
 
    argc=lua_gettop(tolua_S)-1;
    if (1==argc) {
#if COCOS2D_DEBUG>=1
        if (!toluafix_isfunction(tolua_S, 2, "LUA_FUNCTION", 0, &tolua_err)) {
            goto tolua_lerror;
        }
#endif
        
        LUA_FUNCTION handler=(toluafix_ref_function(tolua_S, 2,0));
        self->updateResourceReferenceAsyncHandler(handler);
        return 0;
    }
    
    CCLOG("'updateResourceReferenceAsync' function of Resource  has wrong number of arguments: %d, was expecting %d\n", argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'updateResourceReferenceAsyncHandler'.",&tolua_err);
    return 0;
#endif

}

static int tolua_cocos2d_Resource_addResourceAsyncHandler(lua_State* tolua_S)
{
    if (nullptr==tolua_S)
        return 0;
    
    int argc = 0;
    bool ok  = true;
    Resource* self =nullptr;
    
#if COCOS2D_DEBUG>=1
    tolua_Error tolua_err;
	if (!tolua_isusertype(tolua_S,1,"gx.Resource",0,&tolua_err));
#endif
    
    self=static_cast<Resource*>(tolua_tousertype(tolua_S, 1, 0));
    
#if COCOS2D_DEBUG>=1
    if (nullptr==self) {
        tolua_error(tolua_S,"invalid 'self' in function 'tolua_cocos2d_Resource_addResourceAsyncHandler'\n", NULL);
        return 0;
    }
#endif
    
    argc=lua_gettop(tolua_S)-1;
    std::string arg0;
    std::string arg2="Texture2D";

    if (argc == 2 || argc ==3) {
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok) return 0;
    }
    
    if (argc==3) {
        ok &= luaval_to_std_string(tolua_S, 4,&arg2);
        if(!ok) return 0;
    }
    
#if COCOS2D_DEBUG>=1
    if (!toluafix_isfunction(tolua_S, 3, "LUA_FUNCTION", 0, &tolua_err))
    {
        //goto tolua_lerror1;
    }
#endif
        
    LUA_FUNCTION handler=(toluafix_ref_function(tolua_S, 3,0));
    self->addResourceAsyncHandler(arg0, handler,arg2);
    return 0;
}

static void extendComponent(lua_State* L)
{
    lua_pushstring(L, "gx.Com");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L, "registerScriptHandler", tolua_geniusx_Component_registerScriptHandler);
        tolua_function(L, "unregisterScriptHandler", tolua_geniusx_Component_unregisterScriptHandler);
    }
    lua_pop(L, 1);
}

static void extendSystem(lua_State* L)
{
    lua_pushstring(L, "gx.System");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L, "registerScriptHandler", tolua_geniusx_System_registerScriptHandler);
        tolua_function(L, "unregisterScriptHandler", tolua_geniusx_System_unregisterScriptHandler);
    }
    lua_pop(L, 1);
}

static void extendResource(lua_State* L)
{
    lua_pushstring(L,"gx.Resource");
    lua_rawget(L,LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L, "updateResourceReferenceAsyncHandler", tolua_cocos2d_Resource_updateResourceReferenceAsyncHandler);
        tolua_function(L, "addResourceAsyncHandler", tolua_cocos2d_Resource_addResourceAsyncHandler);
    }
    lua_pop(L, 1);
}


TOLUA_API int register_geniusx_manual(lua_State* tolua_S)
{
    extendComponent(tolua_S);
    extendSystem(tolua_S);
    extendResource(tolua_S);
    return 0;
}

