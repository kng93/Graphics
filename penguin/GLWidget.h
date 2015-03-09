/*************************************************************************
    CSC418/2504, Winter 20l5
    Assignment 1

    Instructions:
        See main.cpp for more instructions.

        This file contains the OpenGL portion of the main window.
**************************************************************************/

#ifndef __GLWidget_h__
#define __GLWidget_h__

#include "include_gl.h"
#include "GLState.h"
#include "GLShape.h"
#include <QtOpenGL/QtOpenGL>


// Before transformed, this class displays a unit square centered at the
// origin.
class UnitSquare : public GLShape
{
public:
    using GLShape::initialize;

    void initialize(int shader_input_location)
    {
	// Use two triangles to create the square.
        GLfloat square_vertices[][2] =
        {
            { -0.5, -0.5 },  // Triangle 1
            {  0.5, -0.5 },
            {  0.5,  0.5 },
            { -0.5, -0.5 },  // Triangle 2
            {  0.5,  0.5 },
            { -0.5,  0.5 },
        };

        initialize(
	    shader_input_location,
            reinterpret_cast<const GLfloat *>(square_vertices),
            /*num_vertices=*/6,
	    GL_TRIANGLES); // Each group of three coordinates is a triangle
    }
};

// Before transformed, this class displays a unit circle centered at the
// origin.
class UnitCircle : public GLShape
{
public:
    using GLShape::initialize;

    void initialize(int shader_input_location, int num_circle_segments)
    {
        // We will draw a circle as a triangle fan.  We are careful to send
	// the second coordinate twice to properly close the circle.
        //        3     2     1
        //         +----+----+
        //        / \   |   /
        //       /   \  |  /
        //      /     \ | /
        //     /       \|/
        //   4+---------+ 0
        //        ...
        std::vector<GLfloat> circle_vertices;
        circle_vertices.push_back(0.0);
        circle_vertices.push_back(0.0);
        for (int i=0; i<=num_circle_segments; ++i)
        {
            double angle = (2 * M_PI * i) / num_circle_segments;
            circle_vertices.push_back(cos(angle));
            circle_vertices.push_back(sin(angle));
        }

        initialize(
	    shader_input_location,
            &circle_vertices[0],
            num_circle_segments + 2,
	    GL_TRIANGLE_FAN);
    }
};

// Draw the head
class PenHead : public GLShape
{
public:
    using GLShape::initialize;

    void initialize(int shader_input_location)
    {
    // Use two triangles to create the square.
        GLfloat square_vertices[][2] =
        {
            { -0.5, 0 },  // Top head
            {  0,  0.5 },
            {  1, 0 },
            { -0.5, 0 }, // Bottom right (1.5/-0.5 = -7.5)
            {  1.2, -1.5 }, 
            {  1, 0 },
            { -0.5, 0 }, // Bottom left
            {  -0.6, -1.5 }, 
            {  1.2, -1.5 }
        };

        initialize(
        shader_input_location,
            reinterpret_cast<const GLfloat *>(square_vertices),
            /*num_vertices=*/9,
        GL_TRIANGLES); // Each group of three coordinates is a triangle
    }
};

// Draw the body
class PenBody : public GLShape
{
public:
    using GLShape::initialize;

    void initialize(int shader_input_location)
    {
    // Use two triangles to create the square.
        GLfloat square_vertices[][2] =
        {
            { -0.7, 2.3 },  // Top right (slope = -7.5 from before)
            {  0.7,  2.3 },
            {  1.1, 0 },
            { -0.7, 2.3 }, // Top left
            { -1, 0 },
            {  1.1, 0 },
            { -1, 0 }, // Middle right
            {  1.1, 0 },
            {  1.75, -2.6 },
            { -1, 0 }, // Middle left
            { -1.4, -2.5 },
            {  1.75, -2.6 },
            { -1.4, -2.5 }, // Bottom right
            {  1.75, -2.6 },
            {  0.6, -3.9 },
            { -1.4, -2.5 }, // Bottom left
            { -0.6, -3.8 },
            {  0.6, -3.9 }
        };

        initialize(
        shader_input_location,
            reinterpret_cast<const GLfloat *>(square_vertices),
            /*num_vertices=*/18,
        GL_TRIANGLES); // Each group of three coordinates is a triangle
    }
};

// Draw the arm
class PenArm : public GLShape
{
public:
    using GLShape::initialize;

    void initialize(int shader_input_location)
    {
    // Use two triangles to create the square.
        GLfloat square_vertices[][2] =
        {
            { -1.0, 1.5 },  // Right 
            {  0.9,  1.5 },
            {  0.55, -1.5 },
            { -1.0, 1.5 }, // Left
            { -0.5, -1.5 },
            {  0.55, -1.5 }
        };

        initialize(
        shader_input_location,
            reinterpret_cast<const GLfloat *>(square_vertices),
            /*num_vertices=*/6,
        GL_TRIANGLES); // Each group of three coordinates is a triangle
    }
};

// Draw the top beak
class PenBeakTop : public GLShape
{
public:
    using GLShape::initialize;

