# SBX
Multithreaded, data oriented, entity-component-system based sandbox world with OpenCV visualizer (for now, later OpenGL) and many other features
## Features
- Entity-Component-System architecture
- Templates & interfaces for all components and systems
- Command line colorful debug & info logger (spdlog)
- Command line parser for live user interaction
- Data driven approach - arrays of components in unordered hash tables for O(1) lookup/add/remove
- visualizer system implemented with OpenCV (for now, later OpenGL)
- Multithreaded systems - each system works asynchronously on a separate thread
- Synchronized target refresh rate across all systems
- Basic kinematics - orbiting planets with gravity demo

![blobs](https://github.com/zdenyhraz/SBX/blob/master/pics/2.png?raw=true)
