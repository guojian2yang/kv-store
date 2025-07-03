# 客户端目标
add_executable(kvs_client c++-kvstore.cc)

# 链接必要库（如需要）
target_link_libraries(kvs_client pthread)