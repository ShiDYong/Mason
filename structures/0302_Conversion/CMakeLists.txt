# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(Conversion Conversion.h Conversion.c Conversion-main.c SqStack.c SqStack.h)
# 链接公共库
target_link_libraries(Conversion Scanf_lib)
