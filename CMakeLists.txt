# CMake 最小版本
cmake_minimum_required(VERSION 2.8)
# CMake 定义项目名称
project(ssl-code)               


# --------------------------------------------------------


# CMake 过程中输出 Makefile 执行过程中详细的命令
set(CMAKE_VERBOSE_MAKEFILE ON)
# 自定义 Make 编译参数
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O0 -g -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function")


# --------------------------------------------------------


# 添加编译时 include 路径
include_directories(. ../openssl-3.2.1/include/)


# --------------------------------------------------------


# 将源码文件设置到变量 LIB_SRC
set(LIB_SRC
    src/ssl.cc
    src/base16.cc
    )


# --------------------------------------------------------


# --- 动态库 --- 

# 添加 .so 共享库 zhou ， 其使用 LIB_SRC 变量中的源文件构建而成
add_library(ssl-code SHARED ${LIB_SRC})


# --- 静态库 --- 

# 生成 .a 静态库 zhou_static ， 其使用 LIB_SRC 变量中的源文件构建而成
# add_library(zhou_static STATIC ${LIB_SRC})
# 将静态库 zhou_static 输出为 zhou.a
# set_target_properties(zhou_static PROPERTIES OUTPUT_NAME "zhou")


# --------------------------------------------------------


# find_package(OpenSSL REQUIRED)
set( SSL_SO
        "/home/zhou/workspace/web_server/ssl/openssl-3.2.1/libcrypto.so"    # RAND_bytes 需要链接该库文件
        # "/home/zhou/workspace/web_server/ssl/openssl-3.2.1/libssl.so"
)


# --------------------------------------------------------


# 生成测试文件 test                    
set(TEST_EXEC test)
add_executable(${TEST_EXEC} tests/${TEST_EXEC}.cc)
# 测试文件 test 依赖于我们生成的共享库 zhou.so  
add_dependencies(${TEST_EXEC} ssl-code)    
# 其链接时需要链接到 zhou.so 共享库          
target_link_libraries(${TEST_EXEC} ssl-code ${SSL_SO}) 
# target_link_libraries(${TEST_EXEC} ssl-code OpenSSL::SSL) 

# 生成测试文件 test                    
set(TEST_EXEC test_base16)
add_executable(${TEST_EXEC} tests/${TEST_EXEC}.cc)
# 测试文件 test 依赖于我们生成的共享库 zhou.so  
add_dependencies(${TEST_EXEC} ssl-code)    
# 其链接时需要链接到 zhou.so 共享库          
target_link_libraries(${TEST_EXEC} ssl-code ${SSL_SO}) 
# target_link_libraries(${TEST_EXEC} ssl-code OpenSSL::SSL) 


# --------------------------------------------------------

# 可执行（测试）文件生成路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 库文件生成路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

