# About

CUDA® is a parallel computing platform and programming model that enables dramatic increases in computing performance by harnessing the power of the graphics processing unit (GPU). 

Since its introduction in 2006, CUDA has been widely deployed through thousands of applications and published research papers, and supported by an installed base of hundreds of millions of CUDA-enabled GPUs in notebooks, workstations, compute clusters and supercomputers.  Applications used in astronomy, biology, chemistry, physics, data mining, manufacturing, finance, and other computationally intense fields are increasingly using CUDA to deliver the benefits of GPU acceleration.

The CUDA programming model is a heterogeneous model in which both the CPU and GPU are used. In CUDA, the host refers to the CPU and its memory, while the device refers to the GPU and its memory. Code run on the host can manage memory on both the host and device, and also launches kernels which are functions executed on the device. These kernels are executed by many GPU threads in parallel.

Given the heterogeneous nature of the CUDA programming model, a typical sequence of operations for a CUDA C program is:

1. Declare and allocate host and device memory.
2. Initialize host data.
3. Transfer data from the host to the device.
4. Execute one or more kernels.
5. Transfer results from the device to the host.

## Fields with GPU-accelerated applications 
1. Bioinformatics: High performance computing (HPC) is one of the most essential tools fueling the advancement of computational science. And the universe of scientific computing has expanded in all directions. From weather forecasting and energy exploration, to computational fluid dynamics and life sciences, researchers are fusing traditional simulations with artificial intelligence, machine learning, deep learning, big data analytics, and edge-computing to solve the mysteries of the world around us.

2. Data Science: Data science workflows have traditionally been slow and cumbersome, relying on CPUs to load, filter, and manipulate data and train and deploy models. GPUs substantially reduce infrastructure costs and provide superior performance for end-to-end data science workflows using RAPIDS™ open source software libraries. GPU-accelerated data science is available everywhere—on the laptop, in the data center, at the edge, and in the cloud.

3. Public Sector: In one of the largest technology transformations ever undertaken, the AI revolution is happening right now amongst the U.S government.  AI is impacting new developments in cybersecurity, healthcare, life sciences, platform sustainment, humanitarian response, and disaster relief. NVIDIA is at the forefront of this democratization of AI, building the technology that will make communities safer and more connected everywhere. GPU-accelerated systems are assisting during natural disasters; serving communities by improving safety, power efficiency, and traffic flows; and helping leaders solve the unsolvable problems within the areas of cybersecurity and cyber resilience.

a. Intelligent System
NVIDIA’s AI platform, for both deep learning training and inference, is transforming the way computers perform perceptual tasks such as computer vision, pattern detection, speech recognition, and behavior prediction. These improvements make it possible to take labor-intensive jobs and automate them for applications like disaster response and humanitarian relief. 
With NVIDIA DeepStream, TAO Toolkit, and CUDA-X™ acceleration libraries, federal and civilian agencies are able to change the way we approach weather prediction models, evacuation route predictions, rescue mission.

b. Predictive Maintenance

Platform sustainment is one of the greatest challenges the U.S. government faces today, managing and maintaining hundreds of thousands of aging aircraft, vehicles, and ships critical to the safety of our nation and allies. Legacy approaches dominate the market, with platforms continuing to experience a high rate of downtime and prohibitive maintenance costs. 

Predictive maintenance is a modern approach driven by predictive analytics and AI that’s been shown to increase availability and reduce costs significantly. NVIDIA EGX™, the edge AI platform for AI and high-performance data analytics, powers all aspects of predictive maintenance—from supply chain optimization, to automated visual inspections, to early failure prediction.

c. Cybersecurity

Defending and securing computer systems requires customizable AI that operates at real-time speeds on extremely large networks. NVIDIA GPUs and the NVIDIA RAPIDS™ suite of open-source software libraries are critical building blocks for creating the future of accelerated log ingestion, anomaly detection, threat hunting, and other essential information security workflows. When security teams and cybersecurity data scientists can leverage these tools and technologies, they can extend the security environment beyond traditional security information and event management (SIEM) and accelerate compute capabilities that can adapt to any network.

d. Autonomous Machines

AI is being used across branches of the U.S government to deliver autonomously operated platforms in the air, on land, and at sea. GPU-powered autonomous machines and robots use AI to solve some of the world’s toughest problems, and they’ve demonstrated their potential to save both lives and costs by enabling efficient and safe operations. With the NVIDIAⓇ Jetson™ platform , it’s possible to develop and deploy AI-powered robots, drones, intelligent video analytics (IVA) applications, and other autonomous machines.

4. Computer Vision
Empower your devices to perceive and understand the world around us with powerful software that’s masterful, scalable, and tested. NVIDIA software enables the end-to-end computer vision workflow—from model development to deployment—for individual developers, higher education and research, and enterprises. Computer vision is a field of technology that enables devices like smart cameras to acquire, process, analyze, and interpret images and videos. For example, the driver assistance system on a vehicle designed with computer vision algorithms uses cameras and other sensors to not only display, but to perceive what’s in front of and behind it to identify and classify regions or points of interest within an image frame. In this case, computer vision has a safety application—helping the vehicle operator to navigate around road debris, other vehicles, animals, and people. Similarly, farmers might rely on computer vision-enabled devices to automatically identify weeds and where crops are growing well over a large field to increase yield. Today’s computer vision tasks like these are based on artificial intelligence and, more specifically, deep learning, a type of machine learning patterned after the brain. Deep learning-based computer vision models enable devices to perform and adapt like a human expert while requiring significantly less input.

5. Data Center GPUs for Servers
Accelerate your most demanding HPC and hyperscale data center workloads with NVIDIA® Data Center GPUs. Data scientists and researchers can now parse petabytes of data orders of magnitude faster than they could using traditional CPUs, in applications ranging from energy exploration to deep learning. NVIDIA’s accelerators also deliver the horsepower needed to run bigger simulations faster than ever before. Plus, NVIDIA GPUs deliver the highest performance and user density for virtual desktops, applications, and workstations.

6. Healthcare
Accelerated computing and AI are supercharging the next generation of medical devices and biomedical research. With one platform for imaging, genomics, patient monitoring, and drug discovery—deployed anywhere, from embedded to edge to every cloud—NVIDIA Clara™ is enabling the healthcare industry to innovate and accelerate the journey to precision medicine.

#### CUDA is a standard feature in all NVIDIA GeForce, Quadro, and Tesla GPUs as well as NVIDIA GRID solutions. 

# How to get started

Software developers, scientists and researchers can add support for GPU acceleration in their own applications using one of  three simple approaches:

* Drop in a GPU-accelerated library to replace or augment CPU-only libraries such as MKL BLAS, IPP, FFTW and other widely-used libraries
* Automatically parallelize loops in Fortran or C code using OpenACC directives for accelerators
* Develop custom parallel algorithms and libraries using a familiar programming language such as C, C++, C#, Fortran, Java, Python, etc.

# Examples: Compiling Cuda

The CUDA C compiler, nvcc, is part of the NVIDIA CUDA Toolkit.  
To compile our SAXPY example, we save the code in a file with a .cu extension, say saxpy.cu. We can then compile it with nvcc.

## Compiling and Running the Code

To check if CUDA is installed:
```
gcc -I/usr/local/cuda/include -L/usr/local/cuda/lib64 has_cuda.c -lcudart -o has_cuda

```

The next example: SAXPY that is stands for “Single-precision A*X Plus Y”, and is a good “hello world” example for parallel computation. 

```
nvcc -o saxpy saxpy.cu
./saxpy
```

####   Nvidia has compiler for this which will handle everything named nvcc, if you use nvcc, you won't need to explicitly select the -I and -L path.

# Sources

https://developer.nvidia.com/about-cuda

https://developer.nvidia.com/blog/easy-introduction-cuda-c-and-c/
