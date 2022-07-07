# About
Learning to create a robot to help human, I will add more study case in the future and the problem-solution as well.

# 1. Motion Imitation
Animals are capable of performing diverse and agile locomotion behaviors in nature, but transferring such behaviors on robots remains a challenge. Robots operating in human environments should be equipped with diverse skills like trot and pace when walking slowly or speeding up, turn around corners, and side-step around obstacles. However, building a universal controller that is robust enough to perform such a wide range of skills is still an unsolved problem.

Sources: 
* https://github.com/erwincoumans/motion_imitation/tree/master
* https://github.com/bulletphysics/pybullet_robots
* https://www.youtube.com/watch?v=lKYh6uuCwRY
* https://arxiv.org/abs/2109.13362

I am going to try the example using the work of Xue Bin Peng et al. It provides a Gym environment for training a simulated quadruped robot to imitate various reference motions, and example training code for learning the policies.

You can git clone the master branch:
```
git clone https://github.com/erwincoumans/motion_imitation.git
```

Then install the dependencies:
1. OpenMPI

After that, install requirements:
```
pip install -r requirements.txt
```

You can explore the environments by running:
```
python3 -m motion_imitation.examples.test_env_gui --robot_type=A1 --motor_control_mode=Position --on_rack=True
```

#### robot_type: 
choose between `A1` and `Laikago` for different robot.

#### motor_control_mode: 
choose between `Position` or `Torque` for different motor control modes.

#### on_rack: 
whether to fix the robot's base on a rack. Setting `on_rack=True` is handy for debugging visualizing open-loop gaits.

# 2. Pybullet Robots
PyBullet is a fast and easy to use Python module for robotics simulation and machine learning, with a focus on sim-to-real transfer. With PyBullet you can load articulated bodies from URDF, SDF, MJCF and other file formats. PyBullet provides forward dynamics simulation, inverse dynamics computation, forward and inverse kinematics, collision detection and ray intersection queries. The Bullet Physics SDK includes PyBullet robotic examples such as a simulated Minitaur quadruped, humanoids running using TensorFlow inference and KUKA arms grasping objects. 

To download it
```
git clone https://github.com/bulletphysics/pybullet_robots.git
```

Install pybullet with `pip` then you can run the example:

```
pip install pybullet
python3 cassie.py
```
You can use these keyboard shortcuts:
S -> Lighting ON/OFF
G -> Eliminate Windows
V -> Eliminate Objects

![cassie](https://github.com/glanzkaiser/glanzshamzs/blob/main/Robotics/images/cassie.png)


## Glanz' idea / question in head:
1. How to create real-time human motion imitation approach to control an anthropomorphic dual arm robot or even any other robot or even imitate real-time motion of Lamborghini to Arduino RC car
2. Not only moving, but responding to output influences, feels itchy you scratch that part. Sleepy then you sleep or for other personality you try to not sleep by washing your face. Smell something that makes you allergic you will sneeze. 
3. If we can imitate not only human, animals, but also plants, then the planets rotation in a solar system. then we can simulate the real world and create infinite universe that will need more than exa- or beyond that of computational power.
