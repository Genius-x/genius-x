//
//  LevelDataSystem.cpp
//  sg
//
//  Created by Elvis on 3/26/14.
//
//

#include "LevelDataSystem.h"
#include "../Events/GameOverEvent.h"
#include "../Events/MonsterAddEvent.h"

LevelDataSystem::LevelDataSystem()
:GX::System("LevelDataSystem",LevelDataCom::_TYPE)
{
    
}

GX::System* LevelDataSystem::cloneEmpty() const
{
    return new LevelDataSystem();
}

void LevelDataSystem::onAttached()
{
    _levelData=(LevelDataCom*)getComByType(LevelDataCom::_TYPE);
    //1,通知Progress开始计时
    
    //初始化
    if (_levelData->data.size()>0) {
        _currentPhaseData=_levelData->data.at(0);
        _levelData->data.erase(_levelData->data.begin());
        
        _currentPhaseTime = 0;
        _currentPhaseInterval=0;
        _totalTime=0;
        _currentCount=0;
        _isOver=false;
        //怪物阶段
        if (_currentPhaseData.data.size()>0) {
            _currentCount=_currentPhaseData.data.size();
            _currentPhaseInterval=_currentPhaseData.durence/_currentPhaseData.data.size();
        }
    }
}

//  1   1   1   1   1
//  |---|---|---|---|---|
void LevelDataSystem::update(float dt)
{
    if (_isOver) {
        return;
    }
    
    //时间到，游戏结束
    if (_totalTime>=_levelData->durence) {
        _isOver=true;
        GameOverEvent* event=new GameOverEvent(true);
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchEvent(event);
        return;
    }
    
    if (_currentPhaseData.durence<_currentPhaseTime) {
        //初始化
        if (_levelData->data.size()>0) {
            _currentPhaseData=_levelData->data.at(0);
            _levelData->data.erase(_levelData->data.begin());
            
            _currentPhaseTime = 0;
            _currentPhaseInterval=0;
            //怪物阶段
            if (_currentPhaseData.data.size()>0) {
                _currentCount=_currentPhaseData.data.size();
                _currentPhaseInterval=_currentPhaseData.durence/_currentPhaseData.data.size();
            }
        }
    }
    
    if (_currentPhaseData.data.size()>0) {
        int n=_currentPhaseTime/_currentPhaseInterval+1;
        //出怪
        if (_currentPhaseData.data.size()>_currentCount-n) {
            MonsterAddEvent* event=new MonsterAddEvent(_currentPhaseData.data.at(0));
            cocos2d::Director::getInstance()->getEventDispatcher()->dispatchEvent(event);
            
            _currentPhaseData.data.erase(_currentPhaseData.data.begin());
        }
    }
    
    _totalTime+=dt;
    _currentPhaseTime+=dt;
}