//
//  LevelSystem.h
//  sg
//
//  Created by Elvis on 3/24/14.
//
//

#ifndef __sg__LevelSystem__
#define __sg__LevelSystem__

#include "genius-x.h"
#include "ui/UIWidget.h"
#include "extensions/cocos-ext.h"
#include "../Coms/LevelCom.h"
#include "../Coms/LevelDataCom.h"

class LevelSystem : public GX::System,public cocos2d::extension::TableViewDataSource,public cocos2d::extension::TableViewDelegate
{
public:
    LevelSystem();
    
protected:
    virtual System* cloneEmpty() const;
    
    virtual void onInit() override;
    virtual void onAttached() override;
    virtual void onDeattached() override;
    
    virtual void update(float dt) override;
    virtual void onComsChanged() override;
    
    virtual void scrollViewDidScroll(cocos2d::extension::ScrollView* view) {};
    virtual void scrollViewDidZoom(cocos2d::extension::ScrollView* view) {};
    virtual void tableCellTouched(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell);
    virtual Size cellSizeForTable(cocos2d::extension::TableView *table);
    virtual cocos2d::extension::TableViewCell* tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx);
    virtual ssize_t numberOfCellsInTableView(cocos2d::extension::TableView *table);
    
    LevelCom* _level;
};


#endif /* defined(__sg__LevelSystem__) */


