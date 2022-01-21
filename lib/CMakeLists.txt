add_library(Aero EulerAngles.cpp EulerAngles.h ODEsolver.cpp ODEsolver.h Aircraft.cpp Aircraft.h)

target_include_directories(Aero 
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                           PUBLIC ${CMAKE_SOURCE_DIR}/dependencies
)