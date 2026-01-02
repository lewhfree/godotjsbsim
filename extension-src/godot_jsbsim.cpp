#include "godot_jsbsim.h"
#include <godot_cpp/variant/utility_functions.hpp>

#include <FGFDMExec.h>
#include <simgear/misc/sg_path.hxx>

using namespace godot;

GodotJSBSim::GodotJSBSim() {
    // Constructor
}

GodotJSBSim::~GodotJSBSim() {
    // Destructor
}

void GodotJSBSim::_bind_methods() {
    ClassDB::bind_method(D_METHOD("SetRootDir", "rootDir"), &GodotJSBSim::SetRootDir);
    ClassDB::bind_method(D_METHOD("GetRootDir"), &GodotJSBSim::GetRootDir);
    ClassDB::bind_method(D_METHOD("GetDeltaT"), &GodotJSBSim::GetDeltaT);
}

void GodotJSBSim::_ready() {
    fdmex = new JSBSim::FGFDMExec();
}

void GodotJSBSim::_physics_process(double delta) {

}

void GodotJSBSim::SetRootDir(const String &dir) {
    fdmex->SetRootDir(SGPath(dir.utf8().get_data()));
}

String GodotJSBSim::GetRootDir(void) {
    const SGPath tmp = fdmex->GetRootDir();
    return String(tmp.c_str());
}

double GodotJSBSim::GetDeltaT(void) {
    return fdmex->GetDeltaT();
}
