# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mfikih15/Documents/kapalTenggelam/serverGabut/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mfikih15/Documents/kapalTenggelam/serverGabut/build

# Include any dependencies generated for this target.
include groundserver/CMakeFiles/remoteServer.dir/depend.make

# Include the progress variables for this target.
include groundserver/CMakeFiles/remoteServer.dir/progress.make

# Include the compile flags for this target's objects.
include groundserver/CMakeFiles/remoteServer.dir/flags.make

groundserver/CMakeFiles/remoteServer.dir/src/remoteServer.cpp.o: groundserver/CMakeFiles/remoteServer.dir/flags.make
groundserver/CMakeFiles/remoteServer.dir/src/remoteServer.cpp.o: /home/mfikih15/Documents/kapalTenggelam/serverGabut/src/groundserver/src/remoteServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mfikih15/Documents/kapalTenggelam/serverGabut/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object groundserver/CMakeFiles/remoteServer.dir/src/remoteServer.cpp.o"
	cd /home/mfikih15/Documents/kapalTenggelam/serverGabut/build/groundserver && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/remoteServer.dir/src/remoteServer.cpp.o -c /home/mfikih15/Documents/kapalTenggelam/serverGabut/src/groundserver/src/remoteServer.cpp

groundserver/CMakeFiles/remoteServer.dir/src/remoteServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/remoteServer.dir/src/remoteServer.cpp.i"
	cd /home/mfikih15/Documents/kapalTenggelam/serverGabut/build/groundserver && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mfikih15/Documents/kapalTenggelam/serverGabut/src/groundserver/src/remoteServer.cpp > CMakeFiles/remoteServer.dir/src/remoteServer.cpp.i

groundserver/CMakeFiles/remoteServer.dir/src/remoteServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/remoteServer.dir/src/remoteServer.cpp.s"
	cd /home/mfikih15/Documents/kapalTenggelam/serverGabut/build/groundserver && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mfikih15/Documents/kapalTenggelam/serverGabut/src/groundserver/src/remoteServer.cpp -o CMakeFiles/remoteServer.dir/src/remoteServer.cpp.s

groundserver/CMakeFiles/remoteServer.dir/src/remoteServer.cpp.o.requires:

.PHONY : groundserver/CMakeFiles/remoteServer.dir/src/remoteServer.cpp.o.requires

groundserver/CMakeFiles/remoteServer.dir/src/remoteServer.cpp.o.provides: groundserver/CMakeFiles/remoteServer.dir/src/remoteServer.cpp.o.requires
	$(MAKE) -f groundserver/CMakeFiles/remoteServer.dir/build.make groundserver/CMakeFiles/remoteServer.dir/src/remoteServer.cpp.o.provides.build
.PHONY : groundserver/CMakeFiles/remoteServer.dir/src/remoteServer.cpp.o.provides

groundserver/CMakeFiles/remoteServer.dir/src/remoteServer.cpp.o.provides.build: groundserver/CMakeFiles/remoteServer.dir/src/remoteServer.cpp.o


# Object files for target remoteServer
remoteServer_OBJECTS = \
"CMakeFiles/remoteServer.dir/src/remoteServer.cpp.o"

# External object files for target remoteServer
remoteServer_EXTERNAL_OBJECTS =

/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: groundserver/CMakeFiles/remoteServer.dir/src/remoteServer.cpp.o
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: groundserver/CMakeFiles/remoteServer.dir/build.make
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /opt/ros/kinetic/lib/libcv_bridge.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /opt/ros/kinetic/lib/libopencv_core3.so.3.3.1
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /opt/ros/kinetic/lib/libopencv_imgproc3.so.3.3.1
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /opt/ros/kinetic/lib/libopencv_imgcodecs3.so.3.3.1
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /opt/ros/kinetic/lib/libimage_transport.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /opt/ros/kinetic/lib/libmessage_filters.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /opt/ros/kinetic/lib/libclass_loader.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /usr/lib/libPocoFoundation.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /usr/lib/x86_64-linux-gnu/libdl.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /opt/ros/kinetic/lib/libroslib.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /opt/ros/kinetic/lib/librospack.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /usr/lib/x86_64-linux-gnu/libpython2.7.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /usr/lib/x86_64-linux-gnu/libtinyxml.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /opt/ros/kinetic/lib/libroscpp.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /opt/ros/kinetic/lib/librosconsole.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /opt/ros/kinetic/lib/libxmlrpcpp.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /opt/ros/kinetic/lib/libroscpp_serialization.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /opt/ros/kinetic/lib/librostime.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /opt/ros/kinetic/lib/libcpp_common.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer: groundserver/CMakeFiles/remoteServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mfikih15/Documents/kapalTenggelam/serverGabut/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer"
	cd /home/mfikih15/Documents/kapalTenggelam/serverGabut/build/groundserver && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/remoteServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
groundserver/CMakeFiles/remoteServer.dir/build: /home/mfikih15/Documents/kapalTenggelam/serverGabut/devel/lib/groundserver/remoteServer

.PHONY : groundserver/CMakeFiles/remoteServer.dir/build

groundserver/CMakeFiles/remoteServer.dir/requires: groundserver/CMakeFiles/remoteServer.dir/src/remoteServer.cpp.o.requires

.PHONY : groundserver/CMakeFiles/remoteServer.dir/requires

groundserver/CMakeFiles/remoteServer.dir/clean:
	cd /home/mfikih15/Documents/kapalTenggelam/serverGabut/build/groundserver && $(CMAKE_COMMAND) -P CMakeFiles/remoteServer.dir/cmake_clean.cmake
.PHONY : groundserver/CMakeFiles/remoteServer.dir/clean

groundserver/CMakeFiles/remoteServer.dir/depend:
	cd /home/mfikih15/Documents/kapalTenggelam/serverGabut/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mfikih15/Documents/kapalTenggelam/serverGabut/src /home/mfikih15/Documents/kapalTenggelam/serverGabut/src/groundserver /home/mfikih15/Documents/kapalTenggelam/serverGabut/build /home/mfikih15/Documents/kapalTenggelam/serverGabut/build/groundserver /home/mfikih15/Documents/kapalTenggelam/serverGabut/build/groundserver/CMakeFiles/remoteServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : groundserver/CMakeFiles/remoteServer.dir/depend

