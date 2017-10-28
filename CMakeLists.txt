cmake_minimum_required(VERSION 3.8)
project(zutils)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        include/mpl/at_impl.hpp
        include/mpl/change_impl.hpp
        include/mpl/contains_impl.hpp
        include/mpl/count_impl.hpp
        include/mpl/erase_all_impl.hpp
        include/mpl/list_impl.hpp
        include/mpl/meta_function.hpp
        include/mpl/no_duplicates_impl.hpp
        include/mpl/push_back_impl.hpp
        include/mpl/push_front_impl.hpp
        include/mpl/reverse_impl.hpp
        include/mpl/size_impl.hpp
        include/mpl/transform_impl.hpp
        include/tests/mpl_test.hpp
        include/tests/transfer_test.hpp
        include/transfer/meta_container.hpp
        include/transfer/transfer_functions.hpp
        include/transfer/type_wrapper.hpp
        include/mpl.hpp
        src/tests/mpl/at.cpp
        src/tests/mpl/change.cpp
        src/tests/mpl/contains.cpp
        src/tests/mpl/count.cpp
        src/tests/mpl/erase_all.cpp
        src/tests/mpl/push_back.cpp
        src/tests/mpl/push_front.cpp
        src/tests/mpl/reverse.cpp
        src/tests/mpl/size.cpp
        src/tests/mpl/transform.cpp
        src/tests/transfer/transfer_functions.cpp
        src/main.cpp)

include_directories(include)
include_directories(include/mpl)
include_directories(include/tests)
include_directories(include/transfer)

add_executable(zutils ${SOURCE_FILES})