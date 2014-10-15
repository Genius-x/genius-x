#include "lua_geniusx_auto.hpp"
#include "genius-x.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_geniusx_Touch_getPreviousLocationInView(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Touch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Touch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Touch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Touch_getPreviousLocationInView'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Vec2 ret = cobj->getPreviousLocationInView();
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getPreviousLocationInView",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Touch_getPreviousLocationInView'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Touch_getLocation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Touch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Touch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Touch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Touch_getLocation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Vec2 ret = cobj->getLocation();
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getLocation",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Touch_getLocation'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Touch_getDelta(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Touch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Touch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Touch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Touch_getDelta'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Vec2 ret = cobj->getDelta();
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDelta",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Touch_getDelta'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Touch_getStartLocationInView(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Touch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Touch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Touch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Touch_getStartLocationInView'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Vec2 ret = cobj->getStartLocationInView();
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getStartLocationInView",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Touch_getStartLocationInView'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Touch_getStartLocation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Touch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Touch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Touch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Touch_getStartLocation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Vec2 ret = cobj->getStartLocation();
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getStartLocation",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Touch_getStartLocation'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Touch_getID(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Touch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Touch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Touch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Touch_getID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Touch_getID'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Touch_setTouchInfo(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Touch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Touch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Touch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Touch_setTouchInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        int arg0;
        double arg1;
        double arg2;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cobj->setTouchInfo(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTouchInfo",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Touch_setTouchInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Touch_getLocationInView(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Touch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Touch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Touch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Touch_getLocationInView'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Vec2 ret = cobj->getLocationInView();
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getLocationInView",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Touch_getLocationInView'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Touch_getPreviousLocation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Touch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Touch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Touch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Touch_getPreviousLocation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Vec2 ret = cobj->getPreviousLocation();
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getPreviousLocation",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Touch_getPreviousLocation'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Touch_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Touch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::Touch();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.Touch");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "Touch",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Touch_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_geniusx_Touch_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Touch)");
    return 0;
}

int lua_register_geniusx_Touch(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.Touch");
    tolua_cclass(tolua_S,"Touch","cc.Touch","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"Touch");
        tolua_function(tolua_S,"new",lua_geniusx_Touch_constructor);
        tolua_function(tolua_S,"getPreviousLocationInView",lua_geniusx_Touch_getPreviousLocationInView);
        tolua_function(tolua_S,"getLocation",lua_geniusx_Touch_getLocation);
        tolua_function(tolua_S,"getDelta",lua_geniusx_Touch_getDelta);
        tolua_function(tolua_S,"getStartLocationInView",lua_geniusx_Touch_getStartLocationInView);
        tolua_function(tolua_S,"getStartLocation",lua_geniusx_Touch_getStartLocation);
        tolua_function(tolua_S,"getID",lua_geniusx_Touch_getID);
        tolua_function(tolua_S,"setTouchInfo",lua_geniusx_Touch_setTouchInfo);
        tolua_function(tolua_S,"getLocationInView",lua_geniusx_Touch_getLocationInView);
        tolua_function(tolua_S,"getPreviousLocation",lua_geniusx_Touch_getPreviousLocation);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::Touch).name();
    g_luaType[typeName] = "cc.Touch";
    g_typeCast["Touch"] = "cc.Touch";
    return 1;
}

