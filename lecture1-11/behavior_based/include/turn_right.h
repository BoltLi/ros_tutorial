#ifndef TURNRIGHT_H
#define TURNRIGHT_H

#include "Behavior.h"
#include <ros/ros.h>
#include "sensor_msgs/LaserScan.h"
#include <cmath>

class turn_right: public Behavior {
public:
    turn_right();
    virtual bool startCond();
    virtual void action();
    virtual bool stopCond();
    virtual ~turn_right();
private:
    double TURN_SPEED_MPS = 1.0;
    double MIN_SCAN_ANGLE_RAD = 0;
    double MAX_SCAN_ANGLE_RAD = 30.0/180 * M_PI;
    double MAX_SCAN_ANGLES = 0;
    float MIN_PROXIMITY_RANGE_M = 1.0;

    ros::NodeHandle node;
    ros::Publisher commandPub;
    ros::Subscriber laserSub;

    void scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan);
    bool b_keep_turn_right;
};

#endif
