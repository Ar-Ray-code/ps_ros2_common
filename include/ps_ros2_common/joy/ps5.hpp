#ifndef PS5_HPP
#define PS5_HPP

#include "ps_base.hpp"

namespace ps5
{
class ps : public ps_base
{
public:
  void get_data(const sensor_msgs::msg::Joy::SharedPtr msg)
  {
    cross_btn = msg->buttons[0];
    circle_btn = msg->buttons[1];
    triangle_btn = msg->buttons[2];
    square_btn = msg->buttons[3];

    L1_btn = bool(msg->buttons[4]);
    R1_btn = bool(msg->buttons[5]);
    L2_btn = bool(msg->buttons[6]);
    R2_btn = bool(msg->buttons[7]);

    select_btn = bool(msg->buttons[8]);
    share_btn = bool(msg->buttons[8]);
    create_btn = bool(msg->buttons[8]);

    start_btn = bool(msg->buttons[9]);
    options_btn = bool(msg->buttons[9]);

    PS_btn = bool(msg->buttons[10]);

    joy_left_x = msg->axes[0];
    joy_left_y = msg->axes[1];

    L2 = msg->axes[2];

    joy_right_x = msg->axes[3];
    joy_right_y = msg->axes[4];

    R2 = msg->axes[5];

    d_pad_x = msg->axes[6];
    d_pad_y = msg->axes[7];

    d_pad2btn();
  }

  // virtual void sub_joy_thread(const sensor_msgs::msg::Joy::SharedPtr msg)
  // {
  //     get_data(msg);
  // }
};
}

#endif
