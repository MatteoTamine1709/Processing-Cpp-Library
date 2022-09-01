set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
cmake_minimum_required(VERSION 3.10)
project(ProcessingCppLib)
SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage -g")
SET(GCC_COVERAGE_LINK_FLAGS    "-lgcov -whole-archive -g")

add_library(ProcessingCppLib STATIC
            src/engine.cpp
            #DATASTRUCTURE
            src/DataStructure/color.cpp
            src/DataStructure/font.cpp
            # STRUCTURE
            src/Structure/exit.cpp
            # COLOR
            # Setting
            src/Color/Setting/background.cpp
            src/Color/Setting/noFill.cpp
            src/Color/Setting/fill.cpp
            src/Color/Setting/noStroke.cpp
            src/Color/Setting/colorMode.cpp
            src/Color/Setting/stroke.cpp
            # CreatingAndReading
            src/Color/CreatingAndReading/alpha.cpp
            src/Color/CreatingAndReading/blue.cpp
            src/Color/CreatingAndReading/brightness.cpp
            src/Color/CreatingAndReading/green.cpp
            src/Color/CreatingAndReading/hue.cpp
            src/Color/CreatingAndReading/red.cpp
            src/Color/CreatingAndReading/saturation.cpp
            # MATH
            src/Math/PVector.cpp
            # Calculation
            src/Math/Calculation/abs.cpp
            src/Math/Calculation/constrain.cpp
            src/Math/Calculation/dist.cpp
            src/Math/Calculation/map.cpp
            src/Math/Calculation/lerp.cpp
            src/Math/Calculation/mag.cpp
            src/Math/Calculation/max.cpp
            src/Math/Calculation/min.cpp
            src/Math/Calculation/norm.cpp
            src/Math/Calculation/sq.cpp
            # Trigonometry
            src/Math/Trigonometry/degrees.cpp
            src/Math/Trigonometry/radians.cpp
            # ENVIRONMENT
            src/Environment/size.cpp
            src/Environment/width.cpp
            src/Environment/height.cpp
            #INPUT
            # Mouse
            src/Input/Mouse/mouseX.cpp
            src/Input/Mouse/mouseY.cpp
            src/Input/Mouse/pmouseX.cpp
            src/Input/Mouse/pmouseY.cpp
            src/Input/Mouse/mouseButton.cpp
            src/Input/Mouse/mousePressed.cpp
            # OUTPUT
            # TextArea
            src/Output/TextArea/print.cpp
            src/Output/TextArea/println.cpp
            # SHAPE
            # 2DPrimitives
            src/Shape/2DPrimitives/square.cpp
            src/Shape/2DPrimitives/rect.cpp
            src/Shape/2DPrimitives/quad.cpp
            src/Shape/2DPrimitives/triangle.cpp
            src/Shape/2DPrimitives/point.cpp
            src/Shape/2DPrimitives/line.cpp
            src/Shape/2DPrimitives/ellipse.cpp
            src/Shape/2DPrimitives/circle.cpp
            src/Shape/2DPrimitives/arc.cpp
            # Attributes
            src/Shape/Attributes/strokeWeight.cpp
            src/Shape/Attributes/rectMode.cpp
            src/Shape/Attributes/ellipseMode.cpp
            # Typography
            src/Typography/text.cpp
            src/Typography/loadFont.cpp
            src/Typography/textFont.cpp
            src/Typography/textSize.cpp
          )

set_target_properties(ProcessingCppLib PROPERTIES CMAKE_INCLUDE_CURRENT_DIR TRUE)
target_include_directories(ProcessingCppLib PUBLIC include)
target_link_libraries(ProcessingCppLib sfml-graphics sfml-window sfml-system)
