int main(int argc, char **argv) {
    ros::init(argc, argv, "read_data"); // Initialize the ROS node
    ros::NodeHandle nh; // Create a node handle
    ros::Publisher pub = nh.advertise<my_ros_msgs::tpcd>("tpcd", 10); // Create a publisher to publish the custom message tpcd

    std::ifstream inputFile("../../qt_develop/data.txt"); // Open the file
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) { // Read each line of data
            std::istringstream iss(line);
            double pointx, pointy, pointz;
            float temperature;
            if (iss >> pointx >> pointy >> pointz >> temperature) { // Parse the data
                my_ros_msgs::tpcd msg;
                msg.temperature = temperature;
                msg.pointx = pointx;
                msg.pointy = pointy;
                msg.pointz = pointz;
                pub.publish(msg); // Publish the message
                ROS_INFO("Published a new tpcd message");
            }
        }
        inputFile.close(); // Close the file
    } else {
        ROS_ERROR("Failed to open the file");
    }
    return 0;
}