    void initialize(int shader_input_location)
    {
    // Use two triangles to create the square.
        GLfloat square_vertices[][2] =
        {
            { -1.5, 0.5 },  // Right 
            {  1.5,  1.5 },
            {  1.5, 0 },
            { -1.5, 0.5 }, // Left
            { -1.4, 0 },
            {  1.5, 0 }
        };

        initialize(
        shader_input_location,
            reinterpret_cast<const GLfloat *>(square_vertices),
            /*num_vertices=*/6,
        GL_TRIANGLES); // Each group of three coordinates is a triangle
    }
};

// Draw the bottom beak
class PenBeakBottom : public GLShape
{
public:
    using GLShape::initialize;

    void initialize(int shader_input_location)
    {
    // Use two triangles to create the square.
        GLfloat square_vertices[][2] =
        {
            { -1.5, 0.5 },  // Right 
            {  1.5,  0.5 },
            {  1.5, 0 },
            { -1.5, 0.5 }, // Left
            { -1.4, 0 },
            {  1.5, 0 }
        };

        initialize(
        shader_input_location,
            reinterpret_cast<const GLfloat *>(square_vertices),
            /*num_vertices=*/6,
        GL_TRIANGLES); // Each group of three coordinates is a triangle
    }
};

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    // These values control the bounds to display on the joint angle sliders.
    static const double OPEN_MOUTH = -1;
    static const double CLOSE_MOUTH = -0.5;

    static const int ARM_JOINT_MIN = -35;
    static const int ARM_JOINT_MAX = 40;
    static const int HEAD_JOINT_MIN = -10;
    static const int HEAD_JOINT_MAX = 10;
    static const int LEFT_FOOT_MIN = -110;
    static const int LEFT_FOOT_MAX = -75;
    static const int RIGHT_FOOT_MIN = -60;
    static const int RIGHT_FOOT_MAX = -100;
    static const int LEFT_LEG_MIN = 20;
    static const int LEFT_LEG_MAX = -15;
    static const int RIGHT_LEG_MIN = -30;
    static const int RIGHT_LEG_MAX = 5;

    static const int MIN_X = -200;
    static const int MAX_X = 200;
    static const int MIN_Y = -30;
    static const int MAX_Y = 30;

    GLWidget(QWidget *parent=NULL);

public slots:
    // This method is called when the user changes the arm joint slider
    void setArmAngle(int angle)
    {
        // This method is called when the user changes the slider value.
        m_arm_angle = angle;
        update(); // Call update() to trigger a redraw.
    }

    // This method is called when the user changes the head joint slider.
    void setHeadAngle(int angle)
    {
        m_head_angle = angle;
        update(); 
    }

    // This method is called when the user changes the mouth slider
    void setMouth(int mouth_pos)
    {
        // Only options = open or close the mouth
        if (mouth_pos == OPEN_MOUTH)
            m_mouth_position = mouth_pos;
        else
            m_mouth_position = CLOSE_MOUTH;

        update(); 
    }

    // This method is called when the user changes the left leg joint slider.
    void setLeftLeg(int angle)
    {
        m_left_leg = angle;
        update(); 
    }

    // This method is called when the user changes the left foot joint slider.
    void setLeftFoot(int angle)
    {
        m_left_foot = angle;
        update(); 
    }

    // This method is called when the user changes the right leg joint slider.
    void setRightLeg(int angle)
    {
        m_right_leg = angle;
        update(); 
    }

    // This method is called when the user changes the right foot joint slider.
    void setRightFoot(int angle)
    {
        m_right_foot = angle;
        update(); 
    }

    // This method is called when the user changes the x axis joint slider.
    void setX(int xVal)
    {
        m_move_x = xVal;
        update(); 
    }

    // This method is called when the user changes the y axis joint slider.
    void setY(int yVal)
    {
        m_move_y = yVal;
        update(); 
    }

    void onPressAnimate(int is_animating)
    {
        // This method is called when the user changes the animation checkbox.
        m_is_animating = (bool)is_animating;
        m_animation_frame = 0;
        update();
    }

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void timerEvent(QTimerEvent *event);

private:
    void closeMouth();
    void nodHead(double joint_rot_speed);
    void moveArm(double joint_rot_speed);
    void leftFoot(double joint_rot_speed);
    void rightFoot(double joint_rot_speed);
    void rightLeg(double joint_rot_speed);
    void leftLeg(double joint_rot_speed);
    void movex();
    void movey();
    GLTransformStack &transformStack()
    { return m_gl_state.transformStack(); }

private:
    GLState m_gl_state;
    bool m_is_animating;
    int m_animation_frame;
    UnitSquare m_unit_square;
    UnitCircle m_unit_circle;
    PenHead m_pen_head;
    PenBody m_pen_body;
    PenArm m_pen_arm;
    PenBeakTop m_beak_top;
    PenBeakBottom m_beak_bottom;

    // Joints
    double m_arm_angle;
    double m_head_angle;
    double m_mouth_position;
    double m_left_leg;
    double m_left_foot;
    double m_right_leg;
    double m_right_foot;

    // For moving the penguin
    double m_move_x;
    double m_move_y;
    double m_pos_x;
    double m_pos_y;
};

#endif
