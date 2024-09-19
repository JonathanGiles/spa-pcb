#!/bin/bash

mkdir output

# Asking for some configuration values from the user, or use defaults
pcb_thickness="1.6"
screw_insert_outer_diameter="3.2"
screw_insert_depth="4.0"
headroom="18.0"

# Prompt the user for input
read -p "What is the thickness of the PCB you plan to use? (Default is $pcb_thickness mm): " user_input
actual_pcb_thickness=${user_input:-$pcb_thickness}

read -p "What is the outer diameter of the screw inserts you plan to use? (Default is $screw_insert_outer_diameter mm): " user_input
actual_screw_insert_outer_diameter=${user_input:-$screw_insert_outer_diameter}

read -p "What is the depth of the screw inserts you plan to use? (Default is $screw_insert_depth mm): " user_input
actual_screw_insert_depth=${user_input:-$screw_insert_depth}

# Generate SCAD files using turbocase
echo "Step 1 of 3: Generating SCAD file using turbocase..."
turbocase --verbose ../spanet-pcb.kicad_pcb output/case.scad

# Convert the single SCAD file to separate case and lid STL files using OpenSCAD
echo -e "\n\nConverting SCAD file to STL files..."
echo "Step 2 of 3: Generating Case STL"
openscad -D render=\"case\" \
    -D pcb_thickness=$actual_pcb_thickness \
    -D insert_M2_5_diameter=$actual_screw_insert_outer_diameter \
    -D insert_M2_5_depth=$actual_screw_insert_depth \
    -D headroom=$headroom \
    -o output/case.stl output/case.scad

echo -e "\n\nStep 3 of 3: Generating Lid STL"
openscad -D render=\"lid\" \
    -D pcb_thickness=$actual_pcb_thickness \
    -D insert_M2_5_diameter=$actual_screw_insert_outer_diameter \
    -D insert_M2_5_depth=$actual_screw_insert_depth \
    -o output/lid.stl output/case.scad

echo -e "\n\nSuccess! SCAD files have been converted to STL files. Review the '/case/output' directory for the generated files."