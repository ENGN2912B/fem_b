// generated by Fast Light User Interface Designer (fluid) version 1.0304

#include "fem_b_gui.h"
#include <assert.h>
#include <fstream>
#include <string>
#include <FL/fl_ask.H>

/**
 Function to print out input sub-block
*/
std::ostream& inblock(std::string name, int size, std::string ent[], std::string val[],std::ostream& out) {
  out << "[./" << name << "]\n";
  if (size > 0) {
  for (int ii=0;ii<size; ++ii) {
  	out << ent[ii] << " = " << val[ii] << "\n";
  }
  }
  
  out << "[../]\n";
}

Fl_Double_Window *main_window=(Fl_Double_Window *)0;

Fl_Group *bc_set=(Fl_Group *)0;

Fl_Round_Button *iso_button_t=(Fl_Round_Button *)0;

static void cb_iso_button_t(Fl_Round_Button*, void*) {
  if (iso_button_t->value()) {
adia_button_t->value(0);
} else {
adia_button_t->value(1);
};
}

Fl_Round_Button *adia_button_t=(Fl_Round_Button *)0;

static void cb_adia_button_t(Fl_Round_Button*, void*) {
  if (adia_button_t->value()) {
iso_button_t->value(0);
} else {
iso_button_t->value(1);
};
}

Fl_Round_Button *iso_button_b=(Fl_Round_Button *)0;

static void cb_iso_button_b(Fl_Round_Button*, void*) {
  if (iso_button_b->value()) {
adia_button_b->value(0);
} else {
adia_button_b->value(1);
};
}

Fl_Round_Button *adia_button_b=(Fl_Round_Button *)0;

static void cb_adia_button_b(Fl_Round_Button*, void*) {
  if (adia_button_b->value()) {
iso_button_b->value(0);
} else {
iso_button_b->value(1);
};
}

Fl_Input *wall_temp_t=(Fl_Input *)0;

Fl_Input *wall_temp_b=(Fl_Input *)0;

Fl_Input *in_temp=(Fl_Input *)0;

Fl_Input *funcin=(Fl_Input *)0;

Fl_Input *conv_x=(Fl_Input *)0;

Fl_Input *conv_y=(Fl_Input *)0;

Fl_Input *tcoef=(Fl_Input *)0;

Fl_Group *gas_set=(Fl_Group *)0;

Fl_Input *gas_tc=(Fl_Input *)0;

Fl_Input *gas_dens=(Fl_Input *)0;

Fl_Input *gas_sh=(Fl_Input *)0;

Fl_Group *mesh_set=(Fl_Group *)0;

Fl_Input *x_elem=(Fl_Input *)0;

Fl_Input *y_elem=(Fl_Input *)0;

Fl_Input *xmax=(Fl_Input *)0;

Fl_Input *ymax=(Fl_Input *)0;

Fl_Group *time_set=(Fl_Group *)0;

Fl_Input *duration=(Fl_Input *)0;

Fl_Input *timestep=(Fl_Input *)0;

Fl_Button *submit=(Fl_Button *)0;

