# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/guojian/share/kv-store/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/guojian/share/kv-store/src/build

# Include any dependencies generated for this target.
include kvs-server/CMakeFiles/kvstore.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include kvs-server/CMakeFiles/kvstore.dir/compiler_depend.make

# Include the progress variables for this target.
include kvs-server/CMakeFiles/kvstore.dir/progress.make

# Include the compile flags for this target's objects.
include kvs-server/CMakeFiles/kvstore.dir/flags.make

kvs-server/CMakeFiles/kvstore.dir/main.cc.o: kvs-server/CMakeFiles/kvstore.dir/flags.make
kvs-server/CMakeFiles/kvstore.dir/main.cc.o: ../kvs-server/main.cc
kvs-server/CMakeFiles/kvstore.dir/main.cc.o: kvs-server/CMakeFiles/kvstore.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guojian/share/kv-store/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object kvs-server/CMakeFiles/kvstore.dir/main.cc.o"
	cd /home/guojian/share/kv-store/src/build/kvs-server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT kvs-server/CMakeFiles/kvstore.dir/main.cc.o -MF CMakeFiles/kvstore.dir/main.cc.o.d -o CMakeFiles/kvstore.dir/main.cc.o -c /home/guojian/share/kv-store/src/kvs-server/main.cc

kvs-server/CMakeFiles/kvstore.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kvstore.dir/main.cc.i"
	cd /home/guojian/share/kv-store/src/build/kvs-server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guojian/share/kv-store/src/kvs-server/main.cc > CMakeFiles/kvstore.dir/main.cc.i

kvs-server/CMakeFiles/kvstore.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kvstore.dir/main.cc.s"
	cd /home/guojian/share/kv-store/src/build/kvs-server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guojian/share/kv-store/src/kvs-server/main.cc -o CMakeFiles/kvstore.dir/main.cc.s

kvs-server/CMakeFiles/kvstore.dir/base/config_file_reader.cc.o: kvs-server/CMakeFiles/kvstore.dir/flags.make
kvs-server/CMakeFiles/kvstore.dir/base/config_file_reader.cc.o: ../kvs-server/base/config_file_reader.cc
kvs-server/CMakeFiles/kvstore.dir/base/config_file_reader.cc.o: kvs-server/CMakeFiles/kvstore.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guojian/share/kv-store/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object kvs-server/CMakeFiles/kvstore.dir/base/config_file_reader.cc.o"
	cd /home/guojian/share/kv-store/src/build/kvs-server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT kvs-server/CMakeFiles/kvstore.dir/base/config_file_reader.cc.o -MF CMakeFiles/kvstore.dir/base/config_file_reader.cc.o.d -o CMakeFiles/kvstore.dir/base/config_file_reader.cc.o -c /home/guojian/share/kv-store/src/kvs-server/base/config_file_reader.cc

kvs-server/CMakeFiles/kvstore.dir/base/config_file_reader.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kvstore.dir/base/config_file_reader.cc.i"
	cd /home/guojian/share/kv-store/src/build/kvs-server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guojian/share/kv-store/src/kvs-server/base/config_file_reader.cc > CMakeFiles/kvstore.dir/base/config_file_reader.cc.i

kvs-server/CMakeFiles/kvstore.dir/base/config_file_reader.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kvstore.dir/base/config_file_reader.cc.s"
	cd /home/guojian/share/kv-store/src/build/kvs-server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guojian/share/kv-store/src/kvs-server/base/config_file_reader.cc -o CMakeFiles/kvstore.dir/base/config_file_reader.cc.s

kvs-server/CMakeFiles/kvstore.dir/base/util.cc.o: kvs-server/CMakeFiles/kvstore.dir/flags.make
kvs-server/CMakeFiles/kvstore.dir/base/util.cc.o: ../kvs-server/base/util.cc
kvs-server/CMakeFiles/kvstore.dir/base/util.cc.o: kvs-server/CMakeFiles/kvstore.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guojian/share/kv-store/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object kvs-server/CMakeFiles/kvstore.dir/base/util.cc.o"
	cd /home/guojian/share/kv-store/src/build/kvs-server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT kvs-server/CMakeFiles/kvstore.dir/base/util.cc.o -MF CMakeFiles/kvstore.dir/base/util.cc.o.d -o CMakeFiles/kvstore.dir/base/util.cc.o -c /home/guojian/share/kv-store/src/kvs-server/base/util.cc

kvs-server/CMakeFiles/kvstore.dir/base/util.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kvstore.dir/base/util.cc.i"
	cd /home/guojian/share/kv-store/src/build/kvs-server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guojian/share/kv-store/src/kvs-server/base/util.cc > CMakeFiles/kvstore.dir/base/util.cc.i

kvs-server/CMakeFiles/kvstore.dir/base/util.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kvstore.dir/base/util.cc.s"
	cd /home/guojian/share/kv-store/src/build/kvs-server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guojian/share/kv-store/src/kvs-server/base/util.cc -o CMakeFiles/kvstore.dir/base/util.cc.s

