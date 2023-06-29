add_library(PeronaMalic PeronaMalic.cpp include/PeronaMalic/PeronaMalic.hpp)
target_compile_features(PeronaMalic PUBLIC cxx_std_20)
target_include_directories(PeronaMalic PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
target_link_libraries(PeronaMalic PUBLIC ${OpenCV_LIBS})
if(PERONAMALIC_INSTALL_TARGET)
	install(TARGETS PeronaMalic DESTINATION bin)
endif()
