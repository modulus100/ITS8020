# ITS8020
Assignment [description](https://gitlab.cs.ttu.ee/henvas/its8020-materials/-/tree/master/assignment/watch)  

## Setup
Linux dev setup is based on [this](https://github.com/maliksahil/docker-ubuntu-sahil) repository  
[Post](https://www.codemag.com/article/1811021/Docker-for-Developers) about Linux dev setup  


## Build
Go to the project root and create a folder for build files
```
cd ITS8020
mkdir cmake-build-debug
```

Init project with cmake, it will generate all requited files to build the project
```
cd cmake-build-debug
cmake ..
```
Build the project
```
make
```

## Run
Run compiled program from the **cmake-build-debug**
```
./watch_command_posix
```

## Clean the build
```
make clean
```

