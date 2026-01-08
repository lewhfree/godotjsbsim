extends Node

var elevatorval = 0
var aileronval = 0
var throttleval = 0

func pull_axes():
	return Vector4(-0.1 * elevatorval, -0.1 * aileronval, 0, throttleval * 0.1)
	
func _input(event):
	if event.is_action("pull up"):
		elevator(1.0)
	elif event.is_action("push down"):
		elevator(-1.0)
	elif event.is_action("roll right"):
		aileron(1.0)
	elif event.is_action("roll left"):
		aileron(-1.0)
	elif event.is_action("throttle up"):
		throttle(1.0)
	elif event.is_action("throttle down"):
		throttle(-1.0)

func elevator(upordown: float):
	if elevatorval <= 10 and elevatorval >= -10:
		if upordown == 1.0:
			elevatorval += 1
		elif upordown == -1.0:
			elevatorval -= 1

func aileron(rightorleft: float):
	if aileronval <= 10 and aileronval >= -10:
		if rightorleft == 1.0:
			aileronval += 1
		elif rightorleft == -1.0:
			aileronval -= 1

func throttle(upordown: float):
	if throttleval <= 10 and throttleval >= 0:
		if upordown == 1.0:
			throttleval += 1
		elif upordown == -1.0:
			throttleval -= 1
