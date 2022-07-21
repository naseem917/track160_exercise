cmake_minimum_required(VERSION 3.0.0)
project(naseem_homework VERSION 0.1.0)

include(CTest)
enable_testing()

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(naseem_homework_exe flipRGB.cpp grayMir.cpp MainClass.cpp videoDecoder.cpp client_example.cpp)
target_compile_features(naseem_homework_exe PUBLIC cxx_std_17)
#set_property(TARGET naseem_homework PROPERTY CXX_STANDARD 17)

target_link_libraries( naseem_homework_exe PRIVATE ${OpenCV_LIBS} )
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(naseem_homework_exe PRIVATE Threads::Threads)




