add_library(VectorLib vector.cpp)
target_link_libraries(VectorLib
        PRIVATE
        Boost::system
        Boost::beast
        Boost::algorithm
)
target_include_directories(VectorLib
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/boost
)


add_executable(HttpServer http_server.cpp)
target_link_libraries(HttpServer PRIVATE VectorLib Boost::beast Boost::asio Boost::algorithm)
target_include_directories(HttpServer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/boost)