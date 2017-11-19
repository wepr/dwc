# Lanthaneum

Lanthaneum is a new experimental coin based on the modified Cryptonote PoW algorithm called SoftCrypton.

Lanthaneum was designed as a light alternative to current Cryptonote-based coins.
It should be mineable even with low-end PCs, including phones and tablets.
Blockchain size and network load plan to stay at reasonable level as well.
Transfer's tiny flat fee is another key point of Lanthaneum for everyday use.

## Building Lanthaneum

### On Windows:

You have to install follow software:

#### MSVC 2015 Community Edition 
http://download.microsoft.com/download/0/B/C/0BC321A4-013F-479C-84E6-4A2F90B11269/vs2015.com_enu.iso
!!! IMPORTANT !!!
You will need to uninstall vs2015 update3 then install vs2015 rtm!
Make sure to uncheck box "Visual Studio 2015 Update 3" else update 3 will be downloaded automatically!!!

#### CMake 2.8.6 or later
https://cmake.org/files/v3.10/cmake-3.10.0-rc5-win64-x64.msi

#### Boost 1.56 or later
https://dl.bintray.com/boostorg/release/1.65.1/source/boost_1_65_1.7z
or
https://dl.bintray.com/boostorg/release/1.65.1/source/boost_1_65_1.zip

Download source code from:
https://github.com/monselice/ZZL
or clone from Github
git clone https://github.com/monselice/ZZL.git zzl

To build Lanthaneum apps, change to a directory where this file is located, and run commands:
------------
x:
cd x:\git\zzl\
mkdir build
cd build

cmake -G "Visual Studio 14 2015 Win64" -DBOOST_ROOT=X:/boost_1_65_1 -DBOOST_LIBRARYDIR=X:/boost_1_65_1/lib64-msvc-14.0 ..
MSBuild Lanthaneum.sln /p:Configuration=release /m
------------

### On Linux:

Dependencies: GCC 4.7.3 or later, CMake 2.8.6 or later, and Boost 1.56 or later.

You may download them from:

- http://gcc.gnu.org/
- http://www.cmake.org/
- http://www.boost.org/

Alternatively, it may be possible to install them using a package manager.

To build:
Run these commands:

------------
sudo apt install git
sudo apt install cmake
sudo apt install build-essential
### DOWNLOAD BOOST >> https://dl.bintray.com/boostorg/release/1.65.1/source/boost_1_65_1.tar.bz2
tar --bzip2 -xf ~/Downloads/boost_1_65_1.tar.bz2

cd ~
mkdir boost
cd boost
cd boost/boost_1_65_1
./bootstrap.sh

cd ~
git clone https://github.com/monselice/ZZL.git zzl
cd zzl
mkdir build
cd build
cmake ..
cd ..
make
------------

The resulting executables can be found in `zzl/build/release/src`.


