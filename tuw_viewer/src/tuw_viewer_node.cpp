#include "tuw_viewer_node.h"

using namespace tuw;

int main ( int argc, char **argv ) {

  
    ros::init ( argc, argv, "self_localization" );
    ros::NodeHandle n;
    ViewerNode node ( n );
    return 0;
}

/**
 * Constructor
 **/
ViewerNode::ViewerNode ( ros::NodeHandle & n )
    : n_ ( n ),
      n_param_ ( "~" ) {

    /// subscribes to  odometry values
    sub_cmd_ = n.subscribe ( "cmd", 1, &ViewerNode::callbackCmd, this );

    /// subscribes to  odometry values
    sub_odometry_ = n.subscribe ( "odom", 1, &ViewerNode::callbackOdometry, this );

    /// subscribers to laser sensor
    sub_laser_ = n.subscribe ( "base_scan", 10, &ViewerNode::callbackLaser, this );
	
    
    viewsPtr_ = std::make_shared<tuw::Views>();
    mglFLTK gr ( viewsPtr_.get(),"Multi-threading test" );	// create window
    gr.RunThr();
    viewsPtr_->SetWnd ( &gr );	// pass window pointer to yours class
    viewsPtr_->Run();	// run calculations
    
    ros::Rate rate ( 10 );
        
    while ( ros::ok() ) {

        /// calls all callbacks waiting in the queue
        ros::spinOnce();

        /// sleep for the time remaining to let us hit our publish rate
        rate.sleep();
	gr.Update();
    }
}


/**
 * copies incoming laser messages to the base class
 * @param laser
 **/
void ViewerNode::callbackLaser ( const sensor_msgs::LaserScan &_laser ) {
  ROS_INFO("callbackLaser");
    int nr = ( _laser.angle_max - _laser.angle_min ) / _laser.angle_increment;
    viewsPtr_->laser[0].Create ( nr );
    viewsPtr_->laser[1].Create ( nr );
    for ( int i = 0; i < nr; i++ ) {
        float length = _laser.ranges[i];
        float angle = _laser.angle_min + ( _laser.angle_increment * i );
        viewsPtr_->laser[0][i] = cos ( angle ) * length;
        viewsPtr_->laser[1][i] = sin ( angle ) * length;
    }
}

/**
 * copies incoming odemetry messages to the base class
 * @param odom
 **/
void ViewerNode::callbackOdometry ( const nav_msgs::Odometry &odom ) {
}

/**
 * copies incoming robot command message
 * @param cmd
 **/
void ViewerNode::callbackCmd ( const geometry_msgs::Twist& cmd ) {
}

