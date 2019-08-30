cmake_minimum_required (VERSION 2.6)
project (clog)
if(NOT Boost_FOUND)
  if(MSVC)
    set(Boost_USE_STATIC_LIBS ON) 
  else()
    set(Boost_USE_STATIC_LIBS OFF)
  endif() 
  set(Boost_USE_MULTITHREADED ON)  
  find_package(Boost COMPONENTS system thread timer filesystem regex log ) 
endif()
include_directories(${PROJECT_SOURCE_DIR}/include ${Boost_INCLUDE_DIRS})


add_library(clog STATIC ${PROJECT_SOURCE_DIR}/clog/clog.cpp)


target_link_libraries(clog   
${Boost_LOG_SETUP_LIBRARY}
${Boost_LOG_LIBRARY}
${Boost_ATOMIC_LIBRARY})
