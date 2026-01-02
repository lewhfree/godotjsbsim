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
    // No methods to bind yet, but this function is required by GDCLASS
    ClassDB::bind_method(D_METHOD("SetRootDir", "rootDir"), &GodotJSBSim::SetRootDir);
}

void GodotJSBSim::_ready() {
    UtilityFunctions::print("ready");
    fdmex = new JSBSim::FGFDMExec();
    UtilityFunctions::print("ready exec");
}

void GodotJSBSim::_physics_process(double delta) {
    // UtilityFunctions::print("physics");
}

void GodotJSBSim::SetRootDir(const String &dir) {
    globalRootDir = SGPath(dir.utf8().get_data());  // allocate new path
    fdmex->SetRootDir(globalRootDir);        // pass pointer

    UtilityFunctions::print("set root dir to", dir);
}
