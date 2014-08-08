
Genius-x
==========
Genius-x是一个基于以属性为中心的游戏对象模型构建的游戏框架，它基于Cocos2d-x，目前支持使用C++/Lua两种语言进行开发，Genius-x最大的目标是要实现数据驱动，使程序中关于关卡设计的部分可以最大限度地从程序中抽离出来，让设计和程序以及其他相关人员进行更轻易地协同开发。

特别致谢
========
Genius-x最早于2014年在北京魂世界(SoulGame)公司的手游项目中使用，并在其授权下将其开源，在此非常感谢魂世界的对次项目的支持。

参考资料
========
# 《游戏引擎架构》
# 《我所理解的Cocos2d-x》
# 《游戏编程精粹(第6卷第4章)》
# 《A Data-Driven Game Object System》


怎样使用？
-------------
1，将根目录的genius-x目录拷贝至你的游戏目录中同cocos2d同级的目录，因为Genius-x会引用Cocos2d-x工程。
2，将genius-x/build目录下对应平台的工程文件添加引用至你的项目中。
3，添加搜索路径，这样才能找到头文件引用，例如在XCode中设置为$(SRCROOT)/../genius-x/genius。
4，添加静态库链接。

特性
---------
1. based on the Origin Entity Component System idea(Decoupbe the system from component,this make it diff from Component-based design).
2. automatic attching system to Entity,you only need concern component.So,
3. it's data-driven.
4. better performance,we make every Entity has it's own System instance,but still keep auto-attaching,you do not need care about System.
5. lua and javascript binding support.(progress....)
6. system ordered.

How to use?
---------------
1. create an Entity: ECSmanager::createEntity(); 
2. create you own Component which should be a subclass of ECS::Component , such as 'MyComponent'
3. create you System which should be a subclass of ECS::System
4. init the ECSManager: auto ecs=new ECSManager();
5. put all your system: ecs->addSystem(mySystem);
6. add component to Entity: ecs->addComponentToEntity(myComponent,myEntity);
7. call the update methed of ECSManager in your gameloop, such as the visit or update method of HelloWorldScene.
8. that's it!
  
  
讨论
-------------
you may leave a message at my blog: http://genius-x.org


Please enjoy this.
-------------------
