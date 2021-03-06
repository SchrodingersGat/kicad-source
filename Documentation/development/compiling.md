# Building KiCad from Source #
If you are a user and not a developer, please consider using one of the prebuilt packages
of KiCad which can be found at the [download][] page on the [KiCad website][].  Building KiCad
from source is not for the faint of heart and is not recommended unless you have reasonable
software development experience.  This document contains the instructions on how to build KiCad
from source on the supported platforms.  It is not intended as a guide for installing or building
[library dependencies](#library_dependencies).  Please consult your platforms documentation for
installing packages or the source code when building the library dependencies.  Currently the
supported platforms are Windows Versions 7-10, just about any version of Linux, and OSX
10.7-10.10.  You may be able to build KiCad on other platforms but it is not supported.  On
Windows and Linux the [GNU GCC][] is the only supported compiler and on OSX [Clang][] is the
only supported compiler.

[TOC]

# Development Tools # {#development_tools}

Before you begin building KiCad, there are a few tools required in addition to your compiler.
Some of these tools are required to build from source and some are optional.

## CMake Build Configuration Tool ## {#cmake}

[CMake][] is the build configuration and makefile generation tool used by KiCad.  It is required.


## GIT Version Control System ## {#git}

The official source code repository is hosted on [Launchpad][] and requires [git][] to get
the latest source. If you prefer to use [GitHub][] there is a read only mirror of the official
KiCad repository. Do not submit pull requests to GitHub. Changes should be sent to the KiCad
developer's [mailing list][] using `git format-patch` and attaching the patch with [PATCH] at
the beginning of the subject or using `git send-email` to send your commit directly to the
developer's [mailing list][].

## Doxygen Code Documentation Generator ## {#doxygen_section}

The KiCad source code is documented using [Doxygen][] which parses the KiCad source code files
and builds a dependency tree along with the source documentation into HTML.  Doxygen is only
required if you are going to build the KiCad documentation.

## SWIG Simplified Wrapper and Interface Generator ## {#swig}

[SWIG][] is used to generate the Python scripting language extensions for KiCad.  SWIG is not
required if you are not going to build the KiCad scripting extension.


# Library Dependencies # {#library_dependencies}

This section includes a list of library dependencies required to build KiCad.  It does not
include any dependencies of the libraries.  Please consult the library's documentation for any
additional dependencies.  Some of these libraries are optional depending on you build
configuration.  This is not a guide on how to install the library dependencies using you systems
package management tools or how to build the library from source.  Consult the appropriate
documentation to perform these tasks.

## wxWidgets Cross Platform GUI Library## {#wxwidgets}

[wxWidgets][] is the graphical user interface (GUI) library used by KiCad.  The current minimum
version is 3.0.0.  However, 3.0.2 should be used whenever possible as there are some known bugs
in prior versions that can cause problems on some platforms.  Please note that there are also
some platform specific patches that must be applied before building wxWidgets from source.  These
patches can be found in the [patches folder][] in the KiCad source.  These patches are named by
the wxWidgets version and platform name they should be applied against.  wxWidgets must be built
with the --with-opengl option.  If you installed the packaged version of wxWidgets on your system,
verify that it was built with this option.

## Boost C++ Libraries ## {#boost}

The [Boost][] C++ library is required only if you intend to build KiCad with the system installed
version of Boost instead of the default internally built version.  If you use the system installed
version of Boost, version 1.56 or greater is required.  Please note there are some platform
specific patches required to build a working Boost library.  These patches can be found in the
[patches folder][] in the KiCad source.  These patches are named by the platform name they should
be applied against.

## GLEW OpenGL Extension Wrangler Library ## {#glew}

The [OpenGL Extension Wrangler][GLEW] is an OpenGL helper library used by the KiCad graphics
abstraction library [GAL] and is always required to build KiCad.

## GLM OpenGL Mathematics Library  ## {#glm}

The [OpenGL Mathematics Library][GLM] is an OpenGL helper library used by the KiCad graphics
abstraction library [GAL] and is always required to build KiCad.

## GLUT OpenGL Utility Toolkit Library ## {#glut}

The [OpenGL Utility Toolkit][GLUT] is an OpenGL helper library used by the KiCad graphics
abstraction library [GAL] and is always required to build KiCad.

## Cairo 2D Graphics Library ## {#cairo}

The [Cairo][] 2D graphics library is used as a fallback rendering canvas when OpenGL is not
available and is always required to build KiCad.

## Python Programming Language ## {#python}

The [Python][] programming language is used to provide scripting support to KiCad.  It only needs
to be install if the [KiCad scripting](#kicad_scripting) build configuration option is enabled.

## wxPython Library ## {#wxpython}

The [wxPython][] library is used to provide a scripting console for Pcbnew.  It only needs to be
installed if the [wxPython scripting](#wxpython_scripting) build configuration option is enabled.
When building KiCad with wxPython support, make sure the version of the wxWidgets library and
the version of wxPython installed on your system are the same.  Mismatched versions have been
known to cause runtime issues.

## Curl Multi-Protocol File Transfer Library ## {#curl}

The [Curl Multi-Protocol File Transfer Library][libcurl] is used to provide secure internet
file transfer access for the [GitHub][] plug in.  This library only needs to be installed if
the GitHub plug build option is enabled.

# KiCad Build Configuration Options # {#build_opts}

KiCad has many build options that can be configured to build different options depending on
the availability of support for each option on a given platform.  This section documents
these options and their default values.

## Advanced Graphics Context ## {#graphics_context_opt}

The USE_WX_GRAPHICS_CONTEXT option replaces wxDC with wxGraphicsContext for graphics rendering.
This option is disabled by default.  Warning: the is experimental and has not been maintained
so use at your own risk.

## Graphics Context Overlay ## {#overlay_opt}

The USE_WX_OVERLAY option is used to enable the optional wxOverlay class for graphics rendering
on OSX.  This is enabled on OSX by default and disabled on all other platforms.

## Scripting Support ## {#scripting_opt}

The KICAD_SCRIPTING option is used to enable building the Python scripting support into Pcbnew.
This options is disabled by default.

## Scripting Module Support ## {#scripting_mod_opt}

The KICAD_SCRIPTING_MODULES option is used to enable building and installing the Python modules
supplied by KiCad.  This option is disabled by default.

## wxPython Scripting Support ## {#wxpython_opt}

The KICAD_SCRIPTING_WXPYTHON option is used to enable building the wxPython interface into
Pcbnew including the wxPython console.  This option is disabled by default.

## GitHub Plugin ## {#github_opt}

The BUILD_GITHUB_PLUGIN option is used to control if the GitHub plug in is built.  This option is
enabled by default.

## Integrated Spice simulator ## {#spice_opt}

The KICAD_SPICE option is used to control if the Spice simulator interface for Eeschema is built.  When
this option is enabled, it requires [ngspice][] to be available as a shared library.  This option is
disabled by default.

## New schematic file format ## {#sch_io_mgr_opt}

The KICAD_USE_SCH_IO_MANAGER option is used to control if the new Eeschema I/O manager for handling
schematic and symbol library I/O is enabled. This option is disabled by default.

## STEP/IGES support for the 3D viewer ## {#oce_opt}

The KICAD_USE_OCE is used for the 3D viewer plugin to support STEP and IGES 3D models. Build tools
and plugins related to OpenCascade Community Edition (OCE) are enabled with this option. When
enabled it requires [OCE][] to be available, and the location of the installed OCE library to be
passed via the OCE_DIR flag. This option is disabled by default.

## Demos and Examples ## {#demo_install_opt}

The KiCad source code includes some demos and examples to showcase the program. You can choose
whether install them or not with the KICAD_INSTALL_DEMOS option. You can also select where to
install them with the KICAD_DEMOS variable. On Linux the demos are installed in
$PREFIX/share/kicad/demos by default.

## Python Scripting Action Menu Support ## {#python_action_menu_opt}

The KICAD_SCRIPTING_ACTION_MENU option allows Python scripts to be added directly to the Pcbnew
menu.  This option is disabled by default.  Please note that this option is highly experimental
and can cause Pcbnew to crash if Python scripts create an invalid object state within Pcbnew.

## Setting the Build Version and Repository Name ## {#build_version_opt}

The KiCad version string is defined by the three CMake variables KICAD_VERSION, KICAD_BRANCH_NAME,
and KICAD_VERSION_EXTRA.  Variables KICAD_BRANCH_NAME and KICAD_VERSION_EXTRA are defined as empty
strings and can be set at configuration.  Unless the source branch is a stable release archive,
KICAD_VERSION is set to "no-vcs-found".  If an optional variable is not define, it is not appended
to the full version string.  If an optional variable is defined it is appended along with a leading
'-' to the full version string as follows:

    KICAD_VERSION[-KICAD_BRANCH_NAME][-KICAD_VERSION_EXTRA]

When the version string is set to "no-vcs-found", the build script automatically creates the
version string information from the [git][] repository information as follows:

    (2016-08-26 revision 67230ac)-master
     |                   |        |
     |                   |        branch name, "HEAD" if not on a branch,
     |                   |        or "unknown" if no .git present
     |                   |
     |                   abbreviated commit hash, or no-git if no .git
     |                   present
     |
     date of commit, or date of build if no .git present

# Getting the KiCad Source Code ## {#getting_src}

There are several ways to get the KiCad source.  If you want to build the stable version you
can down load the source archive from the [KiCad Launchpad][] developers page.  Use tar or some
other archive program to extract the source on your system.  If you are using tar, use the
following command:

    tar -xzf kicad_src_archive.tar.gz

If you are contributing directly to the KiCad project on Launchpad, you can create a local
copy on your machine by using the following command:

    git clone -b master https://git.launchpad.net/kicad

Here is a list of source links:

Stable release archive: https://launchpad.net/kicad/4.0/4.0.2/+download/kicad-4.0.2.tar.xz

Development branch: https://code.launchpad.net/~kicad-product-committers/kicad/+git/product-git/+ref/master

GitHub mirror: https://github.com/KiCad/kicad-source-mirror

# Building KiCad on Linux # {#build_linux}

To perform a full build on Linux, run the following commands:

    cd <your kicad source mirror>
    mkdir -p build/release
    mkdir build/debug               # Optional for debug build.
    cd build/release
    cmake -DCMAKE_BUILD_TYPE=Release \
          -DKICAD_SCRIPTING=ON \
          -DKICAD_SCRIPTING_MODULES=ON \
          -DKICAD_SCRIPTING_WXPYTHON=ON \
          ../../
    make
    sudo make install

If the CMake configuration fails, determine the missing dependencies and install them on your
system.  By default, CMake sets the install path on Linux to /usr/local.  Use the
CMAKE_INSTALL_PREFIX option to specify a different install path.

# Building KiCad on Windows # {#build_windows}

The preferred Windows build environment is [MSYS2][].  The [MinGW][] build environment is still
supported but it is not recommended because the developer is responsible for building *all* of
the dependencies from source which is a huge and frustrating undertaking.  The [MSYS2][] project
provides packages for all of the require dependencies to build KiCad.  To setup the [MSYS2][]
build environment, depending on your system download and run either the [MSYS2 32-bit Installer][]
or the [MSYS2 64-bit Installer][].  After the installer is finished, update to the latest
package versions by running the `msys2_shell.bat` file located in the MSYS2 install path and
running the command `pacman -Syu`.  If the msys2-runtime package is updated, close the shell
and run `msys2_shell.bat`.

## MSYS2 the Easy Way ## {#msys2_easy}

The easiest way to build KiCad using the [MSYS2][] build environment is to use the KiCad
[PKGBUILD][] provided by the MSYS2 project to build package using the head of the KiCad
development branch.  To build the KiCad package, run the `msys2_shell.bat` file located in the
MSYS2 install path and run the following commands:

    pacman -S git
    mkdir src
    cd src
    git clone https://github.com/Alexpux/MINGW-packages
    cd MinGW-packages/mingw-w64-kicad-git
    makepkg-mingw -is

This will download and install all of the build dependencies, clone the KiCad source mirror
from GitHub, create both 32-bit and 64-bit KiCad packages depending on your MSYS setup, and
install the newly built KiCad packages.  Please note that this build process takes a very
long time to build even on a fast system.


## MSYS2 the Hard Way ## {#msys2_hard}

If you do not want to create KiCad packages and prefer the traditional `make && make install`
method of building KiCad, your task is significantly more involved.  For 64 bit builds run
the `mingw64_shell.bat` file located in the MSYS2 install path.  At the command prompt run the
the following commands:

    pacman -S base-devel \
              mingw-w64-x86_64-cmake \
              mingw-w64-x86_64-doxygen \
              mingw-w64-x86_64-gcc \
              mingw-w64-x86_64-python2 \
              mingw-w64-x86_64-pkg-config \
              mingw-w64-x86_64-swig \
              mingw-w64-x86_64-boost \
              mingw-w64-x86_64-cairo \
              mingw-w64-x86_64-glew \
              mingw-w64-x86_64-curl \
              mingw-w64-x86_64-wxPython \
              mingw-w64-x86_64-wxWidgets \
              mingw-w64-x86_64-toolchain \
              mingw-w64-x86_64-glm
    cd kicad-source
    mkdir -p build/release
    mkdir build/debug               # Optional for debug build.
    cd build/release
    cmake -DCMAKE_BUILD_TYPE=Release \
          -G "MSYS Makefiles" \
          -DCMAKE_PREFIX_PATH=/mingw64 \
          -DCMAKE_INSTALL_PREFIX=/mingw64 \
          -DDEFAULT_INSTALL_PATH=/mingw64 \
          -DKICAD_SCRIPTING=ON \
          -DKICAD_SCRIPTING_MODULES=ON \
          -DKICAD_SCRIPTING_WXPYTHON=ON \
          ../../
    make install

For 32-bit builds, run `mingw32_shell.bat` and change `x86_64` to `i686` in the package names and
change the paths in the cmake configuration from `/mingw64` to `/mingw32`.


## Known MSYS2 Build Issues ## {#known_issues_msys2}

There are some known issues that are specific to MSYS2.  This section provides a list of the
currently known issues when building KiCad using MSYS2.


### 64-bit Package of Boost 1.59 ### {#ki_msys2_64bit_boost}

The context library of the x86_64 package of Boost version 1.59 is broken and will cause KiCad
to crash.  You must downgrade to version 1.57 by running the command:

    pacman -U /var/cache/pacman/pkg/mingw-w64-x86_64-boost-1.57.0-4-any.pkg.tar.xz

If the file mingw-w64-x86_64-boost-1.57.0-4-any.pkg.tar.xz is no longer in your pacman cache,
you will have to down load it from the [MSYS2 64-bit SourceForge repo][].  You should also
configure pacman to prevent upgrading the 64-bit Boost package by adding:

    IgnorePkg = mingw-w64-x86_64-boost

to your /etc/pacman.conf file.


# Building KiCad on OSX # {#build_osx}

Building on OSX is challenging at best.  It typically requires building dependency libraries
that require patching in order to work correctly.  For more information on the complexities of
building KiCad on OSX, see the [OSX bundle build scripts][].

Download the wxPython source and build using the following commands:

    cd path-to-wxwidgets-src
    patch -p0 < path-to-kicad-src/patches/wxwidgets-3.0.0_macosx.patch
    patch -p0 < path-to-kicad-src/patches/wxwidgets-3.0.0_macosx_bug_15908.patch
    patch -p0 < path-to-kicad-src/patches/wxwidgets-3.0.0_macosx_soname.patch
    patch -p0 < path-to-kicad-src/patches/wxwidgets-3.0.2_macosx_yosemite.patch
    patch -p0 < path-to-kicad-src/patches/wxwidgets-3.0.0_macosx_scrolledwindow.patch
    patch -p0 < path-to-kicad-src/patches/wxwidgets-3.0.2_macosx_sierra.patch
    patch -p0 < path-to-kicad-src/patches/wxwidgets-3.0.2_macosx_unicode_pasteboard.patch
    mkdir build
    cd build
    export MAC_OS_X_VERSION_MIN_REQUIRED=10.7
    ../configure \
        --prefix=`pwd`/../wx-bin \
        --with-opengl \
        --enable-aui \
        --enable-utf8 \
        --enable-html \
        --enable-stl \
        --with-libjpeg=builtin \
        --with-libpng=builtin \
        --with-regex=builtin \
        --with-libtiff=builtin \
        --with-zlib=builtin \
        --with-expat=builtin \
        --without-liblzma \
        --with-macosx-version-min=10.7 \
        --enable-universal-binary=i386,x86_64 \
        CC=clang \
        CXX=clang++

Build KiCad using the following commands:

    cd kicad-source
    mkdir -p build/release
    mkdir build/debug               # Optional for debug build.
    cd build/release
    cmake -DCMAKE_C_COMPILER=clang \
          -DCMAKE_CXX_COMPILER=clang++ \
          -DCMAKE_OSX_DEPLOYMENT_TARGET=10.7 \
          -DwxWidgets_CONFIG_EXECUTABLE=path-to-wx-install/bin/wx-config \
          -DKICAD_SCRIPTING=ON \
          -DKICAD_SCRIPTING_MODULES=ON \
          -DKICAD_SCRIPTING_WXPYTHON=ON \
          -DPYTHON_EXECUTABLE=path-to-python-exe/python \
          -DPYTHON_SITE_PACKAGE_PATH=wx/wx-bin/lib/python2.7/site-packages \
          -DCMAKE_INSTALL_PREFIX=../bin \
          -DCMAKE_BUILD_TYPE=Release \
          ../../
    make
    make install

# Known Issues # {#known_issues}

There are some known issues that effect all platforms.  This section provides a list of the
currently known issues when building KiCad on any platform.

## Boost C++ Library Issues ## {#boost_issue}

As of version 5 of [GNU GCC][], using the default configuration of downloading, patching, and
building of Boost 1.54 will cause the KiCad build to fail.  Therefore a newer version of Boost
must be used to build KiCad.  If your system has Boost 1.56 or greater installed, you job is
straight forward.  If your system does not have Boost 1.56 or greater installed, you will have
to download and [build Boost][] from source.  If you are building Boost on windows using [MinGW][]
you will have to apply the Boost patches in the KiCad source [patches folder][].


[download]: http://kicad-pcb.org/download/
[KiCad website]: http://kicad-pcb.org/
[KiCad Launchpad]: https://launchpad.net/kicad
[GNU GCC]: https://gcc.gnu.org/
[Clang]: http://clang.llvm.org/
[CMake]: https://cmake.org/
[Launchpad]: https://code.launchpad.net/kicad/
[GIT]: https://git-scm.com/
[GitHub]: https://github.com/KiCad/kicad-source-mirror
[ngspice]: http://ngspice.sourceforge.net/
[Doxygen]: http://www.stack.nl/~dimitri/doxygen/
[mailing list]: https://launchpad.net/~kicad-developers
[SWIG]: http://www.swig.org/
[wxWidgets]: http://wxwidgets.org/
[patches folder]: http://bazaar.launchpad.net/~kicad-product-committers/kicad/product/files/head:/patches/
[Boost]: http://www.boost.org/
[GLEW]: http://glew.sourceforge.net/
[GLUT]: https://www.opengl.org/resources/libraries/glut/
[Cairo]: http://cairographics.org/
[Python]: https://www.python.org/
[wxPython]: http://wxpython.org/
[MSYS2]: http://msys2.github.io/
[MSYS2 32-bit Installer]: http://repo.msys2.org/distrib/i686/msys2-i686-20150916.exe
[MSYS2 64-bit Installer]: http://repo.msys2.org/distrib/x86_64/msys2-x86_64-20150916.exe
[PKGBUILD]: https://github.com/Alexpux/MINGW-packages/blob/master/mingw-w64-kicad-git/PKGBUILD
[OSX bundle build scripts]:http://bazaar.launchpad.net/~adamwolf/+junk/kicad-mac-packaging/files
[MinGW]: http://mingw.org/
[build Boost]: http://www.boost.org/doc/libs/1_59_0/more/getting_started/index.html
[MSYS2 64-bit SourceForge repo]: http://sourceforge.net/projects/msys2/files/REPOS/MINGW/x86_64/
[libcurl]: http://curl.haxx.se/libcurl/
[GLM]: http://glm.g-truc.net/
[git]: https://git-scm.com/
[OCE]: https://github.com/tpaviot/oce
