add_library(ManyFrames EulerAngles.cpp EulerAngles.h ODESolver.cpp ODESolver.h)

target_include_directories(ManyFrames 
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                           PUBLIC ${CMAKE_SOURCE_DIR}/dependencies
)