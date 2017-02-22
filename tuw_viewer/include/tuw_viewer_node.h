#ifndef TUW_VIEWER_NODE_H
#define TUW_VIEWER_NODE_H

#include <memory>
#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose2D.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <sensor_msgs/LaserScan.h>
#include <tuw_viewer/views.h>
#include <boost/thread.hpp>

namespace tuw {
/**
 * class to cover the ros communication for the self-localization
 **/
class ViewerNode{
public:
    ViewerNode ( ros::NodeHandle & n ); /// Constructor
private:
    std::shared_ptr<Views> viewsPtr_;
    ros::NodeHandle n_;             /// node handler to the root node
    ros::NodeHandle n_param_;       /// node handler to the current node
    ros::Subscriber sub_cmd_;       /// Subscriber to the command measurements
    ros::Subscriber sub_odometry_;  /// Subscriber to the odometry measurements
    ros::Subscriber sub_laser_;     /// Subscriber to the laser measurements
    void callbackCmd ( const geometry_msgs::Twist& ); /// callback function to catch motion commands
    void callbackOdometry ( const nav_msgs::Odometry& ); /// callback function to catch odometry messages
    void callbackLaser ( const sensor_msgs::LaserScan& ); /// callback function to catch incoming sensor data
};
};

#endif // TUW_VIEWER_NODE_H
