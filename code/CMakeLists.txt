cmake_minimum_required(VERSION 3.10)

add_subdirectory(arrays)
add_subdirectory(list_tail)
add_subdirectory(queue_list)
add_subdirectory(queue_array)
add_subdirectory(insertion_sort)
add_subdirectory(basicsorts_quick_merge)
add_subdirectory(quick_sort)
add_subdirectory(priority_queue)
add_subdirectory(hash_table)
add_subdirectory(binary_search_tree)
add_subdirectory(graphs)
add_subdirectory(lib/googletest) # add googletest subdirectory

include_directories(googletest/include)
include_directories(list_tail/src)