cmake_minimum_required (VERSION 2.6)
project (clog)
if(NOT Boost_FOUND)
  if(MSVC)
    set(Boost_USE_STATIC_LIBS ON) 
  else()
    set(Boost_USE_STATIC_LIBS OFF)
  endif() 
  set(Boost_USE_MULTITHREADED ON)  
  find_package(Boost COMPONENTS system  timer filesystem regex log ) 
endif()
include_directories(${PROJECT_SOURCE_DIR}/include ${Boost_INCLUDE_DIRS})


add_library(clog STATIC ${PROJECT_SOURCE_DIR}/clog/clog.cpp)


target_link_libraries(clog   
${Boost_LOG_SETUP_LIBRARY}
${Boost_LOG_LIBRARY}
${Boost_ATOMIC_LIBRARY})
if(NOT WIN32)
  add_definitions(-DENABLE_CLOG=1 -DBOOST_LOG_DYN_LINK=1 )
  set(CMAKE_CXX_FLAGS_DEBUG "-fPIC ${CMAKE_CXX_FLAGS_DEBUG}")
  set(CMAKE_CXX_FLAGS_RELEASE "-fPIC ${CMAKE_CXX_FLAGS_RELEASE}")
  set(CMAKE_CXX_FLAGS "-fPIC ${CMAKE_CXX_FLAGS}")
else()
  add_definitions(-DENABLE_CLOG=1)
endif()