int lua_geniusx_Com_getComByType(lua_State* tolua_S)
{
    int argc = 0;
    GX::Com* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Com",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Com*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Com_getComByType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        GX::Com* ret = cobj->getComByType(arg0);
        object_to_luaval<GX::Com>(tolua_S, "gx.Com",(GX::Com*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getComByType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Com_getComByType'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Com_getType(lua_State* tolua_S)
{
    int argc = 0;
    GX::Com* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Com",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Com*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Com_getType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const std::string& ret = cobj->getType();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Com_getType'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Com_getEntity(lua_State* tolua_S)
{
    int argc = 0;
    GX::Com* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Com",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Com*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Com_getEntity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        GX::Entity* ret = cobj->getEntity();
        object_to_luaval<GX::Entity>(tolua_S, "gx.Entity",(GX::Entity*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getEntity",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Com_getEntity'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Com_getScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    GX::Com* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Com",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Com*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Com_getScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getScriptHandler();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getScriptHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Com_getScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Com_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"gx.Com",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        GX::Com* ret = GX::Com::create(arg0);
        object_to_luaval<GX::Com>(tolua_S, "gx.Com",(GX::Com*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Com_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_geniusx_Com_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Com)");
    return 0;
}

int lua_register_geniusx_Com(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"gx.Com");
    tolua_cclass(tolua_S,"Com","gx.Com","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"Com");
        tolua_function(tolua_S,"getComByType",lua_geniusx_Com_getComByType);
        tolua_function(tolua_S,"getType",lua_geniusx_Com_getType);
        tolua_function(tolua_S,"getEntity",lua_geniusx_Com_getEntity);
        tolua_function(tolua_S,"getScriptHandler",lua_geniusx_Com_getScriptHandler);
        tolua_function(tolua_S,"create", lua_geniusx_Com_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(GX::Com).name();
    g_luaType[typeName] = "gx.Com";
    g_typeCast["Com"] = "gx.Com";
    return 1;
}

int lua_geniusx_ComScriptData_getFloat(lua_State* tolua_S)
{
    int argc = 0;
    GX::ComScriptData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.ComScriptData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::ComScriptData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_ComScriptData_getFloat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getFloat();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getFloat",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ComScriptData_getFloat'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_ComScriptData_setNode(lua_State* tolua_S)
{
    int argc = 0;
    GX::ComScriptData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.ComScriptData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::ComScriptData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_ComScriptData_setNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);
        if(!ok)
            return 0;
        cobj->setNode(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setNode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ComScriptData_setNode'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_ComScriptData_getString(lua_State* tolua_S)
{
    int argc = 0;
    GX::ComScriptData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.ComScriptData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::ComScriptData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_ComScriptData_getString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        std::string ret = cobj->getString();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getString",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ComScriptData_getString'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_ComScriptData_setFloat(lua_State* tolua_S)
{
    int argc = 0;
    GX::ComScriptData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.ComScriptData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::ComScriptData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_ComScriptData_setFloat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setFloat(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFloat",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ComScriptData_setFloat'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_ComScriptData_setString(lua_State* tolua_S)
{
    int argc = 0;
    GX::ComScriptData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.ComScriptData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::ComScriptData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_ComScriptData_setString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setString(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ComScriptData_setString'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_ComScriptData_getBool(lua_State* tolua_S)
{
    int argc = 0;
    GX::ComScriptData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.ComScriptData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::ComScriptData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_ComScriptData_getBool'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->getBool();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBool",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ComScriptData_getBool'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_ComScriptData_setRef(lua_State* tolua_S)
{
    int argc = 0;
    GX::ComScriptData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.ComScriptData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::ComScriptData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_ComScriptData_setRef'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Ref* arg0;

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0);
        if(!ok)
            return 0;
        cobj->setRef(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setRef",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ComScriptData_setRef'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_ComScriptData_getCom(lua_State* tolua_S)
{
    int argc = 0;
    GX::ComScriptData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.ComScriptData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::ComScriptData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_ComScriptData_getCom'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        GX::Com* ret = cobj->getCom();
        object_to_luaval<GX::Com>(tolua_S, "gx.Com",(GX::Com*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCom",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ComScriptData_getCom'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_ComScriptData_getVec2(lua_State* tolua_S)
{
    int argc = 0;
    GX::ComScriptData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.ComScriptData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::ComScriptData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_ComScriptData_getVec2'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Vec2 ret = cobj->getVec2();
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getVec2",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ComScriptData_getVec2'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_ComScriptData_setBool(lua_State* tolua_S)
{
    int argc = 0;
    GX::ComScriptData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.ComScriptData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::ComScriptData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_ComScriptData_setBool'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setBool(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBool",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ComScriptData_setBool'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_ComScriptData_setVec2(lua_State* tolua_S)
{
    int argc = 0;
    GX::ComScriptData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.ComScriptData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::ComScriptData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_ComScriptData_setVec2'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Vec2 arg0;

        ok &= luaval_to_vec2(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setVec2(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setVec2",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ComScriptData_setVec2'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_ComScriptData_setCom(lua_State* tolua_S)
{
    int argc = 0;
    GX::ComScriptData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.ComScriptData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::ComScriptData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_ComScriptData_setCom'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        GX::Com* arg0;

        ok &= luaval_to_object<GX::Com>(tolua_S, 2, "gx.Com",&arg0);
        if(!ok)
            return 0;
        cobj->setCom(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCom",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ComScriptData_setCom'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_ComScriptData_getRef(lua_State* tolua_S)
{
    int argc = 0;
    GX::ComScriptData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.ComScriptData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::ComScriptData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_ComScriptData_getRef'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Ref* ret = cobj->getRef();
        object_to_luaval<cocos2d::Ref>(tolua_S, "cc.Ref",(cocos2d::Ref*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getRef",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ComScriptData_getRef'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_ComScriptData_getNode(lua_State* tolua_S)
{
    int argc = 0;
    GX::ComScriptData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.ComScriptData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::ComScriptData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_ComScriptData_getNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getNode();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ComScriptData_getNode'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_ComScriptData_constructor(lua_State* tolua_S)
{
    int argc = 0;
    GX::ComScriptData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new GX::ComScriptData();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"gx.ComScriptData");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "ComScriptData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ComScriptData_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_geniusx_ComScriptData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ComScriptData)");
    return 0;
}

int lua_register_geniusx_ComScriptData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"gx.ComScriptData");
    tolua_cclass(tolua_S,"ComScriptData","gx.ComScriptData","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"ComScriptData");
        tolua_function(tolua_S,"new",lua_geniusx_ComScriptData_constructor);
        tolua_function(tolua_S,"getFloat",lua_geniusx_ComScriptData_getFloat);
        tolua_function(tolua_S,"setNode",lua_geniusx_ComScriptData_setNode);
        tolua_function(tolua_S,"getString",lua_geniusx_ComScriptData_getString);
        tolua_function(tolua_S,"setFloat",lua_geniusx_ComScriptData_setFloat);
        tolua_function(tolua_S,"setString",lua_geniusx_ComScriptData_setString);
        tolua_function(tolua_S,"getBool",lua_geniusx_ComScriptData_getBool);
        tolua_function(tolua_S,"setRef",lua_geniusx_ComScriptData_setRef);
        tolua_function(tolua_S,"getCom",lua_geniusx_ComScriptData_getCom);
        tolua_function(tolua_S,"getVec2",lua_geniusx_ComScriptData_getVec2);
        tolua_function(tolua_S,"setBool",lua_geniusx_ComScriptData_setBool);
        tolua_function(tolua_S,"setVec2",lua_geniusx_ComScriptData_setVec2);
        tolua_function(tolua_S,"setCom",lua_geniusx_ComScriptData_setCom);
        tolua_function(tolua_S,"getRef",lua_geniusx_ComScriptData_getRef);
        tolua_function(tolua_S,"getNode",lua_geniusx_ComScriptData_getNode);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(GX::ComScriptData).name();
    g_luaType[typeName] = "gx.ComScriptData";
    g_typeCast["ComScriptData"] = "gx.ComScriptData";
    return 1;
}

int lua_geniusx_System_setTouchEnabled(lua_State* tolua_S)
{
    int argc = 0;
    GX::System* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.System",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::System*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_System_setTouchEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setTouchEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTouchEnabled",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_System_setTouchEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_System_getComByType(lua_State* tolua_S)
{
    int argc = 0;
    GX::System* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.System",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::System*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_System_getComByType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        GX::Com* ret = cobj->getComByType(arg0);
        object_to_luaval<GX::Com>(tolua_S, "gx.Com",(GX::Com*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getComByType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_System_getComByType'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_System_getTouchMode(lua_State* tolua_S)
{
    int argc = 0;
    GX::System* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.System",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::System*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_System_getTouchMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = (int)cobj->getTouchMode();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getTouchMode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_System_getTouchMode'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_System_setTouchMode(lua_State* tolua_S)
{
    int argc = 0;
    GX::System* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.System",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::System*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_System_setTouchMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Touch::DispatchMode arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setTouchMode(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTouchMode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_System_setTouchMode'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_System_isTouchEnabled(lua_State* tolua_S)
{
    int argc = 0;
    GX::System* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.System",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::System*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_System_isTouchEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isTouchEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isTouchEnabled",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_System_isTouchEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_System_setSwallowsTouches(lua_State* tolua_S)
{
    int argc = 0;
    GX::System* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.System",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::System*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_System_setSwallowsTouches'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setSwallowsTouches(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSwallowsTouches",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_System_setSwallowsTouches'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_System_getEntity(lua_State* tolua_S)
{
    int argc = 0;
    GX::System* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.System",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::System*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_System_getEntity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        GX::Entity* ret = cobj->getEntity();
        object_to_luaval<GX::Entity>(tolua_S, "gx.Entity",(GX::Entity*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getEntity",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_System_getEntity'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_System_isSwallowsTouches(lua_State* tolua_S)
{
    int argc = 0;
    GX::System* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.System",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::System*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_System_isSwallowsTouches'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isSwallowsTouches();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isSwallowsTouches",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_System_isSwallowsTouches'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_System_getScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    GX::System* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.System",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::System*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_System_getScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getScriptHandler();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getScriptHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_System_getScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_System_registerWithTouchDispatcher(lua_State* tolua_S)
{
    int argc = 0;
    GX::System* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.System",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::System*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_System_registerWithTouchDispatcher'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->registerWithTouchDispatcher();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerWithTouchDispatcher",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_System_registerWithTouchDispatcher'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_System_getECSManager(lua_State* tolua_S)
{
    int argc = 0;
    GX::System* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.System",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::System*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_System_getECSManager'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        GX::ECSManager* ret = cobj->getECSManager();
        object_to_luaval<GX::ECSManager>(tolua_S, "gx.ECSManager",(GX::ECSManager*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getECSManager",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_System_getECSManager'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_System_getNode(lua_State* tolua_S)
{
    int argc = 0;
    GX::System* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.System",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::System*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_System_getNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getNode();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_System_getNode'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_System_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"gx.System",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        ok &= luaval_to_std_string(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        GX::System* ret = GX::System::create(arg0, arg1);
        object_to_luaval<GX::System>(tolua_S, "gx.System",(GX::System*)ret);
        return 1;
    }
    if (argc == 3)
    {
        std::string arg0;
        std::string arg1;
        int arg2;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        ok &= luaval_to_std_string(tolua_S, 3,&arg1);
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);
        if(!ok)
            return 0;
        GX::System* ret = GX::System::create(arg0, arg1, arg2);
        object_to_luaval<GX::System>(tolua_S, "gx.System",(GX::System*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_System_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_geniusx_System_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (System)");
    return 0;
}

int lua_register_geniusx_System(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"gx.System");
    tolua_cclass(tolua_S,"System","gx.System","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"System");
        tolua_function(tolua_S,"setTouchEnabled",lua_geniusx_System_setTouchEnabled);
        tolua_function(tolua_S,"getComByType",lua_geniusx_System_getComByType);
        tolua_function(tolua_S,"getTouchMode",lua_geniusx_System_getTouchMode);
        tolua_function(tolua_S,"setTouchMode",lua_geniusx_System_setTouchMode);
        tolua_function(tolua_S,"isTouchEnabled",lua_geniusx_System_isTouchEnabled);
        tolua_function(tolua_S,"setSwallowsTouches",lua_geniusx_System_setSwallowsTouches);
        tolua_function(tolua_S,"getEntity",lua_geniusx_System_getEntity);
        tolua_function(tolua_S,"isSwallowsTouches",lua_geniusx_System_isSwallowsTouches);
        tolua_function(tolua_S,"getScriptHandler",lua_geniusx_System_getScriptHandler);
        tolua_function(tolua_S,"registerWithTouchDispatcher",lua_geniusx_System_registerWithTouchDispatcher);
        tolua_function(tolua_S,"getECSManager",lua_geniusx_System_getECSManager);
        tolua_function(tolua_S,"getNode",lua_geniusx_System_getNode);
        tolua_function(tolua_S,"create", lua_geniusx_System_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(GX::System).name();
    g_luaType[typeName] = "gx.System";
    g_typeCast["System"] = "gx.System";
    return 1;
}

int lua_geniusx_SystemScriptData_setSystem(lua_State* tolua_S)
{
    int argc = 0;
    GX::SystemScriptData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.SystemScriptData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::SystemScriptData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_SystemScriptData_setSystem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        GX::System* arg0;

        ok &= luaval_to_object<GX::System>(tolua_S, 2, "gx.System",&arg0);
        if(!ok)
            return 0;
        cobj->setSystem(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSystem",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_SystemScriptData_setSystem'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_SystemScriptData_getDelta(lua_State* tolua_S)
{
    int argc = 0;
    GX::SystemScriptData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.SystemScriptData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::SystemScriptData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_SystemScriptData_getDelta'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getDelta();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDelta",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_SystemScriptData_getDelta'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_SystemScriptData_getString(lua_State* tolua_S)
{
    int argc = 0;
    GX::SystemScriptData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.SystemScriptData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::SystemScriptData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_SystemScriptData_getString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        std::string ret = cobj->getString();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getString",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_SystemScriptData_getString'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_SystemScriptData_setString(lua_State* tolua_S)
{
    int argc = 0;
    GX::SystemScriptData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.SystemScriptData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::SystemScriptData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_SystemScriptData_setString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setString(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_SystemScriptData_setString'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_SystemScriptData_getSystem(lua_State* tolua_S)
{
    int argc = 0;
    GX::SystemScriptData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.SystemScriptData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::SystemScriptData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_SystemScriptData_getSystem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        GX::System* ret = cobj->getSystem();
        object_to_luaval<GX::System>(tolua_S, "gx.System",(GX::System*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getSystem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_SystemScriptData_getSystem'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_SystemScriptData_constructor(lua_State* tolua_S)
{
    int argc = 0;
    GX::SystemScriptData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new GX::SystemScriptData();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"gx.SystemScriptData");
        return 1;
    }
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj = new GX::SystemScriptData(arg0);
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"gx.SystemScriptData");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "SystemScriptData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_SystemScriptData_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_geniusx_SystemScriptData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (SystemScriptData)");
    return 0;
}

int lua_register_geniusx_SystemScriptData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"gx.SystemScriptData");
    tolua_cclass(tolua_S,"SystemScriptData","gx.SystemScriptData","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"SystemScriptData");
        tolua_function(tolua_S,"new",lua_geniusx_SystemScriptData_constructor);
        tolua_function(tolua_S,"setSystem",lua_geniusx_SystemScriptData_setSystem);
        tolua_function(tolua_S,"getDelta",lua_geniusx_SystemScriptData_getDelta);
        tolua_function(tolua_S,"getString",lua_geniusx_SystemScriptData_getString);
        tolua_function(tolua_S,"setString",lua_geniusx_SystemScriptData_setString);
        tolua_function(tolua_S,"getSystem",lua_geniusx_SystemScriptData_getSystem);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(GX::SystemScriptData).name();
    g_luaType[typeName] = "gx.SystemScriptData";
    g_typeCast["SystemScriptData"] = "gx.SystemScriptData";
    return 1;
}

int lua_geniusx_ComData_constructor(lua_State* tolua_S)
{
    int argc = 0;
    GX::ComData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new GX::ComData();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"gx.ComData");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "ComData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ComData_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_geniusx_ComData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ComData)");
    return 0;
}

int lua_register_geniusx_ComData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"gx.ComData");
    tolua_cclass(tolua_S,"ComData","gx.ComData","gx.ResourceDataDelegate",nullptr);

    tolua_beginmodule(tolua_S,"ComData");
        tolua_function(tolua_S,"new",lua_geniusx_ComData_constructor);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(GX::ComData).name();
    g_luaType[typeName] = "gx.ComData";
    g_typeCast["ComData"] = "gx.ComData";
    return 1;
}

int lua_geniusx_Entity_ComsChanged(lua_State* tolua_S)
{
    int argc = 0;
    GX::Entity* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Entity",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Entity*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Entity_ComsChanged'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->ComsChanged();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "ComsChanged",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Entity_ComsChanged'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Entity_setBucket(lua_State* tolua_S)
{
    int argc = 0;
    GX::Entity* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Entity",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Entity*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Entity_setBucket'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setBucket(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBucket",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Entity_setBucket'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Entity_getComByType(lua_State* tolua_S)
{
    int argc = 0;
    GX::Entity* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Entity",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Entity*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Entity_getComByType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        GX::Com* ret = cobj->getComByType(arg0);
        object_to_luaval<GX::Com>(tolua_S, "gx.Com",(GX::Com*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getComByType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Entity_getComByType'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Entity_getParent(lua_State* tolua_S)
{
    int argc = 0;
    GX::Entity* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Entity",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Entity*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Entity_getParent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        GX::Entity* ret = cobj->getParent();
        object_to_luaval<GX::Entity>(tolua_S, "gx.Entity",(GX::Entity*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getParent",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Entity_getParent'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Entity_removeAllComs(lua_State* tolua_S)
{
    int argc = 0;
    GX::Entity* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Entity",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Entity*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Entity_removeAllComs'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeAllComs();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeAllComs",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Entity_removeAllComs'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Entity_sendEvent(lua_State* tolua_S)
{
    int argc = 0;
    GX::Entity* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Entity",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Entity*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Entity_sendEvent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->sendEvent(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "sendEvent",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Entity_sendEvent'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Entity_getId(lua_State* tolua_S)
{
    int argc = 0;
    GX::Entity* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Entity",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Entity*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Entity_getId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const int& ret = cobj->getId();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getId",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Entity_getId'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Entity_removeCom(lua_State* tolua_S)
{
    int argc = 0;
    GX::Entity* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Entity",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Entity*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Entity_removeCom'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->removeCom(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeCom",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Entity_removeCom'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Entity_getNode(lua_State* tolua_S)
{
    int argc = 0;
    GX::Entity* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Entity",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Entity*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Entity_getNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getNode();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Entity_getNode'.",&tolua_err);
#endif

    return 0;
}
static int lua_geniusx_Entity_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Entity)");
    return 0;
}

int lua_register_geniusx_Entity(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"gx.Entity");
    tolua_cclass(tolua_S,"Entity","gx.Entity","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"Entity");
        tolua_function(tolua_S,"ComsChanged",lua_geniusx_Entity_ComsChanged);
        tolua_function(tolua_S,"setBucket",lua_geniusx_Entity_setBucket);
        tolua_function(tolua_S,"getComByType",lua_geniusx_Entity_getComByType);
        tolua_function(tolua_S,"getParent",lua_geniusx_Entity_getParent);
        tolua_function(tolua_S,"removeAllComs",lua_geniusx_Entity_removeAllComs);
        tolua_function(tolua_S,"sendEvent",lua_geniusx_Entity_sendEvent);
        tolua_function(tolua_S,"getId",lua_geniusx_Entity_getId);
        tolua_function(tolua_S,"removeCom",lua_geniusx_Entity_removeCom);
        tolua_function(tolua_S,"getNode",lua_geniusx_Entity_getNode);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(GX::Entity).name();
    g_luaType[typeName] = "gx.Entity";
    g_typeCast["Entity"] = "gx.Entity";
    return 1;
}

int lua_geniusx_ECSManager_unregisterCom(lua_State* tolua_S)
{
    int argc = 0;
    GX::ECSManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.ECSManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::ECSManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_ECSManager_unregisterCom'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->unregisterCom(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "unregisterCom",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ECSManager_unregisterCom'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_ECSManager_getAllEntitiesPosessingCom(lua_State* tolua_S)
{
    int argc = 0;
    GX::ECSManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.ECSManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::ECSManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_ECSManager_getAllEntitiesPosessingCom'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cocos2d::Vector<GX::Entity *> ret = cobj->getAllEntitiesPosessingCom(arg0);
        ccvector_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAllEntitiesPosessingCom",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ECSManager_getAllEntitiesPosessingCom'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_ECSManager_update(lua_State* tolua_S)
{
    int argc = 0;
    GX::ECSManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.ECSManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::ECSManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_ECSManager_update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->update(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ECSManager_update'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_ECSManager_removeComFromEntity(lua_State* tolua_S)
{
    int argc = 0;
    GX::ECSManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.ECSManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::ECSManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_ECSManager_removeComFromEntity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        GX::Entity* arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_object<GX::Entity>(tolua_S, 3, "gx.Entity",&arg1);
        if(!ok)
            return 0;
        cobj->removeComFromEntity(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeComFromEntity",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ECSManager_removeComFromEntity'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_ECSManager_removeEntity(lua_State* tolua_S)
{
    int argc = 0;
    GX::ECSManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.ECSManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::ECSManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_ECSManager_removeEntity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        GX::Entity* arg0;

        ok &= luaval_to_object<GX::Entity>(tolua_S, 2, "gx.Entity",&arg0);
        if(!ok)
            return 0;
        cobj->removeEntity(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeEntity",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ECSManager_removeEntity'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_ECSManager_removeAllCom(lua_State* tolua_S)
{
    int argc = 0;
    GX::ECSManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.ECSManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::ECSManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_ECSManager_removeAllCom'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeAllCom();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeAllCom",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ECSManager_removeAllCom'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_ECSManager_registerCom(lua_State* tolua_S)
{
    int argc = 0;
    GX::ECSManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.ECSManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::ECSManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_ECSManager_registerCom'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        GX::Com* arg0;

        ok &= luaval_to_object<GX::Com>(tolua_S, 2, "gx.Com",&arg0);
        if(!ok)
            return 0;
        cobj->registerCom(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerCom",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ECSManager_registerCom'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_ECSManager_registerSystem(lua_State* tolua_S)
{
    int argc = 0;
    GX::ECSManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.ECSManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::ECSManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_ECSManager_registerSystem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        GX::System* arg0;

        ok &= luaval_to_object<GX::System>(tolua_S, 2, "gx.System",&arg0);
        if(!ok)
            return 0;
        cobj->registerSystem(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerSystem",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ECSManager_registerSystem'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_ECSManager_addComToEntity(lua_State* tolua_S)
{
    int argc = 0;
    GX::ECSManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.ECSManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::ECSManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_ECSManager_addComToEntity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        GX::Com* arg0;
        GX::Entity* arg1;

        ok &= luaval_to_object<GX::Com>(tolua_S, 2, "gx.Com",&arg0);

        ok &= luaval_to_object<GX::Entity>(tolua_S, 3, "gx.Entity",&arg1);
        if(!ok)
            return 0;
        cobj->addComToEntity(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addComToEntity",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ECSManager_addComToEntity'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_ECSManager_createEntity(lua_State* tolua_S)
{
    int argc = 0;
    GX::ECSManager* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.ECSManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (GX::ECSManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_ECSManager_createEntity'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            GX::Entity* ret = cobj->createEntity(arg0);
            object_to_luaval<GX::Entity>(tolua_S, "gx.Entity",(GX::Entity*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            GX::Entity* ret = cobj->createEntity();
            object_to_luaval<GX::Entity>(tolua_S, "gx.Entity",(GX::Entity*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createEntity",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ECSManager_createEntity'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_ECSManager_unregisterSystem(lua_State* tolua_S)
{
    int argc = 0;
    GX::ECSManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.ECSManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::ECSManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_ECSManager_unregisterSystem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->unregisterSystem(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "unregisterSystem",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ECSManager_unregisterSystem'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_ECSManager_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"gx.ECSManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        GX::ECSManager* ret = GX::ECSManager::create();
        object_to_luaval<GX::ECSManager>(tolua_S, "gx.ECSManager",(GX::ECSManager*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ECSManager_create'.",&tolua_err);
#endif
    return 0;
}
int lua_geniusx_ECSManager_constructor(lua_State* tolua_S)
{
    int argc = 0;
    GX::ECSManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new GX::ECSManager();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"gx.ECSManager");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "ECSManager",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_ECSManager_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_geniusx_ECSManager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ECSManager)");
    return 0;
}

int lua_register_geniusx_ECSManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"gx.ECSManager");
    tolua_cclass(tolua_S,"ECSManager","gx.ECSManager","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"ECSManager");
        tolua_function(tolua_S,"new",lua_geniusx_ECSManager_constructor);
        tolua_function(tolua_S,"unregisterCom",lua_geniusx_ECSManager_unregisterCom);
        tolua_function(tolua_S,"getAllEntitiesPosessingCom",lua_geniusx_ECSManager_getAllEntitiesPosessingCom);
        tolua_function(tolua_S,"update",lua_geniusx_ECSManager_update);
        tolua_function(tolua_S,"removeComFromEntity",lua_geniusx_ECSManager_removeComFromEntity);
        tolua_function(tolua_S,"removeEntity",lua_geniusx_ECSManager_removeEntity);
        tolua_function(tolua_S,"removeAllCom",lua_geniusx_ECSManager_removeAllCom);
        tolua_function(tolua_S,"registerCom",lua_geniusx_ECSManager_registerCom);
        tolua_function(tolua_S,"registerSystem",lua_geniusx_ECSManager_registerSystem);
        tolua_function(tolua_S,"addComToEntity",lua_geniusx_ECSManager_addComToEntity);
        tolua_function(tolua_S,"createEntity",lua_geniusx_ECSManager_createEntity);
        tolua_function(tolua_S,"unregisterSystem",lua_geniusx_ECSManager_unregisterSystem);
        tolua_function(tolua_S,"create", lua_geniusx_ECSManager_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(GX::ECSManager).name();
    g_luaType[typeName] = "gx.ECSManager";
    g_typeCast["ECSManager"] = "gx.ECSManager";
    return 1;
}

int lua_geniusx_NodeCom_getNode(lua_State* tolua_S)
{
    int argc = 0;
    GX::NodeCom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.NodeCom",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::NodeCom*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_NodeCom_getNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getNode();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_NodeCom_getNode'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_NodeCom_getNodeByName(lua_State* tolua_S)
{
    int argc = 0;
    GX::NodeCom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.NodeCom",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::NodeCom*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_NodeCom_getNodeByName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getNodeByName(arg0);
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNodeByName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_NodeCom_getNodeByName'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_NodeCom_setNode(lua_State* tolua_S)
{
    int argc = 0;
    GX::NodeCom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.NodeCom",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::NodeCom*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_NodeCom_setNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);
        if(!ok)
            return 0;
        cobj->setNode(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setNode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_NodeCom_setNode'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_NodeCom_createTMXTiledMap(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"gx.NodeCom",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cocos2d::TMXTiledMap* ret = GX::NodeCom::createTMXTiledMap(arg0);
        object_to_luaval<cocos2d::TMXTiledMap>(tolua_S, "cc.TMXTiledMap",(cocos2d::TMXTiledMap*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createTMXTiledMap",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_NodeCom_createTMXTiledMap'.",&tolua_err);
#endif
    return 0;
}
int lua_geniusx_NodeCom_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"gx.NodeCom",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        GX::NodeCom* ret = GX::NodeCom::create();
        object_to_luaval<GX::NodeCom>(tolua_S, "gx.NodeCom",(GX::NodeCom*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_NodeCom_create'.",&tolua_err);
#endif
    return 0;
}
int lua_geniusx_NodeCom_createAtlasNode(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"gx.NodeCom",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 4)
    {
        std::string arg0;
        int arg1;
        int arg2;
        int arg3;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);
        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3);
        if(!ok)
            return 0;
        cocos2d::AtlasNode* ret = GX::NodeCom::createAtlasNode(arg0, arg1, arg2, arg3);
        object_to_luaval<cocos2d::AtlasNode>(tolua_S, "cc.AtlasNode",(cocos2d::AtlasNode*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createAtlasNode",argc, 4);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_NodeCom_createAtlasNode'.",&tolua_err);
#endif
    return 0;
}
int lua_geniusx_NodeCom_createSprite(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"gx.NodeCom",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);
            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1);
            if (!ok) { break; }
            cocos2d::Sprite* ret = GX::NodeCom::createSprite(arg0, arg1);
            object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 1)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);
            if (!ok) { break; }
            cocos2d::Sprite* ret = GX::NodeCom::createSprite(arg0);
            object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "createSprite",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_NodeCom_createSprite'.",&tolua_err);
#endif
    return 0;
}
int lua_geniusx_NodeCom_createTMXTiledMapWithXML(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"gx.NodeCom",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        ok &= luaval_to_std_string(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cocos2d::TMXTiledMap* ret = GX::NodeCom::createTMXTiledMapWithXML(arg0, arg1);
        object_to_luaval<cocos2d::TMXTiledMap>(tolua_S, "cc.TMXTiledMap",(cocos2d::TMXTiledMap*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createTMXTiledMapWithXML",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_NodeCom_createTMXTiledMapWithXML'.",&tolua_err);
#endif
    return 0;
}
int lua_geniusx_NodeCom_createTileMapAtlas(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"gx.NodeCom",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 4)
    {
        std::string arg0;
        std::string arg1;
        int arg2;
        int arg3;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        ok &= luaval_to_std_string(tolua_S, 3,&arg1);
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);
        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3);
        if(!ok)
            return 0;
        cocos2d::TileMapAtlas* ret = GX::NodeCom::createTileMapAtlas(arg0, arg1, arg2, arg3);
        object_to_luaval<cocos2d::TileMapAtlas>(tolua_S, "cc.TileMapAtlas",(cocos2d::TileMapAtlas*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createTileMapAtlas",argc, 4);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_NodeCom_createTileMapAtlas'.",&tolua_err);
#endif
    return 0;
}
int lua_geniusx_NodeCom_createSpriteBatchNode(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"gx.NodeCom",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cocos2d::SpriteBatchNode* ret = GX::NodeCom::createSpriteBatchNode(arg0);
        object_to_luaval<cocos2d::SpriteBatchNode>(tolua_S, "cc.SpriteBatchNode",(cocos2d::SpriteBatchNode*)ret);
        return 1;
    }
    if (argc == 2)
    {
        std::string arg0;
        ssize_t arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        ok &= luaval_to_ssize(tolua_S, 3, &arg1);
        if(!ok)
            return 0;
        cocos2d::SpriteBatchNode* ret = GX::NodeCom::createSpriteBatchNode(arg0, arg1);
        object_to_luaval<cocos2d::SpriteBatchNode>(tolua_S, "cc.SpriteBatchNode",(cocos2d::SpriteBatchNode*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createSpriteBatchNode",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_NodeCom_createSpriteBatchNode'.",&tolua_err);
#endif
    return 0;
}
int lua_geniusx_NodeCom_constructor(lua_State* tolua_S)
{
    int argc = 0;
    GX::NodeCom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new GX::NodeCom();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"gx.NodeCom");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "NodeCom",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_NodeCom_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_geniusx_NodeCom_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (NodeCom)");
    return 0;
}

int lua_register_geniusx_NodeCom(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"gx.NodeCom");
    tolua_cclass(tolua_S,"NodeCom","gx.NodeCom","gx.Com",nullptr);

    tolua_beginmodule(tolua_S,"NodeCom");
        tolua_function(tolua_S,"new",lua_geniusx_NodeCom_constructor);
        tolua_function(tolua_S,"getNode",lua_geniusx_NodeCom_getNode);
        tolua_function(tolua_S,"getNodeByName",lua_geniusx_NodeCom_getNodeByName);
        tolua_function(tolua_S,"setNode",lua_geniusx_NodeCom_setNode);
        tolua_function(tolua_S,"createTMXTiledMap", lua_geniusx_NodeCom_createTMXTiledMap);
        tolua_function(tolua_S,"create", lua_geniusx_NodeCom_create);
        tolua_function(tolua_S,"createAtlasNode", lua_geniusx_NodeCom_createAtlasNode);
        tolua_function(tolua_S,"createSprite", lua_geniusx_NodeCom_createSprite);
        tolua_function(tolua_S,"createTMXTiledMapWithXML", lua_geniusx_NodeCom_createTMXTiledMapWithXML);
        tolua_function(tolua_S,"createTileMapAtlas", lua_geniusx_NodeCom_createTileMapAtlas);
        tolua_function(tolua_S,"createSpriteBatchNode", lua_geniusx_NodeCom_createSpriteBatchNode);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(GX::NodeCom).name();
    g_luaType[typeName] = "gx.NodeCom";
    g_typeCast["NodeCom"] = "gx.NodeCom";
    return 1;
}

int lua_geniusx_AnimationCom_playAnimation(lua_State* tolua_S)
{
    int argc = 0;
    GX::AnimationCom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.AnimationCom",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::AnimationCom*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_AnimationCom_playAnimation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        cocos2d::Node* arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 3, "cc.Node",&arg1);
        if(!ok)
            return 0;
        cobj->playAnimation(arg0, arg1);
        return 0;
    }
    if (argc == 3) 
    {
        std::string arg0;
        cocos2d::Node* arg1;
        std::function<void ()> arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 3, "cc.Node",&arg1);

        do {
			// Lambda binding for lua is not supported.
			assert(false);
		} while(0)
		;
        if(!ok)
            return 0;
        cobj->playAnimation(arg0, arg1, arg2);
        return 0;
    }
    if (argc == 4) 
    {
        std::string arg0;
        cocos2d::Node* arg1;
        std::function<void ()> arg2;
        cocos2d::Point arg3;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 3, "cc.Node",&arg1);

        do {
			// Lambda binding for lua is not supported.
			assert(false);
		} while(0)
		;

        ok &= luaval_to_point(tolua_S, 5, &arg3);
        if(!ok)
            return 0;
        cobj->playAnimation(arg0, arg1, arg2, arg3);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "playAnimation",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_AnimationCom_playAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_AnimationCom_constructor(lua_State* tolua_S)
{
    int argc = 0;
    GX::AnimationCom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new GX::AnimationCom();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"gx.AnimationCom");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "AnimationCom",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_AnimationCom_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_geniusx_AnimationCom_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (AnimationCom)");
    return 0;
}

int lua_register_geniusx_AnimationCom(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"gx.AnimationCom");
    tolua_cclass(tolua_S,"AnimationCom","gx.AnimationCom","gx.Com",nullptr);

    tolua_beginmodule(tolua_S,"AnimationCom");
        tolua_function(tolua_S,"new",lua_geniusx_AnimationCom_constructor);
        tolua_function(tolua_S,"playAnimation",lua_geniusx_AnimationCom_playAnimation);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(GX::AnimationCom).name();
    g_luaType[typeName] = "gx.AnimationCom";
    g_typeCast["AnimationCom"] = "gx.AnimationCom";
    return 1;
}

int lua_geniusx_EntityCom_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"gx.EntityCom",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        GX::EntityCom* ret = GX::EntityCom::create();
        object_to_luaval<GX::EntityCom>(tolua_S, "gx.EntityCom",(GX::EntityCom*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_EntityCom_create'.",&tolua_err);
#endif
    return 0;
}
int lua_geniusx_EntityCom_constructor(lua_State* tolua_S)
{
    int argc = 0;
    GX::EntityCom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new GX::EntityCom();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"gx.EntityCom");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "EntityCom",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_EntityCom_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_geniusx_EntityCom_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (EntityCom)");
    return 0;
}

int lua_register_geniusx_EntityCom(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"gx.EntityCom");
    tolua_cclass(tolua_S,"EntityCom","gx.EntityCom","gx.Com",nullptr);

    tolua_beginmodule(tolua_S,"EntityCom");
        tolua_function(tolua_S,"new",lua_geniusx_EntityCom_constructor);
        tolua_function(tolua_S,"create", lua_geniusx_EntityCom_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(GX::EntityCom).name();
    g_luaType[typeName] = "gx.EntityCom";
    g_typeCast["EntityCom"] = "gx.EntityCom";
    return 1;
}

int lua_geniusx_DragCom_setLocalZOrder(lua_State* tolua_S)
{
    int argc = 0;
    GX::DragCom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.DragCom",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::DragCom*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_DragCom_setLocalZOrder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setLocalZOrder(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setLocalZOrder",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_DragCom_setLocalZOrder'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_DragCom_setTouchBehavior(lua_State* tolua_S)
{
    int argc = 0;
    GX::DragCom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.DragCom",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::DragCom*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_DragCom_setTouchBehavior'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        bool arg0;
        bool arg1;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->setTouchBehavior(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTouchBehavior",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_DragCom_setTouchBehavior'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_DragCom_setGlobalZOrder(lua_State* tolua_S)
{
    int argc = 0;
    GX::DragCom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.DragCom",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::DragCom*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_DragCom_setGlobalZOrder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setGlobalZOrder(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setGlobalZOrder",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_DragCom_setGlobalZOrder'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_DragCom_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"gx.DragCom",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        GX::DragCom* ret = GX::DragCom::create();
        object_to_luaval<GX::DragCom>(tolua_S, "gx.DragCom",(GX::DragCom*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_DragCom_create'.",&tolua_err);
#endif
    return 0;
}
int lua_geniusx_DragCom_constructor(lua_State* tolua_S)
{
    int argc = 0;
    GX::DragCom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new GX::DragCom();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"gx.DragCom");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "DragCom",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_DragCom_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_geniusx_DragCom_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DragCom)");
    return 0;
}

int lua_register_geniusx_DragCom(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"gx.DragCom");
    tolua_cclass(tolua_S,"DragCom","gx.DragCom","gx.Com",nullptr);

    tolua_beginmodule(tolua_S,"DragCom");
        tolua_function(tolua_S,"new",lua_geniusx_DragCom_constructor);
        tolua_function(tolua_S,"setLocalZOrder",lua_geniusx_DragCom_setLocalZOrder);
        tolua_function(tolua_S,"setTouchBehavior",lua_geniusx_DragCom_setTouchBehavior);
        tolua_function(tolua_S,"setGlobalZOrder",lua_geniusx_DragCom_setGlobalZOrder);
        tolua_function(tolua_S,"create", lua_geniusx_DragCom_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(GX::DragCom).name();
    g_luaType[typeName] = "gx.DragCom";
    g_typeCast["DragCom"] = "gx.DragCom";
    return 1;
}

int lua_geniusx_DragSystem_constructor(lua_State* tolua_S)
{
    int argc = 0;
    GX::DragSystem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new GX::DragSystem();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"gx.DragSystem");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "DragSystem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_DragSystem_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_geniusx_DragSystem_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DragSystem)");
    return 0;
}

int lua_register_geniusx_DragSystem(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"gx.DragSystem");
    tolua_cclass(tolua_S,"DragSystem","gx.DragSystem","gx.System",nullptr);

    tolua_beginmodule(tolua_S,"DragSystem");
        tolua_function(tolua_S,"new",lua_geniusx_DragSystem_constructor);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(GX::DragSystem).name();
    g_luaType[typeName] = "gx.DragSystem";
    g_typeCast["DragSystem"] = "gx.DragSystem";
    return 1;
}

int lua_geniusx_NodeSystem_constructor(lua_State* tolua_S)
{
    int argc = 0;
    GX::NodeSystem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new GX::NodeSystem();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"gx.NodeSystem");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "NodeSystem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_NodeSystem_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_geniusx_NodeSystem_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (NodeSystem)");
    return 0;
}

int lua_register_geniusx_NodeSystem(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"gx.NodeSystem");
    tolua_cclass(tolua_S,"NodeSystem","gx.NodeSystem","gx.System",nullptr);

    tolua_beginmodule(tolua_S,"NodeSystem");
        tolua_function(tolua_S,"new",lua_geniusx_NodeSystem_constructor);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(GX::NodeSystem).name();
    g_luaType[typeName] = "gx.NodeSystem";
    g_typeCast["NodeSystem"] = "gx.NodeSystem";
    return 1;
}

int lua_geniusx_AnimationSystem_constructor(lua_State* tolua_S)
{
    int argc = 0;
    GX::AnimationSystem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new GX::AnimationSystem();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"gx.AnimationSystem");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "AnimationSystem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_AnimationSystem_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_geniusx_AnimationSystem_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (AnimationSystem)");
    return 0;
}

int lua_register_geniusx_AnimationSystem(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"gx.AnimationSystem");
    tolua_cclass(tolua_S,"AnimationSystem","gx.AnimationSystem","gx.System",nullptr);

    tolua_beginmodule(tolua_S,"AnimationSystem");
        tolua_function(tolua_S,"new",lua_geniusx_AnimationSystem_constructor);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(GX::AnimationSystem).name();
    g_luaType[typeName] = "gx.AnimationSystem";
    g_typeCast["AnimationSystem"] = "gx.AnimationSystem";
    return 1;
}

int lua_geniusx_EntitySystem_constructor(lua_State* tolua_S)
{
    int argc = 0;
    GX::EntitySystem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new GX::EntitySystem();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"gx.EntitySystem");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "EntitySystem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_EntitySystem_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_geniusx_EntitySystem_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (EntitySystem)");
    return 0;
}

int lua_register_geniusx_EntitySystem(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"gx.EntitySystem");
    tolua_cclass(tolua_S,"EntitySystem","gx.EntitySystem","gx.System",nullptr);

    tolua_beginmodule(tolua_S,"EntitySystem");
        tolua_function(tolua_S,"new",lua_geniusx_EntitySystem_constructor);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(GX::EntitySystem).name();
    g_luaType[typeName] = "gx.EntitySystem";
    g_typeCast["EntitySystem"] = "gx.EntitySystem";
    return 1;
}

int lua_geniusx_GameSystem_parserFTUEData(lua_State* tolua_S)
{
    int argc = 0;
    GX::GameSystem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.GameSystem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::GameSystem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_GameSystem_parserFTUEData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        GX::FTUEData* arg0;

        ok &= luaval_to_object<GX::FTUEData>(tolua_S, 2, "gx.FTUEData",&arg0);
        if(!ok)
            return 0;
        cobj->parserFTUEData(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "parserFTUEData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_GameSystem_parserFTUEData'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_GameSystem_saveFTUEToServer(lua_State* tolua_S)
{
    int argc = 0;
    GX::GameSystem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.GameSystem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::GameSystem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_GameSystem_saveFTUEToServer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        GX::FTUEData* arg0;

        ok &= luaval_to_object<GX::FTUEData>(tolua_S, 2, "gx.FTUEData",&arg0);
        if(!ok)
            return 0;
        cobj->saveFTUEToServer(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "saveFTUEToServer",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_GameSystem_saveFTUEToServer'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_GameSystem_update(lua_State* tolua_S)
{
    int argc = 0;
    GX::GameSystem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.GameSystem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::GameSystem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_GameSystem_update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->update(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_GameSystem_update'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_GameSystem_init(lua_State* tolua_S)
{
    int argc = 0;
    GX::GameSystem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.GameSystem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::GameSystem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_GameSystem_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->init();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_GameSystem_init'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_GameSystem_assertionFailed(lua_State* tolua_S)
{
    int argc = 0;
    GX::GameSystem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.GameSystem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::GameSystem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_GameSystem_assertionFailed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        long arg3;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_std_string(tolua_S, 3,&arg1);

        ok &= luaval_to_std_string(tolua_S, 4,&arg2);

        ok &= luaval_to_long(tolua_S, 5, &arg3);
        if(!ok)
            return 0;
        cobj->assertionFailed(arg0, arg1, arg2, arg3);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "assertionFailed",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_GameSystem_assertionFailed'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_GameSystem_willDoFTUE(lua_State* tolua_S)
{
    int argc = 0;
    GX::GameSystem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.GameSystem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::GameSystem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_GameSystem_willDoFTUE'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        GX::FTUEData* arg0;

        ok &= luaval_to_object<GX::FTUEData>(tolua_S, 2, "gx.FTUEData",&arg0);
        if(!ok)
            return 0;
        bool ret = cobj->willDoFTUE(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "willDoFTUE",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_GameSystem_willDoFTUE'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_GameSystem_showFTUEUI(lua_State* tolua_S)
{
    int argc = 0;
    GX::GameSystem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.GameSystem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::GameSystem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_GameSystem_showFTUEUI'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        GX::FTUEData* arg0;

        ok &= luaval_to_object<GX::FTUEData>(tolua_S, 2, "gx.FTUEData",&arg0);
        if(!ok)
            return 0;
        bool ret = cobj->showFTUEUI(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "showFTUEUI",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_GameSystem_showFTUEUI'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_GameSystem_getECS(lua_State* tolua_S)
{
    int argc = 0;
    GX::GameSystem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.GameSystem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::GameSystem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_GameSystem_getECS'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        GX::ECSManager* ret = cobj->getECS();
        object_to_luaval<GX::ECSManager>(tolua_S, "gx.ECSManager",(GX::ECSManager*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getECS",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_GameSystem_getECS'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_GameSystem_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"gx.GameSystem",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        GX::GameSystem* ret = GX::GameSystem::getInstance();
        object_to_luaval<GX::GameSystem>(tolua_S, "gx.GameSystem",(GX::GameSystem*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_GameSystem_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_geniusx_GameSystem_constructor(lua_State* tolua_S)
{
    int argc = 0;
    GX::GameSystem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new GX::GameSystem();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"gx.GameSystem");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "GameSystem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_GameSystem_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_geniusx_GameSystem_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GameSystem)");
    return 0;
}

int lua_register_geniusx_GameSystem(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"gx.GameSystem");
    tolua_cclass(tolua_S,"GameSystem","gx.GameSystem","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"GameSystem");
        tolua_function(tolua_S,"new",lua_geniusx_GameSystem_constructor);
        tolua_function(tolua_S,"parserFTUEData",lua_geniusx_GameSystem_parserFTUEData);
        tolua_function(tolua_S,"saveFTUEToServer",lua_geniusx_GameSystem_saveFTUEToServer);
        tolua_function(tolua_S,"update",lua_geniusx_GameSystem_update);
        tolua_function(tolua_S,"init",lua_geniusx_GameSystem_init);
        tolua_function(tolua_S,"assertionFailed",lua_geniusx_GameSystem_assertionFailed);
        tolua_function(tolua_S,"willDoFTUE",lua_geniusx_GameSystem_willDoFTUE);
        tolua_function(tolua_S,"showFTUEUI",lua_geniusx_GameSystem_showFTUEUI);
        tolua_function(tolua_S,"getECS",lua_geniusx_GameSystem_getECS);
        tolua_function(tolua_S,"getInstance", lua_geniusx_GameSystem_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(GX::GameSystem).name();
    g_luaType[typeName] = "gx.GameSystem";
    g_typeCast["GameSystem"] = "gx.GameSystem";
    return 1;
}

int lua_geniusx_Resource_addResourceReference(lua_State* tolua_S)
{
    int argc = 0;
    GX::Resource* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Resource",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Resource*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Resource_addResourceReference'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::ValueMap arg0;

        ok &= luaval_to_ccvaluemap(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->addResourceReference(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addResourceReference",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Resource_addResourceReference'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Resource_stopUpdateResource(lua_State* tolua_S)
{
    int argc = 0;
    GX::Resource* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Resource",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Resource*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Resource_stopUpdateResource'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->stopUpdateResource();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "stopUpdateResource",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Resource_stopUpdateResource'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Resource_getResourceReference(lua_State* tolua_S)
{
    int argc = 0;
    GX::Resource* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Resource",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Resource*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Resource_getResourceReference'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        int ret = cobj->getResourceReference(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getResourceReference",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Resource_getResourceReference'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Resource_unaddResourceAsyncHandler(lua_State* tolua_S)
{
    int argc = 0;
    GX::Resource* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Resource",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Resource*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Resource_unaddResourceAsyncHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->unaddResourceAsyncHandler();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "unaddResourceAsyncHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Resource_unaddResourceAsyncHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Resource_removeResourceReference(lua_State* tolua_S)
{
    int argc = 0;
    GX::Resource* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Resource",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Resource*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Resource_removeResourceReference'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::vector<std::string> arg0;

        ok &= luaval_to_std_vector_string(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->removeResourceReference(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeResourceReference",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Resource_removeResourceReference'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Resource_addResource(lua_State* tolua_S)
{
    int argc = 0;
    GX::Resource* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Resource",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Resource*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Resource_addResource'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        void* ret = cobj->addResource(arg0);
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_std_string(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        void* ret = cobj->addResource(arg0, arg1);
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addResource",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Resource_addResource'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Resource_removeAllUnusedResources(lua_State* tolua_S)
{
    int argc = 0;
    GX::Resource* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Resource",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Resource*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Resource_removeAllUnusedResources'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeAllUnusedResources();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeAllUnusedResources",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Resource_removeAllUnusedResources'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Resource_removeAllResources(lua_State* tolua_S)
{
    int argc = 0;
    GX::Resource* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Resource",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Resource*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Resource_removeAllResources'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeAllResources();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeAllResources",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Resource_removeAllResources'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Resource_unupdateResourceReferenceAsyncHandler(lua_State* tolua_S)
{
    int argc = 0;
    GX::Resource* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Resource",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Resource*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Resource_unupdateResourceReferenceAsyncHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->unupdateResourceReferenceAsyncHandler();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "unupdateResourceReferenceAsyncHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Resource_unupdateResourceReferenceAsyncHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Resource_removeResourceForKey(lua_State* tolua_S)
{
    int argc = 0;
    GX::Resource* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Resource",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Resource*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Resource_removeResourceForKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->removeResourceForKey(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeResourceForKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Resource_removeResourceForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Resource_removeResource(lua_State* tolua_S)
{
    int argc = 0;
    GX::Resource* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Resource",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Resource*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Resource_removeResource'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        void* arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR void*;
        if(!ok)
            return 0;
        cobj->removeResource(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeResource",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Resource_removeResource'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Resource_getResourceCache(lua_State* tolua_S)
{
    int argc = 0;
    GX::Resource* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Resource",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Resource*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Resource_getResourceCache'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        GX::ResourceCache* ret = cobj->getResourceCache();
        object_to_luaval<GX::ResourceCache>(tolua_S, "gx.ResourceCache",(GX::ResourceCache*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getResourceCache",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Resource_getResourceCache'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Resource_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"gx.Resource",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        GX::Resource* ret = GX::Resource::getInstance();
        object_to_luaval<GX::Resource>(tolua_S, "gx.Resource",(GX::Resource*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Resource_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_geniusx_Resource_constructor(lua_State* tolua_S)
{
    int argc = 0;
    GX::Resource* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new GX::Resource();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"gx.Resource");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "Resource",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Resource_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_geniusx_Resource_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Resource)");
    return 0;
}

int lua_register_geniusx_Resource(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"gx.Resource");
    tolua_cclass(tolua_S,"Resource","gx.Resource","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"Resource");
        tolua_function(tolua_S,"new",lua_geniusx_Resource_constructor);
        tolua_function(tolua_S,"addResourceReference",lua_geniusx_Resource_addResourceReference);
        tolua_function(tolua_S,"stopUpdateResource",lua_geniusx_Resource_stopUpdateResource);
        tolua_function(tolua_S,"getResourceReference",lua_geniusx_Resource_getResourceReference);
        tolua_function(tolua_S,"unaddResourceAsyncHandler",lua_geniusx_Resource_unaddResourceAsyncHandler);
        tolua_function(tolua_S,"removeResourceReference",lua_geniusx_Resource_removeResourceReference);
        tolua_function(tolua_S,"addResource",lua_geniusx_Resource_addResource);
        tolua_function(tolua_S,"removeAllUnusedResources",lua_geniusx_Resource_removeAllUnusedResources);
        tolua_function(tolua_S,"removeAllResources",lua_geniusx_Resource_removeAllResources);
        tolua_function(tolua_S,"unupdateResourceReferenceAsyncHandler",lua_geniusx_Resource_unupdateResourceReferenceAsyncHandler);
        tolua_function(tolua_S,"removeResourceForKey",lua_geniusx_Resource_removeResourceForKey);
        tolua_function(tolua_S,"removeResource",lua_geniusx_Resource_removeResource);
        tolua_function(tolua_S,"getResourceCache",lua_geniusx_Resource_getResourceCache);
        tolua_function(tolua_S,"getInstance", lua_geniusx_Resource_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(GX::Resource).name();
    g_luaType[typeName] = "gx.Resource";
    g_typeCast["Resource"] = "gx.Resource";
    return 1;
}

int lua_geniusx_DataBase_executeSql(lua_State* tolua_S)
{
    int argc = 0;
    GX::DataBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.DataBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::DataBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_DataBase_executeSql'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->executeSql(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "executeSql",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_DataBase_executeSql'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_DataBase_openDataScoure(lua_State* tolua_S)
{
    int argc = 0;
    GX::DataBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.DataBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::DataBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_DataBase_openDataScoure'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->openDataScoure();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "openDataScoure",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_DataBase_openDataScoure'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_DataBase_selectDataWithArray(lua_State* tolua_S)
{
    int argc = 0;
    GX::DataBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.DataBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::DataBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_DataBase_selectDataWithArray'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cocos2d::Value ret = cobj->selectDataWithArray(arg0);
        ccvalue_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "selectDataWithArray",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_DataBase_selectDataWithArray'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_DataBase_selectDataWithInteger(lua_State* tolua_S)
{
    int argc = 0;
    GX::DataBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.DataBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::DataBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_DataBase_selectDataWithInteger'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        int ret = cobj->selectDataWithInteger(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "selectDataWithInteger",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_DataBase_selectDataWithInteger'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_DataBase_selectDataWithString(lua_State* tolua_S)
{
    int argc = 0;
    GX::DataBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.DataBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::DataBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_DataBase_selectDataWithString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        std::string ret = cobj->selectDataWithString(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "selectDataWithString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_DataBase_selectDataWithString'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_DataBase_destroyInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"gx.DataBase",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        GX::DataBase::destroyInstance();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "destroyInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_DataBase_destroyInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_geniusx_DataBase_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"gx.DataBase",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        GX::DataBase* ret = GX::DataBase::getInstance();
        object_to_luaval<GX::DataBase>(tolua_S, "gx.DataBase",(GX::DataBase*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_DataBase_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_geniusx_DataBase_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DataBase)");
    return 0;
}

int lua_register_geniusx_DataBase(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"gx.DataBase");
    tolua_cclass(tolua_S,"DataBase","gx.DataBase","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"DataBase");
        tolua_function(tolua_S,"executeSql",lua_geniusx_DataBase_executeSql);
        tolua_function(tolua_S,"openDataScoure",lua_geniusx_DataBase_openDataScoure);
        tolua_function(tolua_S,"selectDataWithArray",lua_geniusx_DataBase_selectDataWithArray);
        tolua_function(tolua_S,"selectDataWithInteger",lua_geniusx_DataBase_selectDataWithInteger);
        tolua_function(tolua_S,"selectDataWithString",lua_geniusx_DataBase_selectDataWithString);
        tolua_function(tolua_S,"destroyInstance", lua_geniusx_DataBase_destroyInstance);
        tolua_function(tolua_S,"getInstance", lua_geniusx_DataBase_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(GX::DataBase).name();
    g_luaType[typeName] = "gx.DataBase";
    g_typeCast["DataBase"] = "gx.DataBase";
    return 1;
}

int lua_geniusx_Localization_getStr(lua_State* tolua_S)
{
    int argc = 0;
    GX::Localization* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Localization",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Localization*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Localization_getStr'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        std::string ret = cobj->getStr(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getStr",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Localization_getStr'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Localization_resetData(lua_State* tolua_S)
{
    int argc = 0;
    GX::Localization* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Localization",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Localization*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Localization_resetData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->resetData();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "resetData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Localization_resetData'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Localization_loadStringsFrom(lua_State* tolua_S)
{
    int argc = 0;
    GX::Localization* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Localization",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Localization*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Localization_loadStringsFrom'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->loadStringsFrom(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "loadStringsFrom",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Localization_loadStringsFrom'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Localization_SaveLocalStrToDB(lua_State* tolua_S)
{
    int argc = 0;
    GX::Localization* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Localization",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Localization*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Localization_SaveLocalStrToDB'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->SaveLocalStrToDB();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "SaveLocalStrToDB",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Localization_SaveLocalStrToDB'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Localization_setData(lua_State* tolua_S)
{
    int argc = 0;
    GX::Localization* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"gx.Localization",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GX::Localization*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_geniusx_Localization_setData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::ValueMap arg0;

        ok &= luaval_to_ccvaluemap(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setData(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Localization_setData'.",&tolua_err);
#endif

    return 0;
}
int lua_geniusx_Localization_destroyInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"gx.Localization",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        GX::Localization::destroyInstance();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "destroyInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Localization_destroyInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_geniusx_Localization_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"gx.Localization",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        GX::Localization* ret = GX::Localization::getInstance();
        object_to_luaval<GX::Localization>(tolua_S, "gx.Localization",(GX::Localization*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Localization_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_geniusx_Localization_constructor(lua_State* tolua_S)
{
    int argc = 0;
    GX::Localization* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new GX::Localization();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"gx.Localization");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "Localization",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_geniusx_Localization_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_geniusx_Localization_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Localization)");
    return 0;
}

int lua_register_geniusx_Localization(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"gx.Localization");
    tolua_cclass(tolua_S,"Localization","gx.Localization","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"Localization");
        tolua_function(tolua_S,"new",lua_geniusx_Localization_constructor);
        tolua_function(tolua_S,"getStr",lua_geniusx_Localization_getStr);
        tolua_function(tolua_S,"resetData",lua_geniusx_Localization_resetData);
        tolua_function(tolua_S,"loadStringsFrom",lua_geniusx_Localization_loadStringsFrom);
        tolua_function(tolua_S,"SaveLocalStrToDB",lua_geniusx_Localization_SaveLocalStrToDB);
        tolua_function(tolua_S,"setData",lua_geniusx_Localization_setData);
        tolua_function(tolua_S,"destroyInstance", lua_geniusx_Localization_destroyInstance);
        tolua_function(tolua_S,"getInstance", lua_geniusx_Localization_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(GX::Localization).name();
    g_luaType[typeName] = "gx.Localization";
    g_typeCast["Localization"] = "gx.Localization";
    return 1;
}
TOLUA_API int register_all_geniusx(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"gx",0);
	tolua_beginmodule(tolua_S,"gx");

	lua_register_geniusx_System(tolua_S);
	lua_register_geniusx_AnimationSystem(tolua_S);
	lua_register_geniusx_Com(tolua_S);
	lua_register_geniusx_NodeCom(tolua_S);
	lua_register_geniusx_NodeSystem(tolua_S);
	lua_register_geniusx_Localization(tolua_S);
	lua_register_geniusx_SystemScriptData(tolua_S);
	lua_register_geniusx_DragSystem(tolua_S);
	lua_register_geniusx_ComData(tolua_S);
	lua_register_geniusx_ECSManager(tolua_S);
	lua_register_geniusx_Resource(tolua_S);
	lua_register_geniusx_DragCom(tolua_S);
	lua_register_geniusx_ComScriptData(tolua_S);
	lua_register_geniusx_DataBase(tolua_S);
	lua_register_geniusx_Entity(tolua_S);
	lua_register_geniusx_EntityCom(tolua_S);
	lua_register_geniusx_GameSystem(tolua_S);
	lua_register_geniusx_Touch(tolua_S);
	lua_register_geniusx_AnimationCom(tolua_S);
	lua_register_geniusx_EntitySystem(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

