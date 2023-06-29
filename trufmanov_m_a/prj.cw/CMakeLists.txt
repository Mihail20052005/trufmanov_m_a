cmake_minimum_required(VERSION 2.8)
project(course_work_2)

set(CMAKE_VERBOSE_MAKEFILE True)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True) 

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

find_package(OpenCV CONFIG REQUIRED)

if(WIN32)
    set(OpenCV_RUNTIME_PATH "${OpenCV_DIR}/../../bin")
else()
    set(OpenCV_RUNTIME_PATH "${OpenCV_DIR}/../../lib")
endif()
if(PERONAMALIC_GENERATE_DOCS)
    find_package(Doxygen)
    if(DOXYGEN_FOUND)
        set(NIBLACK_DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
        set(NIBLACK_DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/docs/Doxyfile)
        configure_file(${NIBLACK_DOXYGEN_IN} ${NIBLACK_DOXYGEN_OUT})
        add_custom_target(niblack_docs_doxygen ALL
                COMMAND ${DOXYGEN_EXECUTABLE} ${NIBLACK_DOXYGEN_OUT}
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/docs
                COMMENT "Generating API documentation with Doxygen"
                VERBATIM)
        install (DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/docs
DESTINATION ./bin)
    else()
        message(STATUS "Couldn't find Doxygen")
    endif()
endif()


if(PERONAMALIC_INSTALL_TARGET)
    install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
      DESTINATION bin
      FILES_MATCHING PATTERN "*opencv_core*"
    )

    install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
      DESTINATION bin
      FILES_MATCHING PATTERN "*opencv_highgui4.dll*"
    )

    install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
      DESTINATION bin
      FILES_MATCHING PATTERN "*opencv_core4*"
    )

    install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
      DESTINATION bin
      FILES_MATCHING PATTERN "*opencv_imgcodecs4*"
    )

    install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
      DESTINATION bin
      FILES_MATCHING PATTERN "*opencv_imgcodecs4*"
    )

    install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
      DESTINATION bin
      FILES_MATCHING PATTERN "*opencv_imgproc4*"
    )

    install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
      DESTINATION bin
      FILES_MATCHING PATTERN "*jpeg62*"
    )

    install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
      DESTINATION bin
      FILES_MATCHING PATTERN "*opencv_videoio4*"
    )

    install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
      DESTINATION bin
      FILES_MATCHING PATTERN "*zlib1*"
    )

    install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
      DESTINATION bin
      FILES_MATCHING PATTERN "*libwebp*"
    )

    install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
      DESTINATION bin
      FILES_MATCHING PATTERN "*libpng16*"
    )

    install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
      DESTINATION bin
      FILES_MATCHING PATTERN "*tiff*"
    )

    install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
      DESTINATION bin
      FILES_MATCHING PATTERN "*libsharpyuv*"
    )

    install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
      DESTINATION bin
      FILES_MATCHING PATTERN "*liblzma*"
    )

endif()


add_subdirectory(perona-malic)
add_subdirectory(testdir)