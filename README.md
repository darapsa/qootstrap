# C++ Plugin for making QML module presentations easy to customise the way a [Bootstrap](https://getbootstrap.com) app can be.

# Building

## Getting

```sh
$ git clone git://darapsa.org/qootstrap.git
$ cd qootstrap
$ git submodule init
$ git submodule update
$ mkdir build
$ cd build
```

## Configuring, compiling, linking and installing for various target hosts

```sh
$ /Applications/Qt/6.10.1/android_arm64_v8a/bin/qmake ../qootstrap.pro CONFIG+=release ANDROID_ABIS=arm64-v8a ANDROID_API_VERSION=21
$ make
$ sed -i '' -e 's/libs\/arm64-v8a/Applications\/Qt\/6.10.1\/android_arm64_v8a\/qml\/Bootstrap/g'
$ make install
```

or

```sh
$ /Applications/Qt/6.10.1/wasm_multithread/bin/qmake ../qootstrap.pro CONFIG+=release
$ emmake make
$ emmake make install
```

or

```sh
$ /Applications/Qt/QtDesignStudio/qt6_design_studio_reduced_version/bin/qmake ../qootstrap.pro CONFIG+=release
$ make
$ make install
```

or so on.