kvs-server/CMakeFiles/kvstore.dir/kvstore_src/command_handler.cc.o: kvs-server/CMakeFiles/kvstore.dir/flags.make
kvs-server/CMakeFiles/kvstore.dir/kvstore_src/command_handler.cc.o: ../kvs-server/kvstore_src/command_handler.cc
kvs-server/CMakeFiles/kvstore.dir/kvstore_src/command_handler.cc.o: kvs-server/CMakeFiles/kvstore.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guojian/share/kv-store/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object kvs-server/CMakeFiles/kvstore.dir/kvstore_src/command_handler.cc.o"
	cd /home/guojian/share/kv-store/src/build/kvs-server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT kvs-server/CMakeFiles/kvstore.dir/kvstore_src/command_handler.cc.o -MF CMakeFiles/kvstore.dir/kvstore_src/command_handler.cc.o.d -o CMakeFiles/kvstore.dir/kvstore_src/command_handler.cc.o -c /home/guojian/share/kv-store/src/kvs-server/kvstore_src/command_handler.cc

kvs-server/CMakeFiles/kvstore.dir/kvstore_src/command_handler.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kvstore.dir/kvstore_src/command_handler.cc.i"
	cd /home/guojian/share/kv-store/src/build/kvs-server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guojian/share/kv-store/src/kvs-server/kvstore_src/command_handler.cc > CMakeFiles/kvstore.dir/kvstore_src/command_handler.cc.i

kvs-server/CMakeFiles/kvstore.dir/kvstore_src/command_handler.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kvstore.dir/kvstore_src/command_handler.cc.s"
	cd /home/guojian/share/kv-store/src/build/kvs-server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guojian/share/kv-store/src/kvs-server/kvstore_src/command_handler.cc -o CMakeFiles/kvstore.dir/kvstore_src/command_handler.cc.s

kvs-server/CMakeFiles/kvstore.dir/kvstore_src/proactor.cc.o: kvs-server/CMakeFiles/kvstore.dir/flags.make
kvs-server/CMakeFiles/kvstore.dir/kvstore_src/proactor.cc.o: ../kvs-server/kvstore_src/proactor.cc
kvs-server/CMakeFiles/kvstore.dir/kvstore_src/proactor.cc.o: kvs-server/CMakeFiles/kvstore.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guojian/share/kv-store/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object kvs-server/CMakeFiles/kvstore.dir/kvstore_src/proactor.cc.o"
	cd /home/guojian/share/kv-store/src/build/kvs-server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT kvs-server/CMakeFiles/kvstore.dir/kvstore_src/proactor.cc.o -MF CMakeFiles/kvstore.dir/kvstore_src/proactor.cc.o.d -o CMakeFiles/kvstore.dir/kvstore_src/proactor.cc.o -c /home/guojian/share/kv-store/src/kvs-server/kvstore_src/proactor.cc

kvs-server/CMakeFiles/kvstore.dir/kvstore_src/proactor.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kvstore.dir/kvstore_src/proactor.cc.i"
	cd /home/guojian/share/kv-store/src/build/kvs-server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guojian/share/kv-store/src/kvs-server/kvstore_src/proactor.cc > CMakeFiles/kvstore.dir/kvstore_src/proactor.cc.i

kvs-server/CMakeFiles/kvstore.dir/kvstore_src/proactor.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kvstore.dir/kvstore_src/proactor.cc.s"
	cd /home/guojian/share/kv-store/src/build/kvs-server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guojian/share/kv-store/src/kvs-server/kvstore_src/proactor.cc -o CMakeFiles/kvstore.dir/kvstore_src/proactor.cc.s

kvs-server/CMakeFiles/kvstore.dir/kvstore_src/reactor.cc.o: kvs-server/CMakeFiles/kvstore.dir/flags.make
kvs-server/CMakeFiles/kvstore.dir/kvstore_src/reactor.cc.o: ../kvs-server/kvstore_src/reactor.cc
kvs-server/CMakeFiles/kvstore.dir/kvstore_src/reactor.cc.o: kvs-server/CMakeFiles/kvstore.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guojian/share/kv-store/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object kvs-server/CMakeFiles/kvstore.dir/kvstore_src/reactor.cc.o"
	cd /home/guojian/share/kv-store/src/build/kvs-server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT kvs-server/CMakeFiles/kvstore.dir/kvstore_src/reactor.cc.o -MF CMakeFiles/kvstore.dir/kvstore_src/reactor.cc.o.d -o CMakeFiles/kvstore.dir/kvstore_src/reactor.cc.o -c /home/guojian/share/kv-store/src/kvs-server/kvstore_src/reactor.cc

kvs-server/CMakeFiles/kvstore.dir/kvstore_src/reactor.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kvstore.dir/kvstore_src/reactor.cc.i"
	cd /home/guojian/share/kv-store/src/build/kvs-server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guojian/share/kv-store/src/kvs-server/kvstore_src/reactor.cc > CMakeFiles/kvstore.dir/kvstore_src/reactor.cc.i

