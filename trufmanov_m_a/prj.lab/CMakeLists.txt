add_library(rational rational.cpp include/rational/rational.hpp "arrayd.cpp")
add_library(arrayd arrayd.cpp include/arrayd/arrayd.hpp)
set_property(TARGET rational PROPERTY CXX_STANDARD 20)
set_property(TARGET arrayd PROPERTY CXX_STANDART 20)
target_include_directories(rational PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
target_include_directories(arrayd PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS rational)
install(TARGETS arrayd)