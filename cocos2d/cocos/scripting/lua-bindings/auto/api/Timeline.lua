
--------------------------------
-- @module Timeline
-- @extend Ref

--------------------------------
-- @function [parent=#Timeline] clone 
-- @param self
-- @return timeline::Timeline#timeline::Timeline ret (return value: ccs.timeline::Timeline)
        
--------------------------------
-- @function [parent=#Timeline] gotoFrame 
-- @param self
-- @param #int int
        
--------------------------------
-- @function [parent=#Timeline] setNode 
-- @param self
-- @param #cc.Node node
        
--------------------------------
-- @function [parent=#Timeline] getActionTimeline 
-- @param self
-- @return timeline::ActionTimeline#timeline::ActionTimeline ret (return value: ccs.timeline::ActionTimeline)
        
--------------------------------
-- @function [parent=#Timeline] insertFrame 
-- @param self
-- @param #ccs.timeline::Frame frame
-- @param #int int
        
--------------------------------
-- @function [parent=#Timeline] setActionTag 
-- @param self
-- @param #int int
        
--------------------------------
-- @function [parent=#Timeline] addFrame 
-- @param self
-- @param #ccs.timeline::Frame frame
        
--------------------------------
-- @function [parent=#Timeline] getFrames 
-- @param self
-- @return array_table#array_table ret (return value: array_table)
        
--------------------------------
-- @function [parent=#Timeline] getActionTag 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- @function [parent=#Timeline] getNode 
-- @param self
-- @return Node#Node ret (return value: cc.Node)
        
--------------------------------
-- @function [parent=#Timeline] removeFrame 
-- @param self
-- @param #ccs.timeline::Frame frame
        
--------------------------------
-- @function [parent=#Timeline] setActionTimeline 
-- @param self
-- @param #ccs.timeline::ActionTimeline actiontimeline
        
--------------------------------
-- @function [parent=#Timeline] stepToFrame 
-- @param self
-- @param #int int
        
--------------------------------
-- @function [parent=#Timeline] create 
-- @param self
-- @return timeline::Timeline#timeline::Timeline ret (return value: ccs.timeline::Timeline)
        
--------------------------------
-- @function [parent=#Timeline] Timeline 
-- @param self
        
return nil
