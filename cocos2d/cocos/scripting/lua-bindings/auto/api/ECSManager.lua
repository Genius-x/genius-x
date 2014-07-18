
--------------------------------
-- @module ECSManager
-- @extend Ref

--------------------------------
-- @function [parent=#ECSManager] unregisterCom 
-- @param self
-- @param #string str
        
--------------------------------
-- @function [parent=#ECSManager] getAllEntitiesPosessingCom 
-- @param self
-- @param #string str
-- @return array_table#array_table ret (return value: array_table)
        
--------------------------------
-- @function [parent=#ECSManager] update 
-- @param self
-- @param #float float
        
--------------------------------
-- @function [parent=#ECSManager] removeComFromEntity 
-- @param self
-- @param #string str
-- @param #gx.Entity entity
        
--------------------------------
-- @function [parent=#ECSManager] removeEntity 
-- @param self
-- @param #gx.Entity entity
        
--------------------------------
-- @function [parent=#ECSManager] removeAllCom 
-- @param self
        
--------------------------------
-- @function [parent=#ECSManager] registerCom 
-- @param self
-- @param #gx.Com com
        
--------------------------------
-- @function [parent=#ECSManager] registerSystem 
-- @param self
-- @param #gx.System system
        
--------------------------------
-- @function [parent=#ECSManager] addComToEntity 
-- @param self
-- @param #gx.Com com
-- @param #gx.Entity entity
        
--------------------------------
-- overload function: createEntity(string)
--          
-- overload function: createEntity()
--          
-- @function [parent=#ECSManager] createEntity
-- @param self
-- @param #string str
-- @return Entity#Entity ret (retunr value: gx.Entity)

--------------------------------
-- @function [parent=#ECSManager] unregisterSystem 
-- @param self
-- @param #string str
        
--------------------------------
-- @function [parent=#ECSManager] create 
-- @param self
-- @return ECSManager#ECSManager ret (return value: gx.ECSManager)
        
--------------------------------
-- @function [parent=#ECSManager] ECSManager 
-- @param self
        
return nil
