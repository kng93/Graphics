/*************************************************************************
    CSC418/2504, Winter 20l5
    Assignment 1
  
  
    Instructions:
        See main.cpp for more instructions.

        This file contains the class for the main window of the program.
**************************************************************************/

#ifndef __MainWindow_h__
#define __MainWindow_h__

#include <QtGui/QtGui>
#include "GLWidget.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow()
    {
        // Create a GLWidget to hold the OpenGL viewport.
        m_gl_widget = new GLWidget();

        // Create a checkbox to turn animation on and off, and make it
        // call GLWidget::onPressAnimate when checked.
        m_animate_checkbox = new QCheckBox("Animate", this);
        connect(
            m_animate_checkbox, SIGNAL(stateChanged(int)),
            m_gl_widget, SLOT(onPressAnimate(int)));

        // Create a button to quit the program.
        m_quit_button = new QPushButton("Quit", this);
        connect(
            m_quit_button, SIGNAL(clicked(bool)),
            this, SLOT(onPressQuit(bool)));

        m_main_layout = new QVBoxLayout();
        m_main_layout->addWidget(m_gl_widget);

        // Create a slider to control the arm joint angle, and make it call
        // GLWidget::setArmAngle when the slider value changes.
        m_slider = create_joint_angle_slider(
	    "Arm Joint", GLWidget::ARM_JOINT_MIN, GLWidget::ARM_JOINT_MAX);
        connect(
            m_slider, SIGNAL(valueChanged(int)),
            m_gl_widget, SLOT(setArmAngle(int)));

        // Slide for head
        m_slider = create_joint_angle_slider(
        "Head Joint", GLWidget::HEAD_JOINT_MIN, GLWidget::HEAD_JOINT_MAX);
        connect(
            m_slider, SIGNAL(valueChanged(int)),
            m_gl_widget, SLOT(setHeadAngle(int)));

        // Open/Close mouth
        m_slider = create_joint_angle_slider(
        "Mouth Joint", GLWidget::OPEN_MOUTH, 0);
        connect(
            m_slider, SIGNAL(valueChanged(int)),
            m_gl_widget, SLOT(setMouth(int)));

        // Slider for left leg
        m_slider = create_joint_angle_slider(
        "Left Leg Joint", GLWidget::LEFT_LEG_MAX, GLWidget::LEFT_LEG_MIN);
        connect(
            m_slider, SIGNAL(valueChanged(int)),
            m_gl_widget, SLOT(setLeftLeg(int)));

        // Slider for left foot
        m_slider = create_joint_angle_slider(
        "Left Foot Joint", GLWidget::LEFT_FOOT_MIN, GLWidget::LEFT_FOOT_MAX);
        connect(
            m_slider, SIGNAL(valueChanged(int)),
            m_gl_widget, SLOT(setLeftFoot(int)));

        // Slider for right leg
        m_slider = create_joint_angle_slider(
        "Right Leg Joint", GLWidget::RIGHT_LEG_MIN, GLWidget::RIGHT_LEG_MAX);
        connect(
            m_slider, SIGNAL(valueChanged(int)),
            m_gl_widget, SLOT(setRightLeg(int)));

        // Slider for right foot
        m_slider = create_joint_angle_slider(
        "Right Foot Joint", GLWidget::RIGHT_FOOT_MAX, GLWidget::RIGHT_FOOT_MIN);
        connect(
            m_slider, SIGNAL(valueChanged(int)),
            m_gl_widget, SLOT(setRightFoot(int)));


        m_main_layout->addWidget(m_animate_checkbox);
        m_main_layout->addWidget(m_quit_button);
        setLayout(m_main_layout);

        // Slider for moving along the x axis
        m_slider = create_joint_angle_slider(
        "X Value", GLWidget::MIN_X, GLWidget::MAX_X);
        connect(
            m_slider, SIGNAL(valueChanged(int)),
            m_gl_widget, SLOT(setX(int)));


        m_main_layout->addWidget(m_animate_checkbox);
        m_main_layout->addWidget(m_quit_button);
        setLayout(m_main_layout);

        // Slider for moving along the y axis
        m_slider = create_joint_angle_slider(
        "Y Value", GLWidget::MIN_Y, GLWidget::MAX_Y);
        connect(
            m_slider, SIGNAL(valueChanged(int)),
            m_gl_widget, SLOT(setY(int)));


        m_main_layout->addWidget(m_animate_checkbox);
        m_main_layout->addWidget(m_quit_button);
        setLayout(m_main_layout);

        m_slider->setValue(0);
        setWindowTitle("CSC418/2504 Assignment 1");
    }

public slots:
    void onPressQuit(bool)
    {
        exit(0);
    }

private:
    QSlider *create_joint_angle_slider(
	const char *label, int min_angle, int max_angle)
    {
        QSlider *slider = new QSlider(Qt::Horizontal, this);
        slider->setRange(min_angle, max_angle);
        slider->setSingleStep(1);
        slider->setPageStep(5);
        slider->setTickInterval(5);
        slider->setTickPosition(QSlider::TicksBelow);

	QBoxLayout *layout = new QHBoxLayout();
	layout->addWidget(new QLabel(label));
	layout->addWidget(slider);
	m_main_layout->addLayout(layout);

        return slider;
    }

    GLWidget *m_gl_widget;
    QCheckBox *m_animate_checkbox;
    QPushButton *m_quit_button;
    QSlider *m_slider;
    QVBoxLayout *m_main_layout;
};

#endif
