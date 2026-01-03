extends Node


# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	$JSBSim.SetRootDir(ProjectSettings.globalize_path("res://JSBSim_files/"))
	print($JSBSim.GetRootDir())
	$JSBSim.Setdt(1.0/60.0)
	print($JSBSim.GetDeltaT())


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(_delta: float) -> void:
	pass
