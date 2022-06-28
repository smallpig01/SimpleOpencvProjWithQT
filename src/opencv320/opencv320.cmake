set(pwd "${CMAKE_CURRENT_LIST_DIR}")

set(INC ${INC}
    "${pwd}"
)

set(lib ${lib}
    "${pwd}/bin/libopencv_core320.dll"
    "${pwd}/bin/libopencv_highgui320.dll"
    "${pwd}/bin/libopencv_imgcodecs320.dll"
    "${pwd}/bin/libopencv_imgproc320.dll"
    "${pwd}/bin/libopencv_videoio320.dll"
)