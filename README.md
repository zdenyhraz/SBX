# SBX
Multithreaded, data oriented, entity-component-system based sandbox world with OpenGL + OpenCV renderer and many other features
## Features
- Entity-Component-System architecture
- Templates & interfaces for all components and systems
- Command line colorful debug & info logger (spdlog)
- Command line parser for live user interaction
- Data driven approach - arrays of components in unordered hash tables for O(1) lookup/add/remove
- Render system implemented with OpenGL & OpenCV
- Multithreaded systems - each system works asynchronously on a separate thread
- Synchronized target refresh rate across all systems
- Dynamic render fps display for both renderers
- Basic kinematics - orbiting planets with gravity demo

![blobs](https://github.com/zdenyhraz/SBX/blob/master/pics/5.PNG?raw=true)

![blobs](https://github.com/zdenyhraz/SBX/blob/master/pics/4.png?raw=true)

![blobs](https://github.com/zdenyhraz/SBX/blob/master/pics/2.png?raw=true)

![blobs](https://github.com/zdenyhraz/SBX/blob/master/pics/3.png?raw=true)
