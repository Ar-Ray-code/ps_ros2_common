#ifndef JOY_BASE_HPP
#define JOY_BASE_HPP

#define PS5 5
#define PS4 4
#define PS3 3

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joy.hpp>
#include <string>

class ps_base
{
public:
  bool up_btn;
  bool down_btn;
  bool right_btn;
  bool left_btn;
  bool square_btn;
  bool circle_btn;
  bool triangle_btn;
  bool cross_btn;
  bool L1_btn;
  bool R1_btn;
  bool select_btn;
  bool start_btn;
  bool PS_btn;
  bool share_btn;
  bool options_btn;
  bool create_btn;
  bool R2_btn;
  bool L2_btn;

  float R2;
  float L2;
  float d_pad_x;
  float d_pad_y;
  float joy_left_x;
  float joy_left_y;
  float joy_right_x;
  float joy_right_y;

  virtual void get_data(const sensor_msgs::msg::Joy::SharedPtr msg) = 0;
  virtual void sub_joy_thread(const sensor_msgs::msg::Joy::SharedPtr msg)
  {
    get_data(msg);
  }
  rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr sub_joy;

  ps_base()
  {
    init_data();
  }

  void btn2d_pad()
  {
    d_pad_x = -1 * float(right_btn) + float(left_btn);
    d_pad_y = -1 * float(down_btn) + float(up_btn);
  }

  void d_pad2btn()
  {
    if (int(d_pad_x) == 1) {
      left_btn = 1;
      right_btn = 0;
    } else if (int(d_pad_x) == -1) {
      left_btn = 0;
      right_btn = 1;
    } else {
      left_btn = 0;
      right_btn = 0;
    }

    if (int(d_pad_y) == 1) {
      up_btn = 1;
      down_btn = 0;
    } else if (int(d_pad_y) == -1) {
      up_btn = 0;
      down_btn = 1;
    } else {
      up_btn = 0;
      down_btn = 0;
    }
  }

  void init_data()
  {
    up_btn = 0;
    down_btn = 0;
    right_btn = 0;
    left_btn = 0;
    square_btn = 0;
    circle_btn = 0;
    triangle_btn = 0;
    cross_btn = 0;
    L1_btn = 0;
    R1_btn = 0;
    select_btn = 0;
    start_btn = 0;
    PS_btn = 0;
    share_btn = 0;
    options_btn = 0;
    create_btn = 0;
    R2_btn = 0;
    L2_btn = 0;

    R2 = 1.0;
    L2 = 1.0;
    d_pad_x = 0;
    d_pad_y = 0;
    joy_left_x = 0;
    joy_left_y = 0;
    joy_right_x = 0;
    joy_right_y = 0;
  }
};

#endif
