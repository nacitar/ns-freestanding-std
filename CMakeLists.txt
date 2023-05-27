cmake_minimum_required(VERSION 3.25)

project(ns_std VERSION 1.0.0 LANGUAGES CXX)

option(NS_STD_SYSTEM
    "System std; define ${PROJECT_NAME} directly within the std namespace"
    OFF
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/ns_std_build_functions.cmake)

# Check platform/compiler capabilities
foreach(source_file
    has_8bit_integral_type.cxx
    has_16bit_integral_type.cxx
    has_32bit_integral_type.cxx
    has_64bit_integral_type.cxx
)
    ns_std_feature_check(NS_STD_FEATURE ${source_file})
endforeach()

# Configure include files to incorporate build/config metadata
foreach(header_file
    ns/std/features.hxx
    ns/std/version.hxx
)
    ns_std_generate_header(${header_file})
endforeach()

# Library definition
add_library(ns_std STATIC)
ns_std_vcs_metadata_updater(ns_std ns/std/vcs/metadata.hxx)
target_include_directories(ns_std
    PUBLIC
        include
        ${CMAKE_CURRENT_BINARY_DIR}/generated
)
target_sources(ns_std
    PRIVATE 
        src/dummy.cxx
)
if(NS_STD_SYSTEM)
    target_include_directories(ns_std
        PUBLIC
            include/ns/std
    )
    set(NS_STD_NAMESPACE "std")
else()
    set(NS_STD_NAMESPACE "ns::std")
endif()
target_compile_definitions(ns_std
    PUBLIC
        NS_STD=${NS_STD_NAMESPACE}
)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(ns_std
        PRIVATE
            -Wall
            -Wextra
            -Wpedantic
            -Werror
            -Wold-style-cast
            #-Wno-unused-function
            #-Wno-unused-value
            -Wconversion
            -Wshadow
            -Wsign-conversion
            -Wnon-virtual-dtor
            -O3
    )
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(ns_std
        PRIVATE
            /W4
            /WX
            /O2
            /EHsc
    )
else()
    message(FATAL_ERROR "No support currently provided for compiler with"
        "id ${CMAKE_CXX_COMPILER_ID}.")
endif()
#target_compile_options(ns_std PRIVATE -nostdinc++)
# Testing
include(CTest)
set(testing_default OFF)
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(testing_default ON)  # when building this specifically
endif()
option(NS_STD_BUILD_TESTING "Enable ns_std tests" ${testing_default})
if(NS_STD_BUILD_TESTING)
    foreach(source_file
        simple_test.cxx
    )
        get_filename_component(test_base_name ${source_file} NAME_WE)
        set(test_target nx_std_test_${test_base_name})  # namespace it
        ns_std_compilation_test(${test_target} ${source_file})
        target_link_libraries(${test_target} ns_std)
    endforeach()
endif()