static void cb_submit(Fl_Button*, void*) {
  std::string Twt_str, Twb_str, Ti_str, TC_str, dens_str, SH_str, MF_str, func_str, conv_x_str, conv_y_str, tcoef_str; //Po_str
std::string RX_str, Hfuel_str, El_x_str, El_y_str, dur_str, timestep_str, xmax_str, ymax_str;
std::string input_str, mesh_str;
bool adia_iso_t, adia_iso_b;


if (wall_temp_t->value()) {
if (atof(wall_temp_t->value()) < 0) {
fl_alert("Temperature must be non-negative.");
}
Twt_str = std::string(wall_temp_t->value());
} else {
Twt_str="300";
}

if (wall_temp_b->value()) {
if (atof(wall_temp_b->value()) < 0) {
fl_alert("Temperature must be non-negative.");
}
Twb_str = std::string(wall_temp_b->value());
} else {
Twb_str="300";
}

if (iso_button_t->value()) {
adia_iso_t = false;
} else if (adia_button_t->value()) {
adia_iso_t = true;
} else {
adia_iso_t = false;
}

if (iso_button_b->value()) {
adia_iso_b = false;
} else if (adia_button_b->value()) {
adia_iso_b = true;
} else {
adia_iso_b = false;
}

if (conv_x->value()) {
conv_x_str = std::string(conv_x->value());
} else {
conv_x_str="1.0";
}

if (conv_y->value()) {
conv_y_str = std::string(conv_y->value());
} else {
conv_y_str="0.0";
}

if (in_temp->value()) {
Ti_str = std::string( in_temp->value());
} else {
Ti_str = std::string("300");
}

// if (out_p->value()) {
// Po_str = std::string( out_p->value());
// } else {
// Po_str = std::string("300");
// }

if (gas_tc->value()) {
TC_str = std::string("'")+std::string( gas_tc->value())+std::string("'");
} else {
TC_str = std::string("300");
}

if (gas_dens->value()) {
dens_str = std::string("'")+std::string( gas_dens->value())+std::string("'");
} else {
dens_str = std::string("300");
}

if (gas_sh->value()) {
SH_str = std::string("'")+std::string( gas_sh->value())+std::string("'");
} else {
SH_str = std::string("300");
}

if (funcin->value()) {
func_str = std::string(funcin->value());
} else {
func_str = 1;
}

if (x_elem->value()) {
if (atof(x_elem->value()) <0) {
fl_alert("Number of elements must be non-negative.");
}
El_x_str = std::string( x_elem->value());
} else {
El_x_str = std::string("20");
}

if (y_elem->value()) {
if (atof(y_elem->value()) < 0) {
fl_alert("Number of elements must be non-negative.");
}
El_y_str = std::string( y_elem->value());
} else {
El_x_str = std::string("20");
}

if (xmax->value()) {
xmax_str = std::string( xmax->value());
} else {
xmax_str = std::string("40");
}

if (tcoef->value()) {
tcoef_str = std::string( tcoef->value());
} else {
tcoef_str = std::string("1.0");
}

if (ymax->value()) {
ymax_str = std::string( ymax->value());
} else {
ymax_str = std::string("40");
}


if (duration->value()) {
dur_str = std::string( duration->value());
} else {
dur_str = std::string("300");
}

if (timestep->value()) {
timestep_str = std::string(timestep->value());
} else {
timestep_str = std::string("2");
}

input_str = std::string("default.i");

if (in_file->value() > 0) {
input_str = std::string(in_file->text(in_file->value()));
} else if (new_file->value()) {
input_str = std::string(new_file->value());
}

if (mesh_file->value() > 0) {
mesh_str = std::string(mesh_file->text(mesh_file->value()));
} else {
mesh_str = std::string("default_mesh.e");
}

std::ofstream outfile(input_str,std::ios::out);

assert(outfile.is_open());

// Mesh

outfile << "[Mesh]\n";

if (mesh_file->value() == 0 && bool(x_elem->value())&& bool(x_elem->value())) {
	outfile << "type = GeneratedMesh\n";
	outfile << "dim = 2\n";
	outfile << "nx = " << El_x_str << "\n";
	outfile << "ny = " << El_y_str << "\n";
	outfile << "nz = 0\n\n";
	outfile << "xmax = " << xmax_str << "\n";
	outfile << "ymax = " << ymax_str << "\n";
	outfile << "zmax = 0\n";
	outfile << "elem_type = TRI3\n";
} else {
	outfile << "file = " << mesh_str << "\n";
}

outfile << "[]\n\n";

outfile << "[Variables]\n[./temp]\n[../]\n[./convdiff]\norder = FIRST\nfamily = LAGRANGE\n[../]\n[]\n\n";

outfile << "[Functions]\n[./forcing_func]\ntype = ParsedFunction\nvalue = " << func_str << "\n[../]\n[]\n\n";

outfile << "[Kernels]\n[./hc]\n type = HeatConduction\n variable = temp\n[../]\n\n";

outfile << "[./HeatTdot]\ntype = HeatConductionTimeDerivative\nvariable = temp\n[../]\n";

outfile << "[./conv]\ntype = Convection\nvariable = convdiff\nvelocity = '" << conv_x_str << " " << conv_y_str << " 0.0'\n[../]\n";

outfile << "[./diff]\ntype = MyDiffusion\nvariable = convdiff\n[../]\n";

outfile << "[./euler]\ntype = MyTimeDerivative\nvariable = convdiff\ntime_coefficient = " << tcoef_str << "\n[../]\n";

outfile << "[./forcing]\ntype = UserForcingFunction\nvariable = temp\nfunction = forcing_func\n[../]\n[]\n\n";

outfile << "[BCs]\n";

std::string dirnames[4] = {std::string("type"),std::string("variable"),std::string("boundary"),std::string("value")};
std::string dirtop[4] = {std::string("DirichletBC"),std::string("temp"),std::string("top"),Twt_str};
std::string dirleft[4] = {std::string("DirichletBC"),std::string("temp"),std::string("left"),Ti_str};
std::string dirbot[4] = {std::string("DirichletBC"),std::string("temp"),std::string("bottom"),Twb_str};

std::string dir_diff_left[4] = {std::string("DirichletBC"),std::string("temp"),std::string("left"),std::string("1.0")};
std::string dir_diff_top[4] = {std::string("DirichletBC"),std::string("temp"),std::string("top"),std::string("0.0")};
std::string dir_diff_bot[4] = {std::string("DirichletBC"),std::string("temp"),std::string("bottom"),std::string("0.0")};

std::string neunames[4] = {std::string("type"),std::string("variable"),std::string("boundary")};
std::string neutop[4] = {std::string("NeumannBC"),std::string("temp"),std::string("top")};
std::string neubot[4] = {std::string("NeumannBC"),std::string("temp"),std::string("bottom")};
std::string neurig[4] = {std::string("NeumannBC"),std::string("temp"),std::string("right")};


if (adia_iso_b && adia_iso_t) {
inblock(std::string("left"),4,dirnames,dirleft,outfile);
inblock(std::string("top"),3,neunames,neutop,outfile);
inblock(std::string("bottom"),3,neunames,neubot,outfile);
inblock(std::string("right"),3,neunames,neurig,outfile);
} else if (adia_iso_b && !adia_iso_t) {
inblock(std::string("left"),4,dirnames,dirleft,outfile);
inblock(std::string("top"),4,dirnames,dirtop,outfile);
inblock(std::string("bottom"),3,neunames,neubot,outfile);
inblock(std::string("right"),3,neunames,neurig,outfile);
} else if (!adia_iso_b && adia_iso_t) {
inblock(std::string("left"),4,dirnames,dirleft,outfile);
inblock(std::string("top"),3,neunames,neutop,outfile);
inblock(std::string("bottom"),4,dirnames,dirbot,outfile);
inblock(std::string("right"),3,neunames,neurig,outfile);
} else if (!adia_iso_b && !adia_iso_t) {
inblock(std::string("left"),4,dirnames,dirleft,outfile);
inblock(std::string("top"),4,dirnames,dirtop,outfile);
inblock(std::string("bottom"),4,dirnames,dirbot,outfile);
inblock(std::string("right"),3,neunames,neurig,outfile);
}

inblock(std::string("left_diffused"),4,dirnames,dir_diff_left,outfile);
inblock(std::string("top_diffused"),4,dirnames,dir_diff_top,outfile);
inblock(std::string("bott_diffused"),4,dirnames,dir_diff_bot,outfile);

outfile << "[]\n\n";

outfile << "[Materials]\n";

std::string matnames[4] = {std::string("type"), std::string("prop_names"),std::string("prop_values"),std::string("block")};
std::string kvals[4] = {std::string("GenericConstantMaterial"),std::string("'thermal_conductivity'"),TC_str,std::string("0")};
std::string cpvals[4] = {std::string("GenericConstantMaterial"),std::string("'specific_heat'"),SH_str,std::string("0")};
std::string rhovals[4] = {std::string("GenericConstantMaterial"),std::string("'density'"),dens_str,std::string("0")};
inblock(std::string("k"),4,matnames,kvals,outfile);
inblock(std::string("cp"),4,matnames,cpvals,outfile);
inblock(std::string("rho"),4,matnames,rhovals,outfile);
outfile << "[]\n\n";

outfile << "[Executioner]\n";
outfile << "type = Transient\nsolve_type = 'PJFNK'\n";
outfile << "num_steps = " << dur_str << "\n";
outfile << "dt = " << timestep_str << "\n";
outfile << "[]\n\n";

outfile << "[Outputs]\nexecute_on = 'timestep_end'\nexodus = true\n[]";
}

