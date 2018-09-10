
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

if (CMAKE_BUILD_TYPE MATCHES Debug)
#  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -Werror -Wextra")
  # -fno-rtti, Disable real-time type information
  # -fno-exceptions Disable exceptions
  # -fsanitize=address Enable memory sanitize plugin
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Werror -Wextra -fno-exceptions")
  # -fsanitize=address, Enable memory address sanitizer.
  # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
  # -fsanitize=leak, Enable memory leak sanitizer.
  # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak")
  # -fsanitize=memory, Enable detecting uninitited memory sanitizer.
  # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=memory")
  #    "-fsanitize-memory-track-origins -fPIC -pie -fno-omit-frame-pointer")

  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wimplicit-fallthrough=0")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-missing-field-initializers")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-parameter")

  # Enable Qt builtin debug mode
  add_definitions("-DQT_MESSAGELOGCONTEXT")
else()
  # -Wl, -O2 Enable linker optimizations
  # -Wl, --gc-sections Remove unused code resulting from -fdsta-sections and
  # -ffunction-sections
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O2 -Wl,-O1 -Wl,--gc-sections")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2 -Wl,-O1 -Wl,--gc-sections")
endif()

find_package(Qt5Core REQUIRED)

include_directories(third_party/breakpad/src)

set(LINK_LIBS
    Qt5::Core
    -lpthread
    )

set(BREAKPAD_FILES
    third_party/breakpad/src/common/string_conversion.cc
    third_party/breakpad/src/common/string_conversion.h
    third_party/breakpad/src/common/convert_UTF.c
    third_party/breakpad/src/common/convert_UTF.h
    third_party/breakpad/src/common/md5.cc
    third_party/breakpad/src/common/md5.h
    third_party/breakpad/src/client/minidump_file_writer.cc
    third_party/breakpad/src/client/minidump_file_writer.h
    )

set(BREAKPAD_LINUX_FILES
    third_party/breakpad/src/common/linux/dump_symbols.cc
    third_party/breakpad/src/common/linux/dump_symbols.h
    third_party/breakpad/src/common/linux/elfutils.cc
    third_party/breakpad/src/common/linux/elfutils.h
    third_party/breakpad/src/common/linux/file_id.cc
    third_party/breakpad/src/common/linux/file_id.h
    third_party/breakpad/src/common/linux/guid_creator.cc
    third_party/breakpad/src/common/linux/guid_creator.h
    third_party/breakpad/src/common/linux/linux_libc_support.cc
    third_party/breakpad/src/common/linux/linux_libc_support.h
    third_party/breakpad/src/common/linux/memory_mapped_file.cc
    third_party/breakpad/src/common/linux/memory_mapped_file.h
    third_party/breakpad/src/common/linux/safe_readlink.cc
    third_party/breakpad/src/common/linux/safe_readlink.h
    third_party/breakpad/src/client/linux/log/log.cc
    third_party/breakpad/src/client/linux/log/log.h
    third_party/breakpad/src/client/linux/crash_generation/crash_generation_client.cc
    third_party/breakpad/src/client/linux/crash_generation/crash_generation_client.h
    third_party/breakpad/src/client/linux/dump_writer_common/thread_info.cc
    third_party/breakpad/src/client/linux/dump_writer_common/thread_info.h
    third_party/breakpad/src/client/linux/dump_writer_common/ucontext_reader.cc
    third_party/breakpad/src/client/linux/dump_writer_common/ucontext_reader.h
    third_party/breakpad/src/client/linux/microdump_writer/microdump_writer.cc
    third_party/breakpad/src/client/linux/microdump_writer/microdump_writer.h
    third_party/breakpad/src/client/linux/minidump_writer/linux_dumper.cc
    third_party/breakpad/src/client/linux/minidump_writer/linux_dumper.h
    third_party/breakpad/src/client/linux/minidump_writer/linux_core_dumper.cc
    third_party/breakpad/src/client/linux/minidump_writer/linux_core_dumper.h
    third_party/breakpad/src/client/linux/minidump_writer/linux_ptrace_dumper.cc
    third_party/breakpad/src/client/linux/minidump_writer/linux_ptrace_dumper.h
    third_party/breakpad/src/client/linux/minidump_writer/minidump_writer.cc
    third_party/breakpad/src/client/linux/minidump_writer/minidump_writer.h
    third_party/breakpad/src/client/linux/handler/minidump_descriptor.cc
    third_party/breakpad/src/client/linux/handler/minidump_descriptor.h
    third_party/breakpad/src/client/linux/handler/exception_handler.cc
    third_party/breakpad/src/client/linux/handler/exception_handler.h
    )

set(SOURCE_FILES
    breakpad_crash_handler.cpp
    breakpad_crash_handler.h
    )

add_library(blade STATIC
            ${BREAKPAD_FILES}
            ${BREAKPAD_LINUX_FILES}
            ${SOURCE_FILES}
            )
target_link_libraries(blade ${LINK_LIBS})