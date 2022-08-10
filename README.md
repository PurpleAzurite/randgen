# randgen
A simple random number generator using Qt

![](https://i.imgur.com/3enbbqs.png)

### Requirements
```
Qt 5.0+
Ninja (Optional)
```

### Buiding
```
git clone https://github.com/PurpleAzurite/randgen.git
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release -G Ninja ../
ninja
```
Alternatively, open then the project in QtCreator and use the IDE's build feature.

### Deploying on Windows
Windeploy is Qt's deployment kit shipped with any installation of Qt. It's usually located in C:\Qt{version}\{compiler}\bin\windeploy.exe
```
windeploy randgen.exe
```
