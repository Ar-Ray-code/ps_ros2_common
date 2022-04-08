#include "joy/ps_base.hpp"
#define JOY_VERSION PS3

#include <std_msgs/msg/int32.hpp>

#if JOY_VERSION == PS5
#include "joy/ps5.hpp"
using namespace ps5;
#elif JOY_VERSION == PS4
#include "joy/ps4.hpp"
using namespace ps4;
#elif JOY_VERSION == PS3
#include "joy/ps3.hpp"
using namespace ps3;
#endif

namespace ps_ros2_common {

class example_joy : public rclcpp::Node, public ps
{
public:
  rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr pub_int;
  std_msgs::msg::Int32 send_data;

  void sub_joy_thread(const sensor_msgs::msg::Joy::SharedPtr msg)
  {
    get_data(msg);

    auto tmp = std::system("clear");
    (void)tmp; // for unused warning

    std::cout << std::endl;
    std::cout << "square_btn:" << square_btn << std::endl;
    std::cout << "cross_btn :" << cross_btn << std::endl;
    std::cout << "circle_btn: " << circle_btn << std::endl;
    std::cout << "triangle_btn: " << triangle_btn << std::endl;
    std::cout << std::endl;
    std::cout << "L1_btn: " << L1_btn << std::endl;
    std::cout << "R1_btn: " << R1_btn << std::endl;
    std::cout << "L2_btn: " << L2_btn << std::endl;
    std::cout << "R2_btn: " << R2_btn << std::endl;
    std::cout << std::endl;
    std::cout << "up_btn: " << up_btn << std::endl;
    std::cout << "down_btn: " << down_btn << std::endl;
    std::cout << "left_btn: " << left_btn << std::endl;
    std::cout << "right_btn: " << right_btn << std::endl;
    std::cout << std::endl;
    std::cout << "select_btn: " << select_btn << std::endl;
    std::cout << "share_btn: " << share_btn << std::endl;
    std::cout << "create_btn: " << create_btn << std::endl;
    std::cout << std::endl;
    std::cout << "start_btn: " << start_btn << std::endl;
    std::cout << "options_btn: " << options_btn << std::endl;
    std::cout << std::endl;
    std::cout << "PS_btn: " << PS_btn << std::endl;
    std::cout << std::endl;
    std::cout << "joy_left_x: " << joy_left_x << std::endl;
    std::cout << "joy_left_y: " << joy_left_y << std::endl;
    std::cout << std::endl;
    std::cout << "joy_right_x: " << joy_right_x << std::endl;
    std::cout << std::endl;
    std::cout << "L2: " << L2 << std::endl;
    std::cout << "R2: " << R2 << std::endl;
    std::cout << std::endl;
    std::cout << "joy_right_y: " << joy_right_y << std::endl;
    std::cout << std::endl;
    std::cout << "d_pad_x: " << d_pad_x << std::endl;
    std::cout << "d_pad_y: " << d_pad_y << std::endl;

    send_data.data = PS_btn;
    pub_int->publish(send_data);
  }

  example_joy(const rclcpp::NodeOptions & options)
  : Node("joy_test", options)
  {
    using namespace std::chrono_literals;
    sub_joy =
      this->create_subscription<sensor_msgs::msg::Joy>(
      "/joy", 1,
      std::bind(&ps::sub_joy_thread, this, std::placeholders::_1));
    pub_int = this->create_publisher<std_msgs::msg::Int32>("output", 1);
  }
};

} // namespace ps_ros2_common

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(ps_ros2_common::example_joy)

int main(int argc, char ** argv)
{
  using namespace ps_ros2_common;
  rclcpp::init(argc, argv);
  rclcpp::NodeOptions options;
  auto node = std::make_shared<example_joy>(options);

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
