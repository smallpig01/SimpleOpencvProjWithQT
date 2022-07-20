#####################
### OPENCV460 SDK ###
#####################
SRC_DIR = $$PWD
INCLUDEPATH += $$SRC_DIR
LIBS += $$SRC_DIR/bin/libopencv_core460.dll
LIBS += $$SRC_DIR/bin/libopencv_highgui460.dll
LIBS += $$SRC_DIR/bin/libopencv_imgcodecs460.dll
LIBS += $$SRC_DIR/bin/libopencv_imgproc460.dll
LIBS += $$SRC_DIR/bin/libopencv_videoio460.dll