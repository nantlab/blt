#!/bin/sh

cd ../..
git pull origin master
cd qt/bltControl
rm -rf build
mkdir build
cd build
qmake ..
make
