# About
Learning to create a robot to help human, I will add more study case in the future and the problem-solution as well.

# 1. Motion Imitation
by Xue Bin Peng et al. It provides a Gym environment for training a simulated quadruped robot to imitate various reference motions, and example training code for learning the policies.

Source: 
https://github.com/erwincoumans/motion_imitation/tree/master

https://www.youtube.com/watch?v=lKYh6uuCwRY

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
