# 3D Case model for PCB

It is possible to generate a 3D model of this PCB, using open source tooling. That means we do not need to maintain a separate 3D model of the PCB, and the case can be generated on demand, taking into account any changes to the PCB. For this to work, it is necessary to install two open source tools:

1. [Turbocase](http://turbocase.org) - This tool is used to generate a SCAD model of the case from the Kicad PCB file.
2. [OpenSCAD](https://www.openscad.org/) - This tool is used to render the SCAD model to an STL file. It has a user interface that can be used to view the model, but we will mainly use it for the command line tooling to convert the SCAD file to separate STL files for the case and case lid.

Once the tools are installed, the case can be generated from the Kicad PCB file. If you have a unix-like system, you can simply run the `generate-case.sh` script in this directory. This script will generate the case and lid STL files in the `case/output` directory.
