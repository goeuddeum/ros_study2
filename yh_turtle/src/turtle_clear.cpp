#include "ros/ros.h"
#include "std_srvs/Empty.h"

struct MyClient
{
    public:
    MyClient()
    {
        
        client = nh.serviceClient<std_srvs::Empty>("clear");
    }    
    void call()
    {
        if (client.call(srv))
        {
            ROS_INFO("Clear");
        }
        else
        {
            ROS_ERROR("Failed");
        }
    }
    private:
    ros::NodeHandle nh;
    ros::ServiceClient client;
    std_srvs::Empty srv;
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "turtle_clear");
    MyClient my_client = MyClient();
    my_client.call();
    
    return 0;
}

