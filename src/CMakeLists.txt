add_library(VectorLib vector.cpp)

target_link_libraries(VectorLib
        PRIVATE
#        Boost::filesystem
        Boost::algorithm
)

target_include_directories(VectorLib
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/boost
)