kvs-server/CMakeFiles/kvstore.dir/kvstore_src/reactor.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kvstore.dir/kvstore_src/reactor.cc.s"
	cd /home/guojian/share/kv-store/src/build/kvs-server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guojian/share/kv-store/src/kvs-server/kvstore_src/reactor.cc -o CMakeFiles/kvstore.dir/kvstore_src/reactor.cc.s

kvs-server/CMakeFiles/kvstore.dir/mysql/db_pool.cc.o: kvs-server/CMakeFiles/kvstore.dir/flags.make
kvs-server/CMakeFiles/kvstore.dir/mysql/db_pool.cc.o: ../kvs-server/mysql/db_pool.cc
kvs-server/CMakeFiles/kvstore.dir/mysql/db_pool.cc.o: kvs-server/CMakeFiles/kvstore.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guojian/share/kv-store/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object kvs-server/CMakeFiles/kvstore.dir/mysql/db_pool.cc.o"
	cd /home/guojian/share/kv-store/src/build/kvs-server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT kvs-server/CMakeFiles/kvstore.dir/mysql/db_pool.cc.o -MF CMakeFiles/kvstore.dir/mysql/db_pool.cc.o.d -o CMakeFiles/kvstore.dir/mysql/db_pool.cc.o -c /home/guojian/share/kv-store/src/kvs-server/mysql/db_pool.cc

kvs-server/CMakeFiles/kvstore.dir/mysql/db_pool.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kvstore.dir/mysql/db_pool.cc.i"
	cd /home/guojian/share/kv-store/src/build/kvs-server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guojian/share/kv-store/src/kvs-server/mysql/db_pool.cc > CMakeFiles/kvstore.dir/mysql/db_pool.cc.i

kvs-server/CMakeFiles/kvstore.dir/mysql/db_pool.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kvstore.dir/mysql/db_pool.cc.s"
	cd /home/guojian/share/kv-store/src/build/kvs-server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guojian/share/kv-store/src/kvs-server/mysql/db_pool.cc -o CMakeFiles/kvstore.dir/mysql/db_pool.cc.s

# Object files for target kvstore
kvstore_OBJECTS = \
"CMakeFiles/kvstore.dir/main.cc.o" \
"CMakeFiles/kvstore.dir/base/config_file_reader.cc.o" \
"CMakeFiles/kvstore.dir/base/util.cc.o" \
"CMakeFiles/kvstore.dir/kvstore_src/command_handler.cc.o" \
"CMakeFiles/kvstore.dir/kvstore_src/proactor.cc.o" \
"CMakeFiles/kvstore.dir/kvstore_src/reactor.cc.o" \
"CMakeFiles/kvstore.dir/mysql/db_pool.cc.o"

# External object files for target kvstore
kvstore_EXTERNAL_OBJECTS =

bin/kvstore: kvs-server/CMakeFiles/kvstore.dir/main.cc.o
bin/kvstore: kvs-server/CMakeFiles/kvstore.dir/base/config_file_reader.cc.o
bin/kvstore: kvs-server/CMakeFiles/kvstore.dir/base/util.cc.o
bin/kvstore: kvs-server/CMakeFiles/kvstore.dir/kvstore_src/command_handler.cc.o
bin/kvstore: kvs-server/CMakeFiles/kvstore.dir/kvstore_src/proactor.cc.o
bin/kvstore: kvs-server/CMakeFiles/kvstore.dir/kvstore_src/reactor.cc.o
bin/kvstore: kvs-server/CMakeFiles/kvstore.dir/mysql/db_pool.cc.o
bin/kvstore: kvs-server/CMakeFiles/kvstore.dir/build.make
bin/kvstore: ../muduo/lib/libmuduo_net.a
bin/kvstore: ../muduo/lib/libmuduo_base.a
bin/kvstore: kvs-server/CMakeFiles/kvstore.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/guojian/share/kv-store/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable ../bin/kvstore"
	cd /home/guojian/share/kv-store/src/build/kvs-server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kvstore.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
kvs-server/CMakeFiles/kvstore.dir/build: bin/kvstore
.PHONY : kvs-server/CMakeFiles/kvstore.dir/build

kvs-server/CMakeFiles/kvstore.dir/clean:
	cd /home/guojian/share/kv-store/src/build/kvs-server && $(CMAKE_COMMAND) -P CMakeFiles/kvstore.dir/cmake_clean.cmake
.PHONY : kvs-server/CMakeFiles/kvstore.dir/clean

kvs-server/CMakeFiles/kvstore.dir/depend:
	cd /home/guojian/share/kv-store/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guojian/share/kv-store/src /home/guojian/share/kv-store/src/kvs-server /home/guojian/share/kv-store/src/build /home/guojian/share/kv-store/src/build/kvs-server /home/guojian/share/kv-store/src/build/kvs-server/CMakeFiles/kvstore.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : kvs-server/CMakeFiles/kvstore.dir/depend

