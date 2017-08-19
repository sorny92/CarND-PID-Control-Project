# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Reflection
#### P, I, D parameters selection:
I tunned manually the paramenters because it is a simple system which doesn't need lot of tunning to achieve a decent performance at low speeds.
I firstly tuned for constant throttle (0.3) and a simple PD controller with a P between [0.5,0.7] works quite good, it just need a D value between [1,5] to control the overshoot that the P is creating.

But we want to have fun at higher speeds, I tried to tune for faster speeds but you have a problem, you can't really predict the curvature of the turns ahead. When the CTE starts to increase you need a high P to avoid going out of the road, but that means an inestable system in straight lines. 
What I did to solve the problem is create a pseudo control in the throttle. Based on the steering angle I increase or decrease the throttle, so in turns I can go slower and have more "frames" to react to the turn.
I also decrease the Kp when the speed increase so I can avoid overshooting in fast turns or straight lines. 
   
   
With this simple control I can achieve around 60mph safetely, 70mph can be achieved with a bit of tunning but depending of the angle when the car enters in the turn after the bridge, it sometimes goes off the road.

Note: You can find a video in the ROOT folder that shows 2 laps around the circuit.

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
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

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 
