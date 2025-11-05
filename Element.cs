using Godot;
using System;

public abstract partial class Element : Resource
{
	[Export]
	public Godot.Collections.Dictionary<Element, ElementInteraction> Ineractions { get; set; }
}
