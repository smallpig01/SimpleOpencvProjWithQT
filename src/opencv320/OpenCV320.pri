#####################
### OPENCV320 SDK ###
#####################
SRC_DIR = $$PWD
INCLUDEPATH += $$SRC_DIR
LIBS += $$SRC_DIR/bin/libopencv_core320.dll
LIBS += $$SRC_DIR/bin/libopencv_highgui320.dll
LIBS += $$SRC_DIR/bin/libopencv_imgcodecs320.dll
LIBS += $$SRC_DIR/bin/libopencv_imgproc320.dll
LIBS += $$SRC_DIR/bin/libopencv_videoio320.dll