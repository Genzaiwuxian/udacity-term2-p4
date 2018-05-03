# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program
using PID controller to control throttle and steering angle, and let vehicle driving on the road.
---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## PID & process

PID controller is one of most classical controllers, in this project, the error is the etc (differneces bettwen realy trajactory and accutal trajacotory).
1. initialize PID controller and throttle_PID controller
2. receive cte and calculate error_P, error_I and error_D;
3. return steering angle= -Kp*error_P - Ki*error_I - Kd*error_D, and set steering angle between [-1, +1]
4. receive speed value and use target_speed-speed as error_PID_throttle, then calculate the throttle value
5. turning the PID controller parameters, makesure vehicle driving on the road

## Reflection
1. the target speed is too small=20Mph, it can be improved next time;
2. didn't use twiddle method to tune PID parameters, try next time.

