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

#ifndef __GX__Statistics__
#define __GX__Statistics__

#include "../GXMacros.h"
#include <functional>
#include <map>

NS_GX_BEGIN

/**
 * 支持开发中或发布后一些数据统计
 *
 * 开发状态:
 *  每个Entity的每个System执行了多长时间，每个System在所有对象中执行多长时间，整个游戏使用阶段和频率以决定应该优化哪些算法，或者异步处理
 *  统计纹理的使用，每一帧每个场景使用哪些纹理，占内存多少，占据多长时间，以决定对纹理的使用优化
 *
 * 发布后状态
 *  玩家每次游戏持续时间，在每个游戏界面停留时间，在每个界面的操作内容，操作步骤（记录System的Operate）
 *  每个目标和关卡花了多少时间，重复了多少次完成
 *
 */
class Statistics
{
    
};

NS_GX_END

#endif /* defined(__GX__Statistics__) */
