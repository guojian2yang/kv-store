INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/base)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/kvstore_src)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/mysql)

INCLUDE_DIRECTORIES(/usr/include/mysql)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/base BASE_LIST)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/kvstore_src KVSTORE_LIST)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/mysql MYSQL_LIST)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/redis REDIS_LIST)

ADD_EXECUTABLE(kvstore main.cc ${BASE_LIST} ${KVSTORE_LIST} ${MYSQL_LIST})

TARGET_LINK_LIBRARIES(kvstore muduo_net mysqlclient pthread uring)
