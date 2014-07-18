
--------------------------------
-- @module NodeCom
-- @extend Com

--------------------------------
-- @function [parent=#NodeCom] getNode 
-- @param self
-- @return Node#Node ret (return value: cc.Node)
        
--------------------------------
-- @function [parent=#NodeCom] getNodeByName 
-- @param self
-- @param #string str
-- @return Node#Node ret (return value: cc.Node)
        
--------------------------------
-- @function [parent=#NodeCom] setNode 
-- @param self
-- @param #cc.Node node
        
--------------------------------
-- @function [parent=#NodeCom] createTMXTiledMap 
-- @param self
-- @param #string str
-- @return TMXTiledMap#TMXTiledMap ret (return value: cc.TMXTiledMap)
        
--------------------------------
-- @function [parent=#NodeCom] create 
-- @param self
-- @return NodeCom#NodeCom ret (return value: gx.NodeCom)
        
--------------------------------
-- @function [parent=#NodeCom] createAtlasNode 
-- @param self
-- @param #string str
-- @param #int int
-- @param #int int
-- @param #int int
-- @return AtlasNode#AtlasNode ret (return value: cc.AtlasNode)
        
--------------------------------
-- overload function: createSprite(string, rect_table)
--          
-- overload function: createSprite(string)
--          
-- @function [parent=#NodeCom] createSprite
-- @param self
-- @param #string str
-- @param #rect_table rect
-- @return Sprite#Sprite ret (retunr value: cc.Sprite)

--------------------------------
-- @function [parent=#NodeCom] createTMXTiledMapWithXML 
-- @param self
-- @param #string str
-- @param #string str
-- @return TMXTiledMap#TMXTiledMap ret (return value: cc.TMXTiledMap)
        
--------------------------------
-- @function [parent=#NodeCom] createTileMapAtlas 
-- @param self
-- @param #string str
-- @param #string str
-- @param #int int
-- @param #int int
-- @return TileMapAtlas#TileMapAtlas ret (return value: cc.TileMapAtlas)
        
--------------------------------
-- @function [parent=#NodeCom] createSpriteBatchNode 
-- @param self
-- @param #string str
-- @param #long long
-- @return SpriteBatchNode#SpriteBatchNode ret (return value: cc.SpriteBatchNode)
        
--------------------------------
-- @function [parent=#NodeCom] NodeCom 
-- @param self
        
return nil
