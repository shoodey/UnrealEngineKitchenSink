// Copyright Shoodey. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class KitchenSinkTarget : TargetRules
{
	public KitchenSinkTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_4;
		ExtraModuleNames.Add("KitchenSink");
	}
}
