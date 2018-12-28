add_library(MotorControl "")

target_sources(
    MotorControl
    PRIVATE
        DCMotor12VoltsDriver.cpp
		operators.cpp
		PID.cpp
		QuadratureEncoder.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/DCMotor12VoltsDriver.h
		${CMAKE_CURRENT_LIST_DIR}/operators.h
		${CMAKE_CURRENT_LIST_DIR}/PID.h
		${CMAKE_CURRENT_LIST_DIR}/PWMDriver.h
		${CMAKE_CURRENT_LIST_DIR}/QuadratureEncoder.h
		${CMAKE_CURRENT_LIST_DIR}/IDCMotor.h
		${CMAKE_CURRENT_LIST_DIR}/IEncoder.h
		${CMAKE_CURRENT_LIST_DIR}/IGPIODriver.h		
    )

target_include_directories(
    MotorControl
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )