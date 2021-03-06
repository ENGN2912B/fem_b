 FEM Group B
=====
Anna Lischke, Matthew Petersen
------------------------------

### Project: 2D Fluid-Thermal Transport Modeling Application

## Summary

This application consists of a GUI (written in FLTK), a solver (made using the [MOOSE framework](http://www.mooseframework.com)), and a visualization capacity (via VTK). The application allows the user to model 2D fluid (gas) transport with thermal conductivity, using  simplified models based off of work done by [Michaelis and Rogg.](http://dx.doi.org/10.1016/j.jcp.2003.10.033). The user can easily take advantage of the world-class FEM capabilities of MOOSE, and quickly and easily generate input files without having to learn MOOSE input syntax. The output files are then able to viewed using [Paraview.](http://www.paraview.org)

Unfortunately, due to ongoing technical issues, we have not been able to build the application on the CCV itself; the executable was compiled on one of our own machines. To build, we used a Mac with clang installed as the default compiler. Due to an issue with the CCV installation of MOOSE, we were unable to build with GCC on the CCV at all. The compiler on the CCV throws errors when attempting to compile the libmesh library. We do not have write access to the library files installed on CCV in order to debug this issue, but we were able to build and compile without errors using clang on our personal machine.

To use the software application, the user must install the MOOSE framework and build it on their machine. Step-by-step instructions can be found on the [MOOSE Getting Started page](http://mooseframework.com/getting-started/). To build the GUI, the user must also have the FLTK GUI framework installed, which comes with [installation instructions](http://www.fltk.org/doc-1.3/intro.html). FLTK is installed on the CCV. Once that is done, the user should build the application on their machine, by running the `make_app.sh` bash script. 

When that is done, the user can launch the GUI by running the "fem_b_gui" excutable in the application directory. This will bring up an interactive interface for generating program input files.

![fem_b GUI](https://github.com/ENGN2912B/fem_b/blob/master/GUI_fem_b.png "GUI Used to generate input file")

## GUI

In the GUI, the user may input the relevant parameters for their simulation. The simulation is designed to model convection-diffusion of gas in addition to heat conduction (in two dimensions). In order to run the simulation, input parameters and a source function definition are required. These are collected in an input file with extension .i, which is written with a special MOOSE syntax. The GUI generates the input file automatically when the user inputs valid parameter values and pushes the submit button. Below, we discuss the individual items involved in the GUI.

The user may upload their own input file from the input file location box. This feature enables users to avoid entering parameter values in the GUI if they want to use the same input file they generated previously.

Otherwise, the user should type the name of their new input file including the ".i" extension in the "New Input File Name" box.

The GUI generates a rectangular, triangulated mesh where the number of elements in the X- and Y- directions are user-specified in the lower right hand section of the GUI. The "X Max" and "Y Max" parameters refer to the upper right hand corner coordinates of the mesh.


If the user wants to use a different 2D mesh (e.g., graded mesh, quadrilateral mesh, etc.), this can be uploaded using the "Mesh File Location" box. The file type for the mesh input file is ".e".

In the "Simulation Parameters" section, the user enters the desired wall temperature on the bottom and top boundaries of the mesh. These values are only applied if the "Isothermal" radio buttons are selected. The inlet temperature is specified on the left boundary, and is required to be a Dirichlet (isothermal) boundary condition. If the user selects adiabatic boundary conditions on the radio buttons, the simulation will have zero flux across that boundary.

The forcing function corresponds to heat sinks and sources arising from chemical reactions. An example forcing function is "1+x" or "sin(pi*x)". Any function defined in the cmath header is valid.

The equation involving convection of the gas includes a constant velocity vector coefficient. The "Conv. x coefficient" is the x-direction of the velocity and the "Conv. y coefficient" is the y-direction.

The time coefficient parameter is a constant coefficient multiplying the time derivative in the convection-diffusion equation for the gas.

The gas settings section allows the user to input properties of the gas being convected. The density and specific heat parameters are coefficients multiplied by the time derivative of the temperature variable. The thermal conductivity also appears as a diffusion coefficient for temperature in the heat conduction equation.

## Running the Application

To run the application, the user uses the following syntax: `./coupled-opt -i MyInputFile.i`. The built-in MOOSE executioner will take the input file and follow its instructions to run the MOOSE solvers. The user can then use the MOOSE executioner (a GUI called Peacock) to view their results, or read the output data (stored in `peacock_run_tmp_out.e`) using an Exodus-format compatible data viewer, such as ParaView.

![meshgen](https://github.com/ENGN2912B/fem_b/blob/master/mesh_gen.png "Peacock")

Peacock is seen above, as the user will see it on first launch. They can then execute:

![execute](https://github.com/ENGN2912B/fem_b/blob/master/execute.png "Peacock")

And view their results:

![temp](https://github.com/ENGN2912B/fem_b/blob/master/temp_model.png "Peacock")

![gas](https://github.com/ENGN2912B/fem_b/blob/master/gas_model.png "Peacock")

## Project Files

The file structure for the essential files is as follows:

```
fem_b
├── GUI
│   ├── makefile
│   └── src
│       ├── fem_b_gui.cxx
│       ├── fem_b_gui.f
│       ├── fem_b_gui.h
│       ├── fem_b_gui_test.cxx
│       └── gui_main.cpp
├── fem_b_gui // GUI executable
├── Makefile
├── README.md
├── coupled-opt // executable
├── include // header files
│   ├── base
│   │   └── TransportApp.h // skeleton header
│   ├── functions
│   │   └── MyFunction.h // source function kernel header
│   └── kernels
│       ├── Convection.h // fluid convection kernel header
│       ├── HeatConduction.h // heat conduction kernel header
│       ├── HeatConductionTimeDerivative.h // heat conduction transient kernel header
│       ├── MyDiffusion.h // fluid diffusion kernel header
│       └── MyTimeDerivative.h // fluid transient kernel header
├── input_transport.i // sample input file
├── lib // container file for peacock-generated cache
└── src
    ├── base
    │   └── TransportApp.C // skeleton definitions (collects kernels)
    ├── functions
    │   └── MyFunction.C // source function kernel definition
    ├── kernels
    │   ├── Convection.C // fuild convection kernel
    │   ├── HeatConduction.C // heat conduction kernel
    │   ├── HeatConductionTimeDerivative.C // heat conduction transient kernel
    │   ├── MyDiffusion.C // fluid diffusion kernel
    │   └── MyTimeDerivative.C // fluid transient kernel
    └── main.C // MOOSE application runner

```

In this repository, all of the files needed to build and run the application are included, with the exception of MOOSE. For MOOSE, go to [its website.](http://www.mooseframework.com)
