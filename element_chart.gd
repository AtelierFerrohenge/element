@tool
extends EditorPlugin

var types_dir: LineEdit = null
var submit_dir: Button = null
var chart: Chart = null


func _enter_tree():
	types_dir = LineEdit.new()
	types_dir.placeholder_text = "res://types"
	EditorInterface.get_editor_main_screen().add_child(types_dir)
	submit_dir = Button.new()
	submit_dir.text = "Get Types"
	EditorInterface.get_editor_main_screen().add_child(submit_dir)
	chart = Chart.new()
	types_dir.text_changed.connect(chart._update_dir)
	submit_dir.pressed.connect(chart._draw_chart)
	EditorInterface.get_editor_main_screen().add_child(chart)
	_make_visible(false)


func _exit_tree():
	if types_dir:
		types_dir.queue_free()
	if submit_dir:
		submit_dir.queue_free()
	if chart:
		chart.queue_free()


func _has_main_screen():
	return true


func _make_visible(visible):
	if types_dir:
		types_dir.visible = visible
	if submit_dir:
		submit_dir.visible = visible
	if chart:
		chart.visible = visible


func _get_plugin_name():
	return "Element Chart"


func _get_plugin_icon():
	return EditorInterface.get_editor_theme().get_icon("Node", "EditorIcons")


class Chart extends GridContainer:
	var dir: String = ""
	
	
	func _update_dir(new_dir: String):
		dir = new_dir
	
	
	func _draw_chart():
		for child in get_children():
			child.queue_free()
		if not DirAccess.dir_exists_absolute(dir):
			return
		var elements = DirAccess.get_files_at(dir)
		columns = elements.size() + 1
		add_child(Label.new())
		for element in elements:
			var top_label = Label.new()
			top_label.text = element.get_slice(".", 0)
			add_child(top_label)
		for element in elements:
			var row_label = Label.new()
			row_label.text = element.get_slice(".", 0)
			add_child(row_label)
			for interact_element in elements:
				# Might be null and error, handle this
				var element_res = load(dir + "/" + element) as Element
				var interact_res = load(dir + "/" + interact_element) as Element
				var result = interact_res.get_interaction(element_res.name)
				var interaction = Label.new()
				interaction.text = str(result)
				add_child(interaction)
