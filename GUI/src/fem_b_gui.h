// generated by Fast Light User Interface Designer (fluid) version 1.0304

#ifndef fem_b_gui_h
#define fem_b_gui_h
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
extern Fl_Double_Window *main_window;
#include <FL/Fl_Group.H>
extern Fl_Group *bc_set;
#include <FL/Fl_Round_Button.H>
extern Fl_Round_Button *iso_button;
extern Fl_Round_Button *adia_button;
#include <FL/Fl_Input.H>
extern Fl_Input *wall_temp;
extern Fl_Input *in_temp;
extern Fl_Input *out_p;
extern Fl_Group *gas_set;
extern Fl_Input *gas_tc;
extern Fl_Input *gas_dens;
extern Fl_Input *gas_sh;
extern Fl_Input *gas_visc;
extern Fl_Input *gas_mf;
extern Fl_Group *chem_set;
extern Fl_Input *rx_rate;
extern Fl_Input *fuel_h;
extern Fl_Group *mesh_set;
extern Fl_Input *x_elem;
extern Fl_Input *y_elem;
extern Fl_Group *time_set;
extern Fl_Input *duration;
extern Fl_Input *timestep;
#include <FL/Fl_Button.H>
extern Fl_Button *submit;
#include <FL/Fl_File_Browser.H>
extern Fl_File_Browser *in_file;
extern Fl_File_Browser *mesh_file;
extern Fl_Input *new_file;
Fl_Double_Window* make_window();
#endif