Fl_File_Browser *in_file=(Fl_File_Browser *)0;

Fl_File_Browser *mesh_file=(Fl_File_Browser *)0;

Fl_Input *new_file=(Fl_Input *)0;

Fl_Double_Window* make_window() {
  { main_window = new Fl_Double_Window(675, 720, "Input File Generator");
    { bc_set = new Fl_Group(190, 30, 475, 475, "Simulation Parameters");
      { iso_button_t = new Fl_Round_Button(510, 119, 25, 25, "Isothermal (top");
        iso_button_t->down_box(FL_ROUND_DOWN_BOX);
        iso_button_t->value(1);
        iso_button_t->callback((Fl_Callback*)cb_iso_button_t);
        iso_button_t->align(Fl_Align(FL_ALIGN_LEFT));
        iso_button_t->when(FL_WHEN_CHANGED);
      } // Fl_Round_Button* iso_button_t
      { adia_button_t = new Fl_Round_Button(510, 138, 25, 25, "Adiabatic (top)");
        adia_button_t->down_box(FL_ROUND_DOWN_BOX);
        adia_button_t->callback((Fl_Callback*)cb_adia_button_t);
        adia_button_t->align(Fl_Align(FL_ALIGN_LEFT));
      } // Fl_Round_Button* adia_button_t
      { iso_button_b = new Fl_Round_Button(510, 156, 25, 25, "Isothermal (Bottom)");
        iso_button_b->down_box(FL_ROUND_DOWN_BOX);
        iso_button_b->value(1);
        iso_button_b->callback((Fl_Callback*)cb_iso_button_b);
        iso_button_b->align(Fl_Align(FL_ALIGN_LEFT));
        iso_button_b->when(FL_WHEN_CHANGED);
      } // Fl_Round_Button* iso_button_b
      { adia_button_b = new Fl_Round_Button(510, 173, 25, 25, "Adiabatic (bottom)");
        adia_button_b->down_box(FL_ROUND_DOWN_BOX);
        adia_button_b->callback((Fl_Callback*)cb_adia_button_b);
        adia_button_b->align(Fl_Align(FL_ALIGN_LEFT));
      } // Fl_Round_Button* adia_button_b
      { wall_temp_t = new Fl_Input(510, 45, 130, 25, "Wall Temperature (top)");
      } // Fl_Input* wall_temp_t
      { wall_temp_b = new Fl_Input(510, 70, 130, 25, "Wall Temperature (bottom)");
      } // Fl_Input* wall_temp_b
      { in_temp = new Fl_Input(510, 95, 130, 25, "Inlet Temperature");
      } // Fl_Input* in_temp
      { funcin = new Fl_Input(510, 197, 130, 25, "Temp. Forcing Function");
      } // Fl_Input* funcin
      { conv_x = new Fl_Input(510, 220, 130, 25, "Conv. X coefficient");
      } // Fl_Input* conv_x
      { conv_y = new Fl_Input(510, 245, 130, 25, "Conv. Y coefficient");
      } // Fl_Input* conv_y
      { tcoef = new Fl_Input(510, 270, 130, 25, "Time coefficient");
      } // Fl_Input* tcoef
      bc_set->end();
    } // Fl_Group* bc_set
    { gas_set = new Fl_Group(185, 323, 475, 473, "Gas Settings");
      { gas_tc = new Fl_Input(510, 332, 130, 25, "Thermal Conductivity");
      } // Fl_Input* gas_tc
      { gas_dens = new Fl_Input(510, 356, 130, 25, "Density");
      } // Fl_Input* gas_dens
      { gas_sh = new Fl_Input(510, 381, 130, 25, "Specific Heat");
      } // Fl_Input* gas_sh
      gas_set->end();
    } // Fl_Group* gas_set
    { mesh_set = new Fl_Group(185, 460, 475, 475, "Mesh Settings");
      { x_elem = new Fl_Input(510, 468, 130, 25, "Elements (X)");
      } // Fl_Input* x_elem
      { y_elem = new Fl_Input(510, 493, 130, 25, "Elements (Y)");
      } // Fl_Input* y_elem
      { xmax = new Fl_Input(510, 518, 130, 25, "X Max");
      } // Fl_Input* xmax
      { ymax = new Fl_Input(510, 543, 130, 25, "Y Max");
      } // Fl_Input* ymax
      mesh_set->end();
    } // Fl_Group* mesh_set
    { time_set = new Fl_Group(185, 590, 475, 675, "Time Settings");
      { duration = new Fl_Input(510, 599, 130, 25, "Number of Steps");
      } // Fl_Input* duration
      { timestep = new Fl_Input(510, 624, 130, 25, "Timestep");
      } // Fl_Input* timestep
      time_set->end();
    } // Fl_Group* time_set
    { submit = new Fl_Button(520, 680, 100, 25, "Submit");
      submit->callback((Fl_Callback*)cb_submit);
    } // Fl_Button* submit
    { in_file = new Fl_File_Browser(26, 105, 310, 235, "Input File Location");
      in_file->load(".");
      in_file->type(FL_HOLD_BROWSER);
    } // Fl_File_Browser* in_file
    { mesh_file = new Fl_File_Browser(26, 424, 310, 235, "Mesh File Location");
      mesh_file->load(".");
      mesh_file->type(FL_HOLD_BROWSER);
    } // Fl_File_Browser* mesh_file
    { new_file = new Fl_Input(177, 364, 161, 25, "New Input File Name");
    } // Fl_Input* new_file
    main_window->end();
  } // Fl_Double_Window* main_window
  return main_window;
}
