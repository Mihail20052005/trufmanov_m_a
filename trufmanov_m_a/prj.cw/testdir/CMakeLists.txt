add_executable(testdir pmtest.cpp)

target_link_libraries(testdir PRIVATE PeronaMalic)

if(PERONAMALIC_INSTALL_TARGET)
	install(TARGETS pmtest DESTINATION bin)
endif()