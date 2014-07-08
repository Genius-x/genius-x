
Genius-x
==========
An Entity Component System framework based on Cocos2d-x, now the supported version is 3.2 alpha0.


How to run?
-------------
Put the genius-x directory to the root directory of your project, and then add genius-x/build/genius-x.xcodeproj to your project. Now it's only suppoert XCode, but we should support Windows soon.

Feature
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
  
  
Discussion
-------------
you may leave a message at my blog: http://elvisco.de


Please enjoy this.
-------------------
