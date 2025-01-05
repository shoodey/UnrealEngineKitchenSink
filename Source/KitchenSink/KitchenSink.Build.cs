// Copyright Shoodey. All Rights Reserved.

using UnrealBuildTool;

public class KitchenSink : ModuleRules
{
	public KitchenSink(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"GameplayTags"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });
	}
}