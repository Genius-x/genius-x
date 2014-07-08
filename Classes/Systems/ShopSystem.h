//
//  ShopSystem.h
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#ifndef __sg__ShopSystem__
#define __sg__ShopSystem__

#include "genius-x.h"
#include "ui/UIWidget.h"
#include "extensions/cocos-ext.h"
#include "../Coms/ShopCom.h"
#include "../Coms/PlayerCom.h"

class ShopSystem : public GX::System,public cocos2d::extension::TableViewDataSource,public cocos2d::extension::TableViewDelegate
{
public:
    ShopSystem();
    
protected:
    virtual System* cloneEmpty() const;
    
    virtual void onAttached() override;
    
    virtual void scrollViewDidScroll(cocos2d::extension::ScrollView* view) {};
    virtual void scrollViewDidZoom(cocos2d::extension::ScrollView* view) {};
    virtual void tableCellTouched(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell);
    virtual Size cellSizeForTable(cocos2d::extension::TableView *table);
    virtual cocos2d::extension::TableViewCell* tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx);
    virtual ssize_t numberOfCellsInTableView(cocos2d::extension::TableView *table);
    
    ShopCom* _level;
    PlayerCom* _player;
};

#endif /* defined(__sg__ShopSystem__) */
